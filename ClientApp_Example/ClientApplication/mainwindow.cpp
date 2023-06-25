#include "mainwindow.h"
#include <QMessageBox>
#include <QUdpSocket>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);

    tcpSocket = new QTcpSocket(this);

    connect(sendButton, &QPushButton::clicked, this, &MainWindow::sendMessage);
    connect(discoverButton, &QPushButton::clicked, this, &MainWindow::discoverServers);
}

void MainWindow::sendMessage()
{
    QString recipient = recipientLineEdit->text();
    QString message;

    if (radioButton1->isChecked()) {
        message = "Opcja 1";
    } else if (radioButton2->isChecked()) {
        message = "Opcja 2";
    } else if (radioButton3->isChecked()) {
        message = "Opcja 3";
    }

    message += "\n\n" + notesTextEdit->toPlainText();

    tcpSocket->connectToHost(recipient, 1234);

    if (tcpSocket->waitForConnected()) {
        tcpSocket->write(message.toUtf8());
        tcpSocket->waitForBytesWritten();
        tcpSocket->disconnectFromHost();
    } else {
        QMessageBox::critical(this, "Błąd", "Nie udało się połączyć z serwerem.");
    }
}

void MainWindow::discoverServers()
{
    QUdpSocket udpSocket;
    udpSocket.bind(1235, QUdpSocket::ShareAddress);

    QByteArray datagram = "DiscoverServers";
    udpSocket.writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 1235);

    QStringList servers;
    while (udpSocket.hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket.pendingDatagramSize());
        udpSocket.readDatagram(datagram.data(), datagram.size());

        QString serverAddress = QString(datagram);
        servers.append(serverAddress);
    }

    populateServerList(servers);
}

void MainWindow::populateServerList(const QStringList& servers)
{
    serverComboBox->clear();
    serverComboBox->addItems(servers);
}

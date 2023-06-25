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
   // connect(tcpSocket, &QTcpSocket::readyRead, this, &MainWindow::receiveMessage);
}

void MainWindow::sendMessage()
{
    QString recipient = recipientLineEdit->text();
    QString UserInfo = QHostInfo::localHostName();
    QString message;

    if (radioButton1->isChecked()) {
        message = "Opcja 1";
    } else if (radioButton2->isChecked()) {
        message = "Opcja 2";
    } else if (radioButton3->isChecked()) {
        message = "Opcja 3";
    }

    message +=  "\n" + UserInfo + "\n" + notesTextEdit->toPlainText() + "\n";


    tcpSocket->connectToHost(recipient, 4829);

    if (tcpSocket->waitForConnected()) {
        qDebug() << "Wysyłanie wiadomości:";
                qDebug() << "Odbiorca: " << UserInfo;
                qDebug() << "Treść: " << message;
        tcpSocket->write(message.toUtf8());
        tcpSocket->waitForBytesWritten();
        tcpSocket->disconnectFromHost();
        qDebug() << "Wysłano Pomyślnie";
    } else {
        QMessageBox::critical(this, "Błąd", "Nie udało się połączyć z serwerem.");
    }
}


//void MainWindow::receiveMessage()
//{
//    QString message = QString::fromUtf8(tcpSocket->readAll());
//    QMessageBox::information(this, "Otrzymano wiadomość", message);
//}

void MainWindow::discoverServers()
{
    QUdpSocket udpSocket;
    udpSocket.bind(4830, QUdpSocket::ShareAddress);

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

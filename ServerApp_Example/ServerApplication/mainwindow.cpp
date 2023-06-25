#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(messageReceived(QString, QString, QString)), this, SLOT(handleMessage(QString, QString, QString)));
    udpServer = new QUdpSocket(this);
    udpServer->bind(4830); // Wybierz odpowiedni port
    connect(udpServer, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));

    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    if (!tcpServer->listen(QHostAddress::Any, 4829))
    {
        QMessageBox::critical(this, "Error", "Failed to start the server: " + tcpServer->errorString());
        return;
    }

    trayMenu = new QMenu(this);
    QAction *toggleVisibilityAction = new QAction("Pokaż", this);
    QAction *quitAction = new QAction("Zamknij",this);
    connect(toggleVisibilityAction, SIGNAL(triggered()), this, SLOT(toggleVisibility()));
    connect(quitAction, SIGNAL(triggered()), SLOT(quit()));
    trayMenu->addAction(toggleVisibilityAction);
    trayMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(QIcon("diag_center.ico"), this);
    trayIcon->setContextMenu(trayMenu);
    trayIcon->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newConnection()
{
    qDebug() << "Nowe połączenie";
    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
    clientSockets.append(clientSocket);
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(readData()));
}

void MainWindow::processPendingDatagrams()
{
    while (udpServer->hasPendingDatagrams())
    {
        QByteArray datagram;
        QHostAddress senderAddress;
        quint16 senderPort;

        datagram.resize(udpServer->pendingDatagramSize());
        udpServer->readDatagram(datagram.data(), datagram.size(), &senderAddress, &senderPort);
    }
}

void MainWindow::readData()
{
    qDebug() << "Czytam";
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (clientSocket)
    {
        qDebug() << "Klient Znaleziony";
        QString data = QString::fromUtf8(clientSocket->readAll());
        qDebug() << "dane odczytane";
        QStringList messageParts = data.split("\n");
        qDebug() << "Czytam messageParts";
        qDebug() << messageParts;
        if (messageParts.size() >= 3)
        {
            qDebug() << "messageParts size >= 3";
            QString senderName = messageParts[1];
            QString subject = messageParts[0];
            QString description = messageParts[2];

            qDebug() << "Odebrano dane. Emitowanie sygnału messageReceived...";
            emit messageReceived(senderName, subject, description); // Emitowanie sygnału z danymi wiadomości

            // Wyświetlenie otrzymanej wiadomości
                        qDebug() << "Otrzymano wiadomość:";
                        qDebug() << "Od: " << senderName;
                        qDebug() << "Temat: " << subject;
                        qDebug() << "Opis: " << description;
        }
    }
}



QList<QString> MainWindow::getMessages()
{
    return messages;
}


void MainWindow::displayMessage(const QString& sender, const QString& subject, const QString& description)
{
    QString message = "Od: " + sender + "\n"
                      "Temat: " + subject + "\n"
                      "Opis: " + description;
    QMessageBox::information(this, "Nowe zgłoszenie", message);
}

void MainWindow::toggleVisibility()
{
    if (isVisible())
        hide();
    else
        show();
}

void MainWindow::quit()
{
    qApp->quit();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (trayIcon->isVisible())
    {
        hide();
        event->ignore();
    }
    else
    {
        event->accept();
    }
}
void MainWindow::handleMessage(const QString& sender, const QString& subject, const QString& description)
{
    qDebug() << "Przetwarzanie otrzymanej wiadomości...";
    qDebug() << "Otrzymano wiadomość:";
        qDebug() << "Od: " << sender;
        qDebug() << "Temat: " << subject;
        qDebug() << "Opis: " << description;
    // Tutaj możesz wykonać odpowiednie operacje na otrzymanych danych wiadomości
    // Na przykład, możesz wyświetlić je w oknie aplikacji serwerowej
    QString message = "Od : " + sender + "\n"
                      "Temat: " + subject + "\n"
                      "Opis: " + description;

    QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Nowe zgłoszenie problemu!!!");
        msgBox.setText(message);
        msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowStaysOnTopHint); // Dodaj flagę WindowStaysOnTopHint
        msgBox.exec();
}


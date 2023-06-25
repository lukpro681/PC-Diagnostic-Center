#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    if (!tcpServer->listen(QHostAddress::Any, 1234))
    {
        QMessageBox::critical(this, "Error", "Failed to start the server: " + tcpServer->errorString());
        return;
    }

    trayMenu = new QMenu(this);
    QAction *toggleVisibilityAction = new QAction("Toggle Visibility", this);
    connect(toggleVisibilityAction, SIGNAL(triggered()), this, SLOT(toggleVisibility()));
    trayMenu->addAction(toggleVisibilityAction);

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
    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
    clientSockets.append(clientSocket);

    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(readData()));
}

void MainWindow::readData()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (clientSocket)
    {
        QString data = QString::fromUtf8(clientSocket->readAll());
        QStringList messageParts = data.split(";");
        if (messageParts.size() == 3)
        {
            QString senderName = clientSocket->peerAddress().toString();
            QString subject = messageParts[0];
            QString description = messageParts[1];

            displayMessage(senderName, subject, description);
        }
    }
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

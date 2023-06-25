#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QMessageBox>
#include <QEvent>
#include <QCloseEvent>
#include <QUdpSocket>
#include <QHostInfo>
#include <QSysInfo>
#include <QList>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QList<QString> getMessages();
protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void newConnection();
    void readData();
    void displayMessage(const QString& sender, const QString& subject, const QString& description);
    void toggleVisibility();
    void quit();
    void processPendingDatagrams();
    void handleMessage(const QString& sender, const QString& subject, const QString& description);

signals:
    void messageReceived(const QString& sender, const QString& subject, const QString& description);



private:
    Ui::MainWindow *ui;
    QTcpServer *tcpServer;
    QUdpSocket *udpServer;
    QList<QTcpSocket*> clientSockets;
    QSystemTrayIcon *trayIcon;
    QMenu *trayMenu;
    QList<QString> messages;
};

#endif // MAINWINDOW_H

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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void newConnection();
    void readData();
    void displayMessage(const QString& sender, const QString& subject, const QString& description);
    void toggleVisibility();

private:
    Ui::MainWindow *ui;
    QTcpServer *tcpServer;
    QList<QTcpSocket*> clientSockets;
    QSystemTrayIcon *trayIcon;
    QMenu *trayMenu;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstdlib>
#include <QMessageBox>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QNetworkInterface>
#include <QSystemTrayIcon>
#include <QAction>
#include <QActionEvent>
#include <QMenu>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showNormal()
    {
        this->showNormal(); // lub this->show()
    }
    void connectsock();

private slots:
    void aboutWindow();
    void on_basic_clicked();

    void on_advanced_clicked();


    void on_pushButton_clicked();


    void on_report_prob_clicked();



    void on_actionO_Aplikacji_triggered();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H

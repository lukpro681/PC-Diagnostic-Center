#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QSysInfo>
#include <QHostInfo>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void sendMessage();
    void discoverServers();
//    void receiveMessage();

private:
    QTcpSocket* tcpSocket;
    void populateServerList(const QStringList& servers);


};

#endif // MAINWINDOW_H

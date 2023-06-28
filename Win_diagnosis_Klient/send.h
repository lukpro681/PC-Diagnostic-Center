#ifndef SEND_H
#define SEND_H

#include <QDialog>
#include <QTcpSocket>
#include <QSysInfo>
#include <QHostInfo>

namespace Ui {
class send;
}

class send : public QDialog
{
    Q_OBJECT

public:
    explicit send(QWidget *parent = nullptr);
    ~send();
    void wyslij();
    void weryfikuj(QString,QString,QString,QString,QString);

    void discoverServers();
private slots:
    void on_buttonBox_accepted();

    void on_sendButton_clicked();

private:
    QTcpSocket* tcpSocket;
    Ui::send *ui;
};

#endif // SEND_H

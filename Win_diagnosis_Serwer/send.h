#ifndef SEND_H
#define SEND_H

#include <QDialog>

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

private slots:
    void on_buttonBox_accepted();

    void on_sendButton_clicked();

private:
    Ui::send *ui;
};

#endif // SEND_H

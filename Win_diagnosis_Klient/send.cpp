#include "send.h"
#include "ui_send.h"
#include <QMessageBox>
#include <QUdpSocket>

send::send(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::send)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket(this);
}

send::~send()
{
    delete ui;
}

void send::on_buttonBox_accepted()
{

}



void send::on_sendButton_clicked()
{
    if(ui->NoTonerProb->isChecked()||ui->VegasProb->isChecked()||ui->ZoomTeamsProb->isChecked()||
            ui->PrinterNotFound->isChecked()||ui->PrinterNotWork->isChecked()||ui->mailProb->isChecked()||
            ui->phoneProb->isChecked()||ui->otherProb->isChecked()){


        QString recipient;


           recipient = ui->OtherIP->text();



            if(ui->type_prob->toPlainText()==""){
                ui->type_prob->setPlainText("Brak opisu");
            }



            QString UserInfo = QHostInfo::localHostName();
            QString message;

            if (ui->NoTonerProb->isChecked()) {
                message = "Brak toneru w drukarce";
            } else if (ui->VegasProb->isChecked()) {
                message = "Problem z Sony Vegas";
            } else if (ui->ZoomTeamsProb->isChecked()) {
                message = "Problem z ZOOM/Teams";
            }
             else if (ui->PrinterNotFound->isChecked()) {
                message = "Komputer nie widzi drukarki";
            }
             else if (ui->PrinterNotWork->isChecked()) {
                message = "Drukarka nie działa";
            }
             else if (ui->mailProb->isChecked()) {
                message = "Problem ze skrzynką mailową";
            }
             else if (ui->phoneProb->isChecked()) {
                message = "Problem z telefonem";
            }
             else if (ui->otherProb->isChecked()) {
                message = "Inny problem";
            }

            message +=  "\n" + UserInfo + "\n" + ui->type_prob->toPlainText() + "\n";

            tcpSocket->connectToHost(recipient, 4829);

            if (tcpSocket->waitForConnected()) {
                qDebug() << "Wysyłanie wiadomości:";
                        qDebug() << "Odbiorca: " << UserInfo;
                        qDebug() << "Treść: " << message;
                tcpSocket->write(message.toUtf8());
                tcpSocket->waitForBytesWritten();
                tcpSocket->disconnectFromHost();
                qDebug() << "Wysłano Pomyślnie";
                ui->type_prob->clear();
                QMessageBox::information(this,"Komunikat","Zgłoszenie zostało wysłane pomyślnie, zajmiemy sie nim od 3-5 dni roboczych");
                send::close();
            } else {
                QMessageBox::critical(this, "Błąd", "Nie udało się połączyć z serwerem.");
            }
        }

    else {
        QMessageBox::critical(this,"Błąd","Musisz wybrać temat");
    }
}
void send::discoverServers()
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
}







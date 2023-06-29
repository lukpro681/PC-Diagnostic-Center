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

        if(ui->Admin->isChecked())
        {
            recipient = "192.168.0.59";
        }
        else{
           recipient = ui->OtherIP->text();
        }


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



//    std::string argTemat, argOpis, arg1, arg2, arg3;

//    {
//        if(ui->BIG_INCIDENT->isChecked())
//            argTemat = "!!! PROBLEM NA ANTENIE !!!";
//        if(ui->EnovaProb->isChecked())
//            argTemat = "Problem z Enovą";
//        if(ui->NoTonerProb->isChecked())
//            argTemat = "Brak Toneru w drukarce";
//        if(ui->RamrokProb->isChecked())
//            argTemat = "Problem z RamRok";
//        if(ui->VegasProb->isChecked())
//            argTemat = "Problem z SAWPRO/VEGAS/Movie Studio";
//        if(ui->ZoomTeamsProb->isChecked())
//            argTemat = "Problem z Zoom/Teams";
//        if(ui->d3Prob->isChecked())
//            argTemat = "Problem z D3";
//        if(ui->phoneProb->isChecked())
//            argTemat = "Problem z telefonem";
//        if(ui->PrinterNotFound->isChecked())
//            argTemat = "Problem ze znalezieniem drukarki";
//        if(ui->PrinterNotWork->isChecked())
//            argTemat = "Drukarka nie działa";
//        if(ui->mailProb->isChecked())
//            argTemat = "Problem ze Skrzynką pocztową";
//        if(ui->otherProb->isChecked())
//            argTemat = "Inny problem";


//        if(ui->type_prob->toPlainText() == "")
//            argOpis = "brak";
//        else{
//            QString Temp = ui->type_prob->toPlainText();
//            argOpis = Temp.toStdString();
//        }

//        if(ui->piotr->isChecked())
//            arg1 = "piotrek8";
//        if(ui->piotr->isChecked())
//            arg2 = "lukasz-radio1";
//        if(ui->piotr->isChecked())
//            arg3 = "markus-radio";

//    }
// std::string command = "cmd.exe /C set argTemat=" + argTemat +" && set argOpis=" + argOpis + " && set arg1=" + arg1 + " && set arg2=" + arg2 + "set arg3=" + arg3 + " && send.bat";

//    system(command.c_str());











//    if(ui->BIG_INCIDENT->isChecked() || ui->EnovaProb->isChecked() ||  ui->NoTonerProb->isChecked() ||
//            ui->RamrokProb->isChecked() || ui->VegasProb->isChecked() ||    ui->ZoomTeamsProb->isChecked() ||
//            ui->d3Prob->isChecked() || ui->phoneProb->isChecked() ||   ui->PrinterNotFound->isChecked() ||
//            ui->PrinterNotWork->isChecked())
//   {
//        if(ui->piotr->isChecked() || ui->luke->isChecked() || ui->markus->isChecked())
//           {
//            if(ui->type_prob->toPlainText() == "")
//                {
//                    if(QMessageBox::question(this, "brak opisu", "Czy na pewno chcesz wysłać wiadomość bez dodatkowych uwag?", QMessageBox::Ok | QMessageBox::No) == QMessageBox::Ok)
//                    {
//                        //wyslij();
//                        std::string argTemat, argOpis, arg1, arg2, arg3;

//                        {
//                            if(ui->BIG_INCIDENT->isChecked())
//                                argTemat = "!!! PROBLEM NA ANTENIE !!!";
//                            if(ui->EnovaProb->isChecked())
//                                argTemat = "Problem z Enovą";
//                            if(ui->NoTonerProb->isChecked())
//                                argTemat = "Brak Toneru w drukarce";
//                            if(ui->RamrokProb->isChecked())
//                                argTemat = "Problem z RamRok";
//                            if(ui->VegasProb->isChecked())
//                                argTemat = "Problem z SAWPRO/VEGAS/Movie Studio";
//                            if(ui->ZoomTeamsProb->isChecked())
//                                argTemat = "Problem z Zoom/Teams";
//                            if(ui->d3Prob->isChecked())
//                                argTemat = "Problem z D3";
//                            if(ui->phoneProb->isChecked())
//                                argTemat = "Problem z telefonem";
//                            if(ui->PrinterNotFound->isChecked())
//                                argTemat = "Problem ze znalezieniem drukarki";
//                            if(ui->PrinterNotWork->isChecked())
//                                argTemat = "Drukarka nie działa";


//                            if(ui->type_prob->toPlainText() == "")
//                                argOpis = "brak";
//                            else{
//                                QString Temp = ui->type_prob->toPlainText();
//                                argOpis = Temp.toStdString();
//                            }

//                            if(ui->piotr->isChecked())
//                                arg1 = "piotrek8";
//                            if(ui->piotr->isChecked())
//                                arg2 = "lukasz-radio1";
//                            if(ui->piotr->isChecked())
//                                arg3 = "markus-radio";

//                        }
//                     std::string command = "cmd.exe /C set argTemat=" + argTemat +" && set argOpis=" + argOpis + " && set arg1=" + arg1 + " && set arg2=" + arg2 + "set arg3=" + arg3 + " && send.bat";

//                        system(command.c_str());
//                        QWidget::close();
//                    }
//                    else(QMessageBox::critical(this,"brak opisu", "Operacja przerwana"));
//                }
//        }
//        else
//        {
//            QMessageBox::critical(this, "Nie wybrano odbiorcy!", "Musisz wybrać odbiorcę bądź odbiorców wiadomości");
//        }
//        }
//    else
//    {
//        QMessageBox::critical(this, "Brak tematu", "Musisz podać temat wiadomości");
//    }





//    if(ui->BIG_INCIDENT->isChecked())
//        Temat = "!!! PROBLEM NA ANTENIE !!!";
//    if(ui->EnovaProb->isChecked())
//        Temat = "Problem z Enovą";
//    if(ui->NoTonerProb->isChecked())
//        Temat = "Brak Toneru w drukarce";
//    if(ui->RamrokProb->isChecked())
//        Temat = "Problem z RamRok";
//    if(ui->VegasProb->isChecked())
//        Temat = "Problem z SAWPRO/VEGAS/Movie Studio";
//    if(ui->ZoomTeamsProb->isChecked())
//        Temat = "Problem z Zoom/Teams";
//    if(ui->d3Prob->isChecked())
//        Temat = "Problem z D3";
//    if(ui->phoneProb->isChecked())
//        Temat = "Problem z telefonem";
//    if(ui->PrinterNotFound->isChecked())
//        Temat = "Problem ze znalezieniem drukarki";
//    if(ui->PrinterNotWork->isChecked())
//        Temat = "Drukarka nie działa";


//    if(ui->type_prob->toPlainText() == "")
//        Opis = "brak";
//    else{
//        Opis = ui->type_prob->toPlainText();
//    }

//    if(ui->piotr->isChecked())
//        arg1 = "192.168.1.122";
//    if(ui->piotr->isChecked())
//        arg2 = "192.168.1.199";
//    if(ui->piotr->isChecked())
//        arg3 = "192.168.1.13";

void send::on_Admin_clicked(bool checked)
{
    if(checked)
        ui->OtherIP->setEnabled(false);
    else ui->OtherIP->setEnabled(true);

}


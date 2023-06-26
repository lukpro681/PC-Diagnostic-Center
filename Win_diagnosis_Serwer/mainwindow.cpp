#include "mainwindow.h"
#include "QtNetwork/qtcpsocket.h"
#include "send.h"
#include "ui_mainwindow.h"
#include "funkcje.h"
#include "about.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(wiadomoscOdebrana(QString,QString,QString)),this,SLOT(pokazWiadomosc(QString,QString,QString)));
    udpServer = new QUdpSocket(this);
    udpServer->bind(4830);
    connect(udpServer,SIGNAL(readyRead()), this, SLOT(przechwycData()));

    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()),this,SLOT(nowePolaczenie()));
    if (!tcpServer->listen(QHostAddress::Any, 4829))
    {
        QMessageBox::critical(this, "Błąd", "Nie można uruchomić nasłuchu: " + tcpServer->errorString());
        return;
    }

    menuZasobnika = new QMenu(this);
    QAction *akcjaWidocznosci = new QAction("Pokaż/ukryj",this);
    QAction *quitAction = new QAction("Zamknij",this);
    connect(akcjaWidocznosci,SIGNAL(triggered()),this,SLOT(widocznosc()));
    connect(quitAction,SIGNAL(triggered()),this,SLOT(zamknij()));

    menuZasobnika->addAction(akcjaWidocznosci);
    menuZasobnika->addAction(quitAction);

    ikonaZasobnik = new QSystemTrayIcon(QIcon("diag_center.ico"),this);
    ikonaZasobnik->setContextMenu(menuZasobnika);
    ikonaZasobnik->show();

    connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(onAboutToQuit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QList<QString> MainWindow::getWiadomosci()
{
    return wiadomosci;
}


void MainWindow::onAboutToQuit()
{
    // Tutaj możesz umieścić odpowiednią logikę lub zostawić pustą implementację
}

void MainWindow::on_basic_clicked()
{
    ui->op1->setDisabled(true);
    ui->op2->setDisabled(true);
    ui->op3->setDisabled(true);
    ui->op4->setDisabled(true);
    ui->op5->setDisabled(true);
    ui->op6->setDisabled(true);
    ui->op7->setDisabled(true);
    ui->op8->setDisabled(true);
    ui->pushButton->setEnabled(true);
  }


void MainWindow::on_advanced_clicked()
{
    ui->op1->setDisabled(false);
    ui->op2->setDisabled(false);
    ui->op3->setDisabled(false);
    ui->op4->setDisabled(false);
    ui->op5->setDisabled(false);
    ui->op6->setDisabled(false);
    ui->op7->setDisabled(false);
    ui->op8->setDisabled(false);
    ui->pushButton->setEnabled(true);
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->basic->isChecked())
    {
        sfcscan();
        dismscan();
        dismrestore();
        checkdiskf();
        restart();
    }
    else if(!ui->op1->isChecked() && !ui->op2->isChecked() && !ui->op3->isChecked() && !ui->op4->isChecked() && !ui->op5->isChecked() && !ui->op6->isChecked() && !ui->op7->isChecked() && !ui->op8->isChecked())
    {
        QMessageBox::critical(this,"Błąd","Musisz wybrać przynajmniej jedną opcję!");
    }
    else {
        if(ui->op8->isChecked())
            erase_temp();
        if(ui->op5->isChecked())
            dismanalyze();
        if(ui->op6->isChecked())
            dismclean();
        if(ui->op1->isChecked())
            sfcscan();
        if(ui->op2->isChecked())
            dismscan();
        if(ui->op3->isChecked())
            dismrestore();
        if(ui->op4->isChecked())
            checkdiskf();
        if(ui->op7->isChecked())
            restart();
    }
}




//void MainWindow::on_report_prob_clicked()      //niedostępne w aplikacji serwer
//{
//    send m_okno;
//    m_okno.setWindowTitle("Zgłoś problem do nas");
//    m_okno.setWindowIcon(QIcon("diag_center.ico"));
//    m_okno.exec();
//}

void MainWindow::nowePolaczenie()
{
    qDebug() << "nowe połączenie";
    QTcpSocket *klient = tcpServer->nextPendingConnection();
    klienci.append(klient);
    connect(klient, SIGNAL(readyRead()),this,SLOT(czytajDane()));
}

void MainWindow::czytajDane()
{
    qDebug() << "Czytam";
    QTcpSocket *klient = qobject_cast<QTcpSocket*>(sender());
    if (klient)
    {
        qDebug() << "Klient Znaleziony";
        QString data = QString::fromUtf8(klient->readAll());
        qDebug() << "dane odczytane";
        QStringList komunikat = data.split("\n");
        qDebug() << "Czytam messageParts";
        qDebug() << komunikat;
        if (komunikat.size() >= 3)
        {
            qDebug() << "komunikat size >= 3";
            QString nazwaNadawcy = komunikat[1];
            QString Temat = komunikat[0];
            QString Opis = komunikat[2];

            qDebug() << "Odebrano dane. Emitowanie sygnału messageReceived...";
            emit wiadomoscOdebrana(nazwaNadawcy, Temat, Opis); // Emitowanie sygnału z danymi wiadomości

            // Wyświetlenie otrzymanej wiadomości
                        qDebug() << "Otrzymano wiadomość: READ_DATA";
                        qDebug() << "Od: " << nazwaNadawcy;
                        qDebug() << "Temat: " << Temat;
                        qDebug() << "Opis: " << Opis;
        }
    }
}

void MainWindow::wyswietlDane(const QString &nadawca, const QString &temat, const QString &opis)
{
    qDebug()<< "WYSWIETL DANE FUNKCJA";
    QString wiadomosc = "Od: " + nadawca + "\n"
                      "Temat: " + temat + "\n"
                      "Opis: " + opis;
    QMessageBox::information(this, "Nowe zgłoszenie", wiadomosc);
}

void MainWindow::widocznosc()
{
    if (isVisible())
    {
        isMinimized = false;
            hide();
    }
    else
 {

       isMinimized = true;
        show();
 }
}

void MainWindow::zamknij()
{
    if (isMinimized) {
            hide();
        } else {
            qApp->quit();
        }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(ikonaZasobnik->isVisible())
    {
        hide();
        event->ignore();
    }
    else
    {
        event->accept();
    }
}
void MainWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::WindowStateChange) {
        QWindowStateChangeEvent *stateChangeEvent = static_cast<QWindowStateChangeEvent*>(event);
        if (stateChangeEvent->oldState() & Qt::WindowMinimized) {
            isMinimized = false;
        } else if (stateChangeEvent->oldState() & Qt::WindowNoState && windowState() & Qt::WindowMinimized) {
            isMinimized = true;
        }
    }
    QMainWindow::changeEvent(event);
}

void MainWindow::przechwycData()
{
    while (udpServer->hasPendingDatagrams())
    {
        QByteArray datagram;
        QHostAddress adresNadawcy;
        quint16 portNadawcy;

        datagram.resize(udpServer->pendingDatagramSize());
        udpServer->readDatagram(datagram.data(),datagram.size(), &adresNadawcy, &portNadawcy);
    }
}

void MainWindow::pokazWiadomosc(const QString &nadawca, const QString &temat, const QString &opis)
{
    qDebug() << "Przetwarzanie otrzymanej wiadomości... HANDLE_MESSAGE";
    qDebug() << "Otrzymano wiadomość:";
        qDebug() << "Od: " << nadawca;
        qDebug() << "Temat: " << temat;
        qDebug() << "Opis: " << opis;

    QString wiadomosc = "Od : " + nadawca + "\n"
                      "Temat: " + temat + "\n"
                      "Opis: " + opis;


    QMessageBox msgBox;

        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowIcon(QIcon("diag_center.ico"));
        msgBox.setWindowTitle("Nowe zgłoszenie problemu!!!");
        msgBox.setText(wiadomosc);
        msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowStaysOnTopHint); // pojawianie się nad wszystkimi oknami
        msgBox.exec();
}






#include "mainwindow.h"

#include <QApplication>
#include <QMenu>
#include <QDebug>
#include <QLocale>
#include <QMessageBox>
#include <QtNetwork/QTcpSocket>
#include <QTranslator>
#include <QtNetwork/QNetworkInterface>
#include <QSystemTrayIcon>
#include <QList>
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.windowIcon() = QIcon("rklogo.ico");
//    a.setQuitOnLastWindowClosed(false);
//    QPixmap trayPix(32,32);
//    trayPix.load("rklogo.ico");


//    QIcon oIcon(trayPix);
//   QSystemTrayIcon *trayIcon = new QSystemTrayIcon(oIcon);
//   qDebug() << trayIcon->isSystemTrayAvailable();
//   trayIcon->setVisible(true);
//   trayIcon->showMessage("LIGO ZŁOTA RĄCZKA", "Serwer Nasłuchu jest włączony", QSystemTrayIcon::Information, 1000);

//    QString serverAddress = "127.0.0.1";
//    quint16 serverPort = 4829;
//    QMessageBox x;
//    x.setWindowIcon(QIcon("rklogo.ico"));
//    QTcpSocket socket;
//        socket.connectToHost(serverAddress, serverPort);
//        if (socket.waitForConnected()) {
//            // Wysyłanie wiadomości do serwera
//            QString message = "Hello, World!";
//            socket.write(message.toUtf8());

//            // Oczekiwanie na odpowiedź od serwera
//            if (socket.waitForReadyRead()) {
//                // Odczytywanie odpowiedzi serwera
//                QString response = socket.readAll();

//                // Wyświetlanie odpowiedzi na ekranie
//                x.information(nullptr, "Odpowiedź serwera", response);
//            }
//        } else {
//            // Wyświetlanie błędu połączenia na ekranie
//            x.critical(nullptr, "Błąd połączenia", "Nie udało się połączyć z serwerem.");
//        }

//        // Zamykanie gniazda TCP
//        socket.close();

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Win_diagnosis_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;
    w.setWindowTitle("Ligo Złota Rączka - Serwer");
    w.setWindowIcon(QIcon("rklogo.ico"));
    w.show();
    return a.exec();
}

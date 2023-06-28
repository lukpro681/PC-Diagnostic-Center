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
#include <Windows.h>
#include <QCoreApplication>


int main(int argc, char *argv[])
{
    // Sprawdzanie uprawnień administratora
       BOOL isElevated = FALSE;
       HANDLE token = NULL;

       if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &token))
          {
              TOKEN_ELEVATION elevation;
              DWORD size = sizeof(TOKEN_ELEVATION);

              if (GetTokenInformation(token, TokenElevation, &elevation, sizeof(elevation), &size))
              {
                  isElevated = elevation.TokenIsElevated;
              }
          }

          // Jeśli nie jesteś administratorem, uruchamiaj aplikację ponownie z uprawnieniami administratora
          if (!isElevated)
          {
              wchar_t executablePath[MAX_PATH];
              GetModuleFileNameW(NULL, executablePath, MAX_PATH);

              ShellExecuteW(NULL, L"runas", executablePath, NULL, NULL, SW_SHOWNORMAL);

              return 0;
          }
    QApplication a(argc, argv);
    a.windowIcon() = QIcon("diag_center.ico");
//    a.setQuitOnLastWindowClosed(false);
//    QPixmap trayPix(32,32);
//    trayPix.load("diag_center.ico");


//    QIcon oIcon(trayPix);
//   QSystemTrayIcon *trayIcon = new QSystemTrayIcon(oIcon);
//   qDebug() << trayIcon->isSystemTrayAvailable();
//   trayIcon->setVisible(true);
//   trayIcon->showMessage("PC Diagnostic Center", "Serwer jest włączony", QSystemTrayIcon::Information, 1000);

//    QString serverAddress = "127.0.0.1";
//    quint16 serverPort = 4829;
//    QMessageBox x;
//    x.setWindowIcon(QIcon("diag_center.ico"));
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
    w.setWindowTitle("PC Diagnostic Center");
    w.setWindowIcon(QIcon("diag_center.ico"));
    w.show();
    return a.exec();
}

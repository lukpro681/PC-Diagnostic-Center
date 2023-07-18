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
//       BOOL isElevated = FALSE;
//       HANDLE token = NULL;

//       if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &token))
//          {
//              TOKEN_ELEVATION elevation;
//              DWORD size = sizeof(TOKEN_ELEVATION);

//              if (GetTokenInformation(token, TokenElevation, &elevation, sizeof(elevation), &size))
//              {
//                  isElevated = elevation.TokenIsElevated;
//              }
//          }

//          // Jeśli nie jesteś administratorem, uruchamiaj aplikację ponownie z uprawnieniami administratora
//          if (!isElevated)
//          {
//              wchar_t executablePath[MAX_PATH];
//              GetModuleFileNameW(NULL, executablePath, MAX_PATH);

//              ShellExecuteW(NULL, L"runas", executablePath, NULL, NULL, SW_SHOWNORMAL);

//              return 0;
//          }
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("diag_center.ico"));
    a.windowIcon() = QIcon("diag_center.ico");

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

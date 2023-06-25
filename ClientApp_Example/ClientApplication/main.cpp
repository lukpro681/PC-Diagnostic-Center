#include <QApplication>
#include "mainwindow.h"
#include <QLocale>
#include <QTranslator>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ClientApplication_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }
    MainWindow mainWindow;
       mainWindow.show();

       return app.exec();
}

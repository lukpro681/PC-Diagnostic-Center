#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <cstdlib>
#include <QMessageBox>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QNetworkInterface>
#include <QSystemTrayIcon>
#include <QAction>
#include <QActionEvent>
#include <QMenu>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QCloseEvent>
#include <QUdpSocket>
#include <QHostInfo>
#include <QSysInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showNormal()
    {
        this->showNormal(); // lub this->show()
    }

    QList<QString> getWiadomosci();

protected:
    void closeEvent(QCloseEvent *event) override;
    void changeEvent(QEvent *event) override;

private slots:
    void on_basic_clicked();

    void on_advanced_clicked();


    void on_pushButton_clicked();


   // void on_report_prob_clicked();   //niedostępne w aplikacji serwer

    void nowePolaczenie();
    void czytajDane();
    void wyswietlDane(const QString& nadawca, const QString& temat, const QString& opis);
    void widocznosc();
    void zamknij();
    void przechwycData();
    void pokazWiadomosc(const QString& nadawca, const QString& temat, const QString& opis);

    void onAboutToQuit();
signals:
    void wiadomoscOdebrana(const QString& nadawca, const QString& temat, const QString& opis);

private:
    QCloseEvent *zamknijEvent;
    bool isMinimized;


    Ui::MainWindow *ui;
    QTcpServer *tcpServer;
    QUdpSocket *udpServer;
    QList<QTcpSocket*> klienci;
    QSystemTrayIcon *ikonaZasobnik;
    QMenu *menuZasobnika;
    QList<QString> wiadomosci;
};


#endif // MAINWINDOW_H

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
//    QMenu *menu1 = new QMenu();
//    QAction* quitAction = new QAction("Quit", this);
//    connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);
//    menu1->addAction(quitAction);


    ui->setupUi(this);
  //  connectsock();
}



MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::connectsock()
{

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




void MainWindow::on_report_prob_clicked()
{
    send m_okno;
    m_okno.setWindowTitle("Zgłoś problem do nas");
    m_okno.setWindowIcon(QIcon("rklogo.ico"));
    m_okno.exec();
}






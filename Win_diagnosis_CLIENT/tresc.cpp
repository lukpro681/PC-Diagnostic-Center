#include "tresc.h"
#include "ui_tresc.h"

Tresc::Tresc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tresc)
{
    ui->setupUi(this);
}

Tresc::~Tresc()
{
    delete ui;
}

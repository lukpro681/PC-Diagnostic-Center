#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    Version = "1.1.0";
    Authors = "Łukasz Prokop";
    Desc =
        "Program ten jest otwarto-źródłowy oraz dostępny dla wszystkich na podstawie licencji "
           "GNU General Public License.";

    ui->setupUi(this);
    showAbout(Version, Authors, Desc);
}

about::~about()
{
    delete ui;
}

void about::showAbout(QString ver, QString aut, QString desc)
{
    ui->VersionLabel->setText("Wersja: " + ver);
    ui->AuthorLabel->setText("Autorzy: " + aut);
    ui->aboutLabel->setText(desc);
}

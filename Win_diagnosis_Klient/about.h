#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

namespace Ui {
class about;
}

class about : public QDialog
{
    Q_OBJECT

public:
    explicit about(QWidget *parent = nullptr);
    ~about();
    void showAbout(QString,QString,QString);

private:
    Ui::about *ui;
    QString Version;
    QString Authors;
    QString Desc;


};

#endif // ABOUT_H

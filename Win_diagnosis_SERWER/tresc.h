#ifndef TRESC_H
#define TRESC_H

#include <QDialog>

namespace Ui {
class Tresc;
}

class Tresc : public QDialog
{
    Q_OBJECT

public:
    explicit Tresc(QWidget *parent = nullptr);
    ~Tresc();

private:
    Ui::Tresc *ui;
};

#endif // TRESC_H

#ifndef CLIENTAPPLICATION_H
#define CLIENTAPPLICATION_H

#include <QWidget>

class ClientApplication : public QWidget
{
    Q_OBJECT

public:

    ClientApplication(QWidget *parent = nullptr);
    ~ClientApplication();
};
#endif // CLIENTAPPLICATION_H

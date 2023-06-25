/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *recipientLabel;
    QLineEdit *recipientLineEdit;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;
    QTextEdit *notesTextEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *sendButton;
    QPushButton *discoverButton;
    QComboBox *serverComboBox;
    QLabel *serverLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 10, 10, 10);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        recipientLabel = new QLabel(centralwidget);
        recipientLabel->setObjectName(QString::fromUtf8("recipientLabel"));

        horizontalLayout_4->addWidget(recipientLabel);

        recipientLineEdit = new QLineEdit(centralwidget);
        recipientLineEdit->setObjectName(QString::fromUtf8("recipientLineEdit"));

        horizontalLayout_4->addWidget(recipientLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        radioButton1 = new QRadioButton(centralwidget);
        radioButton1->setObjectName(QString::fromUtf8("radioButton1"));

        verticalLayout->addWidget(radioButton1);

        radioButton2 = new QRadioButton(centralwidget);
        radioButton2->setObjectName(QString::fromUtf8("radioButton2"));

        verticalLayout->addWidget(radioButton2);

        radioButton3 = new QRadioButton(centralwidget);
        radioButton3->setObjectName(QString::fromUtf8("radioButton3"));

        verticalLayout->addWidget(radioButton3);

        notesTextEdit = new QTextEdit(centralwidget);
        notesTextEdit->setObjectName(QString::fromUtf8("notesTextEdit"));

        verticalLayout->addWidget(notesTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        horizontalLayout->addWidget(sendButton);

        discoverButton = new QPushButton(centralwidget);
        discoverButton->setObjectName(QString::fromUtf8("discoverButton"));

        horizontalLayout->addWidget(discoverButton);


        verticalLayout->addLayout(horizontalLayout);

        serverComboBox = new QComboBox(centralwidget);
        serverComboBox->setObjectName(QString::fromUtf8("serverComboBox"));

        verticalLayout->addWidget(serverComboBox);

        serverLabel = new QLabel(centralwidget);
        serverLabel->setObjectName(QString::fromUtf8("serverLabel"));

        verticalLayout->addWidget(serverLabel);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Klient", nullptr));
        recipientLabel->setText(QCoreApplication::translate("MainWindow", "Odbiorca:", nullptr));
        radioButton1->setText(QCoreApplication::translate("MainWindow", "Opcja 1", nullptr));
        radioButton2->setText(QCoreApplication::translate("MainWindow", "Opcja 2", nullptr));
        radioButton3->setText(QCoreApplication::translate("MainWindow", "Opcja 3", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "Wy\305\233lij", nullptr));
        discoverButton->setText(QCoreApplication::translate("MainWindow", "Szukaj serwer\303\263w", nullptr));
        serverLabel->setText(QCoreApplication::translate("MainWindow", "Dost\304\231pne serwery:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

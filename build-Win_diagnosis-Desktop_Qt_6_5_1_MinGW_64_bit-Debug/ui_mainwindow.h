/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionO_Aplikacji;
    QAction *actionO_Aplikacji_2;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *basic;
    QRadioButton *advanced;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QCheckBox *op8;
    QCheckBox *op4;
    QCheckBox *op2;
    QCheckBox *op6;
    QCheckBox *op1;
    QCheckBox *op5;
    QCheckBox *op3;
    QCheckBox *op7;
    QLabel *diagno_info;
    QLabel *logo;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(350, 573);
        MainWindow->setMinimumSize(QSize(350, 573));
        MainWindow->setMaximumSize(QSize(350, 573));
        actionO_Aplikacji = new QAction(MainWindow);
        actionO_Aplikacji->setObjectName("actionO_Aplikacji");
        actionO_Aplikacji_2 = new QAction(MainWindow);
        actionO_Aplikacji_2->setObjectName("actionO_Aplikacji_2");
        actionO_Aplikacji_2->setCheckable(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        basic = new QRadioButton(groupBox);
        basic->setObjectName("basic");

        gridLayout_2->addWidget(basic, 0, 0, 1, 1);

        advanced = new QRadioButton(groupBox);
        advanced->setObjectName("advanced");

        gridLayout_2->addWidget(advanced, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 4, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setEnabled(true);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName("gridLayout");
        op8 = new QCheckBox(groupBox_2);
        op8->setObjectName("op8");
        op8->setEnabled(false);

        gridLayout->addWidget(op8, 15, 0, 1, 1);

        op4 = new QCheckBox(groupBox_2);
        op4->setObjectName("op4");
        op4->setEnabled(false);

        gridLayout->addWidget(op4, 9, 0, 1, 1);

        op2 = new QCheckBox(groupBox_2);
        op2->setObjectName("op2");
        op2->setEnabled(false);

        gridLayout->addWidget(op2, 4, 0, 1, 1);

        op6 = new QCheckBox(groupBox_2);
        op6->setObjectName("op6");
        op6->setEnabled(false);

        gridLayout->addWidget(op6, 2, 0, 1, 1);

        op1 = new QCheckBox(groupBox_2);
        op1->setObjectName("op1");
        op1->setEnabled(false);
        op1->setCheckable(true);

        gridLayout->addWidget(op1, 3, 0, 1, 1);

        op5 = new QCheckBox(groupBox_2);
        op5->setObjectName("op5");
        op5->setEnabled(false);
        op5->setLocale(QLocale(QLocale::Polish, QLocale::Poland));

        gridLayout->addWidget(op5, 1, 0, 1, 1);

        op3 = new QCheckBox(groupBox_2);
        op3->setObjectName("op3");
        op3->setEnabled(false);

        gridLayout->addWidget(op3, 6, 0, 1, 1);

        op7 = new QCheckBox(groupBox_2);
        op7->setObjectName("op7");
        op7->setEnabled(false);

        gridLayout->addWidget(op7, 16, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 5, 0, 2, 1);

        diagno_info = new QLabel(centralwidget);
        diagno_info->setObjectName("diagno_info");
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        diagno_info->setFont(font);
        diagno_info->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(diagno_info, 3, 0, 1, 1);

        logo = new QLabel(centralwidget);
        logo->setObjectName("logo");
        logo->setMaximumSize(QSize(175, 50));
        logo->setAutoFillBackground(false);
        logo->setPixmap(QPixmap(QString::fromUtf8("diag_center_banner.png")));
        logo->setScaledContents(true);
        logo->setOpenExternalLinks(true);

        gridLayout_3->addWidget(logo, 0, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setEnabled(false);
        pushButton->setMaximumSize(QSize(100, 16777215));

        gridLayout_3->addWidget(pushButton, 7, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionO_Aplikacji->setText(QCoreApplication::translate("MainWindow", "O Aplikacji", nullptr));
        actionO_Aplikacji_2->setText(QCoreApplication::translate("MainWindow", "O Aplikacji", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Wybierz tryb naprawy", nullptr));
#if QT_CONFIG(tooltip)
        basic->setToolTip(QCoreApplication::translate("MainWindow", "Wykonuje podstawow\304\205 procedur\304\231 naprawy systemu plik\303\263w", nullptr));
#endif // QT_CONFIG(tooltip)
        basic->setText(QCoreApplication::translate("MainWindow", "Podstawowy", nullptr));
#if QT_CONFIG(tooltip)
        advanced->setToolTip(QCoreApplication::translate("MainWindow", "Pozwala wybra\304\207 zestaw instrukcji, kt\303\263ry ma zosta\304\207 wykonany", nullptr));
#endif // QT_CONFIG(tooltip)
        advanced->setText(QCoreApplication::translate("MainWindow", "Zaawansowany", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Opcje Zaawansowane", nullptr));
        op8->setText(QCoreApplication::translate("MainWindow", "Usu\305\204 pliki tymczasowe", nullptr));
        op4->setText(QCoreApplication::translate("MainWindow", "Sprawdzenie dysku", nullptr));
        op2->setText(QCoreApplication::translate("MainWindow", "Skanowanie systemu plik\303\263w pod k\304\205tem uszkodze\305\204", nullptr));
        op6->setText(QCoreApplication::translate("MainWindow", "Wyczy\305\233\304\207 tymczasowe pliki aktualizacji", nullptr));
        op1->setText(QCoreApplication::translate("MainWindow", "Kontroler plik\303\263w systemowych", nullptr));
        op5->setText(QCoreApplication::translate("MainWindow", "Analiza tymczasowych plik\303\263w aktualizacji", nullptr));
        op3->setText(QCoreApplication::translate("MainWindow", "Naprawa uszkodzonych plik\303\263w", nullptr));
        op7->setText(QCoreApplication::translate("MainWindow", "Wykonaj ponowne uruchomienie", nullptr));
        diagno_info->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Diagnostyka </p><p>systemu Windows</p></body></html>", nullptr));
        logo->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Rozpocznij", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

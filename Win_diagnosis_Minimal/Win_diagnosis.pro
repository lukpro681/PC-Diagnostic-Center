QT       += core gui
QT += network

# QMAKE_LFLAGS += /MANIFESTUAC:"level='requireAdministrator' uiAccess='false'"

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    funkcje.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    about.h \
    funkcje.h \
    mainwindow.h

FORMS += \
    about.ui \
    mainwindow.ui

TRANSLATIONS += \
    Win_diagnosis_pl_PL.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Win_diagnosis_en_US.ts \
    rklogo.ico


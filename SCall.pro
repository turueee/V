QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

RC_ICONS = 5.ico

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    TCalls.cpp \
    TDatabase.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    TCalls.h \
    TDatabase.h \
    mainwindow.h

FORMS += \
    mainwindow.ui


win32 {
    COPIES += database
    database.files = $$PWD/TCalls.db
    database.path = $$OUT_PWD
}
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

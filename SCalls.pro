QT += core gui widgets sql

CONFIG += c++17

RC_ICONS = 5.ico

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    tcriteriallimit.cpp \
    mainwindow.cpp \
    tcalls.cpp \
    tdatabase.cpp

HEADERS += \
    mainwindow.h \
    tcriteriallimit.h \
    tcalls.h \
    tdatabase.h

FORMS += \
    mainwindow.ui


win32 {
    database.files = $$PWD/calls.db
    database.path = $$OUT_PWD
    COPIES += database
}
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

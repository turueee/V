#include "mainwindow.h"
#include "tdatabase.h"
#include "tcalls.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TDatabase db("calls.db");
    TCalls c_calls(db);
    db.insertLabName("lab1","3824Б1ФИ1");
    MainWindow w(c_calls, db);
    w.show();
    return a.exec();
}

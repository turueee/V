#include "mainwindow.h"
#include "TDatabase.h"
#include "TCalls.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    TDatabase db("calls.db");
    TCalls c_calls(db);
    QApplication a(argc, argv);
    MainWindow w(c_calls, db);
    w.show();
    return a.exec();
}

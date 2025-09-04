#include "mainwindow.h"
#include "TDatabase.h"
#include "TCalls.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TDatabase db("TCalls.db");
    TCalls c_calls(db);
    MainWindow w(c_calls, db);
    w.show();
    return a.exec();
}

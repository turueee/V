#include "mainwindow.h"
#include "TDatabase.h"
#include "TCalls.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TDatabase callsdb("TCalls.db");
    std::vector<std::string> missings;
    TCalls c_calls(callsdb, missings);
    MainWindow w(&c_calls, &callsdb);
    w.show();
    return a.exec();
}

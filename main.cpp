#include "mainwindow.h"
#include "TDatabase.h"
#include "TCalls.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    TDatabase callsdb("calls.db");
    QWidget g;
    std::vector<std::string> missings;
    TCalls c_calls(callsdb, missings);
    w.MainWindow();
    w.show();
    return a.exec();
}

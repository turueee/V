#include "mainwindow.h"
#include "tdatabase.h"
#include "tcalls.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TDatabase db("calls.db");
    TCalls c_calls(db);

    QVector<QString> labs = db.selectLabsNameForGroup("3824Б1ФИ1");
    for (const QString &lab : qAsConst(labs))
        qDebug() << lab;
    //MainWindow w(c_calls, db);
    //w.show();
    return a.exec();
}

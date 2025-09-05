#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QHeaderView>
#include <cstdlib>
#include <ctime>
#include <QString>
#include <QKeyEvent>
#include <QPushButton>
#include <QHeaderView>
#include <QRandomGenerator>
#include <QDebug>
#include <QTableWidget>
#include <QFont>
#include "TCalls.h"
#include "TDatabase.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(TCalls &c_calls, TDatabase &db,QWidget *parent = nullptr);
    ~MainWindow();
    // void read_from_file(const TCalls &c_calls_, TDatabase database_);
    // void save_to_file(const TCalls &c_calls_, TDatabase database_);
    void call_students();
    bool eventFilter(QObject* obj, QEvent* event);
    void setupMissingTable();
    void setupChangedPointsTable();
    void updateChangedPointsTable();
private slots:
    void onPushButtonCallStudentsClicked();
    void onPushButtonMinusPointClicked();
    void onPushButtonPlusPointClicked();
    void onPushButtonSaveDataClicked();
    void onPushButtonBackClicked();
    void onPushButtonNextClicked();
    void onMissingTableButtonClicked();
    void onChangedPointsTableButtonClicked();
signals:
    void qonKeyBoardEnterClicked();
private:
    Ui::MainWindow *ui;
    QString flag;
    TCalls calls;
    TDatabase database;
};
#endif // MAINWINDOW_H

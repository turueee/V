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
    // void fuel_names(std::vector<std::string>& names, const std::vector<std::string>& missing);
    // void k_doske(std::vector<std::string> &names, const size_t stud, std::map<std::string, size_t>& calls, std::vector<std::string> missing);
    // void read_from_file(const TCalls &c_calls_, TDatabase database_);
    // void save_to_file(const TCalls &c_calls_, TDatabase database_);
    void call_students(TCalls &c_calls, TDatabase &db);
    bool eventEnterFilter(QObject* obj, QEvent* event ,TCalls &c_calls, TDatabase & db);
    // int min(std::map<std::string, size_t> calls);
    // void delete_missing(std::vector<std::string>& _names, const std::vector<std::string>& missing);
    void setupMissingTable(TCalls &c_calls);
    void setupChangedPointsTable(TCalls &c_calls);
    void updateChangedPointsTable(TCalls &c_calls);
private slots:
    void onPushButtonCallStudentsClicked();
    // void onPushButtonMinusPointClicked(TCalls &c_calls);
    // void onPushButtonPlusPointClicked(TCalls &c_calls);
    void onPushButtonSaveDataClicked();
    void onPushButtonBackClicked();
    void onPushButtonNextClicked();
    // void onMissingTableButtonClicked(TCalls &c_calls);
    // void onChangedPointsTableButtonClicked(TCalls &c_calls);
signals:
    void qonKeyBoardEnterClicked();
private:
    Ui::MainWindow *ui;
    QString flag;
    int qsize;
};
#endif // MAINWINDOW_H

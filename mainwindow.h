#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QHeaderView>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <QString>
#include <QKeyEvent>
#include <QPushButton>
#include <QHeaderView>
#include <QRandomGenerator>
#include <QDebug>
#include <QTableWidget>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void fuel_names(std::vector<std::string>& names, const std::vector<std::string>& missing);
    void k_doske(std::vector<std::string> &names, const size_t stud, std::map<std::string, size_t>& calls, std::vector<std::string> missing);
    void read_from_file(std::map<std::string, size_t>& calls);
    void save_to_file(std::map<std::string, size_t>& calls,std::vector<std::string> names);
    void call_students(std::map<std::string, size_t>& calls, std::vector<std::string> names, const std::vector<std::string>& missing);
    bool eventFilter(QObject* obj, QEvent* event);
    int min(std::map<std::string, size_t> calls);
    void delete_missing(std::vector<std::string>& _names, const std::vector<std::string>& missing);
    void setupMissingTable(std::map<std::string, size_t> &calls);
    void setupChangedPointsTable(std::map<std::string, size_t> &calls);
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
    std::fstream file;
    std::vector<std::string> names, in_names, missing;
    std::map<std::string, size_t> calls;
    QString flag;
    int qsize;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets/QMainWindow>
#include <QHeaderView>
#include <QString>
#include <QKeyEvent>
#include <QPushButton>
#include <QButtonGroup>
#include <QHeaderView>
#include <QRandomGenerator>
#include <QDebug>
#include <QTableWidget>
#include <QFont>
#include "tcalls.h"
#include "tdatabase.h"

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
    void setupNamesTable();
    void setupLabTable();
private slots:
    void onPushButtonColorTopic();
    void onPushButtonCallStudentsClicked();
    void onPushButtonChangedPointClicked();
    void onPushButtonLabClicked();
    void onPushButtonLabNamesClicked();
    void onPushButtonCancelActiveClicked();
    void onPushButtonSaveDataClicked();
    void onPushButtonBackClicked();
    void onPushButtonNextClicked();
    void onPushButtonMissingTableClicked();
    void onPushButtonChangedPointsTableClicked();
    void onPushButtonNamesClicked();
    void onPushButtonCreateLabClicked();
    void onPushButtonChangedLabClicked();
    void onPushButtonDeleteLabClicked();
signals:
    void qonKeyBoardEnterClicked();
private:
    Ui::MainWindow *ui;
    QString flag;
    QButtonGroup studentButtonGroup;
    QButtonGroup labButtonGroup;
    TCalls calls;
    TDatabase database;
};
#endif // MAINWINDOW_H

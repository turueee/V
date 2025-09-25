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
#include <QTableWidgetItem>
#include <QFont>
#include <QRegularExpression>
#include "dialog.h"
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
    void loadStyleSheet(QApplication& app, const QString& path);
    void call_students();
    bool eventFilter(QObject* obj, QEvent* event);
    void setupMissingTable();
    void setupChangedPointsTable();
    void updateChangedPointsTable();
    void updateLabColumn(const QString& labName);
    void setupChangedLabTable();
     bool isDigitsOnly(const QString& str);
     bool isLettersOnly(const QString& str);
    void setupNamesTable();
    void setupLabTable();
    void setupShowLabTable();
private slots:
    void onPushButtonCreateLabClicked();
    void onPushButtonCallStudentsClicked();
    void onPushButtonChangedPointClicked();
    void onPushButtonLabClicked();
    void onCriterialChanged(QTableWidgetItem *item);
    void onPushButtonLabNamesClicked();
    void onPushButtonCancelActiveClicked();
    void onPushButtonSaveDataClicked();
    void onPushButtonBackClicked();
    void onPushButtonNextClicked();
    void onPushButtonMissingTableClicked();
    void onPushButtonChangedPointsTableClicked();
    void onPushButtonNamesClicked();
    void onPushButtonChangedLabClicked();
    void onPushButtonDeleteLabClicked();
    void onPushButtonDeleteCriterialClicked();
    void onScrollButtonClicked(QAbstractButton *button);
    void onPushButtonAddCriterialClicked();
    void onPushButtonShowTableClicked();
    void adjustTableColumns();
    void onMarkChanged(QTableWidgetItem *item);
    void onCheckBoxEditTableToggled(bool checked);

signals:
    void qonKeyBoardEnterClicked();
private:
    Ui::MainWindow *ui;
    Dialog *dia;
    QString tmp;
    QButtonGroup studentButtonGroup;
    QButtonGroup labButtonGroup;
    TCalls calls;
    TDatabase database;
};
#endif // MAINWINDOW_H

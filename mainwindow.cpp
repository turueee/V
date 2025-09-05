#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(TCalls &c_calls, TDatabase &db,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , calls(c_calls)
    , database(db)
{ 
    ui->setupUi(this);
    flag = "";
    setupMissingTable();
    ui->stackedWidget->setCurrentWidget(ui->StartPage);
    ui->pushButtonBackClicked->setVisible(false);
    ui->pushButtonNextClicked->setVisible(true);
    ui->textEditInput->installEventFilter(this);
    ui->lineEditMessage->setText("Remove missing students");
    ui->lineEditMessage->setReadOnly(true);
    ui->textEditOutput->setReadOnly(true);
    connect(ui->pushButtonCallStudents, &QPushButton::clicked, this, &MainWindow::onPushButtonCallStudentsClicked);
    connect(ui->pushButtonMinusPoint, &QPushButton::clicked, this, &MainWindow::onPushButtonMinusPointClicked);
    connect(ui->pushButtonPlusPoint, &QPushButton::clicked, this, &MainWindow::onPushButtonPlusPointClicked);
    connect(ui->pushButtonSaveData, &QPushButton::clicked, this, &MainWindow::onPushButtonSaveDataClicked);
    connect(ui->pushButtonBackClicked,&QPushButton::clicked, this, &MainWindow::onPushButtonBackClicked);
    connect(ui->pushButtonNextClicked,&QPushButton::clicked, this, &MainWindow::onPushButtonNextClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::call_students()
{
    // переделать
    std::vector<std::string> names = calls.getNamesWithoutMissings();
    size_t max = names.size(), stud = 0;
    ui->textEditOutput->clear();
    stud = ui->textEditInput->toPlainText().toInt();
    if (stud > max || stud < 0)
    {
        ui->statusbar->showMessage("Error count");
        return;
    }
    std::vector<std::string> names_2;
    names_2 = calls.getNamesKDoske(stud);
    for (size_t i = 0; i < stud ; i++)
    {
        ui->textEditOutput->append(QString::fromStdString(names_2[i]));
    }
    database.updateNumbersByName(calls.getCalls());
}

bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{
    if (obj == ui->textEditInput && event->type() == QEvent::KeyPress)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Return &&
            !keyEvent->modifiers().testFlag(Qt::ShiftModifier))
        {
            call_students();
            return true;
        }
    }
    return QMainWindow::eventFilter(obj, event);
}


void MainWindow::onPushButtonCallStudentsClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->CallPage);
    ui->lineEditMessage->setText("Enter the count of students");
    ui->textEditInput->setFocus();
    ui->pushButtonBackClicked->setVisible(true);
}

void MainWindow::onPushButtonMinusPointClicked()
{
    ui->lineEditMessage->setText("Enter name");
    flag = "-";
    setupChangedPointsTable();
    ui->pushButtonBackClicked->setVisible(true);
    ui->stackedWidget->setCurrentWidget(ui->ChangedPointPage);
}

void MainWindow::onPushButtonPlusPointClicked()
{
    ui->lineEditMessage->setText("Enter name");
    flag = "+";
    setupChangedPointsTable();
    ui->pushButtonBackClicked->setVisible(true);
    ui->stackedWidget->setCurrentWidget(ui->ChangedPointPage);
}

void MainWindow::onPushButtonSaveDataClicked()
{
    ui->statusbar->showMessage("Saved");
    database.updateNumbersByName(calls.getCalls());
}

void MainWindow::onPushButtonBackClicked()
{
    ui->lineEditMessage->setText("Сhoice the action");
    ui->stackedWidget->setCurrentWidget(ui->ChoicePage);
    ui->pushButtonBackClicked->setVisible(false);
    flag = "";
    ui->statusbar->clearMessage();
}

void MainWindow::onPushButtonNextClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ChoicePage);
    ui->pushButtonNextClicked->setVisible(false);
    ui->lineEditMessage->setText("Сhoice the action");
    database.updateNumbersByName(calls.getCalls());
}

void MainWindow::setupMissingTable()
{
    int i = 0;
    ui->tableWidget->setRowCount(calls.getCallsSize());
    ui->tableWidget->setColumnWidth(0, 300);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    std::vector<std::string> names = calls.getNames();
    for (std::string name : names)
    {
        QTableWidgetItem *nameItem = new QTableWidgetItem(QString::fromStdString(name));
        QFont font = nameItem->font();
        font.setPointSize(12);
        nameItem->setFont(font);
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget->setItem(i, 0, nameItem);
        QPushButton *button = new QPushButton("absent");
        button->setProperty("studentName", QString::fromStdString(name));
        connect(button, &QPushButton::clicked, this, &MainWindow::onMissingTableButtonClicked);
        ui->tableWidget->setCellWidget(i, 1, button);
        i++;
    }
}

void MainWindow::setupChangedPointsTable()
{
    std::vector<std::string> names = calls.getNamesWithoutMissings();
    ui->tableWidget_2->setRowCount(names.size());
    ui->tableWidget_2->setColumnWidth(0, 300);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->tableWidget_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (size_t i = 0; i < names.size(); ++i)
    {
        QTableWidgetItem *nameItem = new QTableWidgetItem(QString::fromStdString(names[i]));
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
        QFont font = nameItem->font();
        font.setPointSize(12);
        nameItem->setFont(font);
        ui->tableWidget_2->setItem(i, 0, nameItem);
        QTableWidgetItem *callItem = new QTableWidgetItem(QString::number(calls.getPoints(names[i])));
        callItem->setFont(font);
        callItem->setFlags(callItem->flags() & ~Qt::ItemIsEditable);
        QPushButton *button = new QPushButton(flag);
        button->setProperty("studentName", QString::fromStdString(names[i]));
        ui->tableWidget_2->setItem(i, 1, callItem);
        connect(button, &QPushButton::clicked, this,&MainWindow::onChangedPointsTableButtonClicked);
        ui->tableWidget_2->setCellWidget(i, 2, button);
    }
}

void MainWindow::updateChangedPointsTable()
{
    std::vector<std::string> names = calls.getNamesWithoutMissings();
    for (size_t i = 0; i < names.size(); ++i) {
        QTableWidgetItem *callItem = ui->tableWidget_2->item(i, 1);
        if (callItem) {
            callItem->setText(QString::number(calls.getPoints(names[i])));
        }
    }
    database.updateNumbersByName(calls.getCalls());
}

void MainWindow::onMissingTableButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    QString studentName = button->property("studentName").toString();
    calls.setMissings(studentName.toStdString());
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        if (ui->tableWidget->cellWidget(row, 1) == button) {
            QTableWidgetItem* nameItem = ui->tableWidget->item(row, 0);
            if (nameItem) {
                QFont font = nameItem->font();
                font.setStrikeOut(true);
                nameItem->setFont(font);
            }
            break;
        }
    }
    button->setEnabled(false);
}

void MainWindow::onChangedPointsTableButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString studentName = button->property("studentName").toString();
    if(flag == "+")
        calls.setCallsByName(studentName.toStdString(),1);
    else if((flag == "-") && (calls.getPoints(studentName.toStdString()) > 0))
        calls.setCallsByName(studentName.toStdString(),-1);
    else
        ui->statusbar->showMessage("Error");
    updateChangedPointsTable();
}



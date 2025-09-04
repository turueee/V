#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(TCalls &c_calls, TDatabase &db,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{ 
    ui->setupUi(this);
    flag = "";
    setupMissingTable(c_calls);
    ui->stackedWidget->setCurrentWidget(ui->StartPage);
    ui->pushButtonBackClicked->setVisible(false);
    ui->pushButtonNextClicked->setVisible(true);
    ui->textEditInput->installEventFilter(this);
    ui->lineEditMessage->setText("Remove missing students");
    ui->lineEditMessage->setReadOnly(true);
    ui->textEditOutput->setReadOnly(true);
    connect(ui->pushButtonCallStudents, &QPushButton::clicked, this, &MainWindow::onPushButtonCallStudentsClicked);
    connect(ui->pushButtonMinusPoint, &QPushButton::clicked, this, [this,&c_calls]()
        {
        ui->lineEditMessage->setText("Enter name");
        flag = "-";
        setupChangedPointsTable(c_calls);
        ui->pushButtonBackClicked->setVisible(true);
        ui->stackedWidget->setCurrentWidget(ui->ChangedPointPage);
        });
    connect(ui->pushButtonPlusPoint, &QPushButton::clicked, this,[this,&c_calls]()
        {
        ui->lineEditMessage->setText("Enter name");
        flag = "-";
        setupChangedPointsTable(c_calls);
        ui->pushButtonBackClicked->setVisible(true);
        ui->stackedWidget->setCurrentWidget(ui->ChangedPointPage);
        });
    connect(ui->pushButtonSaveData, &QPushButton::clicked, this, &MainWindow::onPushButtonSaveDataClicked);
    connect(ui->pushButtonBackClicked,&QPushButton::clicked, this, &MainWindow::onPushButtonBackClicked);
    connect(ui->pushButtonNextClicked,&QPushButton::clicked, this, &MainWindow::onPushButtonNextClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::call_students(TCalls &c_calls, TDatabase &db)
{
    size_t max = qsize, stud = 0;
    ui->textEditOutput->clear();
    stud = ui->textEditInput->toPlainText().toInt();
    if (stud > max || stud < 0)
    {
        ui->statusbar->showMessage("Error count");
        return;
    }
    std::vector<std::string> names_2;
    names_2 = c_calls.getNamesKDoske(stud);
    for (size_t i = 0; i < stud ; i++)
    {
        ui->textEditOutput->append(QString::fromStdString(names_2[i]));
    }
    db.updateNumbersByName(c_calls.getCalls());
}

bool MainWindow::eventEnterFilter(QObject* obj, QEvent* event,TCalls &c_calls, TDatabase &db)
{
    if (obj == ui->textEditInput && event->type() == QEvent::KeyPress)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Return &&
            !keyEvent->modifiers().testFlag(Qt::ShiftModifier))
        {
            call_students(c_calls, db);
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

// void MainWindow::onPushButtonMinusPointClicked(TCalls &c_calls)
// {
//     ui->lineEditMessage->setText("Enter name");
//     flag = "-";
//     setupChangedPointsTable(c_calls);
//     ui->pushButtonBackClicked->setVisible(true);
//     ui->stackedWidget->setCurrentWidget(ui->ChangedPointPage);
// }

// void MainWindow::onPushButtonPlusPointClicked(TCalls &c_calls)
// {
//     ui->lineEditMessage->setText("Enter name");
//     flag = "+";
//     setupChangedPointsTable(c_calls);
//     ui->pushButtonBackClicked->setVisible(true);
//     ui->stackedWidget->setCurrentWidget(ui->ChangedPointPage);
// }

void MainWindow::onPushButtonSaveDataClicked()
{
    // save_to_file(calls,names);
    ui->statusbar->showMessage("Saved");
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
    // qsize = calls.size()- missing.size();
    ui->lineEditMessage->setText("Сhoice the action");
}

void MainWindow::setupMissingTable(TCalls &c_calls)
{
    int i = 0;
    ui->tableWidget->setRowCount(c_calls.getCallsSize());
    ui->tableWidget->setColumnWidth(0, 300);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (std::pair<std::string, int> call : c_calls.getCalls())
    {
        QTableWidgetItem *nameItem = new QTableWidgetItem(QString::fromStdString(call.first));
        QFont font = nameItem->font();
        font.setPointSize(12);
        nameItem->setFont(font);
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget->setItem(i, 0, nameItem);
        QPushButton *button = new QPushButton("absent");
        button->setProperty("studentName", QString::fromStdString(call.first));
        connect(button, &QPushButton::clicked, this, [this, &c_calls]
                {
            QPushButton *button = qobject_cast<QPushButton*>(sender());
            if (!button) return;
            QString studentName = button->property("studentName").toString();
            std::vector<std::string> missing;
            missing.push_back(studentName.toStdString());
            c_calls.setMissings(missing);
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
        });
        ui->tableWidget->setCellWidget(i, 1, button);
        i++;
    }
}

void MainWindow::setupChangedPointsTable(TCalls &c_calls)
{
    std::vector<std::string> names = c_calls.getNames();
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
        QTableWidgetItem *callItem = new QTableWidgetItem(QString::number(c_calls.getPoints(names[i])));
        callItem->setFont(font);
        callItem->setFlags(callItem->flags() & ~Qt::ItemIsEditable);
        QPushButton *button = new QPushButton(flag);
        button->setProperty("studentName", QString::fromStdString(names[i]));
        ui->tableWidget_2->setItem(i, 1, callItem);
        connect(button, &QPushButton::clicked, this, [this, &c_calls]
                {
            QPushButton *button = qobject_cast<QPushButton*>(sender());
            if (!button) return;

            QString studentName = button->property("studentName").toString();
            if(flag == "+")
                c_calls.setCallsByName(studentName.toStdString(),1);
            else if((flag == "-") && (c_calls.getPoints(studentName.toStdString()) > 0))
                c_calls.setCallsByName(studentName.toStdString(),-1);
            else
                ui->statusbar->showMessage("Error");
            updateChangedPointsTable(c_calls);
        });
        ui->tableWidget_2->setCellWidget(i, 2, button);
    }
}

void MainWindow::updateChangedPointsTable(TCalls &c_calls)
{
    std::vector<std::string> names = c_calls.getNames();
    for (size_t i = 0; i < names.size(); ++i) {
        QTableWidgetItem *callItem = ui->tableWidget_2->item(i, 1);
        if (callItem) {
            callItem->setText(QString::number(c_calls.getPoints(names[i])));
        }
    }
    // save_to_file(calls, names);
}

// void MainWindow::onMissingTableButtonClicked(TCalls &c_calls)
// {
//     QPushButton *button = qobject_cast<QPushButton*>(sender());
//     if (!button) return;
//     QString studentName = button->property("studentName").toString();
//     std::vector<std::string> missing;
//     missing.push_back(studentName.toStdString());
//     c_calls.setMissings(missing);
//     for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
//         if (ui->tableWidget->cellWidget(row, 1) == button) {
//             QTableWidgetItem* nameItem = ui->tableWidget->item(row, 0);
//             if (nameItem) {
//                 QFont font = nameItem->font();
//                 font.setStrikeOut(true);
//                 nameItem->setFont(font);
//             }
//             break;
//         }
//     }
//     button->setEnabled(false);
// }

// void MainWindow::onChangedPointsTableButtonClicked(TCalls &c_calls)
// {
//     QPushButton *button = qobject_cast<QPushButton*>(sender());
//     if (!button) return;

//     QString studentName = button->property("studentName").toString();
//     if(flag == "+")
//         c_calls.setCallsByName(studentName.toStdString(),1);
//     else if((flag == "-") && (c_calls.getPoints(studentName.toStdString()) > 0))
//         c_calls.setCallsByName(studentName.toStdString(),-1);
//     else
//         ui->statusbar->showMessage("Error");
//     updateChangedPointsTable(c_calls);
// }



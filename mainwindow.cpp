#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, TCalls *c_calls, TDatabase *database)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{ 
    ui->setupUi(this);
    c_calls->setCalls(database->readTableToMap());
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

// void MainWindow::fuel_names(std::vector<std::string> &names, const std::vector<std::string>& missing)
// {
//     read_from_file(calls);
//     for (std::pair<std::string, size_t> call:calls)
//     {
//         names.push_back(call.first);
//     }
//     delete_missing(names, missing);
// }

// void MainWindow::delete_missing(std::vector<std::string>& _names, const std::vector<std::string>& missing)
// {
//     for (std::string absent : missing)
//     {
//         auto it = std::find(_names.begin(), _names.end(), absent);
//         if (it != _names.end()) {
//             _names.erase(it);
//         }
//     }
// }

// void MainWindow::k_doske(std::vector<std::string> &names, const size_t stud, std::map<std::string, size_t>& calls, std::vector<std::string> missing)
// {
//     read_from_file(calls);
//     std::srand(std::time(nullptr));
//     std::vector<std::string> min_calls, max_calls;
//     size_t minim = min(calls),i = 0;
//     for (std::pair<std::string, size_t> call : calls)
//     {
//         if (call.second == minim)
//             min_calls.push_back(call.first);
//         else
//             max_calls.push_back(call.first);
//     }

//     delete_missing(min_calls, missing);
//     delete_missing(max_calls, missing);

//     while (!min_calls.empty() && i < stud)
//     {
//         int random = std::rand() % min_calls.size();
//         ui->textEditOutput->append(QString::fromStdString(min_calls[random]));
//         calls[min_calls[random]] += 1;
//         min_calls.erase(min_calls.begin() + random);
//         i++;
//     }
//     while (!max_calls.empty() && i < stud)
//     {
//         int random = std::rand() % max_calls.size();
//         ui->textEditOutput->append(QString::fromStdString(max_calls[random]));
//         calls[max_calls[random]] += 1;
//         max_calls.erase(max_calls.begin() + random);
//         i++;
//     }
//     save_to_file(calls, names);
// }

// void MainWindow::read_from_file(TCalls &c_calls_, TDatabase database_)
// {
//     c_calls_.setCalls(database_.readTableToMap());
// }

// void MainWindow::save_to_file(TCalls &calls)
// {
//     TDatabase callsdb("calls.db");
//     callsdb.updateNumbersByName(calls);
// }
void MainWindow::call_students(TCalls *c_calls)
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
    names_2 = c_calls->getNamesKDoske(stud);
    for (size_t i = 0; i < stud ; i++)
    {
        ui->textEditOutput->append(QString::fromStdString(names_2[i]));
    }
    // мб тут нудно getNames
}

bool MainWindow::eventEnterFilter(QObject* obj, QEvent* event,TCalls *c_calls)
{
    if (obj == ui->textEditInput && event->type() == QEvent::KeyPress)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Return &&
            !keyEvent->modifiers().testFlag(Qt::ShiftModifier))
        {
            call_students(c_calls);
            return true;
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

// int MainWindow::min(std::map<std::string, size_t> calls)
// {
//     size_t min = 1000;
//     for (std::pair<std::string, size_t> call : calls)
//         min = (min > call.second) ? call.second : min;
//     return min;
// }

void MainWindow::onPushButtonCallStudentsClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->CallPage);
    ui->lineEditMessage->setText("Enter the count of students");
    ui->textEditInput->setFocus();
    ui->pushButtonBackClicked->setVisible(true);
}

void MainWindow::onPushButtonMinusPointClicked(TCalls *c_calls)
{
    ui->lineEditMessage->setText("Enter name");
    flag = "-";
    setupChangedPointsTable(c_calls);
    ui->pushButtonBackClicked->setVisible(true);
    ui->stackedWidget->setCurrentWidget(ui->ChangedPointPage);
}

void MainWindow::onPushButtonPlusPointClicked(TCalls *c_calls)
{
    ui->lineEditMessage->setText("Enter name");
    flag = "+";
    setupChangedPointsTable(c_calls);
    ui->pushButtonBackClicked->setVisible(true);
    ui->stackedWidget->setCurrentWidget(ui->ChangedPointPage);
}

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

void MainWindow::setupMissingTable(TCalls *c_calls)
{
    int i = 0;
    ui->tableWidget->setRowCount(c_calls->getCallsSize());
    ui->tableWidget->setColumnWidth(0, 300);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (std::pair<std::string, int> call : c_calls->getCalls())
    {
        QTableWidgetItem *nameItem = new QTableWidgetItem(QString::fromStdString(call.first));
        QFont font = nameItem->font();
        font.setPointSize(12);
        nameItem->setFont(font);
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget->setItem(i, 0, nameItem);
        QPushButton *button = new QPushButton("absent");
        button->setProperty("studentName", QString::fromStdString(call.first));
        connect(button, &QPushButton::clicked, this, &MainWindow::onMissingTableButtonClicked);
        ui->tableWidget->setCellWidget(i, 1, button);
        i++;
    }
}

void MainWindow::setupChangedPointsTable(TCalls *c_calls)
{
    ui->tableWidget_2->setRowCount(qsize);
    ui->tableWidget_2->setColumnWidth(0, 300);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->tableWidget_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    std::vector<std::string> names = c_calls->getNames();
    for (size_t i = 0; i < names.size(); ++i)
    {
        QTableWidgetItem *nameItem = new QTableWidgetItem(QString::fromStdString(names[i]));
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
        QFont font = nameItem->font();
        font.setPointSize(12);
        nameItem->setFont(font);
        ui->tableWidget_2->setItem(i, 0, nameItem);
        QTableWidgetItem *callItem = new QTableWidgetItem(QString::number(calls[names[i]]));
        callItem->setFont(font);
        callItem->setFlags(callItem->flags() & ~Qt::ItemIsEditable);
        QPushButton *button = new QPushButton(flag);
        button->setProperty("studentName", QString::fromStdString(names[i]));
        ui->tableWidget_2->setItem(i, 1, callItem);
        connect(button, SIGNAL(clicked()), this, SLOT(onChangedPointsTableButtonClicked()));
        ui->tableWidget_2->setCellWidget(i, 2, button);
    }
}

void MainWindow::updateChangedPointsTable()
{
    for (int i = 0; i < qsize; ++i) {
        QTableWidgetItem *callItem = ui->tableWidget_2->item(i, 1);
        if (callItem) {
            callItem->setText(QString::number(calls[names[i]]));
        }
    }
    save_to_file(calls, names);
}

void MainWindow::onMissingTableButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    QString studentName = button->property("studentName").toString();
    missing.push_back(studentName.toStdString());
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
        calls[studentName.toStdString()]++;
    else if((flag == "-") && (calls[studentName.toStdString()] > 0))
        calls[studentName.toStdString()]--;
    else
        ui->statusbar->showMessage("Error");
    updateChangedPointsTable();
}



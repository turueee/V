#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(TCalls &c_calls, TDatabase &db,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , calls(c_calls)
    , database(db)
{
    ui->setupUi(this);
    dia = new Dialog(this);
    setupMissingTable();
    ui->stackedWidget->setCurrentWidget(ui->StartPage);
    ui->pushButtonBackClicked->setVisible(false);
    ui->textEditInput->installEventFilter(this);
    ui->lineEditMessage->setText("Отметьте отсутствующий студентов");
    ui->lineEditMessage->setReadOnly(true);
    ui->textEditOutput->setReadOnly(true);
//    onPushButtonColorTopic();
    connect(ui->pushButtonCallStudents, &QPushButton::clicked, this, &MainWindow::onPushButtonCallStudentsClicked);
    connect(ui->pushButtonLab, &QPushButton::clicked, this, &MainWindow::onPushButtonLabClicked);
    connect(ui->pushButtonChangedPoint, &QPushButton::clicked, this, &MainWindow::onPushButtonChangedPointClicked);
    connect(ui->pushButtonSaveData, &QPushButton::clicked, this, &MainWindow::onPushButtonSaveDataClicked);
    connect(ui->pushButtonBackClicked,&QPushButton::clicked, this, &MainWindow::onPushButtonBackClicked);
    connect(ui->pushButtonNextClicked,&QPushButton::clicked, this, &MainWindow::onPushButtonNextClicked);
    connect(ui->pushButtonCansel,&QPushButton::clicked, this, &MainWindow::onPushButtonCancelActiveClicked);
    connect(ui->pushButtonCreateLab, &QPushButton::clicked, this,&MainWindow::onPushButtonCreateLabClicked);
    connect(ui->pushButtonDeleteLab,&QPushButton::clicked, this, &MainWindow::onPushButtonDeleteLabClicked);
    connect(ui->pushButtonChangedLab, &QPushButton::clicked, this, &MainWindow::onPushButtonChangedLabClicked);
    connect(ui->pushButtonAddCriterial, &QPushButton::clicked, this, &MainWindow::onPushButtonAddCriterialClicked);
    connect(ui->tableWidgetChangedLab, &QTableWidget::itemChanged, this, &MainWindow::onCriterialChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dia;
}

void MainWindow::call_students()
{
    QVector<QString> names = calls.getNamesWithoutMissings();
    size_t max = names.size(), stud = 0;
    ui->textEditOutput->clear();
    stud = ui->textEditInput->toPlainText().toInt();
    if (stud > max || stud < 0)
    {
        ui->statusbar->showMessage("Error count");
        return;
    }
    QVector<QString> names_2;
    names_2 = calls.getNamesKDoske(stud);
    for (size_t i = 0; i < stud ; i++)
    {
        ui->textEditOutput->append(names_2[i]);
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
    ui->lineEditMessage->setText("Введите количество вызываемых студентов");
    ui->textEditInput->setFocus();
    ui->pushButtonBackClicked->setVisible(true);
}

// void MainWindow::loadStyleSheet(QApplication& app, const QString& path)
// {
//     QFile styleFile(path);
//     if (styleFile.open(QFile::ReadOnly)) {
//         QString style = QLatin1String(styleFile.readAll());
//         app.setStyleSheet(style);
//         styleFile.close();
//     }
// }

void MainWindow::onPushButtonLabClicked()
{
    ui->lineEditMessage->setText("");
    qDeleteAll(labButtonGroup.buttons());
    ui->pushButtonBackClicked->setVisible(true);
    setupLabTable();
    setupNamesTable();
    ui->scrollAreaNames->setVisible(false);
    ui->scrollAreaLabNames->setVisible(true);
    ui->pushButtonShowTable->setVisible(false);
    ui->pushButtonChangedPoints->setVisible(false);
    ui->pushButtonChangedLab->setVisible(false);
    ui->pushButtonDeleteLab->setVisible(false);
    ui->stackedWidget->setCurrentWidget(ui->LabPage);
}


void MainWindow::onPushButtonLabNamesClicked()
{
    for (QAbstractButton* button : labButtonGroup.buttons())
    {
        button->setEnabled(false);
    }
    ui->pushButtonShowTable->setVisible(true);
    ui->pushButtonChangedPoints->setVisible(true);
    ui->pushButtonChangedLab->setVisible(true);
    ui->pushButtonDeleteLab->setVisible(true);
}

void MainWindow::onPushButtonCancelActiveClicked()
{
    ui->pushButtonChangedLab->setVisible(false);
    ui->pushButtonChangedPoints->setVisible(false);
    ui->pushButtonShowTable->setVisible(false);
    ui->pushButtonDeleteLab->setVisible(false);
    ui->scrollAreaLabNames->clearFocus();
    for (QAbstractButton* button : studentButtonGroup.buttons())
    {
        button->setEnabled(true);
    }
    for (QAbstractButton* button : labButtonGroup.buttons())
    {
        button->setEnabled(true);
    }
}

void MainWindow::onPushButtonChangedPointClicked()
{
    ui->lineEditMessage->setText("Введите имя");
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
    ui->lineEditMessage->setText("Выберете действие");
    if(ui->stackedWidget->currentWidget() == ui->ChangeLabPage)
        ui->stackedWidget->setCurrentWidget(ui->LabPage);
    else
    {
        ui->stackedWidget->setCurrentWidget(ui->ChoicePage);
        ui->pushButtonBackClicked->setVisible(false);
        ui->lineEditMessage->setText("Выберете действие");
    }
    ui->statusbar->clearMessage();
}

void MainWindow::onPushButtonNextClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ChoicePage);
    ui->pushButtonNextClicked->setVisible(false);
    ui->lineEditMessage->setText("Выберете действие");
    database.updateNumbersByName(calls.getCalls());
}

void MainWindow::onPushButtonNamesClicked()
{
    for (QAbstractButton* button : studentButtonGroup.buttons())
    {
        button->setEnabled(false);
    }
}

void MainWindow::onPushButtonCreateLabClicked()
{
    if(dia->exec() == QDialog::Accepted)
    {
        database.insertLabName(dia->getLabName(), dia->getGroupName());
        updateLabColumn(dia->getLabName());
        // нужно переделать чтобы работало через database а не как параметр в функции
    }
    else
        qDebug() << "Eror Dialog Window";
}

void MainWindow::onCriterialChanged(QTableWidgetItem *item)
{
    qDebug()<< "2";
    QString labName = ui->pushButtonDeleteLab->property("удалить").toString()
            , criterialName = item->data(Qt::UserRole).toString();
    // if(!criterialName.isEmpty()
    //     && criterialName != item->text()
    //     && isDigitsOnly(item->text()))
        // database.updateCriteriaMaxPoint(labName, criterialName, item->text());
    if(!criterialName.isEmpty() && criterialName != item->text())
        database.updateCriteriaName(labName, criterialName, item->text());
}

// bool MainWindow::isDigitsOnly(const QString& str) {
//     QRegularExpression regex("^\\d+$");
//     return regex.match(str).hasMatch();
// }

// bool MainWindow::isLettersOnly(const QString& str) {
//     QRegularExpression regex("^\\p{L}+$");
//     return regex.match(str).hasMatch();
// }

void MainWindow::onPushButtonChangedLabClicked()
{
    setupChangedLabTable();
    ui->stackedWidget->setCurrentWidget(ui->ChangeLabPage);
}
void MainWindow::onPushButtonAddCriterialClicked()
{
    ui->tableWidgetChangedLab->blockSignals(true);
    int rowCount = ui->tableWidgetChangedLab->rowCount();
    ui->tableWidgetChangedLab->insertRow(rowCount);
    QTableWidgetItem* nameLabItem = new QTableWidgetItem("");
    ui->tableWidgetChangedLab->setItem(rowCount, 0, nameLabItem);
    QTableWidgetItem* maxpointItem = new QTableWidgetItem("");
    ui->tableWidgetChangedLab->setItem(rowCount, 1, maxpointItem);
    QPushButton * buttonDelete = new QPushButton("удалить");
    buttonDelete->setProperty("rowIndex", QVariantList{nameLabItem->text(), maxpointItem->text(), rowCount});
    connect(buttonDelete, &QPushButton::clicked, this, &MainWindow::onPushButtonDeleteCriterialClicked);
    ui->tableWidgetChangedLab->setCellWidget(rowCount, 2, buttonDelete);
    ui->tableWidgetChangedLab->blockSignals(false);
}

void MainWindow::onPushButtonDeleteLabClicked()
{
    QString labName = ui->pushButtonDeleteLab->property("удалить").toString();
    database.deleteLab(labName, "3824Б1ФИ1");
    qDeleteAll(labButtonGroup.buttons());
    setupLabTable();
}

void MainWindow::onPushButtonDeleteCriterialClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString labName = ui->pushButtonDeleteLab->property("удалить").toString();
    QVariantList tmp = button->property("rowIndex").toList();
    if((tmp[0] != "") && (tmp[1] != ""))
        database.deleteCriteria(labName,tmp[0].toString());
    if (button)
    {
        int rowToDelete = tmp[2].toInt();
        if (rowToDelete >= 0 && rowToDelete < ui->tableWidgetChangedLab->rowCount())
        {
            ui->tableWidgetChangedLab->removeRow(rowToDelete);

            for (int row = rowToDelete; row < ui->tableWidgetChangedLab->rowCount(); ++row)
            {
                QPushButton* btn = qobject_cast<QPushButton*>(
                    ui->tableWidgetChangedLab->cellWidget(row, 2));
                if (btn)
                    btn->setProperty("rowIndex", row);
            }
        }
    }
}

void MainWindow::onScrollButtonClicked(QAbstractButton *button)
{
    ui->pushButtonDeleteLab->setProperty("удалить", button->text());
}

void MainWindow::onPushButtonColorTopic()
{
    // переписать нормально
//    ui->pushButtonBackClicked->setStyleSheet("background-color: #323232;");
//    ui->pushButtonCallStudents->setStyleSheet("background-color: #323232;");
//    ui->pushButtonChangedPoint->setStyleSheet("background-color: #323232;");
//    ui->pushButtonLab->setStyleSheet("background-color: #323232;");
//    ui->pushButtonNextClicked->setStyleSheet("background-color: #323232;");
//    ui->pushButtonSaveData->setStyleSheet("background-color: #323232;");
//    ui->CallPage->setStyleSheet("background-color: #323232;");
//    ui->ChangedPointPage->setStyleSheet("background-color: #323232;");
//    ui->ChoicePage->setStyleSheet("background-color: #323232;");
//    ui->StartPage->setStyleSheet("background-color: #323232;");
//    ui->centralwidget->setStyleSheet("background-color: #323232;");
//    ui->lineEditMessage->setStyleSheet("background-color: #323232;");
//    ui->textEditInput->setStyleSheet("background-color: #323232;");
//    ui->textEditOutput->setStyleSheet("background-color: #323232;");
//    ui->menubar->setStyleSheet("background-color: #323232;");
//    ui->tableWidgetMissing->setStyleSheet("background-color: #323232;");
//    ui->tableWidgetChangedPoint->setStyleSheet("background-color: #323232;");
//    ui->stackedWidget->setStyleSheet("background-color: #323232;");
}

void MainWindow::onPushButtonMissingTableClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    QString studentName = button->property("studentName").toString();
    calls.setMissings(studentName);
    for (int row = 0; row < ui->tableWidgetMissing->rowCount(); ++row) {
        if (ui->tableWidgetMissing->cellWidget(row, 1) == button) {
            QTableWidgetItem* nameItem = ui->tableWidgetMissing->item(row, 0);
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

void MainWindow::onPushButtonChangedPointsTableClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString studentName = button->property("studentName").toString();
    if(button->text() == "+")
        calls.setCallsByName(studentName,1);
    else if((button->text() == "-") && (calls.getPoints(studentName) > 0))
        calls.setCallsByName(studentName,-1);
    else
        ui->statusbar->showMessage("Error");
    updateChangedPointsTable();
}

void MainWindow::setupMissingTable()
{
    size_t i = 0;
    ui->tableWidgetMissing->setRowCount(calls.getCallsSize());
    ui->tableWidgetMissing->setColumnWidth(0, 300);
    ui->tableWidgetMissing->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidgetMissing->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QVector<QString> names = calls.getNames();
    for (const auto& name : names)
    {
        QTableWidgetItem *nameItem = new QTableWidgetItem(name);
        QFont font = nameItem->font();
        font.setPointSize(12);
        nameItem->setFont(font);
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
        ui->tableWidgetMissing->setItem(i, 0, nameItem);
        QPushButton *buttonMissing = new QPushButton("Отсутствует");
        buttonMissing->setProperty("studentName", name);
        connect(buttonMissing, &QPushButton::clicked, this, &MainWindow::onPushButtonMissingTableClicked);
        ui->tableWidgetMissing->setCellWidget(i, 1, buttonMissing);
        i++;
    }
}

void MainWindow::setupChangedPointsTable()
{
    QVector<QString> names = calls.getNamesWithoutMissings();
    ui->tableWidgetChangedPoint->setRowCount(names.size());
    ui->tableWidgetChangedPoint->setColumnWidth(0, 300);
    ui->tableWidgetChangedPoint->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableWidgetChangedPoint->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->tableWidgetChangedPoint->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (size_t i = 0; i < names.size(); ++i)
    {
        QTableWidgetItem *nameItem = new QTableWidgetItem(names[i]);
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
        QFont font = nameItem->font();
        font.setPointSize(12);
        nameItem->setFont(font);
        ui->tableWidgetChangedPoint->setItem(i, 0, nameItem);
        QTableWidgetItem *callItem = new QTableWidgetItem(QString::number(calls.getPoints(names[i])));
        callItem->setFont(font);
        callItem->setFlags(callItem->flags() & ~Qt::ItemIsEditable);
        ui->tableWidgetChangedPoint->setItem(i, 1, callItem);
        QPushButton *buttonPlus = new QPushButton("+");
        buttonPlus->setProperty("studentName", names[i]);
        connect(buttonPlus, &QPushButton::clicked, this,&MainWindow::onPushButtonChangedPointsTableClicked);
        ui->tableWidgetChangedPoint->setCellWidget(i, 2, buttonPlus);
        QPushButton *buttonMinus = new QPushButton("-");
        buttonMinus->setProperty("studentName", names[i]);
        connect(buttonMinus, &QPushButton::clicked, this,&MainWindow::onPushButtonChangedPointsTableClicked);
        ui->tableWidgetChangedPoint->setCellWidget(i, 3, buttonMinus);
    }
}

void MainWindow::setupNamesTable()
{
    QVector<QString> names = calls.getNamesWithoutMissings();
    studentButtonGroup.setExclusive(true);
    for (const QString &name : names)
    {
        QPushButton *buttonNames = new QPushButton(name);
        connect(buttonNames, &QPushButton::clicked, this, &MainWindow::onPushButtonNamesClicked);
        buttonNames->setCheckable(true);
        buttonNames->setStyleSheet(
                    "QPushButton {"
                    "   text-align: left;"
                    "   padding: 8px;"
                    "   border: 1px solid #ccc;"
                    "   background: #f0f0f0;"
                    "}"
                    "QPushButton:hover {"
                    "   background: #e0e0e0;"
                    "}"
                    "QPushButton:checked {"
                    "   border: 2px solid #0078d7;"
                    "   background: #d0e8f0;"
                    "   font-weight: bold;"
                    "}"
                    "QPushButton:checked:disabled {"
                    "   border: 2px solid #0078d7;"
                    "   background: #d0e8f0;"
                    "   font-weight: bold;"
                    "   color: #000;"
                    "}"
                );
        studentButtonGroup.addButton(buttonNames);
        ui->verticalLayoutNames->addWidget(buttonNames);
    }
}

void MainWindow::setupLabTable()
{
    QVector<QString> labNames = database.selectLabsNameForGroup("3824Б1ФИ1");
    studentButtonGroup.setExclusive(true);
    for (const QString &name : labNames)
    {
        QPushButton *buttonLab = new QPushButton(name);
        connect(buttonLab, &QPushButton::clicked, this, &MainWindow::onPushButtonLabNamesClicked);
        buttonLab->setCheckable(true);
        buttonLab->setStyleSheet(
                    "QPushButton {"
                    "   text-align: left;"
                    "   padding: 8px;"
                    "   border: 1px solid #ccc;"
                    "   background: #f0f0f0;"
                    "}"
                    "QPushButton:hover {"
                    "   background: #e0e0e0;"
                    "}"
                    "QPushButton:checked {"
                    "   border: 2px solid #0078d7;"
                    "   background: #d0e8f0;"
                    "   font-weight: bold;"
                    "}"
                    "QPushButton:checked:disabled {"
                    "   border: 2px solid #0078d7;"
                    "   background: #d0e8f0;"
                    "   font-weight: bold;"
                    "   color: #000;"
                    "}"
                );
        labButtonGroup.addButton(buttonLab);
        ui->verticalLayoutLabNames->addWidget(buttonLab);
    }
    connect(&labButtonGroup, QOverload<QAbstractButton*>::of(&QButtonGroup::buttonClicked), this, &MainWindow::onScrollButtonClicked);
}

void MainWindow::setupChangedLabTable()
{
    ui->tableWidgetChangedLab->blockSignals(true);
    ui->tableWidgetChangedLab->setRowCount(0);
    QString labName = ui->pushButtonDeleteLab->property("удалить").toString();
    ui->tableWidgetChangedLab->verticalHeader()->setDefaultSectionSize(40);
    ui->tableWidgetChangedLab->setColumnCount(3);
    ui->tableWidgetChangedLab->setHorizontalHeaderLabels({"название критерия", "макисмальный балл", "удалить"});
    ui->tableWidgetChangedLab->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableWidgetChangedLab->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->tableWidgetChangedLab->setColumnWidth(0, 300);
    ui->tableWidgetChangedLab->horizontalHeader()->setStretchLastSection(false);
    QMap<QString, int> limits = database.selectLabCriteriaLimits(labName);
    int i = 0;
    for(auto it = limits.begin(); it != limits.end(); ++it)
    {
        ui->tableWidgetChangedLab->insertRow(i);
        ui->tableWidgetChangedLab->setRowHeight(i, 50);
        QTableWidgetItem* nameLabItem = new QTableWidgetItem(it.key());
        ui->tableWidgetChangedLab->setItem(i, 0, nameLabItem);
        QTableWidgetItem* maxpointItem = new QTableWidgetItem(QString::number(it.value()));
        ui->tableWidgetChangedLab->setItem(i, 1, maxpointItem);
        QPushButton * buttonDelete = new QPushButton("удалить");
        buttonDelete->setProperty("rowIndex",QVariantList{nameLabItem->text(), maxpointItem->text(), i});
        connect(buttonDelete, &QPushButton::clicked, this, &MainWindow::onPushButtonDeleteCriterialClicked);
        ui->tableWidgetChangedLab->setCellWidget(i, 2, buttonDelete);
        i++;
    }
    ui->tableWidgetChangedLab->blockSignals(false);
}

void MainWindow::updateChangedPointsTable()
{
    QVector<QString> names = calls.getNamesWithoutMissings();
    for (size_t i = 0; i < names.size(); ++i) {
        QTableWidgetItem *callItem = ui->tableWidgetChangedPoint->item(i, 1);
        if (callItem)
        {
            callItem->setText(QString::number(calls.getPoints(names[i])));
        }
    }
    database.updateNumbersByName(calls.getCalls());
}

void MainWindow::updateLabColumn(const QString& labName)
{
    QPushButton *buttonLab = new QPushButton(labName);
    connect(buttonLab, &QPushButton::clicked, this, &MainWindow::onPushButtonLabNamesClicked);
    buttonLab->setCheckable(true);
    buttonLab->setStyleSheet(
                "QPushButton {"
                "   text-align: left;"
                "   padding: 8px;"
                "   border: 1px solid #ccc;"
                "   background: #f0f0f0;"
                "}"
                "QPushButton:hover {"
                "   background: #e0e0e0;"
                "}"
                "QPushButton:checked {"
                "   border: 2px solid #0078d7;"
                "   background: #d0e8f0;"
                "   font-weight: bold;"
                "}"
                "QPushButton:checked:disabled {"
                "   border: 2px solid #0078d7;"
                "   background: #d0e8f0;"
                "   font-weight: bold;"
                "   color: #000;"
                "}"
            );
    labButtonGroup.addButton(buttonLab);
    ui->verticalLayoutLabNames->addWidget(buttonLab);
}


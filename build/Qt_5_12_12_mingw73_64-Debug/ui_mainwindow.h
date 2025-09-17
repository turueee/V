/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonBackClicked;
    QPushButton *pushButtonNextClicked;
    QLineEdit *lineEditMessage;
    QStackedWidget *stackedWidget;
    QWidget *StartPage;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidgetMissing;
    QWidget *ChangedPointPage;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidgetChangedPoint;
    QWidget *ChoicePage;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QPushButton *pushButtonLab;
    QPushButton *pushButtonCallStudents;
    QPushButton *pushButtonChangedPoint;
    QPushButton *pushButtonSaveData;
    QWidget *CallPage;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *textEditOutput;
    QTextEdit *textEditInput;
    QWidget *LabPage;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButtonCreateLab;
    QPushButton *pushButtonCansel;
    QHBoxLayout *horizontalLayout_3;
    QScrollArea *scrollAreaNames;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayoutNames;
    QScrollArea *scrollAreaLabNames;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayoutLabNames;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButtonChangedLab;
    QPushButton *pushButtonDeleteLab;
    QPushButton *pushButtonChangedPoints;
    QPushButton *pushButtonShowTable;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QWidget *ChangeLabPage;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButtonAddCriterial;
    QVBoxLayout *verticalLayout_7;
    QTextEdit *textEditLabName;
    QTableWidget *tableWidgetChangedLab;
    QWidget *ShowLabPage;
    QTableWidget *tableWidgetShowLab;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(768, 697);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButtonBackClicked = new QPushButton(centralwidget);
        pushButtonBackClicked->setObjectName(QString::fromUtf8("pushButtonBackClicked"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonBackClicked->sizePolicy().hasHeightForWidth());
        pushButtonBackClicked->setSizePolicy(sizePolicy);
        pushButtonBackClicked->setMinimumSize(QSize(40, 25));
        pushButtonBackClicked->setMaximumSize(QSize(40, 25));

        horizontalLayout->addWidget(pushButtonBackClicked, 0, Qt::AlignLeft);

        pushButtonNextClicked = new QPushButton(centralwidget);
        pushButtonNextClicked->setObjectName(QString::fromUtf8("pushButtonNextClicked"));
        sizePolicy.setHeightForWidth(pushButtonNextClicked->sizePolicy().hasHeightForWidth());
        pushButtonNextClicked->setSizePolicy(sizePolicy);
        pushButtonNextClicked->setMinimumSize(QSize(40, 25));
        pushButtonNextClicked->setMaximumSize(QSize(40, 25));

        horizontalLayout->addWidget(pushButtonNextClicked, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout);

        lineEditMessage = new QLineEdit(centralwidget);
        lineEditMessage->setObjectName(QString::fromUtf8("lineEditMessage"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditMessage->sizePolicy().hasHeightForWidth());
        lineEditMessage->setSizePolicy(sizePolicy1);
        lineEditMessage->setMinimumSize(QSize(300, 30));
        lineEditMessage->setMaximumSize(QSize(300, 30));
        lineEditMessage->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));
        lineEditMessage->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lineEditMessage, 0, Qt::AlignHCenter);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        StartPage = new QWidget();
        StartPage->setObjectName(QString::fromUtf8("StartPage"));
        verticalLayout_2 = new QVBoxLayout(StartPage);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidgetMissing = new QTableWidget(StartPage);
        if (tableWidgetMissing->columnCount() < 2)
            tableWidgetMissing->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetMissing->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetMissing->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidgetMissing->setObjectName(QString::fromUtf8("tableWidgetMissing"));
        tableWidgetMissing->setMinimumSize(QSize(500, 470));
        tableWidgetMissing->setMaximumSize(QSize(500, 470));

        verticalLayout_2->addWidget(tableWidgetMissing, 0, Qt::AlignHCenter);

        stackedWidget->addWidget(StartPage);
        ChangedPointPage = new QWidget();
        ChangedPointPage->setObjectName(QString::fromUtf8("ChangedPointPage"));
        horizontalLayout_2 = new QHBoxLayout(ChangedPointPage);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableWidgetChangedPoint = new QTableWidget(ChangedPointPage);
        if (tableWidgetChangedPoint->columnCount() < 4)
            tableWidgetChangedPoint->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetChangedPoint->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetChangedPoint->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetChangedPoint->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetChangedPoint->setHorizontalHeaderItem(3, __qtablewidgetitem5);
        tableWidgetChangedPoint->setObjectName(QString::fromUtf8("tableWidgetChangedPoint"));
        tableWidgetChangedPoint->setMinimumSize(QSize(600, 470));
        tableWidgetChangedPoint->setMaximumSize(QSize(500, 470));

        horizontalLayout_2->addWidget(tableWidgetChangedPoint);

        stackedWidget->addWidget(ChangedPointPage);
        ChoicePage = new QWidget();
        ChoicePage->setObjectName(QString::fromUtf8("ChoicePage"));
        verticalLayout_3 = new QVBoxLayout(ChoicePage);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButtonLab = new QPushButton(ChoicePage);
        pushButtonLab->setObjectName(QString::fromUtf8("pushButtonLab"));
        pushButtonLab->setMinimumSize(QSize(250, 70));
        pushButtonLab->setMaximumSize(QSize(200, 70));
        pushButtonLab->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(pushButtonLab, 1, 1, 1, 1);

        pushButtonCallStudents = new QPushButton(ChoicePage);
        pushButtonCallStudents->setObjectName(QString::fromUtf8("pushButtonCallStudents"));
        pushButtonCallStudents->setMinimumSize(QSize(250, 70));
        pushButtonCallStudents->setMaximumSize(QSize(200, 70));
        pushButtonCallStudents->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(pushButtonCallStudents, 0, 0, 1, 1);

        pushButtonChangedPoint = new QPushButton(ChoicePage);
        pushButtonChangedPoint->setObjectName(QString::fromUtf8("pushButtonChangedPoint"));
        pushButtonChangedPoint->setMinimumSize(QSize(250, 70));
        pushButtonChangedPoint->setMaximumSize(QSize(200, 70));
        pushButtonChangedPoint->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(pushButtonChangedPoint, 0, 1, 1, 1);

        pushButtonSaveData = new QPushButton(ChoicePage);
        pushButtonSaveData->setObjectName(QString::fromUtf8("pushButtonSaveData"));
        pushButtonSaveData->setMinimumSize(QSize(250, 70));
        pushButtonSaveData->setMaximumSize(QSize(200, 70));
        pushButtonSaveData->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(pushButtonSaveData, 1, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        stackedWidget->addWidget(ChoicePage);
        CallPage = new QWidget();
        CallPage->setObjectName(QString::fromUtf8("CallPage"));
        verticalLayout_4 = new QVBoxLayout(CallPage);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        textEditOutput = new QTextEdit(CallPage);
        textEditOutput->setObjectName(QString::fromUtf8("textEditOutput"));
        textEditOutput->setMinimumSize(QSize(700, 350));
        textEditOutput->setMaximumSize(QSize(700, 400));
        textEditOutput->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));

        verticalLayout_4->addWidget(textEditOutput, 0, Qt::AlignHCenter);

        textEditInput = new QTextEdit(CallPage);
        textEditInput->setObjectName(QString::fromUtf8("textEditInput"));
        textEditInput->setMinimumSize(QSize(700, 50));
        textEditInput->setMaximumSize(QSize(700, 50));
        textEditInput->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));

        verticalLayout_4->addWidget(textEditInput, 0, Qt::AlignHCenter);

        stackedWidget->addWidget(CallPage);
        LabPage = new QWidget();
        LabPage->setObjectName(QString::fromUtf8("LabPage"));
        horizontalLayout_7 = new QHBoxLayout(LabPage);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButtonCreateLab = new QPushButton(LabPage);
        pushButtonCreateLab->setObjectName(QString::fromUtf8("pushButtonCreateLab"));
        pushButtonCreateLab->setMinimumSize(QSize(100, 30));
        pushButtonCreateLab->setMaximumSize(QSize(100, 30));
        pushButtonCreateLab->setStyleSheet(QString::fromUtf8("font: 12pt \"MS Shell Dlg 2\";"));

        horizontalLayout_6->addWidget(pushButtonCreateLab);

        pushButtonCansel = new QPushButton(LabPage);
        pushButtonCansel->setObjectName(QString::fromUtf8("pushButtonCansel"));
        pushButtonCansel->setMinimumSize(QSize(100, 30));
        pushButtonCansel->setMaximumSize(QSize(100, 30));
        pushButtonCansel->setStyleSheet(QString::fromUtf8("font: 12pt \"MS Shell Dlg 2\";"));

        horizontalLayout_6->addWidget(pushButtonCansel);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        scrollAreaNames = new QScrollArea(LabPage);
        scrollAreaNames->setObjectName(QString::fromUtf8("scrollAreaNames"));
        scrollAreaNames->setMinimumSize(QSize(200, 400));
        scrollAreaNames->setMaximumSize(QSize(200, 500));
        scrollAreaNames->setStyleSheet(QString::fromUtf8("font: 11pt \"MS Shell Dlg 2\";"));
        scrollAreaNames->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 198, 398));
        horizontalLayout_4 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayoutNames = new QVBoxLayout();
        verticalLayoutNames->setObjectName(QString::fromUtf8("verticalLayoutNames"));

        horizontalLayout_4->addLayout(verticalLayoutNames);

        scrollAreaNames->setWidget(scrollAreaWidgetContents);

        horizontalLayout_3->addWidget(scrollAreaNames);

        scrollAreaLabNames = new QScrollArea(LabPage);
        scrollAreaLabNames->setObjectName(QString::fromUtf8("scrollAreaLabNames"));
        scrollAreaLabNames->setMinimumSize(QSize(200, 400));
        scrollAreaLabNames->setMaximumSize(QSize(200, 500));
        scrollAreaLabNames->setStyleSheet(QString::fromUtf8("font: 11pt \"MS Shell Dlg 2\";"));
        scrollAreaLabNames->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 198, 398));
        horizontalLayout_5 = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayoutLabNames = new QVBoxLayout();
        verticalLayoutLabNames->setObjectName(QString::fromUtf8("verticalLayoutLabNames"));

        horizontalLayout_5->addLayout(verticalLayoutLabNames);

        scrollAreaLabNames->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_3->addWidget(scrollAreaLabNames);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        pushButtonChangedLab = new QPushButton(LabPage);
        pushButtonChangedLab->setObjectName(QString::fromUtf8("pushButtonChangedLab"));
        pushButtonChangedLab->setMinimumSize(QSize(200, 60));
        pushButtonChangedLab->setMaximumSize(QSize(150, 60));
        pushButtonChangedLab->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));

        verticalLayout_5->addWidget(pushButtonChangedLab);

        pushButtonDeleteLab = new QPushButton(LabPage);
        pushButtonDeleteLab->setObjectName(QString::fromUtf8("pushButtonDeleteLab"));
        pushButtonDeleteLab->setMinimumSize(QSize(200, 60));
        pushButtonDeleteLab->setMaximumSize(QSize(150, 60));
        pushButtonDeleteLab->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));

        verticalLayout_5->addWidget(pushButtonDeleteLab);

        pushButtonChangedPoints = new QPushButton(LabPage);
        pushButtonChangedPoints->setObjectName(QString::fromUtf8("pushButtonChangedPoints"));
        pushButtonChangedPoints->setMinimumSize(QSize(200, 60));
        pushButtonChangedPoints->setMaximumSize(QSize(150, 60));
        pushButtonChangedPoints->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));

        verticalLayout_5->addWidget(pushButtonChangedPoints);

        pushButtonShowTable = new QPushButton(LabPage);
        pushButtonShowTable->setObjectName(QString::fromUtf8("pushButtonShowTable"));
        pushButtonShowTable->setMinimumSize(QSize(200, 60));
        pushButtonShowTable->setMaximumSize(QSize(150, 60));
        pushButtonShowTable->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));

        verticalLayout_5->addWidget(pushButtonShowTable);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_3);


        horizontalLayout_7->addLayout(verticalLayout_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        stackedWidget->addWidget(LabPage);
        ChangeLabPage = new QWidget();
        ChangeLabPage->setObjectName(QString::fromUtf8("ChangeLabPage"));
        verticalLayout_8 = new QVBoxLayout(ChangeLabPage);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setSizeConstraint(QLayout::SetFixedSize);
        pushButtonAddCriterial = new QPushButton(ChangeLabPage);
        pushButtonAddCriterial->setObjectName(QString::fromUtf8("pushButtonAddCriterial"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButtonAddCriterial->sizePolicy().hasHeightForWidth());
        pushButtonAddCriterial->setSizePolicy(sizePolicy2);
        pushButtonAddCriterial->setMinimumSize(QSize(200, 30));
        pushButtonAddCriterial->setMaximumSize(QSize(200, 30));

        horizontalLayout_8->addWidget(pushButtonAddCriterial);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setSizeConstraint(QLayout::SetFixedSize);
        textEditLabName = new QTextEdit(ChangeLabPage);
        textEditLabName->setObjectName(QString::fromUtf8("textEditLabName"));
        sizePolicy2.setHeightForWidth(textEditLabName->sizePolicy().hasHeightForWidth());
        textEditLabName->setSizePolicy(sizePolicy2);
        textEditLabName->setMinimumSize(QSize(250, 30));
        textEditLabName->setMaximumSize(QSize(250, 30));

        verticalLayout_7->addWidget(textEditLabName, 0, Qt::AlignHCenter);


        horizontalLayout_8->addLayout(verticalLayout_7);


        horizontalLayout_9->addLayout(horizontalLayout_8);


        verticalLayout_8->addLayout(horizontalLayout_9);

        tableWidgetChangedLab = new QTableWidget(ChangeLabPage);
        tableWidgetChangedLab->setObjectName(QString::fromUtf8("tableWidgetChangedLab"));
        tableWidgetChangedLab->horizontalHeader()->setDefaultSectionSize(250);

        verticalLayout_8->addWidget(tableWidgetChangedLab);

        stackedWidget->addWidget(ChangeLabPage);
        ShowLabPage = new QWidget();
        ShowLabPage->setObjectName(QString::fromUtf8("ShowLabPage"));
        tableWidgetShowLab = new QTableWidget(ShowLabPage);
        tableWidgetShowLab->setObjectName(QString::fromUtf8("tableWidgetShowLab"));
        tableWidgetShowLab->setGeometry(QRect(110, 100, 521, 341));
        stackedWidget->addWidget(ShowLabPage);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 768, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonBackClicked->setText(QApplication::translate("MainWindow", "\320\275\320\260\320\267\320\260\320\264", nullptr));
        pushButtonNextClicked->setText(QApplication::translate("MainWindow", "\320\264\320\260\320\273\320\265\320\265", nullptr));
        lineEditMessage->setText(QApplication::translate("MainWindow", "\320\262\321\213\320\261\320\265\321\200\320\265\321\202\320\265 \320\273\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\321\203\321\216", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetMissing->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\270\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetMissing->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetChangedPoint->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\270\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetChangedPoint->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\261\320\260\320\273\320\273\321\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetChangedPoint->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\277\320\273\321\216\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetChangedPoint->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\320\274\320\270\320\275\321\203\321\201", nullptr));
        pushButtonLab->setText(QApplication::translate("MainWindow", "\320\273\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\321\213\320\265", nullptr));
        pushButtonCallStudents->setText(QApplication::translate("MainWindow", "\320\262\321\213\320\267\320\262\320\260\321\202\321\214 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260", nullptr));
        pushButtonChangedPoint->setText(QApplication::translate("MainWindow", "\320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\272\320\276\320\273-\320\262\320\276 \320\262\321\213\320\267\320\276\320\262\320\276\320\262", nullptr));
        pushButtonSaveData->setText(QApplication::translate("MainWindow", "\321\201\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        pushButtonCreateLab->setText(QApplication::translate("MainWindow", "\321\201\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        pushButtonCansel->setText(QApplication::translate("MainWindow", "\320\276\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        pushButtonChangedLab->setText(QApplication::translate("MainWindow", "\320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        pushButtonDeleteLab->setText(QApplication::translate("MainWindow", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButtonChangedPoints->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \320\261\320\260\320\273\320\273\321\213", nullptr));
        pushButtonShowTable->setText(QApplication::translate("MainWindow", "\320\277\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        pushButtonAddCriterial->setText(QApplication::translate("MainWindow", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\321\200\320\270\321\202\320\265\321\200\320\270\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

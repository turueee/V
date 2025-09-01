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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonBackClicked;
    QPushButton *pushButtonNextClicked;
    QLineEdit *lineEditMessage;
    QStackedWidget *stackedWidget;
    QWidget *ChoicePage;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButtonPlusPoint;
    QPushButton *pushButtonCallStudents;
    QPushButton *pushButtonSaveData;
    QPushButton *pushButtonMinusPoint;
    QWidget *CallPage;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *textEditOutput;
    QTextEdit *textEditInput;
    QWidget *ChangedPointPage;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget_2;
    QWidget *StartPage;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(791, 720);
        QIcon icon;
        icon.addFile(QString::fromUtf8("5.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButtonBackClicked = new QPushButton(centralwidget);
        pushButtonBackClicked->setObjectName(QString::fromUtf8("pushButtonBackClicked"));
        pushButtonBackClicked->setMinimumSize(QSize(50, 20));
        pushButtonBackClicked->setMaximumSize(QSize(50, 20));

        horizontalLayout->addWidget(pushButtonBackClicked, 0, Qt::AlignmentFlag::AlignLeft);

        pushButtonNextClicked = new QPushButton(centralwidget);
        pushButtonNextClicked->setObjectName(QString::fromUtf8("pushButtonNextClicked"));
        pushButtonNextClicked->setMinimumSize(QSize(50, 20));
        pushButtonNextClicked->setMaximumSize(QSize(50, 20));

        horizontalLayout->addWidget(pushButtonNextClicked, 0, Qt::AlignmentFlag::AlignRight);


        verticalLayout_2->addLayout(horizontalLayout);

        lineEditMessage = new QLineEdit(centralwidget);
        lineEditMessage->setObjectName(QString::fromUtf8("lineEditMessage"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditMessage->sizePolicy().hasHeightForWidth());
        lineEditMessage->setSizePolicy(sizePolicy);
        lineEditMessage->setMinimumSize(QSize(300, 30));
        lineEditMessage->setMaximumSize(QSize(300, 30));
        lineEditMessage->setMouseTracking(true);

        verticalLayout_2->addWidget(lineEditMessage, 0, Qt::AlignmentFlag::AlignHCenter);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        ChoicePage = new QWidget();
        ChoicePage->setObjectName(QString::fromUtf8("ChoicePage"));
        horizontalLayout_2 = new QHBoxLayout(ChoicePage);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButtonPlusPoint = new QPushButton(ChoicePage);
        pushButtonPlusPoint->setObjectName(QString::fromUtf8("pushButtonPlusPoint"));
        pushButtonPlusPoint->setMinimumSize(QSize(200, 70));
        pushButtonPlusPoint->setMaximumSize(QSize(200, 70));

        gridLayout->addWidget(pushButtonPlusPoint, 0, 1, 1, 1);

        pushButtonCallStudents = new QPushButton(ChoicePage);
        pushButtonCallStudents->setObjectName(QString::fromUtf8("pushButtonCallStudents"));
        pushButtonCallStudents->setMinimumSize(QSize(200, 70));
        pushButtonCallStudents->setMaximumSize(QSize(200, 70));

        gridLayout->addWidget(pushButtonCallStudents, 0, 0, 1, 1);

        pushButtonSaveData = new QPushButton(ChoicePage);
        pushButtonSaveData->setObjectName(QString::fromUtf8("pushButtonSaveData"));
        pushButtonSaveData->setMinimumSize(QSize(200, 70));
        pushButtonSaveData->setMaximumSize(QSize(200, 70));

        gridLayout->addWidget(pushButtonSaveData, 1, 0, 1, 1);

        pushButtonMinusPoint = new QPushButton(ChoicePage);
        pushButtonMinusPoint->setObjectName(QString::fromUtf8("pushButtonMinusPoint"));
        pushButtonMinusPoint->setMinimumSize(QSize(200, 70));
        pushButtonMinusPoint->setMaximumSize(QSize(200, 70));

        gridLayout->addWidget(pushButtonMinusPoint, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        stackedWidget->addWidget(ChoicePage);
        CallPage = new QWidget();
        CallPage->setObjectName(QString::fromUtf8("CallPage"));
        verticalLayout_5 = new QVBoxLayout(CallPage);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        textEditOutput = new QTextEdit(CallPage);
        textEditOutput->setObjectName(QString::fromUtf8("textEditOutput"));
        textEditOutput->setMinimumSize(QSize(700, 350));
        textEditOutput->setMaximumSize(QSize(700, 400));

        verticalLayout_5->addWidget(textEditOutput, 0, Qt::AlignmentFlag::AlignHCenter);

        textEditInput = new QTextEdit(CallPage);
        textEditInput->setObjectName(QString::fromUtf8("textEditInput"));
        textEditInput->setMinimumSize(QSize(700, 50));
        textEditInput->setMaximumSize(QSize(700, 50));

        verticalLayout_5->addWidget(textEditInput, 0, Qt::AlignmentFlag::AlignHCenter);

        stackedWidget->addWidget(CallPage);
        ChangedPointPage = new QWidget();
        ChangedPointPage->setObjectName(QString::fromUtf8("ChangedPointPage"));
        verticalLayout_3 = new QVBoxLayout(ChangedPointPage);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableWidget_2 = new QTableWidget(ChangedPointPage);
        if (tableWidget_2->columnCount() < 3)
            tableWidget_2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget_2->rowCount() < 15)
            tableWidget_2->setRowCount(15);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setMinimumSize(QSize(500, 472));
        tableWidget_2->setMaximumSize(QSize(400, 472));
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(160);

        verticalLayout_3->addWidget(tableWidget_2, 0, Qt::AlignmentFlag::AlignHCenter);

        stackedWidget->addWidget(ChangedPointPage);
        StartPage = new QWidget();
        StartPage->setObjectName(QString::fromUtf8("StartPage"));
        horizontalLayout_3 = new QHBoxLayout(StartPage);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tableWidget = new QTableWidget(StartPage);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QFont font;
        font.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        if (tableWidget->rowCount() < 15)
            tableWidget->setRowCount(15);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem6);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(500, 470));
        tableWidget->setMaximumSize(QSize(400, 470));
        tableWidget->horizontalHeader()->setDefaultSectionSize(200);

        horizontalLayout_3->addWidget(tableWidget, 0, Qt::AlignmentFlag::AlignHCenter);

        stackedWidget->addWidget(StartPage);

        verticalLayout_2->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 791, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "VisovkDoske", nullptr));
        pushButtonBackClicked->setText(QApplication::translate("MainWindow", "back", nullptr));
        pushButtonNextClicked->setText(QApplication::translate("MainWindow", "next", nullptr));
        pushButtonPlusPoint->setText(QApplication::translate("MainWindow", "Plus point", nullptr));
        pushButtonCallStudents->setText(QApplication::translate("MainWindow", "Call students", nullptr));
        pushButtonSaveData->setText(QApplication::translate("MainWindow", "Save data and end program", nullptr));
        pushButtonMinusPoint->setText(QApplication::translate("MainWindow", "Minus point", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\262\321\213\320\267\320\276\320\262\321\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\270\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

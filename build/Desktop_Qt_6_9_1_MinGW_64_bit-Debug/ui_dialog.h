/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditLabNameDialog;
    QTextEdit *textEditLabNameDialog;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditGroupNameDialog;
    QTextEdit *textEditGroupNameDialog;
    QPushButton *pushButtonCreateDialog;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(439, 237);
        verticalLayout_4 = new QVBoxLayout(Dialog);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEditLabNameDialog = new QLineEdit(Dialog);
        lineEditLabNameDialog->setObjectName("lineEditLabNameDialog");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditLabNameDialog->sizePolicy().hasHeightForWidth());
        lineEditLabNameDialog->setSizePolicy(sizePolicy);
        lineEditLabNameDialog->setMinimumSize(QSize(150, 30));
        lineEditLabNameDialog->setMaximumSize(QSize(150, 30));

        verticalLayout->addWidget(lineEditLabNameDialog, 0, Qt::AlignHCenter|Qt::AlignBottom);

        textEditLabNameDialog = new QTextEdit(Dialog);
        textEditLabNameDialog->setObjectName("textEditLabNameDialog");
        textEditLabNameDialog->setMinimumSize(QSize(200, 30));
        textEditLabNameDialog->setMaximumSize(QSize(200, 30));
        textEditLabNameDialog->setStyleSheet(QString::fromUtf8("font: 12pt \"MS Shell Dlg 2\";"));

        verticalLayout->addWidget(textEditLabNameDialog, 0, Qt::AlignHCenter|Qt::AlignTop);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        lineEditGroupNameDialog = new QLineEdit(Dialog);
        lineEditGroupNameDialog->setObjectName("lineEditGroupNameDialog");
        sizePolicy.setHeightForWidth(lineEditGroupNameDialog->sizePolicy().hasHeightForWidth());
        lineEditGroupNameDialog->setSizePolicy(sizePolicy);
        lineEditGroupNameDialog->setMinimumSize(QSize(150, 30));
        lineEditGroupNameDialog->setMaximumSize(QSize(150, 30));

        verticalLayout_2->addWidget(lineEditGroupNameDialog, 0, Qt::AlignHCenter|Qt::AlignBottom);

        textEditGroupNameDialog = new QTextEdit(Dialog);
        textEditGroupNameDialog->setObjectName("textEditGroupNameDialog");
        textEditGroupNameDialog->setMinimumSize(QSize(200, 30));
        textEditGroupNameDialog->setMaximumSize(QSize(200, 30));
        textEditGroupNameDialog->setStyleSheet(QString::fromUtf8("font: 12pt \"MS Shell Dlg 2\";"));

        verticalLayout_2->addWidget(textEditGroupNameDialog, 0, Qt::AlignHCenter|Qt::AlignTop);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        pushButtonCreateDialog = new QPushButton(Dialog);
        pushButtonCreateDialog->setObjectName("pushButtonCreateDialog");

        verticalLayout_3->addWidget(pushButtonCreateDialog);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        lineEditLabNameDialog->setText(QCoreApplication::translate("Dialog", "\320\262\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217 \320\273\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\276\320\271", nullptr));
        lineEditGroupNameDialog->setText(QCoreApplication::translate("Dialog", "\320\262\320\262\320\265\320\264\320\270\321\202\320\265 \320\263\321\200\321\203\320\277\320\277\321\203", nullptr));
        pushButtonCreateDialog->setText(QCoreApplication::translate("Dialog", "\321\201\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

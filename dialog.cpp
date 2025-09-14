#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
//    ui->textEditGroupNameDialog->setFontPointSize(12);
//    ui->textEditLabNameDialog->setFontPointSize(12);
    ui->lineEditGroupNameDialog->setReadOnly(true);
    ui->lineEditLabNameDialog->setReadOnly(true);
    ui->textEditLabNameDialog->setFocus();
    connect(ui->pushButtonCreateDialog, &QPushButton::clicked, this, &Dialog::onPushButtonCreateClicked);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::getLabName()
{
    return labName;
}

QString Dialog::getGroupName()
{
    return groupName;
}

void Dialog::onPushButtonCreateClicked()
{
    labName = ui->textEditLabNameDialog->toPlainText();
    groupName = ui->textEditGroupNameDialog->toPlainText();
    ui->textEditGroupNameDialog->clear();
    ui->textEditLabNameDialog->clear();
    accept();
}

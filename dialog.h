#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QString getLabName();
    QString getGroupName();
private slots:
    void onPushButtonCreateClicked();
private:
    Ui::Dialog *ui;
    QString groupName, labName;
};

#endif // DIALOG_H

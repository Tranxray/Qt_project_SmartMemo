#ifndef DIALOG_DELETE_ISSUE_H
#define DIALOG_DELETE_ISSUE_H

#include <QDialog>
#include<Classes_of_Issue.h>

namespace Ui {
class Dialog_Delete_Issue;
}

class Dialog_Delete_Issue : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Delete_Issue(QWidget *parent = nullptr,Issue* is=nullptr);
    ~Dialog_Delete_Issue();

private:
    Ui::Dialog_Delete_Issue *ui;
};

#endif // DIALOG_DELETE_ISSUE_H

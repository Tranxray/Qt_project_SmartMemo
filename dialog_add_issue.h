#ifndef DIALOG_ADD_ISSUE_H
#define DIALOG_ADD_ISSUE_H

#include <QDialog>
#include<IssueList.h>
#include<TimeofIssue.h>

namespace Ui {
class Dialog_Add_Issue;
}

class Dialog_Add_Issue : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Add_Issue(QWidget *parent = nullptr,IssueList* il=nullptr,int type=1);
    ~Dialog_Add_Issue();

private slots:
    void Add_Issue();
    void Modify_Issue();

private:
    IssueList* ilist;
    Ui::Dialog_Add_Issue *ui;
};

#endif // DIALOG_ADD_ISSUE_H

#ifndef ISSUES_OF_DAY_H
#define ISSUES_OF_DAY_H

#include <QDialog>
#include<QDateEdit>
#include<IssueList.h>

namespace Ui {
class Issues_of_Day;
}

class Issues_of_Day : public QDialog
{
    Q_OBJECT

public:
    explicit Issues_of_Day(QWidget *parent = nullptr,IssueList* il=NULL);
    ~Issues_of_Day();
    IssueList* ilist;

private slots:
    void Add_Issue();
    void Show_List();

private:
    Ui::Issues_of_Day *ui;
};

#endif // ISSUES_OF_DAY_H

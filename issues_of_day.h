#ifndef ISSUES_OF_DAY_H
#define ISSUES_OF_DAY_H

#include <QDialog>
#include<QDateEdit>
#include<IssueList.h>
#include<qlistwidget.h>

namespace Ui {
class Issues_of_Day;
}

class Issues_of_Day : public QDialog
{
    Q_OBJECT

public:
    explicit Issues_of_Day(QDate* date, QWidget *parent = nullptr,IssueList* il=NULL);
    ~Issues_of_Day();
    IssueList* ilist;

private slots:
    void Add_Issue();
    void Show_List();
    void Modify_Issue(QListWidgetItem *item);
    void Delete_Issue();

private:
    Ui::Issues_of_Day *ui;
};

#endif // ISSUES_OF_DAY_H

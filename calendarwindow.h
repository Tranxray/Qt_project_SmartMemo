#ifndef CALENDARWINDOW_H
#define CALENDARWINDOW_H

#include <QDialog>
#include <QDate>
#include "IssueList.h"
#include<qlistwidget.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class calendarwindow;
}
QT_END_NAMESPACE

class calendarwindow : public QDialog
{
    Q_OBJECT

public:
    calendarwindow(IssueList* il = nullptr,QWidget *parent = nullptr);
    ~calendarwindow();
    IssueList* ilist;

private slots:
    void on_calendarwindowWidget_clicked(const QDate &date);
    void on_dateEdit_userDateChanged(const QDate &date);
    void on_calendarWidget_activated(const QDate &date);
    void Show_List();
    void Show_Issues_of_day();
    void on_pushButtonAdd_clicked();
    void Modify_Issue(QListWidgetItem *item);
    void Modify_Issue_2();
    void Delete_Issue();

public:
    QDate m_date;

private:
    Ui::calendarwindow *ui;
};
#endif // CALENDARWINDOW_H

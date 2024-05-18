#ifndef ISSUES_OF_DAY_H
#define ISSUES_OF_DAY_H

#include <QDialog>
#include<QDateEdit>

namespace Ui {
class Issues_of_Day;
}

class Issues_of_Day : public QDialog
{
    Q_OBJECT

public:
    explicit Issues_of_Day(QWidget *parent = nullptr);
    ~Issues_of_Day();

private slots:
    void Add_Issue();
    void Close_window();

private:
    Ui::Issues_of_Day *ui;
};

#endif // ISSUES_OF_DAY_H

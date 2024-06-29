#ifndef WIDGET_OF_ISUUE_H
#define WIDGET_OF_ISUUE_H

#include <QWidget>
#include<Classes_of_Issue.h>

namespace Ui {
class Widget_of_Isuue;
}

class Widget_of_Isuue : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_of_Isuue(QWidget *parent = nullptr,Issue* is=nullptr);
    ~Widget_of_Isuue();

private slots:
    void Issue_Completed();

private:
    Ui::Widget_of_Isuue *ui;
    Issue* is;
};

#endif // WIDGET_OF_ISUUE_H

#include "widget_of_isuue.h"
#include "ui_widget_of_isuue.h"
#include"Classes_of_Issue.h"

Widget_of_Isuue::Widget_of_Isuue(QWidget *parent,Issue* is)
    : QWidget(parent)
    , ui(new Ui::Widget_of_Isuue)
{
    ui->setupUi(this);
    this->is=is;
    //this->setStyleSheet("border: 1px solid #CCCCCC");
    //this->setStyleSheet("border-radius: 4px");
    //this->setStyleSheet("padding: 5px");
    connect(ui->checkBox,SIGNAL(checkStateChanged(Qt::CheckState)),this,SLOT(Issue_Completed()));
    ui->TiTleLabel->setText(QString::fromStdString("事件："+is->getName()));
    ui->PositionLabel->setText(QString::fromStdString("地点："+is->getPosition()));
    ui->DescriptionLabel->setText(QString::fromStdString("描述："+is->getDiscription()));
    ui->HourNumber->setDigitCount(2);
    ui->MinNumber->setDigitCount(2);
    ui->HourNumber->display(is->getHour());
    ui->MinNumber->display(is->getMin());
    ui->HourNumber->setStyleSheet(
        "QLCDNumber { "
        "color: red; "           // 设置字体颜色
        "background-color: black; " // 设置背景颜色
        "border: 2px solid green; "  // 设置边框
        "}"
        );
    ui->MinNumber->setStyleSheet(
        "QLCDNumber { "
        "color: red; "           // 设置字体颜色
        "background-color: black; " // 设置背景颜色
        "border: 2px solid green; "  // 设置边框
        "}"
        );
    if(is->getRepeat()>0)
        ui->RepeatLabel->setText("每"+QString::number(is->getRepeat())+"天");
    else
        ui->RepeatLabel->setText("不重复");
    setFixedSize(371,71);
}

Widget_of_Isuue::~Widget_of_Isuue()
{
    delete ui;
}


void Widget_of_Isuue::Issue_Completed(){
    if(ui->checkBox->checkState())
        this->is->setComplete(true);
    else
        this->is->setComplete(false);
}

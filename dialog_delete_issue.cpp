#include "dialog_delete_issue.h"
#include "ui_dialog_delete_issue.h"
#include<Classes_of_Issue.h>
#include<qstring.h>

Dialog_Delete_Issue::Dialog_Delete_Issue(QWidget *parent,Issue* is)
    : QDialog(parent)
    , ui(new Ui::Dialog_Delete_Issue)
{
    ui->setupUi(this);
    string title=is->getName();
    ui->Asklabel->setText("你确定要删除事件\""+QString::fromStdString(title)+"\"吗");
    this->show();
}

Dialog_Delete_Issue::~Dialog_Delete_Issue()
{
    delete ui;
}

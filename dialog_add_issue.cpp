#include "dialog_add_issue.h"
#include "ui_dialog_add_issue.h"
#include"qmessagebox.h"

Dialog_Add_Issue::Dialog_Add_Issue(QWidget *parent,IssueList* il,int type)
    : QDialog(parent)
    , ui(new Ui::Dialog_Add_Issue)
{
    ui->setupUi(this);
    ilist=il;
    QDateTime curdatetime=QDateTime::currentDateTime();
    ui->StartTimeedit->setDateTime(curdatetime);
    if(type==1)
        connect(ui->AcceptButton,SIGNAL(clicked()),this,SLOT(Add_Issue()));
    else if(type==2)
        connect(ui->AcceptButton,SIGNAL(clicked()),this,SLOT(Modify_Issue()));
    connect(ui->CancelButton,SIGNAL(clicked()),this,SLOT(close()));
    ui->IssueTypeBox->addItem("PointIssue");
    ui->IssueTypeBox->addItem("LastingIssue");
    ui->IssueTypeBox->addItem("HabitIssue");
    ui->IssueTypeBox->addItem("TaskIssue");
    ui->RepeatTypeBox->addItem("天");
    ui->RepeatTypeBox->addItem("周");
    ui->RepeatTypeBox->addItem("月");
}

Dialog_Add_Issue::~Dialog_Add_Issue()
{
    delete ui;
}

void Dialog_Add_Issue::Modify_Issue(){

}


void Dialog_Add_Issue::Add_Issue(){
    std::string name=ui->Titletext->toPlainText().toStdString();
    int IssueType=ui->IssueTypeBox->currentIndex();
    if(name==""||IssueType<0){
        QMessageBox::information(this,"InputError","Title and Type can not be empty!");
        return;
    }
    std::string description=ui->Descriptiontext->toPlainText().toStdString();
    std::string position=ui->Positiontext->toPlainText().toStdString();
    QDateTime dt=ui->StartTimeedit->dateTime();
    int year,month,day,hour,min;
    QDate date=dt.date();
    QTime tim=dt.time();
    year=date.year();
    month=date.month();
    day=date.day();
    hour=tim.hour();
    min=tim.minute();
    TimeofIssue* newtime=new TimeofIssue(year,month,day,hour,min);
    int repeat=ui->numberBox->value();
    qDebug()<<"asda   "<<IssueType;
    Issue* newIssue=new Issue(name,description,position,repeat,newtime,IssueType);
    this->ilist->addIssue(newIssue);
    this->close();
}

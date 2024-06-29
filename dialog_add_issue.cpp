#include "dialog_add_issue.h"
#include "ui_dialog_add_issue.h"
#include"qmessagebox.h"

Dialog_Add_Issue::Dialog_Add_Issue(QWidget *parent,IssueList* il)
    : QDialog(parent)
    , ui(new Ui::Dialog_Add_Issue)
{
    ui->setupUi(this);
    ilist=il;
    QDateTime curdatetime=QDateTime::currentDateTime();
    ui->StartTimeedit->setDateTime(curdatetime);
    ui->EndTimeedit->setDateTime(curdatetime);
    connect(ui->AcceptButton,SIGNAL(clicked()),this,SLOT(Add_Issue()));
    connect(ui->CancelButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->IssueTypeBox,SIGNAL(currentIndexChanged(int)),this,SLOT(Show_EndTime()));
    ui->EndTimeedit->hide();
    ui->labelofEndTime->hide();
    ui->IssueTypeBox->addItem("PointIssue");
    ui->IssueTypeBox->addItem("LastingIssue");
    ui->IssueTypeBox->addItem("HabitIssue");
    ui->IssueTypeBox->addItem("TaskIssue");
    ui->RepeatTypeBox->addItem("天");
    ui->RepeatTypeBox->addItem("周");
    ui->RepeatTypeBox->addItem("月");
    //this->setStyleSheet("background-color: rgb(255, 255, 255);");
}

Dialog_Add_Issue::Dialog_Add_Issue(QWidget *parent, IssueList *il, Issue *is)
    : QDialog(parent)
    , ui(new Ui::Dialog_Add_Issue)
{
    ui->setupUi(this);
    ilist=il;
    this->is=is;
    QDateTime curdatetime=is->getstQdatetime();
    QDateTime eddatetime=is->getedQdatetime();
    ui->StartTimeedit->setDateTime(curdatetime);
    ui->EndTimeedit->setDateTime(eddatetime);
    connect(ui->AcceptButton,SIGNAL(clicked()),this,SLOT(Modify_Issue()));
    connect(ui->CancelButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->IssueTypeBox,SIGNAL(currentIndexChanged(int)),this,SLOT(Show_EndTime()));
    if(is->getType()!=1){
        ui->EndTimeedit->hide();
        ui->labelofEndTime->hide();
    }
    ui->IssueTypeBox->hide();
    ui->labelofIssueType->hide();
    ui->IssueTypeBox->addItem("PointIssue");
    ui->IssueTypeBox->addItem("LastingIssue");
    ui->IssueTypeBox->addItem("HabitIssue");
    ui->IssueTypeBox->addItem("TaskIssue");
    ui->RepeatTypeBox->addItem("天");
    ui->RepeatTypeBox->addItem("周");
    ui->RepeatTypeBox->addItem("月");
    ui->Titletext->setText(QString::fromStdString(is->getName()));
    ui->Descriptiontext->setText(QString::fromStdString(is->getDiscription()));
    ui->Positiontext->setText(QString::fromStdString(is->getPosition()));
    //qDebug()<<ilist->ls_0.size();
    qDebug()<<is->getTypename()<<is->getType();
    ui->IssueTypeBox->setCurrentIndex(is->getType());
    ui->numberBox->setValue(is->getRepeat());
}

Dialog_Add_Issue::~Dialog_Add_Issue()
{
    delete ui;
}

void Dialog_Add_Issue::Modify_Issue(){
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
    dt=ui->EndTimeedit->dateTime();
    date=dt.date();
    tim=dt.time();
    year=date.year();
    month=date.month();
    day=date.day();
    hour=tim.hour();
    min=tim.minute();
    TimeofIssue* endtime=new TimeofIssue(year,month,day,hour,min);
    int repeat=ui->numberBox->value();
    Issue* newIssue=nullptr;
    switch (IssueType) {
    case 0:
        newIssue=new Issue_point(name,description,position,repeat,newtime);
        delete endtime;
        break;
    case 1:
        newIssue=new Issue_lasting(name,description,position,repeat,newtime,endtime);
        break;
    case 2:
        newIssue=new Issue_habit(name,description,position,repeat,newtime);
        delete endtime;
        break;
    case 3:
        newIssue=new Issue_task(name,description,position,repeat,newtime);
        delete endtime;
        break;
    default:
        break;
    }
    ilist->updateIssue(is->getID(),*newIssue);
    delete newIssue;
    this->close();
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
    dt=ui->EndTimeedit->dateTime();
    date=dt.date();
    tim=dt.time();
    year=date.year();
    month=date.month();
    day=date.day();
    hour=tim.hour();
    min=tim.minute();
    TimeofIssue* endtime=new TimeofIssue(year,month,day,hour,min);
    int repeat=ui->numberBox->value();
    Issue* newIssue=nullptr;
    switch (IssueType) {
    case 0:
        newIssue=new Issue_point(name,description,position,repeat,newtime);
        delete endtime;
        break;
    case 1:
        newIssue=new Issue_lasting(name,description,position,repeat,newtime,endtime);
        break;
    case 2:
        newIssue=new Issue_habit(name,description,position,repeat,newtime);
        delete endtime;
        break;
    case 3:
        newIssue=new Issue_task(name,description,position,repeat,newtime);
        delete endtime;
        break;
    default:
        break;
    }
    this->ilist->addIssue(newIssue);
    this->close();
}


void Dialog_Add_Issue::Show_EndTime(){
    int IssueType=ui->IssueTypeBox->currentIndex();
    if(IssueType==1){
        ui->EndTimeedit->show();
        ui->labelofEndTime->show();
    }
    else{
        ui->EndTimeedit->hide();
        ui->labelofEndTime->hide();
    }
}

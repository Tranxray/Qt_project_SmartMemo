#include "issues_of_day.h"
#include "ui_issues_of_day.h"
#include"dialog_add_issue.h"
#include"qdebug.h"

Issues_of_Day::Issues_of_Day(QWidget *parent,IssueList* il)
    : QDialog(parent)
    , ui(new Ui::Issues_of_Day)
{
    ui->setupUi(this);
    this->ilist=il;
    this->setWindowTitle("一日事件");
    QDate curdate=QDate::currentDate();
    ui->dateEdit->setDate(curdate);
    this->Show_List();
    connect(ui->AddButton,SIGNAL(clicked()),this,SLOT(Add_Issue()));
    connect(ui->CloseButton,SIGNAL(clicked(bool)),this,SLOT(close()));
}



Issues_of_Day::~Issues_of_Day()
{
    delete ui;
}

void Issues_of_Day::Add_Issue(){
    Dialog_Add_Issue* dai=new Dialog_Add_Issue(this,this->ilist);
    dai->exec();
    TimeofIssue ti(2024,5,22);
    Show_List();
}

void Issues_of_Day::Show_List(){
    ui->list_of_Issues->clear();
    ui->list_of_Issues->setSortingEnabled(true);
    QDate date=ui->dateEdit->date();
    int year,month,day;
    year=date.year();
    month=date.month();
    day=date.day();
    qDebug()<<year<<month<<day;
    TimeofIssue tdate(year,month,day);
    list<Issue*> il=this->ilist->getIssues(tdate);
    for(list<Issue*>::iterator it=il.begin();it!=il.end();it++){
        QString issue_string="";
        issue_string+=QString::number((*it)->getHour());
        issue_string+=":";
        issue_string+=QString::number((*it)->getMin());
        issue_string+="\t";
        issue_string+=(*it)->getName()+"\t"+(*it)->getPosition()+"\t"+(*it)->getTypename();
        ui->list_of_Issues->addItem(issue_string);
    }
}

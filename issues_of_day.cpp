#include "issues_of_day.h"
#include "ui_issues_of_day.h"
#include"dialog_add_issue.h"
#include"qdebug.h"
#include<QListWidget>
#include<widget_of_isuue.h>
#include<dialog_delete_issue.h>

Issues_of_Day::Issues_of_Day(QDate* date, QWidget *parent,IssueList* il)
    : QDialog(parent)
    , ui(new Ui::Issues_of_Day)
{
    ui->setupUi(this);
    this->ilist=il;
    this->setWindowTitle("一日事件");
    if(date) {
        ui->dateEdit->setDate(*date);
    } else {
        QDate curdate=QDate::currentDate();
        ui->dateEdit->setDate(curdate);
    }
    this->Show_List();
    connect(ui->AddButton,SIGNAL(clicked()),this,SLOT(Add_Issue()));
    connect(ui->CloseButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->dateEdit,SIGNAL(dateChanged(QDate)),this,SLOT(Show_List()));
    connect(ui->list_of_Issues,&QListWidget::itemDoubleClicked,this,&Issues_of_Day::Modify_Issue);
    connect(ui->DeleteButton,SIGNAL(clicked(bool)),this,SLOT(Delete_Issue()));
    //this->setStyleSheet("background-color: rgb(255, 255, 255);");
}



Issues_of_Day::~Issues_of_Day()
{
    delete ui;
}

void Issues_of_Day::Add_Issue(){
    Dialog_Add_Issue* dai=new Dialog_Add_Issue(this,this->ilist);
    dai->exec();
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
    qDebug()<<"size"<<il.size();
    for(list<Issue*>::reverse_iterator it=il.rbegin();it!=il.rend();it++){
        qDebug()<<(*it)->getMin();
        Widget_of_Isuue* woi=new Widget_of_Isuue(this,*it);
        QListWidgetItem* item =new QListWidgetItem();
        item->setData(Qt::UserRole,(*it)->getID());
        item->setSizeHint(QSize(371,71));
        ui->list_of_Issues->addItem(item);
        ui->list_of_Issues->setItemWidget(item,woi);
        // QString issue_string="";
        // issue_string+=QString::number((*it)->getHour());
        // issue_string+=":";
        // issue_string+=QString::number((*it)->getMin());
        // issue_string+="\t";
        // issue_string+=(*it)->getName()+"\t"+(*it)->getPosition()+"\t"+(*it)->getTypename();
        // QListWidgetItem* item =new QListWidgetItem();
        // item->setText(issue_string);
        // item->setData(Qt::UserRole,(*it)->getID());
        // ui->list_of_Issues->addItem(item);
    }
}

void Issues_of_Day::Modify_Issue(QListWidgetItem *item){
    long long id=item->data(Qt::UserRole).toLongLong();
    Issue* is=ilist->getIssue(id);
    if(is){
        Dialog_Add_Issue* dai=new Dialog_Add_Issue(this,ilist,is);
        dai->exec();
    }
    Show_List();
}


void Issues_of_Day::Delete_Issue(){
    QList<QListWidgetItem*> items =ui->list_of_Issues->selectedItems();
    for(QList<QListWidgetItem*>::iterator item=items.begin();item!=items.end();item++){
        Issue* is=ilist->getIssue((*item)->data(Qt::UserRole).toLongLong());
        Dialog_Delete_Issue* ddi=new Dialog_Delete_Issue(this,is);
        int result=ddi->exec();
        if(result==QDialog::Accepted){
            ilist->deleteIssue(is->getID());
            this->Show_List();
        }
    }
}

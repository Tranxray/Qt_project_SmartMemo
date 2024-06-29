#include "calendarwindow.h"
#include "ui_calendarwindow.h"
#include "dialog_add_issue.h"
#include "TimeofIssue.h"
#include "issues_of_day.h"
#include "widget_of_isuue.h"
#include<QListWidget>
#include"dialog_delete_issue.h"

calendarwindow::calendarwindow(IssueList* il,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::calendarwindow)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    this->ilist=il;
    Show_List();
    Show_Issues_of_day();
    connect(ui->list_of_Issue,&QListWidget::itemDoubleClicked,this,&calendarwindow::Modify_Issue);
    connect(ui->ModifyButton,&QPushButton::clicked,this,&calendarwindow::Modify_Issue_2);
    connect(ui->DeleteButton,SIGNAL(clicked(bool)),this,SLOT(Delete_Issue()));
    connect(ui->calendarWidget,SIGNAL(selectionChanged()),this,SLOT(Show_List()));
    connect(ui->calendarWidget,SIGNAL(selectionChanged()),this,SLOT(Show_Issues_of_day()));
}


calendarwindow::~calendarwindow()
{
    delete ui;
}


void calendarwindow::on_calendarwindowWidget_clicked(const QDate &date)
{
    m_date = date;
    accept();
}

void calendarwindow::on_dateEdit_userDateChanged(const QDate &date)
{
    ui->calendarWidget->setSelectedDate(date);
}

void calendarwindow::on_calendarWidget_activated(const QDate &date)
{
    ui->dateEdit->setDate(date);
    ui->Issues_of_Oneday->clear();
    ui->Issues_of_Oneday->setSortingEnabled(true);
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
        ui->Issues_of_Oneday->addItem(item);
        ui->Issues_of_Oneday->setItemWidget(item,woi);
    }
}

void calendarwindow::Show_List(){
    ui->list_of_Issue->clear();
    ui->list_of_Issue->setSortingEnabled(true);
    QDate date=ui->calendarWidget->selectedDate();
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
        ui->list_of_Issue->addItem(item);
        ui->list_of_Issue->setItemWidget(item,woi);
    }
}

void calendarwindow::on_pushButtonAdd_clicked()
{
    Dialog_Add_Issue* dai=new Dialog_Add_Issue(this,ilist);
    dai->exec();
    TimeofIssue ti(2024,5,24);
    Show_List();
    Show_Issues_of_day();
    ilist->writeData("IssueData.json");
}

void calendarwindow::Show_Issues_of_day()
{
    ilist->writeData("IssueData.json");
    ui->Issues_of_Oneday->clear();
    ui->Issues_of_Oneday->setSortingEnabled(true);
    QDate date=ui->calendarWidget->selectedDate();
    int year,month,day;
    year=date.year();
    month=date.month();
    day=date.day();
    TimeofIssue tdate(year,month,day);
    list<Issue*> il=this->ilist->getIssues(tdate);
    for(list<Issue*>::reverse_iterator it=il.rbegin();it!=il.rend();it++){
        QString issue_string="";
         issue_string+=QString::number((*it)->getHour());
         issue_string+=":";
         issue_string+=QString::number((*it)->getMin());
         issue_string+="\t";
         issue_string+=(*it)->getName()+"\t"+(*it)->getPosition()+"\t"+(*it)->getTypename();
         QListWidgetItem* item =new QListWidgetItem();
         item->setText(issue_string);
         item->setData(Qt::UserRole,(*it)->getID());
         ui->Issues_of_Oneday->addItem(item);
    }
}


void calendarwindow::Modify_Issue(QListWidgetItem *item){
    long long id=item->data(Qt::UserRole).toLongLong();
    Issue* is=ilist->getIssue(id);
    if(is){
        Dialog_Add_Issue* dai=new Dialog_Add_Issue(this,ilist,is);
        dai->exec();
    }
    Show_List();
    Show_Issues_of_day();
}

void calendarwindow::Modify_Issue_2(){
    QList<QListWidgetItem*> items=ui->list_of_Issue->selectedItems();
    for(QList<QListWidgetItem*>::iterator item=items.begin();item!=items.end();item++){
        Modify_Issue((*item));
    }
    Show_List();
    Show_Issues_of_day();
}

void calendarwindow::Delete_Issue(){
    QList<QListWidgetItem*> items =ui->list_of_Issue->selectedItems();
    for(QList<QListWidgetItem*>::iterator item=items.begin();item!=items.end();item++){
        Issue* is=ilist->getIssue((*item)->data(Qt::UserRole).toLongLong());
        Dialog_Delete_Issue* ddi=new Dialog_Delete_Issue(this,is);
        int result=ddi->exec();
        if(result==QDialog::Accepted){
            ilist->deleteIssue(is->getID());
            this->Show_List();
            this->Show_Issues_of_day();
        }
    }
}

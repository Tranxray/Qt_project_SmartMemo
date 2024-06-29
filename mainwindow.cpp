#include "mainwindow.h"
#include"settings.h"
#include "ui_mainwindow.h"
#include"dialog_add_issue.h"
#include"qdebug.h"
#include"calendarwindow.h"
#include"ui_calendarwindow.h"
#include"stylesheetmanager.h"
#include<widget_of_isuue.h>
#include<dialog_delete_issue.h>
#include<QListWidget>
#include "issues_of_day.h"
MainWindow::MainWindow(IssueList* il,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("主界面");
    this->ilist=il;
    this->Show_List();
    connect(ui->ViewMoreButton,SIGNAL(clicked()),this,SLOT(Open_Issue_of_Day()));
    connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::SettingsButton_clicked);
    connect(ui->Add,SIGNAL(clicked()),this,SLOT(Add_Issue()));
    connect(ui->Date,SIGNAL(clicked(bool)),this,SLOT(Open_Calendar()));
    colormode=1;
    languagemode=1;
    StyleSheetManager::instance().SetStyle(colormode);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Open_Issue_of_Day(){
    Issues_of_Day* day_issues=new Issues_of_Day(nullptr, this,this->ilist);
    day_issues->ilist=this->ilist;
    day_issues->exec();
    delete day_issues;
    Show_List();
    ilist->writeData("IssueData.json");
}

void MainWindow::SettingsButton_clicked()
{
    setting=new Settings(this);
    setting->exec();
    //Settings* st=new Settings(this);
    //st->show();
}

void MainWindow::Add_Issue(){
    Dialog_Add_Issue* dai=new Dialog_Add_Issue(this,ilist);
    dai->exec();
    TimeofIssue ti(2024,5,24);
    Show_List();
    ilist->writeData("IssueData.json");
}

void MainWindow::Show_List(){
    ui->list_of_Issues->clear();
    ui->list_of_Issues->setSortingEnabled(true);
    QDate date=QDate::currentDate();
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
    }
}

void MainWindow::Open_Calendar(){
    calendarwindow *cal = new calendarwindow(ilist,this);
    if(cal->exec() == QDialog::Accepted) {
        Issues_of_Day dlg(&(cal->m_date), this, this->ilist);
        dlg.exec();
    }
    this->Show_List();
}


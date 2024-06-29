#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    IssueList* ilist;
    qDebug()<<1;
    ilist= new IssueList();
    qDebug()<<1;
    ilist->readData("./IssueData.json");
    qDebug()<<1;
    MainWindow w(ilist);
    w.show();
    return a.exec();
}

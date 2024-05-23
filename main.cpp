#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    IssueList* ilist;
    ilist= new IssueList();
    ilist->readData("IssueData.json");
    w.ilist=ilist;
    w.show();
    return a.exec();
}

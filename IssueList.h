#ifndef ISSUELIST_H
#define ISSUELIST_H

#include<Classes_of_Issue.h>
#include<TimeofIssue.h>
#include<list>

class IssueList{
private:
    list<Issue*> ls;
    list<Issue*> ls_0;//时间点事件
    list<Issue*> ls_1;//持续事件
    list<Issue*> ls_2;//习惯事件
    list<Issue*> ls_3;//ddl事件

public:
    IssueList();
    ~IssueList();
    static bool compare(const Issue* is1,const Issue* is2);

    void readData(string path);//从文件中读入数据

    void writeData(string path);//向文件中写入数据

    void addIssue(Issue* it);//添加事件
    void deleteIssue(long long id);//删除事件，调用后就无法访问这个id的事件了
    void updateIssue(long long id,const Issue& it);//更改事件信息（用一个新的事件对象）
    list<Issue*> getIssues(TimeofIssue& tm);//获取当日的事件,以list对象返回
    Issue* getIssue(long long id);//获取特定事件的指针

};

#endif // ISSUELIST_H

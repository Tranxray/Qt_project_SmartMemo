#ifndef CLASSES_OF_ISSUE_H
#define CLASSES_OF_ISSUE_H

#include<vector>
#include<cstring>
#include<TimeofIssue.h>
using namespace std;


class Issue{//事件基类
protected:
    long long ID;
    string m_Name;//事件标题
    TimeofIssue* m_startTime;//事件开始的时间信息
    string m_Typename;//事件类型：时间点事件，持续事件，习惯事件，ddl事件
    string m_Discription;//事件描述
    string m_Position;//事件地点
    int m_Repeat;//重复事件的时间间隔，以天为单位，<=0表示不重复
    bool isPast;//是否已经过期

public:
    Issue();
    Issue(string name,string discription,string position,int repeat,TimeofIssue* st_time,int type);
    Issue(long long id,string name,string discription,string position,int repeat,TimeofIssue* st_time,int type);
    virtual ~Issue();
    Issue(const Issue& other);

    long long getID();
    string getName();//获取事件标题
    string getTypename();//获取事件种类名称：“时间点事件”，“持续事件”，“习惯事件”，“ddl事件”
    int getType();//获取事件种类编号：0，1，2，3
    string getDiscription();//获取事件描述
    string getPosition();//获取事件地点
    int getRepeat();//获取事件重复的间隔时间（天数），<=0表示不重复
    TimeofIssue* getTimeofIssue();
    virtual int getLastingtime();//获取事件持续的时间，只有持续事件有

    virtual void examineDate();//检查是否到时
    bool isPasted();//返回是否到时

    //设置（开始）年月日时分
    void setYear(int year);
    void setMonth(int month);
    void setDate(int date);
    void setHour(int hour);
    void setMin(int min);

    //获取（开始）年月日时分
    int getYear();
    int getMonth();
    int getDate();
    int getHour();
    int getMin();

    //设置结束年月日时分
    virtual void setedYear(int year);
    virtual void setedMonth(int month);
    virtual void setedDate(int date);
    virtual void setedHour(int hour);
    virtual void setedMin(int min);

    //获取结束年月日时分
    virtual int getedYear();
    virtual int getedMonth();
    virtual int getedDate();
    virtual int getedHour();
    virtual int getedMin();

    friend bool operator<(const Issue& it1,const Issue& it2);

    virtual void fulfilled();
    virtual int getall_days();
    virtual int getfulfilled_days();
};

class Issue_point:public Issue{//时间点事件
private:

public:
    Issue_point(string name,string discription,string position,int repeat,TimeofIssue* st_time);
    Issue_point(long long id,string name,string discription,string position,int repeat,TimeofIssue* st_time);
};

class Issue_lasting:public Issue{//持续事件
private:
    TimeofIssue* m_endTime;

public:
    Issue_lasting(string name,string discription,string position,int repeat,TimeofIssue* st_time,TimeofIssue* ed_Time);
    Issue_lasting(long long id,string name,string discription,string position,int repeat,TimeofIssue* st_time,TimeofIssue* ed_Time);

    //设置结束年月日时分
    void setedYear(int year);
    void setedMonth(int month);
    void setedDate(int date);
    void setedHour(int hour);
    void setedMin(int min);

    //获取结束年月日时分
    int getedYear();
    int getedMonth();
    int getedDate();
    int getedHour();
    int getedMin();

};

class Issue_habit:public Issue{//习惯事件
private:
    int all_days;//习惯总计天数
    int fulfilled_days;//完成习惯的天数

public:
    Issue_habit(string name, string discription, string position, int repeat, TimeofIssue* st_time);
    Issue_habit(long long id,string name, string discription, string position, int repeat, TimeofIssue* st_time,int alldays,int fulfilleddays);

    void examineDate();
    void fulfilled();
    int getall_days();
    int getfulfilled_days();
};

class Issue_task:public Issue{//ddl事件
private:

public:
    Issue_task(string name,string discription,string position,int repeat,TimeofIssue* ed_time);
    Issue_task(long long id,string name,string discription,string position,int repeat,TimeofIssue* ed_time);
};


#endif // CLASSES_OF_ISSUE_H

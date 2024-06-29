#include<Classes_of_Issue.h>
#include<TimeofIssue.h>
#include<random>
using namespace std;


Issue::Issue()
{
    std::random_device rd;  // 用于获得种子
    std::mt19937_64 eng(rd());  // 64位随机数生成器，种子为random_device
    std::uniform_int_distribution<long long> distr;
    ID = distr(eng);
    m_Name = "";
    m_startTime = getLocalTime();
    m_Typename = "point";
    m_Discription = "";
    m_Position = "";
    m_Repeat = 0;
    isPast = false;
    isCompleted=false;
}

Issue::Issue(string name, string discription, string position, int repeat, TimeofIssue* st_time, int type)
{
    std::random_device rd;  // 用于获得种子
    std::mt19937_64 eng(rd());  // 64位随机数生成器，种子为random_device
    std::uniform_int_distribution<long long> distr;
    ID = distr(eng);
    m_Name = name;
    m_startTime = st_time;
    switch (type)
    {
    case 0:
        m_Typename = "point";
        break;
    case 1:
        m_Typename = "lasting";
        break;
    case 2:
        m_Typename = "habit";
        break;
    case 3:
        m_Typename = "ddl";
        break;

    default:
        break;
    }
    m_Discription = discription;
    m_Position = position;
    m_Repeat = repeat;
    isPast = false;
}

Issue::Issue(long long id, string name, string discription, string position, int repeat, TimeofIssue *st_time, int type){
    ID = id;
    m_Name = name;
    m_startTime = st_time;
    switch (type)
    {
    case 0:
        m_Typename = "point";
        break;
    case 1:
        m_Typename = "lasting";
        break;
    case 2:
        m_Typename = "habit";
        break;
    case 3:
        m_Typename = "ddl";
        break;

    default:
        break;
    }
    m_Discription = discription;
    m_Position = position;
    m_Repeat = repeat;
    isPast = false;
}

Issue::~Issue()
{
    if (m_startTime != NULL)
        delete m_startTime;
}

Issue::Issue(const Issue &other){
    ID=other.ID;
    m_Name=other.m_Name;
    m_Typename=other.m_Typename;
    m_Discription=other.m_Discription;
    m_Position=other.m_Position;
    m_Repeat=other.m_Repeat;
    isPast=other.isPast;
    TimeofIssue* tmp=new TimeofIssue((*other.m_startTime));
    m_startTime=tmp;
}

long long Issue::getID(){return ID;}
string Issue::getName()const{return m_Name;}
string Issue::getTypename()const{ return m_Typename;}
int Issue::getType()const
{
    if (m_Typename == "point")return 0;
    else if (m_Typename == "lasting")return 1;
    else if (m_Typename == "habit")return 2;
    else if (m_Typename == "ddl")return 3;
    return -1;
}
string Issue::getDiscription()const{return m_Discription;}
string Issue::getPosition() const{ return m_Position; }
int Issue::getRepeat()const { return m_Repeat; }
int Issue::getLastingtime() { return 0; }
void Issue::setComplete(bool tmp){isCompleted=tmp;}


void Issue::examineDate()
{
    TimeofIssue* time_now = getLocalTime();
    if (!(m_startTime < time_now))
    {
        isPast = true;
    }
    delete time_now;
}
bool Issue::isPasted() { return isPast; }
void Issue::setYear(int year) { m_startTime->setYear(year); }
void Issue::setMonth(int month) { m_startTime->setMonth(month); }
void Issue::setDate(int date) { m_startTime->setDate(date); }
void Issue::setHour(int hour) { m_startTime->setHour(hour); }
void Issue::setMin(int min) { m_startTime->setMin(min); }
int Issue::getYear() const { return m_startTime->getYear(); }
int Issue::getMonth() const { return m_startTime->getMonth(); }
int Issue::getDate() const { return m_startTime->getDate(); }
int Issue::getHour() const{ return m_startTime->getHour(); }
int Issue::getMin() const { return m_startTime->getMin(); }
void Issue::setedYear(int year) { }
void Issue::setedMonth(int month) {}
void Issue::setedDate(int date) { }
void Issue::setedHour(int hour) {}
void Issue::setedMin(int min) { }
int Issue::getedYear()const { return 0;}
int Issue::getedMonth()const { return 0; }
int Issue::getedDate()const { return 0; }
int Issue::getedHour()const { return 0; }
int Issue::getedMin()const { return 0; }

void Issue::setName(string name){m_Name=name;}
void Issue::setPosition(string position){m_Position=position;}
void Issue::setDescription(string description){m_Discription=description;}
void Issue::setRepeat(int repeat){m_Repeat=repeat;}

bool operator<(const Issue& it1, const Issue& it2){return it1.m_startTime < it2.m_startTime;}
void Issue::fulfilled(){   }
int Issue::getall_days(){return 0;}
int Issue::getfulfilled_days(){   return 0;}
TimeofIssue* Issue::getTimeofIssue(){return m_startTime;}

QDateTime Issue::getstQdatetime(){return m_startTime->getQdatetime();}
QDateTime Issue::getedQdatetime(){return QDateTime();}

Issue_point::Issue_point(string name, string discription, string position, int repeat, TimeofIssue* st_time) :Issue(name, discription, position, repeat, st_time, 0) {}
Issue_point::Issue_point(long long id,string name, string discription, string position, int repeat, TimeofIssue* st_time) :Issue(id,name, discription, position, repeat, st_time, 0) {}

Issue_lasting::Issue_lasting(string name, string discription, string position, int repeat, TimeofIssue* st_time, TimeofIssue* ed_Time) :Issue(name, discription, position, repeat, st_time, 1)
{
    m_endTime = ed_Time;
}
Issue_lasting::Issue_lasting(long long id,string name, string discription, string position, int repeat, TimeofIssue* st_time, TimeofIssue* ed_Time) :Issue(id,name, discription, position, repeat, st_time, 1)
{
    m_endTime = ed_Time;
}
void Issue_lasting::setedYear(int year) { m_endTime->setYear(year); }
void Issue_lasting::setedMonth(int month) { m_endTime->setMonth(month); }
void Issue_lasting::setedDate(int date) { m_endTime->setDate(date); }
void Issue_lasting::setedHour(int hour) { m_endTime->setHour(hour); }
void Issue_lasting::setedMin(int min) { m_endTime->setMin(min); }
int Issue_lasting::getedYear() const{ return m_endTime->getYear(); }
int Issue_lasting::getedMonth()const { return m_endTime->getMonth(); }
int Issue_lasting::getedDate() const{ return m_endTime->getDate(); }
int Issue_lasting::getedHour()const { return m_endTime->getHour(); }
int Issue_lasting::getedMin()const { return m_endTime->getMin(); }
QDateTime Issue_lasting::getedQdatetime(){
    return m_endTime->getQdatetime();
}

Issue_habit::Issue_habit(string name, string discription, string position, int repeat, TimeofIssue* st_time) :Issue(name, discription, position, repeat, st_time, 2)
{
    all_days = 0;
    fulfilled_days = 0;
}
Issue_habit::Issue_habit(long long id,string name, string discription, string position, int repeat, TimeofIssue* st_time,int alldays,int fulfilleddays) :Issue(id,name, discription, position, repeat, st_time, 2)
{
    all_days = alldays;
    fulfilled_days = fulfilleddays;
}
void Issue_habit::examineDate() { all_days++; }
void Issue_habit::fulfilled() { fulfilled_days++; }
int Issue_habit::getall_days() { return all_days; }
int Issue_habit::getfulfilled_days() { return fulfilled_days; }

Issue_task::Issue_task(string name, string discription, string position, int repeat, TimeofIssue* ed_time) :Issue(name, discription, position, repeat, ed_time, 3) {}
Issue_task::Issue_task(long long id,string name, string discription, string position, int repeat, TimeofIssue* ed_time) :Issue(id,name, discription, position, repeat, ed_time, 3) {}

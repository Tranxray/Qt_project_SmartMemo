#include<IssueList.h>
#include<TimeofIssue.h>
#include<qfile.h>
#include<qjsonarray.h>
#include<qjsondocument.h>
#include<qjsonobject.h>
#include<qjsonvalue.h>
#include<QDebug>

typedef list<Issue*>::iterator it;

IssueList::IssueList()
{
    ls.clear();
    ls_0.clear();
    ls_1.clear();
    ls_2.clear();
    ls_3.clear();
}

IssueList::~IssueList()
{
    for (it i = ls.begin();i != ls.end();i++)
    {
        delete (*i);
    }
}

void IssueList::readData(string path)
{
    QFile file(path.c_str());
    file.open(QFile::ReadOnly);
    QByteArray json = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(json);
    QJsonObject obj = doc.object();
    QJsonObject issues = obj["issues"].toObject();
    QJsonArray issue_point = issues["point"].toArray();
    QJsonArray issue_lasting = issues["lasting"].toArray();
    QJsonArray issue_habit = issues["habit"].toArray();
    QJsonArray issue_task = issues["ddl"].toArray();
    int len0 = issue_point.count();
    int len1 = issue_lasting.count();
    int len2 = issue_habit.count();
    int len3 = issue_task.count();
    int len = len0 + len1 + len2 + len3;
    for (int i = 0;i < len0;i++)
    {
        QJsonObject tmp = issue_point[i].toObject();
        long long id = tmp["ID"].toInteger();
        string name = tmp["name"].toString().toStdString();
        string discription = tmp["discription"].toString().toStdString();
        string position = tmp["position"].toString().toStdString();
        int repeat = tmp["repeat"].toInt();
        QJsonObject t = tmp["time"].toObject();
        int year = t["year"].toInt();
        int month = t["month"].toInt();
        int date = t["date"].toInt();
        int hour = t["hour"].toInt();
        int min = t["min"].toInt();
        TimeofIssue* tt = new TimeofIssue(year, month, date, hour, min);
        Issue* issue = new Issue_point(id, name, discription, position, repeat, tt);
        ls.push_back(issue);
        ls_0.push_back(issue);
    }
    for (int i = 0;i < len1;i++)
    {
        QJsonObject tmp = issue_lasting[i].toObject();
        long long id = tmp["ID"].toInteger();
        string name = tmp["name"].toString().toStdString();
        string discription = tmp["discription"].toString().toStdString();
        string position = tmp["position"].toString().toStdString();
        int repeat = tmp["repeat"].toInt();
        QJsonObject t = tmp["time"].toObject();
        QJsonObject edt = tmp["edtime"].toObject();
        int year = t["year"].toInt();
        int month = t["month"].toInt();
        int date = t["date"].toInt();
        int hour = t["hour"].toInt();
        int min = t["min"].toInt();
        int edyear = edt["year"].toInt();
        int edmonth = edt["month"].toInt();
        int eddate = edt["date"].toInt();
        int edhour = edt["hour"].toInt();
        int edmin = edt["min"].toInt();
        TimeofIssue* tt = new TimeofIssue(year, month, date, hour, min);
        TimeofIssue* et = new TimeofIssue(edyear, edmonth, eddate, edhour, edmin);
        Issue* issue = new Issue_lasting(id, name, discription, position, repeat, tt, et);
        ls.push_back(issue);
        ls_1.push_back(issue);
    }
    for (int i = 0;i < len2;i++)
    {
        QJsonObject tmp = issue_habit[i].toObject();
        long long id = tmp["ID"].toInteger();
        string name = tmp["name"].toString().toStdString();
        string discription = tmp["discription"].toString().toStdString();
        string position = tmp["position"].toString().toStdString();
        int repeat = tmp["repeat"].toInt();
        int alldays = tmp["alldays"].toInt();
        int fulfilleddays = tmp["fulfilleddays"].toInt();
        QJsonObject t = tmp["time"].toObject();
        int year = t["year"].toInt();
        int month = t["month"].toInt();
        int date = t["date"].toInt();
        int hour = t["hour"].toInt();
        int min = t["min"].toInt();
        TimeofIssue* tt = new TimeofIssue(year, month, date, hour, min);
        Issue* issue = new Issue_habit(id, name, discription, position, repeat, tt, alldays, fulfilleddays);
        ls.push_back(issue);
        ls_2.push_back(issue);
    }
    for (int i = 0;i < len3;i++)
    {
        QJsonObject tmp = issue_task[i].toObject();
        long long id = tmp["ID"].toInteger();
        string name = tmp["name"].toString().toStdString();
        string discription = tmp["discription"].toString().toStdString();
        string position = tmp["position"].toString().toStdString();
        int repeat = tmp["repeat"].toInt();
        QJsonObject t = tmp["time"].toObject();
        int year = t["year"].toInt();
        int month = t["month"].toInt();
        int date = t["date"].toInt();
        int hour = t["hour"].toInt();
        int min = t["min"].toInt();
        TimeofIssue* tt = new TimeofIssue(year, month, date, hour, min);
        Issue* issue = new Issue_task(id, name, discription, position, repeat, tt);
        ls.push_back(issue);
        ls_3.push_back(issue);
    }
    ls_0.sort();
    ls_1.sort();
    ls_2.sort();
    ls_3.sort();
    ls.sort();
}

void IssueList::writeData(string path)
{
    QJsonArray a_0, a_1, a_2, a_3;
    for (it i = ls_0.begin();i != ls_0.end();i++)
    {
        QJsonObject tmp, t;
        Issue* is = *i;
        tmp.insert("ID", is->getID());
        tmp.insert("name", QString::fromStdString(is->getName()));
        tmp.insert("discription", QString::fromStdString(is->getDiscription()));
        tmp.insert("position", QString::fromStdString(is->getPosition()));
        tmp.insert("repeat", is->getRepeat());
        t.insert("year", is->getYear());
        t.insert("month", is->getMonth());
        t.insert("date", is->getDate());
        t.insert("hour", is->getHour());
        t.insert("min", is->getMin());
        tmp.insert("time", t);
        a_0.append(tmp);
    }
    for (it i = ls_1.begin();i != ls_1.end();i++)
    {
        QJsonObject tmp, t, et;
        Issue* is = *i;
        tmp.insert("ID", is->getID());
        tmp.insert("name", QString::fromStdString(is->getName()));
        tmp.insert("discription", QString::fromStdString(is->getDiscription()));
        tmp.insert("position", QString::fromStdString(is->getPosition()));
        tmp.insert("repeat", is->getRepeat());
        t.insert("year", is->getYear());
        t.insert("month", is->getMonth());
        t.insert("date", is->getDate());
        t.insert("hour", is->getHour());
        t.insert("min", is->getMin());
        et.insert("year", is->getedYear());
        et.insert("month", is->getedMonth());
        et.insert("date", is->getedDate());
        et.insert("hour", is->getedHour());
        et.insert("min", is->getedMin());
        tmp.insert("time", t);
        tmp.insert("edtime", et);
        a_1.append(tmp);
    }
    for (it i = ls_2.begin();i != ls_2.end();i++)
    {
        QJsonObject tmp, t;
        Issue* is = *i;
        tmp.insert("ID", is->getID());
        tmp.insert("name", QString::fromStdString(is->getName()));
        tmp.insert("discription", QString::fromStdString(is->getDiscription()));
        tmp.insert("position", QString::fromStdString(is->getPosition()));
        tmp.insert("repeat", is->getRepeat());
        tmp.insert("alldays", is->getall_days());
        tmp.insert("fulfilleddays", is->getfulfilled_days());
        t.insert("year", is->getYear());
        t.insert("month", is->getMonth());
        t.insert("date", is->getDate());
        t.insert("hour", is->getHour());
        t.insert("min", is->getMin());
        tmp.insert("time", t);
        a_2.append(tmp);
    }
    for (it i = ls_3.begin();i != ls_3.end();i++)
    {
        QJsonObject tmp, t;
        Issue* is = *i;
        tmp.insert("ID", is->getID());
        tmp.insert("name", QString::fromStdString(is->getName()));
        tmp.insert("discription", QString::fromStdString(is->getDiscription()));
        tmp.insert("position", QString::fromStdString(is->getPosition()));
        tmp.insert("repeat", is->getRepeat());
        t.insert("year", is->getYear());
        t.insert("month", is->getMonth());
        t.insert("date", is->getDate());
        t.insert("hour", is->getHour());
        t.insert("min", is->getMin());
        tmp.insert("time", t);
        a_3.append(tmp);
    }
    QJsonObject obj;
    obj.insert("point", a_0);
    obj.insert("lasting", a_1);
    obj.insert("habit", a_2);
    obj.insert("ddl", a_3);
    QJsonDocument doc(obj);
    QByteArray json = doc.toJson();
    QFile file(path.c_str());
    file.open(QFile::WriteOnly);
    file.write(json);
    file.close();
}

void IssueList::addIssue(Issue* is)
{
    ls.push_back(is);
    if (is->getType() == 0)ls_0.push_back(is);
    else if (is->getType() == 1)ls_1.push_back(is);
    else if (is->getType() == 2)ls_2.push_back(is);
    else if (is->getType() == 3)ls_3.push_back(is);
    ls.sort();
    ls_0.sort();
    ls_1.sort();
    ls_2.sort();
    ls_3.sort();
}

void IssueList::deleteIssue(long long id)
{
    int type=0;
    Issue* tmp=NULL;
    for (it i = ls.begin();i != ls.end();i++)
    {
        Issue* is = *i;
        if (is->getID() == id)
        {
            type = is->getType();
            tmp = *i;
            ls.erase(i);
        }
    }
    if (type == 0)
    {
        for (it i = ls_0.begin();i != ls_0.end();i++)
        {
            Issue* is = *i;
            if (is->getID() == id)
                ls_0.erase(i);
        }
    }
    else if (type == 1)
    {
        for (it i = ls_1.begin();i != ls_1.end();i++)
        {
            Issue* is = *i;
            if (is->getID() == id)
                ls_1.erase(i);
        }
    }
    else if (type == 2)
    {
        for (it i = ls_2.begin();i != ls_2.end();i++)
        {
            Issue* is = *i;
            if (is->getID() == id)
                ls_2.erase(i);
        }
    }
    else if (type == 3)
    {
        for (it i = ls_3.begin();i != ls_3.end();i++)
        {
            Issue* is = *i;
            if (is->getID() == id)
                ls_3.erase(i);
        }
    }
    if(tmp!=NULL)
        delete tmp;

//QDebug()<<"delete error";
}

void IssueList::updateIssue(long long id, const Issue& it)
{

}

list<Issue*> IssueList::getIssues(TimeofIssue &tm){
    int flag=0;
    list<Issue*> ret;
    for(it i=ls.begin();i!=ls.end();i++){
        if(tm.judge_date_equal(*(*i)->getTimeofIssue())){
            flag=1;
            ret.push_back(*i);
        }
        else if(flag==1)break;
    }
    return ret;
}

#ifndef TIMEOFISSUE_H
#define TIMEOFISSUE_H


class TimeofIssue{//事件的时间信息
private:
    int m_year;//事件开始的年月日时分
    int m_month;
    int m_date;
    int m_hour;
    int m_min;

public:
    TimeofIssue(int year,int month,int date);//创建具体到日期的时间对象
    TimeofIssue(int year,int month,int date,int hour,int min);//创建具体到分钟的时间对象

    //设置年月日时分
    void setYear(int year);
    void setMonth(int month);
    void setDate(int date);
    void setHour(int hour);
    void setMin(int min);

    //获取年月日时分
    int getYear();
    int getMonth();
    int getDate();
    int getHour();
    int getMin();

    bool judge_date_equal(const TimeofIssue& other);//判断是否是同一天

    int getDuration(const TimeofIssue& other);//计算两个时间相差的天数

    friend bool operator<(const TimeofIssue& t1,const TimeofIssue& t2);
};

//并不需要这个
// class TimeofIssue_lasting:public TimeofIssue{//持续一段时间的事件的时间信息
// public:
//     int ed_year;//事件结束的年月日时分
//     int ed_month;
//     int ed_date;
//     int ed_hour;
//     int ed_min;
//     int last_time;//持续时间
//     TimeofIssue_lasting(int styear,int stmonth,int stdate,int sthour,int stmin,int edyear,int edmonth,int eddate,int edhour,int edmin):TimeofIssue(styear,stmonth,stdate,sthour,stmin);
// };

#endif // TIMEOFISSUE_H

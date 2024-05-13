#include<TimeofIssue.h>

bool isLeap(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            return year % 400 == 0;
        }
        return true;
    }
    return false;
}

int dayOfYear(int year, int month, int day)
{
    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (isLeap(year))
        days_in_month[1] = 29;
    int total_days = 0;
    for (int i = 0; i < month - 1; i++)
        total_days += days_in_month[i];
    total_days += day;
    return total_days;
}

void swap(int& num1, int& num2)
{
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
}

void TimeofIssue::setYear(int year){m_year=year;}
void TimeofIssue::setMonth(int month){m_month=month;}
void TimeofIssue::setDate(int date){m_date=date;}
void TimeofIssue::setHour(int hour){m_hour = hour;}
void TimeofIssue::setMin(int min) { m_min = min; }
int TimeofIssue::getYear() { return m_year; }
int TimeofIssue::getMonth() { return m_month; }
int TimeofIssue::getDate() { return m_year; }
int TimeofIssue::getHour() { return m_hour; }
int TimeofIssue::getMin() { return m_min; }

bool TimeofIssue::judge_date_equal(const TimeofIssue& other)
{
    return m_year == other.m_year && m_month == other.m_month && m_date == other.m_date;
}
int TimeofIssue::getDuration(const TimeofIssue& other)
{
    int year1, month1, day1, year2, month2, day2;
    year1 = m_year;
    month1 = m_month;
    day1 = m_date;
    year2 = other.m_year;
    month2 = other.m_month;
    day2 = other.m_date;
    if (year1 == year2 && month1 == month2 && day1 == day2)
        return 0;
    if (year1 > year2 || (year1 == year2 && month1 > month2) ||
        (year1 == year2 && month1 == month2 && day1 > day2))
    {
        swap(year1, year2);
        swap(month1, month2);
        swap(day1, day2);
    }
    int day_num1 = dayOfYear(year1, month1, day1);
    int day_num2 = dayOfYear(year2, month2, day2);
    if (year1 == year2)
        return day_num2 - day_num1;
    else
    {
        int days_in_year1 = isLeap(year1) ? 366 : 365;
        int days_between = days_in_year1 - day_num1 + day_num2;
        for (int year = year1 + 1; year < year2; year++)
        {
            days_between += isLeap(year) ? 366 : 365;
        }
        return days_between;
    }
}

bool operator<(const TimeofIssue& t1, const TimeofIssue& t2)
{
    if (t1.m_year != t2.m_year)return t1.m_year < t2.m_year;
    if (t1.m_month != t2.m_month)return t1.m_month < t2.m_month;
    if (t1.m_date != t2.m_date)return t1.m_date < t2.m_date;
    if (t1.m_hour != t2.m_hour)return t1.m_hour < t2.m_hour;
    return t1.m_min < t2.m_min;
}

TimeofIssue* getLocalTime()
{
    auto now = std::chrono::system_clock::now();
    // 转换为time_t类型，便于转换为本地时间
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    // 转换为本地时间
    std::tm* now_tm = std::localtime(&now_c);

    // 提取年、月、日、小时和分钟
    int year = 1900 + now_tm->tm_year; // tm_year是从1900年开始的年份偏移量
    int month = 1 + now_tm->tm_mon; // tm_mon是从0开始计数的月份
    int day = now_tm->tm_mday;
    int hour = now_tm->tm_hour;
    int minute = now_tm->tm_min;
    TimeofIssue* ret = new TimeofIssue(year, month, day, hour, minute);
    return ret;
}
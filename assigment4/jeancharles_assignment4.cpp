//Birth day countdown//


#include <iostream>
#include <ctime>
#include <iomanip>
#include <ctime>
#include <stdexcept>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class DateYear {
public:
    DateYear();
    DateYear(int m, int d, int y);
    void setDate(int m, int d, int y);
    void setMonth(int m);
    void setDay(int d);
    void setYear(int y);
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    int getDayOfYear() const;
    int BDCountdown() const;
    friend bool DateCompare(const DateYear& date1, const DateYear& date2);

private:
    int month;
    int day;
    int year;
    int DayOfYear() const;
};

DateYear::DateYear() {
    time_t t = time(NULL);
    struct tm timeInfo;
    localtime_s(&timeInfo, &t);
    month = timeInfo.tm_mon + 1;
    day = timeInfo.tm_mday;
    year = timeInfo.tm_year + 1900;
}


DateYear::DateYear(int m, int d, int y) {
    setDate(m, d, y);
}

void DateYear::setDate(int m, int d, int y) {
    setMonth(m);
    setDay(d);
    setYear(y);
}

void DateYear::setMonth(int m) {
    if (m >= 1 && m <= 12) {
        month = m;
    }
    else {
        cout << "Invalid month. Setting to 1.\n";
        month = 1;
    }
}

void DateYear::setDay(int d) {
    if (d >= 1 && d <= 31) {
        day = d;
    }
    else {
        cout << "Invalid day. Setting to 1.\n";
        day = 1;
    }
}

void DateYear::setYear(int y) {
    year = y;
}

int DateYear::getMonth() const {
    return month;
}

int DateYear::getDay() const {
    return day;
}

int DateYear::getYear() const {
    return year;
}

int DateYear::getDayOfYear() const {
    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int dayOfYear = day;
    for (int i = 0; i < month - 1; i++) {
        dayOfYear += daysInMonth[i];
    }
    if (month > 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        dayOfYear++;
    }
    return dayOfYear;
}
bool DateCompare(const DateYear& date1, const DateYear& date2) {
    return date1.year == date2.year;
}


int DateYear::BDCountdown() const {
    DateYear today;
    int currentDayOfYear = today.getDayOfYear();
    int birthdayDayOfYear = getDayOfYear();
    if (birthdayDayOfYear > currentDayOfYear) {
        return birthdayDayOfYear - currentDayOfYear;
    }
    else {
        return 365 - currentDayOfYear + birthdayDayOfYear;
    }
}

int main() {
    int month = 0, day = 0, year = 0;
    cout << "Please enter your birth month (mm): ";
    cin >> month;
    cout << "Please enter your birth day (dd): ";
    cin >> day;
    cout << "Please enter your birth year (yyyy): ";
    cin >> year;
    DateYear birthday(month, day, year);
    cout << "Your birthday is on " << month << "/" << day << "/" << year << endl;
    cout << "There are " << birthday.BDCountdown() << " days until your next birthday.\n";
    DateYear currentYear;
    if (DateCompare(birthday, currentYear)) {
        cout << "This is your birth year!" << endl;
        return 1;
    }
    
    
    return 0;
}

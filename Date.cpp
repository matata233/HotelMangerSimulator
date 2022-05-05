/**
 * Jia Jun Liu
 * 100353218
 * 2021-05-18
 * This .cpp file contains the implementation of a Date class.
 */
#include "Date.h"

/**
 * A default constructor of date 0/0/0 (dd/mm/yyyy)
 */
Date::Date() {
    day_ = 0;
    month_ = 0;
    year_ = 0;
}

/**
 * A helper function for checking if current year/entered year is a leap year
 * @return true if it is leap year
 */
bool Date::isLeapYear() const {
    if ((year_ % 4 == 0 && year_ % 100 != 0) || year_ % 400 == 0) {
        return true;
    }
    return false;
}

int Date::getDay() const {
    return day_;
}

void Date::setDay(int &day) {
    if (day < 0) {//set day to 1 for invalid input
        day_ = 1;
    } else if (day > 27)
        switch (month_) {
            case 1:
                if (day > 31) {
                    day_ = day - 31;
                    day = day_;
                    setDay(day);
                    setMonth(2);
                }
                break;
            case 2:
                if (isLeapYear()) {
                    if (day > 29) {
                        day_ = day - 29;
                        day = day_;
                        setDay(day);
                        setMonth(3);
                    }
                } else {
                    if (day > 28) {
                        day_ = day - 28;
                        day = day_;
                        setDay(day);
                        setMonth(3);
                    }
                }
                break;
            case 3:
                if (day > 31) {
                    day_ = day - 31;
                    day = day_;
                    setDay(day);
                    setMonth(4);
                }
                break;
            case 4:
                if (day > 30) {
                    day_ = day - 30;
                    day = day_;
                    setDay(day);
                    setMonth(5);
                }
                break;
            case 5:
                if (day > 31) {
                    day_ = day - 31;
                    day = day_;
                    setDay(day);
                    setMonth(6);
                }
                break;
            case 6:
                if (day > 30) {
                    day_ = day - 30;
                    day = day_;
                    setDay(day);
                    setMonth(7);
                }
                break;
            case 7:
                if (day > 31) {
                    day_ = day - 31;
                    day = day_;
                    setDay(day);
                    setMonth(8);
                }
                break;
            case 8:
                if (day > 31) {
                    day_ = day - 31;
                    day = day_;
                    setDay(day);
                    setMonth(9);
                }
                break;
            case 9:
                if (day > 30) {
                    day_ = day - 30;
                    day = day_;
                    setDay(day);
                    setMonth(2);
                }
                break;
            case 10:
                if (day > 31) {
                    day_ = day - 31;
                    day = day_;
                    setDay(day);
                    setMonth(11);
                }
                break;
            case 11:
                if (day > 30) {
                    day_ = day - 30;
                    day = day_;
                    setDay(day);
                    setMonth(12);
                }
                break;
            case 12:
                if (day > 31) {
                    day_ = day - 31;
                    setMonth(1);
                    setYear(year_ + 1);
                    day = day_;
                    setDay(day);
                }
                break;
        }
    else {
        day_ = day;
    }
}

int Date::getMonth() const {
    return month_;
}

void Date::setMonth(int month) {
    if (month < 0 || month > 12) {
        month_ = 1;
    } else {
        month_ = month;
    }
}

int Date::getYear() const {
    return year_;
}

void Date::setYear(int year) {
    year_ = year;
}

Date::Date(int day, int month, int year) {
    day_ = day;
    setMonth(month);
    year_ = year;
}

Date Date::getDate() const {
    return *this;
}
/**
 * A function that compare if both Date indicate the same date
 * @param date the date to be compared
 * @return true if day,month and year is same.
 */
bool Date::operator==(Date date) const {
    if (day_ == date.getDay() && month_ == date.getMonth() && year_ == date.getYear()) {
        return true;
    }
    return false;
}



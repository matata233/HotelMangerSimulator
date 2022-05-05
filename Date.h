/**
 * Jia Jun Liu
 * 100353218
 * 2021-05-18
 * This .h file contains the prototype of a Date class.
 */
#ifndef DATE_H
#define DATE_H

class Date {
private:
    int day_;
    int month_{};
    int year_;

    bool isLeapYear() const;

public:
    Date();

    Date(int day, int month, int year);

    bool operator==(Date) const;

    Date getDate() const;

    int getDay() const;

    void setDay(int &day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);
};


#endif //DATE_H

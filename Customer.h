/**
 * Jia Jun Liu
 * 100353218
 * 2021-05-18
 * This .h file contains the prototype of a Customer class.
 */
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Date.h"
#include "string"
class Customer {
private:
    Date inDate_;
    std::string customerId_;
    int nBeds_;
    int duration_;
public:
    Customer();

    Customer(Date, std::string&, int, int);

    void setInDate(const Date &inDate);

    void setCustomerId(const std::string &customerId);

    void setNBeds(int nBeds);

    void setDuration(int duration);

    std::string getCustomerId() const;

    Date getInDate()const;

    int getDuration()const;

    int getNBeds()const;
};


#endif //CUSTOMER_H

/**
 * Jia Jun Liu
 * 100353218
 * 2021-05-18
 * This .cpp file contains the implementation of a Customer class.
 */
#include "Customer.h"

/**
 * A default constructor that creates a customer
 */
Customer::Customer() {
    inDate_ = Date(0, 0, 0);
    customerId_ = "empty";
    nBeds_ = 0;
    duration_ = 0;
}

/**
 * A constructor that create a customer with specify check-in date, customer ID, the number of bed wanted, and the duration staying in the hotel
 * @param inDate the check-in date of the customer
 * @param customerId the unique ID of the customer
 * @param nBeds the number of beds wanted
 * @param duration days of the customer staying in the hotel
 */
Customer::Customer(Date inDate, std::string &customerId, int nBeds, int duration) {
    inDate_ = inDate;
    customerId_ = customerId;
    nBeds_ = nBeds;
    duration_ = duration;
}

std::string Customer::getCustomerId() const {
    return customerId_;
}

Date Customer::getInDate() const {
    return inDate_;
}

int Customer::getDuration() const {
    return duration_;
}

int Customer::getNBeds() const {
    return nBeds_;
}

void Customer::setInDate(const Date &inDate) {
    inDate_ = inDate;
}

void Customer::setCustomerId(const std::string &customerId) {
    customerId_ = customerId;
}

void Customer::setNBeds(int nBeds) {
    nBeds_ = nBeds;
}

void Customer::setDuration(int duration) {
    duration_ = duration;
}





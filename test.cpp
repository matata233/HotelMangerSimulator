/**
 * Jia Jun Liu
 * 100353218
 * 2021-05-18
 * Hotel Manager Simulator for
 * This program simulates a hotel that can optimize the arrangement for random customers requesting rooms and report the result.
 */
#include <iostream>
#include <fstream>
#include "Room.h"
#include "Customer.h"
#include "Hotel.h"
#include "Date.h"

/**
 * A function that initialize the simulated environment.
 * @param myHotel the hotel will be simulated
 * @param customers the provided and simulated the requests of random customers
 */
void construct(Hotel &myHotel, Queue<Customer> &customers) {
    //generate the required number of rooms for the assignment
    myHotel.add1BedR(100);
    myHotel.add2BedR(50);
    myHotel.add3BedR(30);

    std::ifstream in;
    in.open("Customers.txt");
    std::string msg;
    char c; //absorb "," and "/" in the txt file
    int num;
    Customer customer;
    Date date;

    //read and create a queue of customers for simulation
    if (in.is_open()) {
        std::getline(in, msg);
        while (!in.eof()) {
            in >> num;
            date.setDay(num);
            in >> c;
            in >> num;
            date.setMonth(num);
            in >> c;
            in >> num;
            date.setYear(num);
            in >> c;
            customer.setInDate(date);
            getline(in, msg, ',');
            customer.setCustomerId(msg.substr(1));
            in >> num;
            customer.setNBeds(num);
            in >> c;
            in >> num;
            customer.setDuration(num);
            customers.enqueue(customer);
        }
    }
}

/**
 * A function for processing customer check-in
 * @param myHotel the simulated hotel
 * @param customer the queue of incoming customers
 * @param tempRoom the room that satisfied the customer requests
 */
void takeIn(Hotel &myHotel, Customer &customer, Room &tempRoom) {
    tempRoom.checkIn(customer);
    myHotel.getOccupiedBedR().push_back(tempRoom);
}

/**
 * A function for processing customer check-out
 * @param myHotel the simulated hotel
 * @param currDate the current Date in the simulation
 */
void checkOut(Hotel &myHotel, Date &currDate) {
    for (unsigned int i = 0; i < myHotel.getOccupiedBedR().size(); i++) {
        Room temp = myHotel.getOccupiedBedR().at(i);
        if (temp.getOutDate() == currDate) { //if the check-out date of the occupant match the current date, check-out
            temp.checkOut();
            switch (temp.getNBeds()) { //add the empty room back to the queue according to the number of beds
                case 1:
                    myHotel.getUnoccupied1BedR().enqueue(temp);
                    break;
                case 2:
                    myHotel.getUnoccupied2BedR().enqueue(temp);
                    break;
                case 3:
                    myHotel.getUnoccupied3BedR().enqueue(temp);
                    break;
            }
            myHotel.getOccupiedBedR().erase(
                    myHotel.getOccupiedBedR().begin() + i);//remove the room from the occupied vector
        }
    }
}

/**
 * A function that optimize the room arrangement
 * @param myHotel the simulated hotel
 * @param customers the queue of incoming customers
 * @param nBedNeed the number of bed requested from the customer
 */
void roomArrange(Hotel &myHotel, Queue<Customer> &customers, int nBedNeed) {
    Customer customer = customers.dequeue();
    if (nBedNeed == 1) {
        if (!myHotel.getUnoccupied1BedR().isEmpty()) { //case: 1-bed room is available
            Room room = myHotel.getUnoccupied1BedR().dequeue();
            takeIn(myHotel, customer, room);
            myHotel.addNumServed(1);
        } else if (!myHotel.getUnoccupied2BedR().isEmpty()) { //case: 2-bed room is available
            Room room = myHotel.getUnoccupied2BedR().dequeue();
            takeIn(myHotel, customer, room);
            myHotel.addNumServed(1);
        } else if (!myHotel.getUnoccupied3BedR().isEmpty()) {//case: 3-bed room is available
            Room room = myHotel.getUnoccupied3BedR().dequeue();
            takeIn(myHotel, customer, room);
            myHotel.addNumServed(1);
        } else {
            std::cout << "Sorry, customer ID [" << customer.getCustomerId() << "]. "
                      << "All our rooms are full at the moment." << std::endl;
        }
    } else if (nBedNeed == 2) {
        if (!myHotel.getUnoccupied2BedR().isEmpty()) { //case: 2-bed room is available
            Room room = myHotel.getUnoccupied2BedR().dequeue();
            takeIn(myHotel, customer, room);
            myHotel.addNumServed(1);
        } else if (!myHotel.getUnoccupied3BedR().isEmpty()) {//case: 3-bed room is available
            Room room = myHotel.getUnoccupied3BedR().dequeue();
            takeIn(myHotel, customer, room);
            myHotel.addNumServed(1);
        } else if (myHotel.getUnoccupied1BedR().getSize() >=
                   2) {//case: 1-bed room is available and have 2 rooms available
            Room room1 = myHotel.getUnoccupied1BedR().dequeue();
            Room room2 = myHotel.getUnoccupied1BedR().dequeue();
            takeIn(myHotel, customer, room1);
            takeIn(myHotel, customer, room2);
            myHotel.addNumServed(1);
        } else {
            std::cout << "Sorry, customer ID [" << customer.getCustomerId() << "]. "
                      << "All our rooms are full at the moment." << std::endl;
        }
    } else if (nBedNeed == 3) {
        if (!myHotel.getUnoccupied3BedR().isEmpty()) { //case: 3-bed room is available
            Room room = myHotel.getUnoccupied3BedR().dequeue();
            takeIn(myHotel, customer, room);
            myHotel.addNumServed(1);
        } else if (myHotel.getUnoccupied2BedR().getSize() >=
                   2) { //case: 2-bed room is available and have 2 rooms available
            Room room1 = myHotel.getUnoccupied2BedR().dequeue();
            Room room2 = myHotel.getUnoccupied2BedR().dequeue();
            takeIn(myHotel, customer, room1);
            takeIn(myHotel, customer, room2);
            myHotel.addNumServed(1);
        } else if (myHotel.getUnoccupied1BedR().getSize() >=
                   3) { //case: 1-bed room is available and have 3 rooms available
            Room room1 = myHotel.getUnoccupied1BedR().dequeue();
            Room room2 = myHotel.getUnoccupied1BedR().dequeue();
            Room room3 = myHotel.getUnoccupied1BedR().dequeue();
            takeIn(myHotel, customer, room1);
            takeIn(myHotel, customer, room2);
            takeIn(myHotel, customer, room3);
            myHotel.addNumServed(1);
        } else {
            std::cout << "Sorry, customer ID [" << customer.getCustomerId() << "]. "
                      << "All our rooms are full at the moment." << std::endl;
        }
    }
}

/**
 * A function that run the simulation
 * @param myHotel the simulated hotel
 * @param customers the queue of incoming customers
 */
void run(Hotel &myHotel, Queue<Customer> &customers) {
    int timer = 1;
    Date currDate(1, 1, 2018); //set the starting date according to the txt file
    while (true) {
        if (customers.isEmpty()) {
            break;
        }
        checkOut(myHotel, currDate);
        if (customers.front().getInDate() == currDate) {
            roomArrange(myHotel, customers, customers.front().getNBeds());
        } else {
            timer++;
            currDate.setDay(timer);
        }
    }
}

/**
 * A function that report the number of customers have been served in the simulation
 * @param myHotel the simulated hotel
 */
void report(const Hotel &myHotel) {
    std::cout << std::endl;
    std::cout << "The total number of customers have been served is " << myHotel.getNumServed() << std::endl;
}

int main() {
    Hotel myHotel;
    Queue<Customer> customers;
    construct(myHotel, customers);
    int nbed = 0;
    int bed1 = 0;
    int bed2 = 0;
    int bed3 = 0;
    while (customers.getSize() >= 100000 - 141) {
        nbed = customers.front().getNBeds();
        if (nbed == 1) {
            bed1++;
        } else if (nbed == 2) {
            bed2++;
        } else if (nbed == 3) {
            bed3++;
        }
        customers.dequeue();
    }
    std::cout<<bed1<<std::endl;
    std::cout<<bed2<<std::endl;
    std::cout<<bed3<<std::endl;
    //run(myHotel, customers);
    //report(myHotel);
    return 0;
}

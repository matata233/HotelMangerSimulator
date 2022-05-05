/**
 * Jia Jun Liu
 * 100353218
 * 2021-05-18
 * This .cpp file contains the prototype of a Hotel class.
 */
#include "Hotel.h"
/**
 * Default constructor. Initialize the number of served customer to 0
 */
Hotel::Hotel() {
    nServed_ = 0;
}
/**
 * A function that add an indicated integer amount of one-bed room in the hotel
 * @param nRoom the number of one-bed room will be created
 */
void Hotel::add1BedR(int nRoom) {
    for (int i = 0; i < nRoom; i++) {
        unoccupied1BedR.enqueue(Room(1));
    }
}
/**
 * A function that add an indicated integer amount of two-bed room in the hotel
 * @param nRoom the number of two-bed room will be created
 */
void Hotel::add2BedR(int nRoom) {
    for (int i = 0; i < nRoom; i++) {
        unoccupied2BedR.enqueue(Room(2));
    }
}
/**
 * A function that add an indicated integer amount of three-bed room in the hotel
 * @param nRoom the number of three-bed room will be created
 */
void Hotel::add3BedR(int nRoom) {
    for (int i = 0; i < nRoom; i++) {
        unoccupied3BedR.enqueue(Room(3));
    }
}

std::vector<Room> &Hotel::getOccupiedBedR() {
    return occupiedBedR;
}

Queue<Room> &Hotel::getUnoccupied1BedR() {
    return unoccupied1BedR;
}

Queue<Room> &Hotel::getUnoccupied2BedR() {
    return unoccupied2BedR;
}

Queue<Room> &Hotel::getUnoccupied3BedR() {
    return unoccupied3BedR;
}

int Hotel::getNumServed() const {
    return nServed_;
}
/**
 * A function that update the number of customers that have been served in the hotel
 * @param num the number of customer(s)
 */
void Hotel::addNumServed(int num) {
    nServed_ += num;
}





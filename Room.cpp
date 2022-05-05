/**
 * Jia Jun Liu
 * 100353218
 * 2021-05-18
 * This .cpp file contains the implementation of a Room class.
 */

#include "Room.h"
/**
 * Default constructor
 */
Room::Room() {
    nBeds_ = 1;
}
/**
 * A constructor with indicated integer of beds
 * @param nBeds The number of beds that the room has
 */
Room::Room(int nBeds) {
    nBeds_ = nBeds;
}

std::string Room::getOccupantId() {
    return occupant_.front().getCustomerId();
}

int Room::getNBeds() const{
    return nBeds_;
}

void Room::setNBeds(int nBeds) {
    nBeds_ = nBeds;
}
/**
 * A function that return if the room is currently being occupied
 * @return true if the room is empty
 */
bool Room::isEmpty() {
    return occupant_.isEmpty();
}

Date Room::getInDate() {
    return occupant_.front().getInDate();
}

Date Room::getOutDate() {
    Date outDate = getInDate();
    int outDay = occupant_.front().getInDate().getDay() + occupant_.front().getDuration();
    outDate.setDay(outDay);
    return outDate;
}
/**
 * A function for occupant check-in.
 * @param customer the occupant of the room
 */
void Room::checkIn(Customer &customer) {
    occupant_.enqueue(customer);
}
/**
 * A function for occupant check-out.
 */
void Room::checkOut() {
    occupant_.dequeue();
}

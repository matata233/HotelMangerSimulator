/**
 * Jia Jun Liu
 * 100353218
 * 2021-05-18
 * This .h file contains the prototype of a Room class.
 */
#ifndef ROOM_H
#define ROOM_H
#include "string"
#include "Date.h"
#include "Customer.h"
#include "Queue.h"

class Room {
private:
    int nBeds_;
    Queue<Customer> occupant_;
public:
    Room();

    Room(int nBeds);

    bool isEmpty();

    std::string getOccupantId() ;

    Date getInDate() ;

    Date getOutDate() ;

    int getNBeds() const;

    void setNBeds(int nBeds);

    void checkIn(Customer &);

    void checkOut();

};


#endif //ROOM_H

/**
 * Jia Jun Liu
 * 100353218
 * 2021-05-18
 * This .h file contains the prototype of a Hotel class.
 */
#ifndef HOTEL_H
#define HOTEL_H
#include <vector>
#include "Queue.h"
#include "Room.h"

class Hotel {
private:
    int nServed_;
    std::vector<Room> occupiedBedR;
    Queue<Room> unoccupied1BedR;
    Queue<Room> unoccupied2BedR;
    Queue<Room> unoccupied3BedR;
public:
    Hotel();

    void add1BedR(int);

    void add2BedR(int);

    void add3BedR(int);

    std::vector<Room> &getOccupiedBedR();

    Queue<Room> &getUnoccupied1BedR();

    Queue<Room> &getUnoccupied2BedR();

    Queue<Room> &getUnoccupied3BedR();

    int getNumServed() const;

    void addNumServed(int num);
};


#endif //HOTEL_H

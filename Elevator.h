// Created by Cena Hasanzadeh on 5/26/2023 AD.
#ifndef ELEVATOR_H
#define ELEVATOR_H
#include <iostream>
class Elevator {
private:
    int currentFloor;
    const int maxFloor;
public:
    Elevator(int);
    void Move(int);
    int currentFloorShow() const;
};

#endif //ELEVATOR_H
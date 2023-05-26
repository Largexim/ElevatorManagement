// Created by Cena Hasanzadeh on 5/26/2023 AD.
#include "Elevator.h"
#include <iostream>
using namespace std;

Elevator::Elevator(int mF) : currentFloor(1) , maxFloor(mF) {};

void Elevator::Move(int requestedFloorNum)
{
    if(requestedFloorNum>maxFloor || requestedFloorNum<1)
    {
        cout << "Enter a valid floor!!\n";
    }

    else if(requestedFloorNum==currentFloor)
        cout<<"Elevator is here.Pleas open the dor.\n";

    else if(requestedFloorNum<currentFloor)
    {
        for(int i=currentFloor ; i!=requestedFloorNum ; i++ )
        {
            cout<<"Elevator is moving down to floor "<<i-1<<" ...\n";
            currentFloor = i;
        }
        cout<<"Elevator is in floor "<<requestedFloorNum<<" .\n";
        currentFloor = requestedFloorNum;
    }

    else if(requestedFloorNum>currentFloor)
    {
        for(int i=currentFloor ; i!=requestedFloorNum ; i++ )
        {
            cout<<"Elevator is moving up to floor "<<i+1<<" ...\n";
            currentFloor = i;
        }
        cout<<"Elevator is in floor "<<requestedFloorNum<<" .\n";
        currentFloor = requestedFloorNum;

    }
}

int Elevator::currentFloorShow() const
{
    cout<<"\nElevator is in floor "<<currentFloor<<" .\n";
    return currentFloor;
}

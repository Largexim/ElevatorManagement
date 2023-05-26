#include <iostream>
#include "Elevator.h"
using namespace std;
bool requestingElevator(Elevator &);
int main() {

    int floorCount;
    cout<<"How many floor building is? ";
    cin>>floorCount;
    Elevator mainElevator(floorCount);
    cout<<"building is done.\n";
    bool exit = true;
    while (exit)
    {
        exit = requestingElevator(mainElevator);
    }
}

bool requestingElevator(Elevator &mainElevator)
{
    int elevatorNeedCount;
    cout<<"\nHow many floors needs Elevator? ";
    cin>>elevatorNeedCount;

    if(elevatorNeedCount==0) return false;

    int elevatorNeed[elevatorNeedCount];
    cout<<"Done. Which floors needs Elevator? ";

    for(int i=0 ; i<elevatorNeedCount ; i++)
    {
        cin>>elevatorNeed[i];
    }

    int elevatorCurrentFloor = mainElevator.currentFloorShow();
    for(int j=elevatorNeedCount ; j>0 ; j--) {
        for (int i = 0; i < j-1 ; i++) {
            int first, next;
            first = elevatorCurrentFloor - elevatorNeed[i];
            if (first < 0)
                first *= -1;
            next = elevatorCurrentFloor - elevatorNeed[i + 1];
            if (next < 0)
                next *= -1;
            if (first > next) {
                int temp = elevatorNeed[i + 1];
                elevatorNeed[i + 1] = elevatorNeed[i];
                elevatorNeed[i] = temp;
            }
        }
    }

    for(int i=0 ; i<elevatorNeedCount ; i++)
    {
        mainElevator.Move(elevatorNeed[i]);
    }

    if (elevatorNeedCount>0) return true;
}

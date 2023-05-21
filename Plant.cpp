#include <iostream>
#include <string>
#include "Plant.hpp"

using namespace std;

// Plant class for managing plants
Plant::Plant(int id, string name, string location, int laborers, int capacity) {
    plantId = id;
    plantName = name;
    plantLoc = location;
    laborerCount = laborers;
    capacityPerMonth = capacity;
}
void Plant::getPlant() {
    cout<<"\n Plant Details...";
    cout<<"\n Plant Id: "<<plantId;
    cout<<"\n Plant Name: "<<plantName;
    cout<<"\n Plant Location: "<<plantLoc;
    cout<<"\n Laborer Count: "<< laborerCount;
    cout<<"\n Capacity Per Month: "<<capacityPerMonth;
}
int Plant::getPlantId() {
    return plantId;
}
string Plant::getPlantName() {
    return plantName;
}        
string Plant::getPlantLoc() {
    return plantLoc;
}
int Plant::getLabourerCount() {
    return laborerCount;
}
int Plant::getCapacityPerMonth() {
    return capacityPerMonth;
}
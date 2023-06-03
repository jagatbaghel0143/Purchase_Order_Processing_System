#include <iostream>
#include <string>
#include "headers/Plant.hpp"

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
int Plant::getLaborerCount() {
    return laborerCount;
}
int Plant::getCapacityPerMonth() {
    return capacityPerMonth;
}
void Plant::setPlantName(string name) {
    plantName = name;
}        
void Plant::setPlantLoc(string loc) {
    plantLoc = loc;
}
void Plant::setLaborerCount(int laborer) {
    laborerCount = laborer;
}
void Plant::setCapacityPerMonth(int capacity) {
    capacityPerMonth = capacity;
}
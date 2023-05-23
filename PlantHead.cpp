#include <iostream>
#include <string>
#include "PlantHead.hpp"

using namespace std;

// Plant class for managing plants
PlantHead::PlantHead(int id, string name, string password) {
    plantHeadId = id;
    plantHeadName = name;
    plantHeadPassword = password;
}
void PlantHead::getPlantHead() {
    cout<<"\n\t Plant Head Details...";
    cout<<"\n\t Plant Head Id: "<<plantHeadId;
    cout<<"\n\t Plant Head Name: "<<plantHeadName;
}
int PlantHead::getPlantHeadId() {
    return plantHeadId;
}
string PlantHead::getPlantHeadName() {
    return plantHeadName;
}        
string PlantHead::getPlantHeadPassword() {
    return plantHeadPassword;
}        
void PlantHead::setPlantHeadName(string name) {
    plantHeadName = name;
}
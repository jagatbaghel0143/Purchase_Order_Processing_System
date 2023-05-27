#include <iostream>
#include <string>
#include "PlantHead.hpp"

using namespace std;

// Plant class for managing plants
PlantHead::PlantHead(int id, string name, string password, bool isVerified, bool loggedIn) {
    plantHeadId = id;
    plantHeadName = name;
    plantHeadPassword = password;
    plantHeadIsVerified = isVerified;
    plantHeadLoggedIn = loggedIn;
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
bool PlantHead::getPlantHeadIsVerified() {
    return plantHeadIsVerified;
}    
bool PlantHead::getPlantHeadLoggedIn() {
    return plantHeadLoggedIn;
}    
string PlantHead::getPlantHeadPassword() {
    return plantHeadPassword;
}        
void PlantHead::setPlantHeadName(string name) {
    plantHeadName = name;
}
void PlantHead::setPlantHeadPassword(string password) {
    plantHeadPassword = password;
}
void PlantHead::setPlantHeadLoggedIn(bool loggedIn) {
    plantHeadLoggedIn = loggedIn;
}
void PlantHead::setPlantHeadIsVerified(bool isVerified) {
    plantHeadIsVerified = isVerified;
}
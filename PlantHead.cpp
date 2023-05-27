#include <iostream>
#include <string>
#include "PlantHead.hpp"

using namespace std;

// Plant class for managing plants
PlantHead::PlantHead(int id, string name, string password, string isVerified, string loggedIn) {
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
string PlantHead::getPlantHeadIsVerified() {
    return plantHeadIsVerified;
}    
string PlantHead::getPlantHeadLoggedIn() {
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
void PlantHead::setPlantHeadLoggedIn(string loggedIn) {
    plantHeadLoggedIn = loggedIn;
}
void PlantHead::setPlantHeadIsVerified(string isVerified) {
    plantHeadIsVerified = isVerified;
}
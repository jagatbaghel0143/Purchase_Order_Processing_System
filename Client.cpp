#include <iostream>
#include <string>
#include "headers/Client.hpp"

Client::Client(int ID, long number, std::string name, std::string location,
       std::string business, std::string password, string isApporvedAdmin, string verified, string loggedIn) {
        clientID = ID;
        clientNumber = number;
        clientName = name;
        clientLoc = location;
        primaryBusiness = business;
        clientPassword = password;
        isApprovedByAdmin = isApporvedAdmin;
        isVerified = verified;
        isloggedIn = loggedIn;
}

// Getters
int Client::getClientID(){
    return clientID;
}

long Client::getClientNumber(){
    return clientNumber;
}

std::string Client::getClientName(){
    return clientName;
}

std::string Client::getClientLocation(){
    return clientLoc;
}

std::string Client::getPrimaryBusiness(){
    return primaryBusiness;
}

std::string Client::getClientPassword(){
    return clientPassword;
}

string Client::isClientVerified(){
    return isVerified;
}

string Client::isClientLoggedIn(){
    return isloggedIn;
}

string Client::isClientApprovedByAdmin(){
    return isApprovedByAdmin;
}

// Setters
void Client::setClientID(int ID) {
    clientID = ID;
}

void Client::setClientNumber(long number) {
    clientNumber = number;
}

void Client::setClientName(std::string name) {
    clientName = name;
}

void Client::setClientLocation(std::string location) {
    clientLoc = location;
}

void Client::setPrimaryBusiness(std::string business) {
    primaryBusiness = business;
}

void Client::setClientPassword(std::string password) {
    clientPassword = password;
}

void Client::setClientVerified(string verified) {
    isVerified = verified;
}

void Client::setClientLoggedIn(string loggedIn) {
    isloggedIn = loggedIn;
}

void Client::setClientApprovedByAdmin(string approved) {
    isApprovedByAdmin = approved;
}
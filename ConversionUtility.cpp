#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "ConversionUtility.hpp"
#include "Plant.hpp"
#include "PlantHead.hpp"
#include "Client.hpp"

using namespace std;

// Public functions for general use
string ConversionUtility::convertPlantVectorToString(vector<Plant> plants) {
    stringstream ss;
    for (auto plant : plants) {
        ss << plant.getPlantId() << "," << plant.getPlantName() << "," << plant.getPlantLoc() << "," << plant.getLaborerCount() << "," << plant.getCapacityPerMonth() << "\n";
    }
    return ss.str();
}

vector<Plant> ConversionUtility::convertPlantStringToVector(string data) {
    vector<Plant> plants;
    stringstream ss(data);
    string line;
    while (getline(ss, line)) {
        stringstream lineStream(line);
        int id, laborers, capacity;
        string name, location;
        lineStream >> id;
        lineStream.ignore();
        getline(lineStream, name, ',');
        getline(lineStream, location, ',');
        lineStream >> laborers;
        lineStream.ignore();
        lineStream >> capacity;
        plants.emplace_back(id, name, location, laborers, capacity);
    }
    return plants;
}

string ConversionUtility::convertPlantHeadVectorToString(vector<PlantHead> plantHeads) {
    stringstream ss;
    for (auto plantHead : plantHeads) {
        ss << plantHead.getPlantHeadId() << "," << plantHead.getPlantHeadName() << "," << plantHead.getPlantHeadPassword()<<","<< plantHead.getPlantHeadIsVerified()<<","<<plantHead.getPlantHeadLoggedIn() <<"\n";
    }
    return ss.str();
}

vector<PlantHead> ConversionUtility::convertPlantHeadStringToVector(string data) {
    vector<PlantHead> plantHeads;
    stringstream ss(data);
    string line;
    while (getline(ss, line)) {
        stringstream lineStream(line);
        int id;
        string name, password, isLoggedIn, isVerified;
        lineStream >> id;
        lineStream.ignore();
        getline(lineStream, name, ',');
        getline(lineStream, password, ',');
        getline(lineStream, isVerified, ',');
        getline(lineStream, isLoggedIn, ',');
        plantHeads.emplace_back(id, name, password, isLoggedIn, isVerified);
    }
    return plantHeads;
}

string ConversionUtility::convertClientVectorToString(vector<Client> clients) {
    stringstream ss;
    for (auto client : clients) {
        ss << client.getClientID() << "," << client.getClientNumber() << "," << client.getClientName()<<","<< client.getClientLocation()<<","<<client.getPrimaryBusiness()<<","<<client.getClientPassword()<<","<<client.isClientVerified()<<","<<client.isClientApprovedByAdmin()<<","<<client.isClientLoggedIn()<<"\n";
    }
    return ss.str();
}

vector<Client> ConversionUtility::convertClientStringToVector(string data) {
    vector<Client> clients;
    stringstream ss(data);
    string line;
    while (getline(ss, line)) {
        stringstream lineStream(line);
        int clientID;
        long clientNumber;
        string clientName, clientLoc, primaryBusiness, clientPassword, isVerified, isloggedIn, isApprovedByAdmin;
        lineStream >> clientID;
        lineStream.ignore();
        lineStream >> clientNumber;
        lineStream.ignore();
        getline(lineStream, clientName, ',');
        getline(lineStream, clientLoc, ',');
        getline(lineStream, primaryBusiness, ',');
        getline(lineStream, clientPassword, ',');
        getline(lineStream, isApprovedByAdmin, ',');
        getline(lineStream, isVerified, ',');
        getline(lineStream, isloggedIn, ',');
        clients.emplace_back(clientID,clientNumber,clientName,clientLoc,primaryBusiness,clientPassword,isApprovedByAdmin,isVerified,isloggedIn);
    }
    return clients;
}
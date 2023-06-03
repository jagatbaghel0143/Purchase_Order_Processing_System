#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "headers/ConversionUtility.hpp"
#include "headers/Plant.hpp"
#include "headers/PlantHead.hpp"
#include "headers/Client.hpp"
#include "headers/Order.hpp"

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
        // plants.emplace_back(id, name, location, laborers, capacity);
        Plant plant(id, name, location, laborers, capacity);
        plants.push_back(plant);
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
        // plantHeads.emplace_back(id, name, password, isLoggedIn, isVerified);
        PlantHead head(id, name, password, isLoggedIn, isVerified);
        plantHeads.push_back(head);
    }
    return plantHeads;
}

string ConversionUtility::convertClientVectorToString(vector<Client> clients) {
    stringstream ss;
    for (auto client : clients) {
        ss << client.getClientID() << "," << client.getClientNumber() << "," << client.getClientName()<<","<< client.getClientLocation()<<","<<client.getPrimaryBusiness()<<","<<client.getClientPassword()<<","<<client.isClientApprovedByAdmin()<<","<<client.isClientVerified()<<","<<client.isClientLoggedIn()<<"\n";
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
        // clients.emplace_back(clientID,clientNumber,clientName,clientLoc,primaryBusiness,clientPassword,isApprovedByAdmin,isVerified,isloggedIn);
        Client client(clientID,clientNumber,clientName,clientLoc,primaryBusiness,clientPassword,isApprovedByAdmin,isVerified,isloggedIn);
        clients.push_back(client);
    }
    return clients;
}

string ConversionUtility::convertOrderVectorToString(vector<Order> orders) {
    stringstream ss;
    for (auto order : orders) {
        ss <<  order.getClientID() << "," <<  order.getOrderID() << "," <<  order.getProductName()<<","<<  order.getQuantity()<<","<< order.getOrderStatus()<<"\n";
    }
    return ss.str();
}

vector<Order> ConversionUtility::convertOrderStringToVector(string data) {
    vector<Order> orders;
    stringstream ss(data);
    string line;
    while (getline(ss, line)) {
        stringstream lineStream(line);
        int quantity, orderid, clientID;
        std::string productName, orderStatus;
        lineStream >> clientID;
        lineStream.ignore();
        lineStream >> orderid;
        lineStream.ignore();
        getline(lineStream, productName, ',');
        lineStream >> quantity;
        lineStream.ignore();
        getline(lineStream, orderStatus, ',');
        Order order(clientID,orderid,productName,quantity,orderStatus);
        orders.push_back(order);
    }
    return orders;
}

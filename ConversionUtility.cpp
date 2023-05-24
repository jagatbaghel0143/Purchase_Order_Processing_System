#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "ConversionUtility.hpp"
#include "Plant.hpp"
#include "PlantHead.hpp"

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
        ss << plantHead.getPlantHeadId() << "," << plantHead.getPlantHeadName() << "," << plantHead.getPlantHeadPassword()<< "\n";
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
        string name, password;
        lineStream >> id;
        lineStream.ignore();
        getline(lineStream, name, ',');
        getline(lineStream, password, ',');
        plantHeads.emplace_back(id, name, password);
    }
    return plantHeads;
}
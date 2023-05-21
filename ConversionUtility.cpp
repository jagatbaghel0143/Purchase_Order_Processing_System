#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "ConversionUtility.hpp"
#include "Plant.hpp"

using namespace std;

// Public functions for general use
string ConversionUtility::convertVectorToString(vector<Plant> plants) {
    stringstream ss;
    for (auto plant : plants) {
        ss << plant.getPlantId() << "," << plant.getPlantName() << "," << plant.getPlantLoc() << "," << plant.getLaborerCount() << "," << plant.getCapacityPerMonth() << "\n";
    }
    return ss.str();
}

vector<Plant> ConversionUtility::convertStringToVector(string data) {
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
#ifndef CONVERSIONUTILITY_HPP
#define CONVERSIONUTILITY_HPP
#include <vector>
#include <string>
#include "Plant.hpp"
#include "PlantHead.hpp"

using namespace std;

class ConversionUtility {
    public:
        vector<Plant> convertPlantStringToVector(string data);
        string convertPlantVectorToString(vector<Plant> plants);
        vector<PlantHead> convertPlantHeadStringToVector(string data);
        string convertPlantHeadVectorToString(vector<PlantHead> plantHeads);
};
#endif
#ifndef CONVERSIONUTILITY_HPP
#define CONVERSIONUTILITY_HPP
#include <vector>
#include <string>
#include "Plant.hpp"

using namespace std;

class ConversionUtility {
    public:
        vector<Plant> convertStringToVector(string data);
        string convertVectorToString(vector<Plant> plants);
};

#endif

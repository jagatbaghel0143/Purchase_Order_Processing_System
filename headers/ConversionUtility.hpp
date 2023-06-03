#ifndef CONVERSIONUTILITY_HPP
#define CONVERSIONUTILITY_HPP
#include <vector>
#include <string>
#include "Plant.hpp"
#include "PlantHead.hpp"
#include "Client.hpp"
#include "Order.hpp"
#include "Item.hpp"

using namespace std;

class ConversionUtility {
    public:
        vector<Plant> convertPlantStringToVector(string data);
        string convertPlantVectorToString(vector<Plant> plants);
        vector<PlantHead> convertPlantHeadStringToVector(string data);
        string convertPlantHeadVectorToString(vector<PlantHead> plantHeads);
        vector<Client> convertClientStringToVector(string data);
        string convertClientVectorToString(vector<Client> clients);
        vector<Order> convertOrderStringToVector(string data);
        string convertOrderVectorToString(vector<Order> orders);
        vector<Item> convertItemStringToVector(string data);
        string convertItemVectorToString(vector<Item> items);
};
#endif
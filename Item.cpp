#include <iostream>
#include "headers/Item.hpp"

Item::Item(int id, std::string name, std::string desc, std::string material, int time, int count, int cost) {
    itemID = id;
    laborerCount = count;
    timeRequired = time;
    manufacturingCostPerUnit = cost;
    itemName = name;
    description = desc;
    rawMaterialReq = material;
}

// Getters
int Item::getItemID() {
    return itemID;
}

int Item::getLaborerCount() {
    return laborerCount;
}

int Item::getTimeRequired() {
    return timeRequired;
}

int Item::getManufacturingCostPerUnit() {
    return manufacturingCostPerUnit;
}

std::string Item::getItemName() {
    return itemName;
}

std::string Item::getDescription() {
    return description;
}

std::string Item::getRawMaterialReq() {
    return rawMaterialReq;
}

// Setters
void Item::setItemID(int id) {
    itemID = id;
}

void Item::setLaborerCount(int count) {
    laborerCount = count;
}

void Item::setTimeRequired(int time) {
    timeRequired = time;
}

void Item::setManufacturingCostPerUnit(int cost) {
    manufacturingCostPerUnit = cost;
}

void Item::setItemName(std::string name) {
    itemName = name;
}

void Item::setDescription(std::string desc) {
    description = desc;
}

void Item::setRawMaterialReq(std::string material) {
    rawMaterialReq = material;
}
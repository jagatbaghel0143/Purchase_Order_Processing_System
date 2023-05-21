#include <iostream>
#include <string>
#include <vector>
#include <Plant.hpp>
#include <ConversionUtility.hpp>
// #include "ReadAndWrite.hpp"
#include <Administration.hpp>
using namespace std;

// Administration class for managing  admin activities
void Administration::addPlant() {
    int id = time(nullptr);
    string name;
    string loc;
    int laborers;
    int capacity;
    cout<<"\n"<<"Enter Plant Name: ";
    cin>>name;
    cout<<"Enter Plant Location: ";
    cin>>loc;
    cout<<"Enter Loborer Count: ";
    cin>>laborers;
    cout<<"Enter Capacity Per Month: ";
    cin>>capacity;
    Plant plant(id, name, loc, laborers, capacity);
    ReadAndWrite readAndWrite;
    string data = readAndWrite.readDataFromFile();
    ConversionUtility conversionUtility;
    vector<Plant> plants = conversionUtility.convertStringToVector(data);
    plants.emplace_back(plant);
    data = conversionUtility.convertVectorToString(plants);
    readAndWrite.writeDataToFile(data);
    int idd = plant.getPlantId();
    cout<<"\nNew manufacturing unit with ID #"<<idd<<" is added successfully!\n";
    cin.get();
}
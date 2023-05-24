#include <iostream>
#include <string>
#include <vector>
#include "ConversionUtility.hpp"
#include "ReadAndWrite.hpp"
#include "AdministrationHead.hpp"
#include "RandomStringGenerator.hpp"
#include "PlantHead.hpp"

using namespace std;

static ConversionUtility conversionUtility;
static ReadAndWrite readAndWrite;
RandomStringGenerator randomStringGenerator;

void AdministrationHead::addPlantHead() {
    system("clear");
    const int LENGTH = 10;
    int id = time(nullptr);
    string name;
    cout<<"\n\t\tEnter Plant Head Name: ";
    cin>>name;
    string password;
    password = randomStringGenerator.generateRandomString(LENGTH) ;
    PlantHead plantHead(id, name, password);
    string data = readAndWrite.readDataFromFile("plantHeadDetails.txt");
    vector<PlantHead> plantHeads = conversionUtility.convertPlantHeadStringToVector(data);
    plantHeads.emplace_back(plantHead);
    data = conversionUtility.convertPlantHeadVectorToString(plantHeads);
    if(readAndWrite.writeDataToFile(data, "plantHeadDetails.txt")) {
        cout<<"\n\tNew Plant Head with User ID # "<< id <<" and password : " << password <<" is added successfully!";
        cout<<"\n\tPlease Note Your Id and password";
    } else {
        cout<<"\n\t\tError while adding new plant";
    }
    cout<<"\n\t\tPress ENTER to continue...";
    cin.ignore();
    cin.get();
}

void AdministrationHead::updatePlantHead() {
    system("clear");
    int plantHeadId;
    cout<<"\t\tEnter Plant Head ID which you want to update: ";
    cin>>plantHeadId;
    bool flag = true, updateStatus = false;
    string data = readAndWrite.readDataFromFile("plantHeadDetails.txt");
    vector<PlantHead> plantHeads = conversionUtility.convertPlantHeadStringToVector(data);
    for(auto i = plantHeads.begin(); i != plantHeads.end(); ++i) {
        if(i->getPlantHeadId() == plantHeadId) {
            string name,loc;
            int count, capacity, choice = -1;
            flag = false;
            while(1) {
                cout<<"\t\tCurrent Plant Heaad Details are as follows:";
                cout<<"\n\t\tPlant Head Id: "<<i->getPlantHeadId();
                cout<<"\n\t\t1. Plant Head Name: "<<i->getPlantHeadName();
                cout<<"\n\t\t2. Save";
                cout<<"\nEnter your choice to update [1,2]: ";
                cin>>choice;
            
                switch(choice) {
                    case 1:
                        cout<<"\t\tEnter New Plant Head Name: ";
                        cin>>name;
                        i->setPlantHeadName(name);
                        break;

                    default:
                        break;
                }
                if(choice == 2) {
                    break;
                } else if ((choice > 0)  && (choice < 5)) {
                    updateStatus = true;
                }
            }
            if(updateStatus) {
                if(readAndWrite.writeDataToFile(conversionUtility.convertPlantHeadVectorToString(plantHeads), "plantHeadDetails.txt")) {
                    cout<<"\n\t\tPlant details updated successfully!\n\n";
                }else {
                cout<<"\nError while updating plant details...";
                }
            }
        }
    }
    if(flag) {
        cout << "\n\t\tOpps! No plant exists with this #"<<plantHeadId<<" Id\n\n";
    }
    cout<<"Press ENTER to continue...";
    cin.ignore();
    cin.get();
}

void AdministrationHead::deletePlantHead() {
    system("clear");
    // int plantId;
    // cout<<"Enter Plant ID which you want to delete: ";
    // cin>>plantId;
    // bool flag = true, updateStatus = false;
    // string data = readAndWrite.readDataFromFile();
    // vector<Plant> plant = conversionUtility.convertStringToVector(data);
    // for(auto i = plant.begin(); i != plant.end(); ++i) {
    //     if(i->getPlantId() == plantId) {
    //         int choice = -1;
    //         flag = false;
    //         cout<<"\t\tPlant Details are as follows:";
    //         cout<<"\n\t\tPlant Id: "<<i->getPlantId();
    //         cout<<"\n\t\tPlant Name: "<<i->getPlantName();
    //         cout<<"\n\t\tPlant Location: "<<i->getPlantLoc();
    //         cout<<"\n\t\tLaborer Count: "<<i->getLaborerCount();
    //         cout<<"\n\t\tCapacity Per Month: "<<i->getCapacityPerMonth();
    //         cout<<"\n\n\t\tAre you sure you want to delete it...";
    //         cout<<"\n\t\t1. YES";
    //         cout<<"\n\t\t2. NO";
    //         cout<<"\nEnter your choice to update [1,2]: ";
    //         cin>>choice;

    //         switch(choice) {
    //             case 1:
    //                 plant.erase(i);
    //                 break;
    //             default:
    //                 break;
    //         }
    //         if(choice == 2) {
    //             break;
    //         } else if ((choice > 0)  && (choice < 2)) {
    //             updateStatus = true;
    //         }
    //         if(updateStatus) {
    //             if(readAndWrite.writeDataToFile(conversionUtility.convertVectorToString(plant))) {
    //                 cout<<"\n\t\tPlant with id #"<<plantId<<" deleted successfully!\n\n";
    //             }else {
    //             cout<<"\nError while deleting plant details...";
    //             }
    //         }
    //         break;
    //     }
    // }
    // if(flag) {
    //     cout << "\n\t\tOpps! No plant exists with this #"<<plantId<<" Id\n\n";
    // }
    // cout<<"Press ENTER to continue...";
    // cin.ignore();
    // cin.get();
}

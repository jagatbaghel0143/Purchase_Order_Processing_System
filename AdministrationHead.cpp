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
    string data = readAndWrite.readDataFromFile("plantHeadDeatils.txt");
    vector<PlantHead> plantHeads = conversionUtility.convertPlantHeadStringToVector(data);
    plantHeads.emplace_back(plantHead);
    data = conversionUtility.convertPlantHeadVectorToString(plantHeads);
    if(readAndWrite.writeDataToFile(data, "plantHeadDeatils.txt")) {
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
    // int plantId;
    // cout<<"\t\tEnter Plant ID which you want to update: ";
    // cin>>plantId;
    // bool flag = true, updateStatus = false;
    // string data = readAndWrite.readDataFromFile();
    // vector<Plant> plant = conversionUtility.convertStringToVector(data);
    // for(int i=0; i<plant.size(); ++i) {
    //     if(plant.at(i).getPlantId() == plantId) {
    //         string name,loc;
    //         int count, capacity, choice = -1;
    //         flag = false;
    //         while(1) {
    //             cout<<"\t\tCurrent Plant Details are as follows:";
    //             cout<<"\n\t\tPlant Id: "<<plant.at(i).getPlantId();
    //             cout<<"\n\t\t1. Plant Name: "<<plant.at(i).getPlantName();
    //             cout<<"\n\t\t2. Plant Location: "<<plant.at(i).getPlantLoc();
    //             cout<<"\n\t\t3. Laborer Count: "<<plant.at(i).getLaborerCount();
    //             cout<<"\n\t\t4. Capacity Per Month: "<<plant.at(i).getCapacityPerMonth();
    //             cout<<"\n\t\t5. Save";
    //             cout<<"\nEnter your choice to update [1,2,3,4,5]: ";
    //             cin>>choice;
            
    //             switch(choice) {
    //                 case 1:
    //                     cout<<"\t\tEnter New Plant Name: ";
    //                     cin>>name;
    //                     plant.at(i).setPlantName(name);
    //                     break;
                    
    //                 case 2:
    //                     cout<<"\t\tEnter New Plant Location: ";
    //                     cin>>loc;
    //                     plant.at(i).setPlantLoc(loc);
    //                     break;
                    
    //                 case 3:
    //                     cout<<"\t\tEnter New Laborer Count: ";
    //                     cin>>count;
    //                     plant.at(i).setLaborerCount(count);
    //                     break;
                    
    //                 case 4:
    //                     cout<<"\t\tEnter New Capacity Per Month: ";
    //                     cin>>capacity;
    //                     plant.at(i).setCapacityPerMonth(capacity);
    //                     break;
    //                 default:
    //                     break;
    //             }
    //             if(choice == 5) {
    //                 break;
    //             } else if ((choice > 0)  && (choice < 5)) {
    //                 updateStatus = true;
    //             }
    //         }
    //         if(updateStatus) {
    //             if(readAndWrite.writeDataToFile(conversionUtility.convertVectorToString(plant))) {
    //                 cout<<"\n\t\tPlant details updated successfully!\n\n";
    //             }else {
    //             cout<<"\nError while updating plant details...";
    //             }
    //         }
    //     }
    // }
    // if(flag) {
    //     cout << "\n\t\tOpps! No plant exists with this #"<<plantId<<" Id\n\n";
    // }
    // cout<<"Press ENTER to continue...";
    // cin.ignore();
    // cin.get();
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

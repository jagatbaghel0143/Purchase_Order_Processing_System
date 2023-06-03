#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "headers/Plant.hpp"
#include "headers/ConversionUtility.hpp"
#include "headers/ReadAndWrite.hpp"
#include "headers/Administration.hpp"
using namespace std;

ConversionUtility conversionUtility;
ReadAndWrite readAndWrite;

// Administration class for managing  admin activities
void Administration::addPlant() {
    system("clear");
    int id = time(nullptr);
    string name;
    string loc;
    int laborers;
    int capacity;
    std::cout<<"\n\t\tEnter Plant Name: ";
    std::cin>>name;
    std::cout<<"\t\tEnter Plant Location: ";
    std::cin>>loc;
    std::cout<<"\t\tEnter Loborer Count: ";
    std::cin>>laborers;
    std::cout<<"\t\tEnter Capacity Per Month: ";
    std::cin>>capacity;
    Plant plant(id, name, loc, laborers, capacity);
    string data = readAndWrite.readDataFromFile("plants.txt");
    vector<Plant> plants = conversionUtility.convertPlantStringToVector(data);
    plants.push_back(plant);
    data = conversionUtility.convertPlantVectorToString(plants);
    if(readAndWrite.writeDataToFile(data, "plants.txt")) {
        int idd = plant.getPlantId();
        std::cout<<"\n\tNew manufacturing unit with ID #"<<idd<<" is added successfully!";
    } else {
        std::cout<<"\n\t\tError while adding new plant";
    }
    std::cout<<"\n\t\tPress ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}

void Administration::updatePlant() {
    system("clear");
    int plantId;
    std::cout<<"\t\tEnter Plant ID which you want to update: ";
    std::cin>>plantId;
    bool flag = true, updateStatus = false;
    string data = readAndWrite.readDataFromFile("plants.txt");
    vector<Plant> plant = conversionUtility.convertPlantStringToVector(data);
    for(auto i = plant.begin(); i != plant.end(); ++i) {
        if(i->getPlantId() == plantId) {
            string name,loc;
            int count, capacity, choice = -1;
            flag = false;
            while(1) {
                std::cout<<"\t\tCurrent Plant Details are as follows:";
                std::cout<<"\n\t\tPlant Id: "<<i->getPlantId();
                std::cout<<"\n\t\t1. Plant Name: "<<i->getPlantName();
                std::cout<<"\n\t\t2. Plant Location: "<<i->getPlantLoc();
                std::cout<<"\n\t\t3. Laborer Count: "<<i->getLaborerCount();
                std::cout<<"\n\t\t4. Capacity Per Month: "<<i->getCapacityPerMonth();
                std::cout<<"\n\t\t5. Save";
                std::cout<<"\nEnter your choice to update [1,2,3,4,5]: ";
                std::cin>>choice;
            
                switch(choice) {
                    case 1:
                        std::cout<<"\t\tEnter New Plant Name: ";
                        std::cin>>name;
                        i->setPlantName(name);
                        break;
                    
                    case 2:
                        std::cout<<"\t\tEnter New Plant Location: ";
                        std::cin>>loc;
                        i->setPlantLoc(loc);
                        break;
                    
                    case 3:
                        std::cout<<"\t\tEnter New Laborer Count: ";
                        std::cin>>count;
                        i->setLaborerCount(count);
                        break;
                    
                    case 4:
                        std::cout<<"\t\tEnter New Capacity Per Month: ";
                        std::cin>>capacity;
                        i->setCapacityPerMonth(capacity);
                        break;
                    default:
                        break;
                }
                if(choice == 5) {
                    break;
                } else if ((choice > 0)  && (choice < 5)) {
                    updateStatus = true;
                }
            }
            if(updateStatus) {
                if(readAndWrite.writeDataToFile(conversionUtility.convertPlantVectorToString(plant), "plants.txt")) {
                    std::cout<<"\n\t\tPlant details updated successfully!\n\n";
                }else {
                std::cout<<"\nError while updating plant details...";
                }
            }
        }
    }
    if(flag) {
        std::cout << "\n\t\tOpps! No plant exists with this #"<<plantId<<" Id\n\n";
    }
    std::cout<<"Press ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}

void Administration::deletePlant() {
    system("clear");
    int plantId;
    std::cout<<"Enter Plant ID which you want to delete: ";
    std::cin>>plantId;
    bool flag = true, updateStatus = false;
    string data = readAndWrite.readDataFromFile("plants.txt");
    vector<Plant> plant = conversionUtility.convertPlantStringToVector(data);
    for(auto i = plant.begin(); i != plant.end(); ++i) {
        if(i->getPlantId() == plantId) {
            int choice = -1;
            flag = false;
            std::cout<<"\t\tPlant Details are as follows:";
            std::cout<<"\n\t\tPlant Id: "<<i->getPlantId();
            std::cout<<"\n\t\tPlant Name: "<<i->getPlantName();
            std::cout<<"\n\t\tPlant Location: "<<i->getPlantLoc();
            std::cout<<"\n\t\tLaborer Count: "<<i->getLaborerCount();
            std::cout<<"\n\t\tCapacity Per Month: "<<i->getCapacityPerMonth();
            std::cout<<"\n\n\t\tAre you sure you want to delete it...";
            std::cout<<"\n\t\t1. YES";
            std::cout<<"\n\t\t2. NO";
            std::cout<<"\nEnter your choice to update [1,2]: ";
            std::cin>>choice;

            switch(choice) {
                case 1:
                    plant.erase(i);
                    break;
                default:
                    break;
            }
            if(choice == 2) {
                break;
            } else if ((choice > 0)  && (choice < 2)) {
                updateStatus = true;
            }
            if(updateStatus) {
                if(readAndWrite.writeDataToFile(conversionUtility.convertPlantVectorToString(plant),"plants.txt")) {
                    std::cout<<"\n\t\tPlant with id #"<<plantId<<" deleted successfully!\n\n";
                }else {
                std::cout<<"\nError while deleting plant details...";
                }
            }
            break;
        }
    }
    if(flag) {
        std::cout << "\n\t\tOpps! No plant exists with this #"<<plantId<<" Id\n\n";
    }
    std::cout<<"Press ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}

void Administration::searchPlant() {
    system("clear");
    string plantNameOrLoc;
    std::cout<<"Enter Plant name or location to search OR enter (*) to view all plants: ";
    std::cin>>plantNameOrLoc;
    bool flag = true;
    string data = readAndWrite.readDataFromFile("plants.txt");
    vector<Plant> plant = conversionUtility.convertPlantStringToVector(data);
    if(plant.size() > 0) {
        if(plantNameOrLoc == "*") {
            int index = 1;
            flag = false;
            for(auto i = plant.begin(); i != plant.end(); ++i, ++index) {
                std::cout<<"\t\t" + index << ". Plant Details are as follows:";
                std::cout<<"\n\t\tPlant Id: "<<i->getPlantId();
                std::cout<<"\n\t\tPlant Name: "<<i->getPlantName();
                std::cout<<"\n\t\tPlant Location: "<<i->getPlantLoc();
                std::cout<<"\n\t\tLaborer Count: "<<i->getLaborerCount();
                std::cout<<"\n\t\tCapacity Per Month: "<<i->getCapacityPerMonth()<<endl<<endl;
            }
        } else {
            for(auto i = plant.begin(); i != plant.end(); ++i) {
                if(i->getPlantName() == plantNameOrLoc || i->getPlantLoc() == plantNameOrLoc) {
                    flag = false;
                    std::cout<<"\t\tPlant Details are as follows:";
                    std::cout<<"\n\t\tPlant Id: "<<i->getPlantId();
                    std::cout<<"\n\t\tPlant Name: "<<i->getPlantName();
                    std::cout<<"\n\t\tPlant Location: "<<i->getPlantLoc();
                    std::cout<<"\n\t\tLaborer Count: "<<i->getLaborerCount();
                    std::cout<<"\n\t\tCapacity Per Month: "<<i->getCapacityPerMonth()<<endl<<endl;
                }
            }

        }
    }
    if(flag) {
        std::cout << "\n\t\tOpps! No plant exists with this Name or Location";
    }
    std::cout<<"\n\t\tPress ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}

void Administration::viewOrders() {
    system("clear");
    string data = readAndWrite.readDataFromFile("orders.txt");
    vector<Order> orders = conversionUtility.convertOrderStringToVector(data);
    std::cout<<"\n\t\t***********************************************";
    std::cout<<"\n\t\t*    Recent Order Details are as follows      *";
    std::cout<<"\n\t\t***********************************************";
    for(auto i = orders.begin(); i != orders.end(); ++i) {
        std::cout<<"\n\t\t\tClient Id: "<<i->getClientID();
        std::cout<<"\n\t\t\tOrder ID: "<<i->getOrderID();
        std::cout<<"\n\t\t\tItem Name: "<<i->getProductName();
        std::cout<<"\n\t\t\tQuantity: "<<i->getQuantity();
        std::cout<<"\n\t\t\tOrder Status: "<<i->getOrderStatus();
        std::cout<<"\n\t\t***********************************************";
        
    }
    std::cout<<"\n\t\tPress ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}

void Administration::viewRequests() {
    system("clear");
    string data = readAndWrite.readDataFromFile("clientDetails.txt");
    vector<Client> clients = conversionUtility.convertClientStringToVector(data);
    if(clients.size()>0) {
        std::cout<<"\n\t\tClient Requests are as follows(if any): ";
    }
    bool noPendingRequest=true;
    for(auto i = clients.begin(); i != clients.end(); ++i) {
        if(i->isClientApprovedByAdmin() == "pending") {
            noPendingRequest = false;
            std::cout<<"\n\t\tID                : "<<i->getClientID();
            std::cout<<"\n\t\tMobile Number     : "<<i->getClientNumber();
            std::cout<<"\n\t\tName              : "<<i->getClientName();
            std::cout<<"\n\t\tLocation          : "<<i->getClientLocation();
            std::cout<<"\n\t\tPrimary Business  : "<<i->getPrimaryBusiness();
            std::cout<<"\n\t\tApproved By Admin : "<<i->isClientApprovedByAdmin();
            std::cout<<"\n\t\t***************************************************";
        }
    }
    if(noPendingRequest) {
        std::cout<<"\n\t\tNo Pending request available!";
    }
    std::cout<<"\n\t\tPress ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}

void Administration::approveDenyRequest() {
    system("clear");
    int clientID=-1;
    std::cout<<"\n \t\tEnter Client ID : ";
    std::cin>>clientID;
    string data = readAndWrite.readDataFromFile("clientDetails.txt");
    vector<Client> clients = conversionUtility.convertClientStringToVector(data);
    int choice=-1;
    for(auto i = clients.begin(); i != clients.end(); ++i) {
        if(clientID == i->getClientID()) {
            if(i->isClientApprovedByAdmin() == "pending") {
                std::cout<<"\n\t\t***********************************";
                std::cout<<"\n\t\t*       Want to Approve Or Deny   *";
                std::cout<<"\n\t\t***********************************";
                std::cout<<"\n\t\t*           1. Approve            *";
                std::cout<<"\n\t\t*           2. Deny               *";
                std::cout<<"\n\t\t*           3. Back               *";
                std::cout<<"\n\t\t***********************************";
                std::cout<<"\n\t\tEnter your choice [1,2,3]: " ;
                std::cin>>choice;
                switch(choice) {
                    case 1:
                        i->setClientApprovedByAdmin("true");
                        break;

                    case 2:
                        i->setClientApprovedByAdmin("false");
                        break;

                    default :
                        break;
                }
                break;
            }
        }
    }
    if(choice == -1) {
        std::cout<<"\n\t\tNo request exists with this Id";
    } else if (choice == 1 || choice == 2){
        data = conversionUtility.convertClientVectorToString(clients);
        if(readAndWrite.writeDataToFile(data, "clientDetails.txt")) {
            if(choice == 1) {
                std::cout<<"\n\t\tClient Request Approved Successfully!";
            } else {
                std::cout<<"\n\t\tClient Request Denied!";
            }
        } else {
            std::cout<<"\n\t\tError while approving request!";
        }
    }
    std::cout<<"\n\t\tPress ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}
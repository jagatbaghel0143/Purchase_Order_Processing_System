#include <iostream>
#include <string>
#include <vector>
#include "ConversionUtility.hpp"
#include "ReadAndWrite.hpp"
#include "ClientManagement.hpp"
#include "RandomStringGenerator.hpp"
#include "Client.hpp"

using namespace std;

static ConversionUtility conversionUtility;
static ReadAndWrite readAndWrite;
static RandomStringGenerator randomStringGenerator;

void ClientManagement::addClient() {
    system("clear");
    const int LENGTH = 10;
    int clientID = time(nullptr);
    long clientNumber;
    string clientName, clientLoc, primaryBusiness, clientPassword;
    bool isVerified, isloggedIn, isApprovedByAdmin;
    cout<<"\t\t1. Enter Name: ";
    std::cin>>clientName;
    cout<<"\t\t2. Enter Location: ";
    std::cin>>clientLoc;
    cout<<"\t\t3. Enter Primary Business: ";
    std::cin>>primaryBusiness;
    cout<<"\t\t4. Enter Contact Number: ";
    std::cin>>clientNumber;
    clientPassword = randomStringGenerator.generateRandomString(LENGTH) ;
    Client client(clientID, clientNumber, clientName, clientLoc, primaryBusiness, clientPassword, "false", "false", "false");
    string data = readAndWrite.readDataFromFile("clientDetails.txt");
    vector<Client> clients = conversionUtility.convertClientStringToVector(data);
    clients.emplace_back(client);
    data = conversionUtility.convertClientVectorToString(clients);
    if(readAndWrite.writeDataToFile(data, "clientDetails.txt")) {
        cout<<"\n\tNew Plant Head with User ID # "<< clientID <<" and password : " << clientPassword <<" is added successfully!";
        cout<<"\n\tPlease Note Your Id and password and you will be able to login after admin approval";
    } else {
        cout<<"\n\t\tError while adding new plant";
    }
    cout<<"\n\t\tPress ENTER to continue...";
    cin.ignore();
    cin.get();
}

void ClientManagement::updateClient() {
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

void ClientManagement::deleteClient() {
    system("clear");
    int plantId;
    cout<<"Enter Plant Head ID which you want to delete: ";
    cin>>plantId;
    bool flag = true, updateStatus = false;
    string data = readAndWrite.readDataFromFile("plantHeadDetails.txt");
    vector<PlantHead> plantHeads = conversionUtility.convertPlantHeadStringToVector(data);
    for(auto i = plantHeads.begin(); i != plantHeads.end(); ++i) {
        if(i->getPlantHeadId() == plantId) {
            int choice = -1;
            flag = false;
            cout<<"\t\tPlant Head Details are as follows:";
            cout<<"\n\t\tPlant Head Id: "<<i->getPlantHeadId();
            cout<<"\n\t\tPlant Head Name: "<<i->getPlantHeadName();
            cout<<"\n\n\t\tAre you sure you want to delete it...";
            cout<<"\n\t\t1. YES";
            cout<<"\n\t\t2. NO";
            cout<<"\nEnter your choice to update [1,2]: ";
            cin>>choice;

            switch(choice) {
                case 1:
                    plantHeads.erase(i);
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
                if(readAndWrite.writeDataToFile(conversionUtility.convertPlantHeadVectorToString(plantHeads), "plantHeadDetails.txt")) {
                    cout<<"\n\t\tPlant with id #"<<plantId<<" deleted successfully!\n\n";
                }else {
                cout<<"\nError while deleting plant details...";
                }
            }
            break;
        }
    }
    if(flag) {
        cout << "\n\t\tOpps! No plant exists with this #"<<plantId<<" Id\n\n";
    }
    cout<<"Press ENTER to continue...";
    cin.ignore();
    cin.get();
}

#include <iostream>
#include <string>
#include <vector>
#include "ConversionUtility.hpp"
#include "ReadAndWrite.hpp"
#include "ClientManagement.hpp"
#include "RandomStringGenerator.hpp"
#include "Client.hpp"
#include "Order.hpp"

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
    std::cout<<"\t\t1. Enter Name: ";
    std::cin>>clientName;
    std::cout<<"\t\t2. Enter Location: ";
    std::cin>>clientLoc;
    std::cout<<"\t\t3. Enter Primary Business: ";
    std::cin>>primaryBusiness;
    std::cout<<"\t\t4. Enter Contact Number: ";
    std::cin>>clientNumber;
    clientPassword = randomStringGenerator.generateRandomString(LENGTH) ;
    Client client(clientID, clientNumber, clientName, clientLoc, primaryBusiness, clientPassword, "pend", "false", "false");
    string data = readAndWrite.readDataFromFile("clientDetails.txt");
    vector<Client> clients = conversionUtility.convertClientStringToVector(data);
    clients.push_back(client);
    data = conversionUtility.convertClientVectorToString(clients);
    if(readAndWrite.writeDataToFile(data, "clientDetails.txt")) {
        std::cout<<"\n\tNew Plant Head with User ID # "<< clientID <<" and password : " << clientPassword <<" is added successfully!";
        std::cout<<"\n\tPlease Note Your Id and password and you will be able to login after admin approval";
    } else {
        std::cout<<"\n\t\tError while adding new plant";
    }
    std::cout<<"\n\t\tPress ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}

void ClientManagement::updateClient() {
    system("clear");
    int plantHeadId;
    std::cout<<"\t\tEnter Plant Head ID which you want to update: ";
    std::cin>>plantHeadId;
    bool flag = true, updateStatus = false;
    string data = readAndWrite.readDataFromFile("clientDetails.txt");
    vector<PlantHead> plantHeads = conversionUtility.convertPlantHeadStringToVector(data);
    for(auto i = plantHeads.begin(); i != plantHeads.end(); ++i) {
        if(i->getPlantHeadId() == plantHeadId) {
            string name,loc;
            int count, capacity, choice = -1;
            flag = false;
            while(1) {
                std::cout<<"\t\tCurrent Plant Heaad Details are as follows:";
                std::cout<<"\n\t\tPlant Head Id: "<<i->getPlantHeadId();
                std::cout<<"\n\t\t1. Plant Head Name: "<<i->getPlantHeadName();
                std::cout<<"\n\t\t2. Save";
                std::cout<<"\nEnter your choice to update [1,2]: ";
                std::cin>>choice;
            
                switch(choice) {
                    case 1:
                        std::cout<<"\t\tEnter New Plant Head Name: ";
                        std::cin>>name;
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
                    std::cout<<"\n\t\tPlant details updated successfully!\n\n";
                }else {
                std::cout<<"\nError while updating plant details...";
                }
            }
        }
    }
    if(flag) {
        std::cout << "\n\t\tOpps! No plant exists with this #"<<plantHeadId<<" Id\n\n";
    }
    std::cout<<"Press ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}

void ClientManagement::deleteClient() {
    system("clear");
    int plantId;
    std::cout<<"Enter Plant Head ID which you want to delete: ";
    std::cin>>plantId;
    bool flag = true, updateStatus = false;
    string data = readAndWrite.readDataFromFile("clientDetails.txt");
    vector<PlantHead> plantHeads = conversionUtility.convertPlantHeadStringToVector(data);
    for(auto i = plantHeads.begin(); i != plantHeads.end(); ++i) {
        if(i->getPlantHeadId() == plantId) {
            int choice = -1;
            flag = false;
            std::cout<<"\t\tPlant Head Details are as follows:";
            std::cout<<"\n\t\tPlant Head Id: "<<i->getPlantHeadId();
            std::cout<<"\n\t\tPlant Head Name: "<<i->getPlantHeadName();
            std::cout<<"\n\n\t\tAre you sure you want to delete it...";
            std::cout<<"\n\t\t1. YES";
            std::cout<<"\n\t\t2. NO";
            std::cout<<"\nEnter your choice to update [1,2]: ";
            std::cin>>choice;

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

void ClientManagement::checkStatus() {
    system("clear");
    int clientID=-1;
    std::cout<<"\n \t\tEnter Client ID : ";
    std::cin>>clientID;
    string data = readAndWrite.readDataFromFile("clientDetails.txt");
    vector<Client> clients = conversionUtility.convertClientStringToVector(data);
    for(auto i = clients.begin(); i != clients.end(); ++i) {
        if(to_string(clientID) == to_string(i->getClientID())) {
            if(i->isClientApprovedByAdmin() == "true") {
                std::cout<<"\n\t\tCongratulations! Account is approved by Admin";
            } else if (i->isClientApprovedByAdmin() == "false"){
                std::cout<<"\n\t\tSorry, Your account is NOT approved by Admin!";
            } else {
                std::cout<<"\n\t\tYour account is NOT approved by Admin till now!";
            }
            break;
        }
    }
    std::cout<<"Press ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}

void ClientManagement::activityClient() {
    while(1) {
        system("clear");
        std::cout<<"\n\t\t***************************************************************";
        std::cout<<"\n\t\t*             Welcome to Client Dashboard                     *";
        std::cout<<"\n\t\t***************************************************************";
        std::cout<<"\n\t\t*             1. Generate Purchase Order                      *";
        std::cout<<"\n\t\t*             2. View Purchase Order Status                   *";
        std::cout<<"\n\t\t*             3. Logout                                       *";
        std::cout<<"\n\t\t***************************************************************";
        std::cout<<"\n\t\tEnter your choice[1,2,3]: ";
        int choice = -1;
        std::cin>>choice;
        switch(choice) {
            case 1:
                generateOrder();
                break;

            case 2:
                viewOrder();
                break;

            default:
                std::cout<<"\n\t\tLogged out successfully! See you soon again!\n";
                break;
        }
        if(choice == 3) {
            break;
        }
    }
}

void ClientManagement::generateOrder() {
    system("clear");
    int quantity=0, cID=-1;
    string pName="";
    string id = to_string(time(nullptr));
    id = id.substr(id.length() - 5);
    int orderid = stoi(id);
    std::cout<<"\n\t\tEnter client id : ";
    std::cin>>cID;
    std::cout<<"\n\t\tEnter item name : ";
    std::cin>>pName;
    std::cout<<"\n\t\tEnter quantity : ";
    std::cin>>quantity;
    std::cout<<"\t\t\t-------------------------------------------";
    Order order(cID, orderid, pName, quantity, "pending");
    string data = readAndWrite.readDataFromFile("orders.txt");
    vector<Order> orders = conversionUtility.convertOrderStringToVector(data);
    orders.push_back(order);
    data = conversionUtility.convertOrderVectorToString(orders);
    if(readAndWrite.writeDataToFile(data, "orders.txt")) {
        std::cout<<"\n\t\tYour order with orderid #" << orderid <<" is successfully placed!";
    } else {
        std::cout<<"\n\t\tError while placing your order";
    }
    std::cout<<"\n\t\tPress ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
    
}

void ClientManagement::viewOrder() {
    system("clear");
    int orderID;
    std::cout<<"\t\tEnter Order ID : ";
    std::cin>>orderID;
    bool flag = true;
    string data = readAndWrite.readDataFromFile("orders.txt");
    vector<Order> orders = conversionUtility.convertOrderStringToVector(data);
    for(auto i = orders.begin(); i != orders.end(); ++i) {
        if(i->getOrderID() == orderID) {
            flag = false;
            std::cout<<"\n\t\t***********************************************";
            std::cout<<"\n\t\t*       Order Details are as follows          *";
            std::cout<<"\n\t\t***********************************************";
            std::cout<<"\n\t\t\tClient Id: "<<i->getClientID();
            std::cout<<"\n\t\t\tOrder ID: "<<i->getOrderID();
            std::cout<<"\n\t\t\tItem Name: "<<i->getProductName();
            std::cout<<"\n\t\t\tQuantity: "<<i->getQuantity();
            std::cout<<"\n\t\t\tOrder Status: "<<i->getOrderStatus();
            std::cout<<"\n\t\t***********************************************";
        
        }
    }
    if(flag) {
        std::cout << "\n\t\tOpps! No order exists with this #"<<orderID<<" Id";
    }
    std::cout<<"\n\t\tPress ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}

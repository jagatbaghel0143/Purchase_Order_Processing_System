#include <iostream>
#include <string>
#include <vector>
#include "headers/ReadAndWrite.hpp"
#include "headers/ConversionUtility.hpp"
#include "headers/Order.hpp"
#include "headers/PlantHeadActivity.hpp"
#include "headers/Item.hpp"

static ReadAndWrite readAndWrite;
static ConversionUtility conversionUtility;


void PlantHeadActivity::viewPurchaseOrder() {
    system("clear");
    string data = readAndWrite.readDataFromFile("Resources/orders.txt");
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

void PlantHeadActivity::addItem() {
    system("clear");
    string name, desc, material;
    int manufacturingTime, count, cost;
    string id = to_string(time(nullptr));
    id = id.substr(id.length() - 5);
    int itemID = stoi(id);
    std::cout<<"\n\t\tEnter item name : ";
    std::cin>>name;
    std::cout<<"\n\t\tEnter item description : ";
    std::cin>>desc;
    std::cout<<"\n\t\tEnter raw material used with underscore(_) separated values without space: ";
    std::cin>>material;
    std::cout<<"\n\t\tEnter maufacturing time in Hours: ";
    std::cin>>manufacturingTime;
    std::cout<<"\n\t\tEnter laborer count: ";
    std::cin>>count;
    std::cout<<"\n\t\tEnter manufacturing cost per unit: ";
    std::cin>>cost;

    Item item(itemID, name, desc, material, manufacturingTime, count, cost);
    string data = readAndWrite.readDataFromFile("Resources/items.txt");
    vector<Item> items = conversionUtility.convertItemStringToVector(data);
    items.push_back(item);
    data = conversionUtility.convertItemVectorToString(items);
    if(readAndWrite.writeDataToFile(data, "Resources/items.txt")) {
        std::cout<<"\n\t\tItem with itemid #" << id <<" is added successfully!";
    } else {
        std::cout<<"\n\t\tError while adding item";
    }
    std::cout<<"\n\t\tPress ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}

void PlantHeadActivity::updateItem() {
    system("clear");
    int itemId;
    std::cout<<"\t\tEnter Item ID which you want to update: ";
    std::cin>>itemId;
    bool flag = true, updateStatus = false;
    string data = readAndWrite.readDataFromFile("Resources/items.txt");
    vector<Item> items = conversionUtility.convertItemStringToVector(data);
    for(auto i = items.begin(); i != items.end(); ++i) {
        if(i->getItemID() == itemId) {
            string name,desc, material;
            int count, time, choice = -1, cost;
            flag = false;
            while(1) {
                std::cout<<"\t\tCurrent Item Details are as follows:";
                std::cout<<"\n\t\tItem Id: "<<i->getItemID();
                std::cout<<"\n\t\t1. Item Name: "<<i->getItemName();
                std::cout<<"\n\t\t2. Item Description: "<<i->getDescription();
                std::cout<<"\n\t\t3. Raw Material Required: "<<i->getRawMaterialReq();
                std::cout<<"\n\t\t4. Manufacturing Time: "<<i->getTimeRequired();
                std::cout<<"\n\t\t5. Laborer Count: "<<i->getLaborerCount();
                std::cout<<"\n\t\t6. Manufacturing Cost Per Unit: "<<i->getLaborerCount();
                std::cout<<"\n\t\t7. Save";
                std::cout<<"\nEnter your choice to update [1,2,3,4,5,6,7]: ";
                std::cin>>choice;
            
                switch(choice) {
                    case 1:
                        std::cout<<"\t\tEnter New Item Name: ";
                        std::cin>>name;
                        i->setItemName(name);
                        break;
                    
                    case 2:
                        std::cout<<"\t\tEnter New Item Description: ";
                        std::cin>>desc;
                        i->setDescription(desc);
                        break;
                    
                    case 3:
                        std::cout<<"\t\tEnter New Raw Material Required: ";
                        std::cin>>material;
                        i->setRawMaterialReq(material);
                        break;
                    
                    case 4:
                        std::cout<<"\t\tEnter New Manufacturing time required: ";
                        std::cin>>time;
                        i->setTimeRequired(time);
                        break;

                    case 5:
                        std::cout<<"\t\tEnter New Laborer count required: ";
                        std::cin>>count;
                        i->setLaborerCount(count);
                        break;

                    case 6:
                        std::cout<<"\t\tEnter New Manufacturing cost: ";
                        std::cin>>cost;
                        i->setManufacturingCostPerUnit(cost);
                        break;

                    default:
                        break;
                }
                if(choice == 7) {
                    break;
                } else if ((choice > 0)  && (choice < 7)) {
                    updateStatus = true;
                }
            }
            if(updateStatus) {
                if(readAndWrite.writeDataToFile(conversionUtility.convertItemVectorToString(items), "Resources/items.txt")) {
                    std::cout<<"\n\t\tItem details updated successfully!\n\n";
                }else {
                std::cout<<"\nError while updating item details...";
                }
            }
        }
    }
    if(flag) {
        std::cout << "\n\t\tOpps! No item exists with this #"<<itemId<<" Id\n\n";
    }
    std::cout<<"Press ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}

void PlantHeadActivity::deleteItem() {
    system("clear");
    int itemId;
    std::cout<<"Enter Item ID which you want to delete: ";
    std::cin>>itemId;
    bool flag = true, updateStatus = false;
    string data = readAndWrite.readDataFromFile("Resources/items.txt");
    vector<Item> items = conversionUtility.convertItemStringToVector(data);
    for(auto i = items.begin(); i != items.end(); ++i) {
        if(i->getItemID() == itemId) {
            int choice = -1;
            flag = false;
            std::cout<<"\t\tCurrent Item Details are as follows:";
            std::cout<<"\n\t\tItem Id: "<<i->getItemID();
            std::cout<<"\n\t\t1. Item Name: "<<i->getItemName();
            std::cout<<"\n\t\t2. Item Description: "<<i->getDescription();
            std::cout<<"\n\t\t3. Raw Material Required: "<<i->getRawMaterialReq();
            std::cout<<"\n\t\t4. Manufacturing Time: "<<i->getTimeRequired();
            std::cout<<"\n\t\t5. Laborer Count: "<<i->getLaborerCount();
            std::cout<<"\n\t\t6. Manufacturing Cost Per Unit: "<<i->getLaborerCount();
            std::cout<<"\n\n\t\tAre you sure you want to delete it...";
            std::cout<<"\n\t\t1. YES";
            std::cout<<"\n\t\t2. NO";
            std::cout<<"\nEnter your choice to update [1,2]: ";
            std::cin>>choice;

            switch(choice) {
                case 1:
                    items.erase(i);
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
                if(readAndWrite.writeDataToFile(conversionUtility.convertItemVectorToString(items),"Resources/items.txt")) {
                    std::cout<<"\n\t\tItem with id #"<<itemId<<" deleted successfully!\n\n";
                }else {
                std::cout<<"\nError while deleting item details...";
                }
            }
            break;
        }
    }
    if(flag) {
        std::cout << "\n\t\tOpps! No plant exists with this #"<<itemId<<" Id\n\n";
    }
    std::cout<<"Press ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}

void PlantHeadActivity::viewItems() {
    system("clear");
    string data = readAndWrite.readDataFromFile("Resources/items.txt");
    vector<Item> items = conversionUtility.convertItemStringToVector(data);
    std::cout<<"\n\t\t***********************************************";
    std::cout<<"\n\t\t*         Items list are as follows           *";
    std::cout<<"\n\t\t***********************************************";
    for(auto i = items.begin(); i != items.end(); ++i) {
        std::cout<<"\n\t\t\t1. Item Id: "<<i->getItemID();
        std::cout<<"\n\t\t\t2. Item Name: "<<i->getItemName();
        std::cout<<"\n\t\t\t3. Item Description: "<<i->getDescription();
        std::cout<<"\n\t\t\t4. Raw Material Required: "<<i->getRawMaterialReq();
        std::cout<<"\n\t\t\t5. Manufacturing Time: "<<i->getTimeRequired();
        std::cout<<"\n\t\t\t6. Laborer Count: "<<i->getLaborerCount();
        std::cout<<"\n\t\t\t7. Manufacturing Cost Per Unit: "<<i->getLaborerCount();
        std::cout<<"\n\t\t***********************************************";
        
    }
    std::cout<<"\n\t\tPress ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}
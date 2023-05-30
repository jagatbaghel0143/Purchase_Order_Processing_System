#include <iostream>
#include <string>
#include <vector>
#include "ReadAndWrite.hpp"
#include "ConversionUtility.hpp"
#include "Order.hpp"
#include "PlantHeadActivity.hpp"

static ReadAndWrite readAndWrite;
static ConversionUtility conversionUtility;


void PlantHeadActivity::viewPurchaseOrder() {
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

void PlantHeadActivity::addItem() {

    std::cout<<"\n\t\tAdd Items functionality will include soon";
    std::cin.ignore();
    std::cin.get();
}

void PlantHeadActivity::updateItem() {
    std::cout<<"\n\t\tUpdate Items functionality will include soon";
    std::cin.ignore();
    std::cin.get();
}

void PlantHeadActivity::deleteItem() {
    std::cout<<"\n\t\tDelete Items functionality will include soon";
    std::cin.ignore();
    std::cin.get();
}

void PlantHeadActivity::viewItems() {
    std::cout<<"\n\t\tView Items functionality will include soon";
    std::cin.ignore();
    std::cin.get();
}
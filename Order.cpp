#include <string>
#include "headers/Order.hpp"

Order::Order(int cID, int oid, std::string pName,int quan, std::string oStatus) {
    quantity = quan;
    orderid = oid;
    clientID = cID;
    productName = pName;
    orderStatus = oStatus;
}

// Getters
int Order::getQuantity() {
    return quantity;
}

int Order::getOrderID() {
    return orderid;
}

int Order::getClientID() {
    return clientID;
}

std::string Order::getProductName() {
    return productName;
}

std::string Order::getOrderStatus() {
    return orderStatus;
}

// Setters
void Order::setQuantity(int newQuantity) {
    quantity = newQuantity;
}

void Order::setOrderID(int newOrderID) {
    orderid = newOrderID;
}

void Order::setClientID(int newClientID) {
    clientID = newClientID;
}

void Order::setProductName(std::string newProductName) {
    productName = newProductName;
}

void Order::setOrderStatus(std::string newOrderStatus) {
    orderStatus = newOrderStatus;
}

#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>

class Order {
    private:
        int quantity, orderid, clientID;
        std::string productName, orderStatus;

    public:
        Order(int clientID, int orderid, std::string productName, int quantity, std::string orderStatus);
        int getQuantity();
        int getOrderID();
        int getClientID();
        std::string getProductName();
        std::string getOrderStatus();
        void setQuantity(int quant);
        void setOrderID(int orderid);
        void setClientID(int clientid);
        void setProductName(std::string pName);
        void setOrderStatus(std::string status);
                
};
#endif
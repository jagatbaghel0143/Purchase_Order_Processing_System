#ifndef ADMINISTRATION_HPP
#define ADMINISTRATION_HPP

#include "User.hpp"
#include "ReadAndWrite.hpp"

using namespace std;

class Administration : public User {
    public:
        void addPlant();
        void updatePlant();
        void deletePlant();
        void searchPlant();
        void viewOrders();
        void viewRequests();
        void approveDenyRequest();
};
#endif
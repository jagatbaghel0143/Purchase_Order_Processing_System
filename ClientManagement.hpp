#ifndef CLIENTMANAGEMENT_HPP
#define CLIENTMANAGEMENT_HPP

#include "User.hpp"

using namespace std;

class ClientManagement : public User {
    public:
        void addClient();
        void updateClient();
        void deleteClient();
        void checkStatus();
        void activityClient();
};
#endif
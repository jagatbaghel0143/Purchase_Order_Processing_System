#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "User.hpp"
#include <string>

using namespace std;

class Client : public User {
    private:
        int clientID;
        long clientNumber;
        string clientName, clientLoc, primaryBusiness, clientPassword, isVerified, isloggedIn, isApprovedByAdmin;

    public:
        Client(int ID, long number, const std::string name, std::string location,
        std::string business, std::string password, string isApprovedByAdmin, string isVerified, string isloggedIn);
        int getClientID();
        long getClientNumber();
        std::string getClientName();
        std::string getClientLocation();
        std::string getPrimaryBusiness();
        std::string getClientPassword();
        string isClientVerified();
        string isClientLoggedIn();
        string isClientApprovedByAdmin();
        void setClientID(int ID);
        void setClientNumber(long number);
        void setClientName(std::string& name);
        void setClientLocation(std::string& location);
        void setPrimaryBusiness(std::string& business);
        void setClientPassword(std::string& password);
        void setClientVerified(string verified);
        void setClientLoggedIn(string loggedIn);
        void setClientApprovedByAdmin(string approved);
};
#endif
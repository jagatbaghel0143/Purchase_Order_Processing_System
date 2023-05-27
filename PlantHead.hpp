#ifndef PLANTHEAD_HPP
#define PLANTHEAD_HPP

#include <string>

using namespace std;

class PlantHead {
    private:
        int plantHeadId;
        string plantHeadName;
        string plantHeadPassword;
        bool plantHeadIsVerified;
        bool plantHeadLoggedIn;

    public:
        PlantHead(int id, string name, string password, bool isVerified, bool loggedIn);
        void getPlantHead();
        int getPlantHeadId();
        string getPlantHeadName();
        string getPlantHeadPassword();
        bool getPlantHeadIsVerified();
        bool getPlantHeadLoggedIn();
        void setPlantHeadName(string name);
        void setPlantHeadPassword(string password);
        void setPlantHeadIsVerified(bool isVerified);
        void setPlantHeadLoggedIn(bool loggedIn);
};
#endif
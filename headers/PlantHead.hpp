#ifndef PLANTHEAD_HPP
#define PLANTHEAD_HPP

#include <string>

using namespace std;

class PlantHead {
    private:
        int plantHeadId;
        string plantHeadName, plantHeadPassword, plantHeadIsVerified, plantHeadLoggedIn;

    public:
        PlantHead(int id, string name, string password, string isVerified, string loggedIn);
        void getPlantHead();
        int getPlantHeadId();
        string getPlantHeadName();
        string getPlantHeadPassword();
        string getPlantHeadIsVerified();
        string getPlantHeadLoggedIn();
        void setPlantHeadName(string name);
        void setPlantHeadPassword(string password);
        void setPlantHeadIsVerified(string isVerified);
        void setPlantHeadLoggedIn(string loggedIn);
};
#endif
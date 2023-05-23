#ifndef PLANTHEAD_HPP
#define PLANTHEAD_HPP

#include <string>

using namespace std;

class PlantHead {
    private:
        int plantHeadId;
        string plantHeadName;
        string plantHeadPassword;

    public:
        PlantHead(int id, string name, string password);
        void getPlantHead();
        int getPlantHeadId();
        string getPlantHeadName();
        string getPlantHeadPassword();
        void setPlantHeadName(string name);
};
#endif
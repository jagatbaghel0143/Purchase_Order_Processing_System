#ifndef PLANT_HPP
#define PLANT_HPP

#include <string>

using namespace std;

class Plant {
    private:
        int plantId;
        string plantName;
        string plantLoc;
        int laborerCount;
        int capacityPerMonth;

    public:
        Plant(int id, const string name, const string location, int laborers, int capacity);
        void getPlant();
        int getPlantId();
        string getPlantName();        
        string getPlantLoc();
        int getLaborerCount();
        int getCapacityPerMonth();
        void setPlantName(string name);        
        void setPlantLoc(string loc);
        void setLaborerCount(int laborer);
        void setCapacityPerMonth(int capacity);
};
#endif
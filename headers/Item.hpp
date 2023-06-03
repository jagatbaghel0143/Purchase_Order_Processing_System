#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <vector>

class Item {
    private:
        int itemID, laborerCount, timeRequired, manufacturingCostPerUnit;
        std::string itemName, description, rawMaterialReq;

    public:
        Item(int itemID, std::string itemName, std::string description, std::string rawMaterialReq, int timeRequired, int laborerCount, int manufacturingCostPerUnit);

        int getItemID();
        int getLaborerCount();
        int getTimeRequired();
        int getManufacturingCostPerUnit();
        std::string getItemName();
        std::string getDescription();
        std::string getRawMaterialReq();
        void setItemID(int id);
        void setLaborerCount(int count);
        void setTimeRequired(int time);
        void setManufacturingCostPerUnit(int cost);
        void setItemName(const std::string name);
        void setDescription(std::string desc);
        void setRawMaterialReq(std::string material);
};
#endif
#ifndef ADMINISTRATIONHEAD_HPP
#define ADMINISTRATIONHEAD_HPP

#include "User.hpp"
#include "ReadAndWrite.hpp"

using namespace std;

class AdministrationHead : public User {
    public:
        void addPlantHead();
        void updatePlantHead();
        void deletePlantHead();
};
#endif
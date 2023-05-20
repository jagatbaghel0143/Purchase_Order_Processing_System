#ifndef ADMINISTRATION_HPP
#define ADMINISTRATION_HPP

#include "User.hpp"
#include "ReadAndWrite.hpp"

class Administration : public User {
    public:
        void addPlant();
};
#endif
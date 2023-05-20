#ifndef READANDWRITE_HPP
#define READANDWRITE_HPP

#include <string>
using namespace std;

class ReadAndWrite {
    public:
        void writeDataToFile(string data);
        string readDataFromFile();
};

#endif
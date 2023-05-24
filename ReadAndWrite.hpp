#ifndef READANDWRITE_HPP
#define READANDWRITE_HPP

#include <string>

using namespace std;

class ReadAndWrite {
    public:
        bool writeDataToFile(string data, string filename);
        string readDataFromFile(string filename);
};
#endif
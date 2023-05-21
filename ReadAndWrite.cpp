#include <iostream>
#include <fstream>
#include <sstream>
#include "ReadAndWrite.hpp"

using namespace std;

bool ReadAndWrite::writeDataToFile(string data) {
    ofstream file("plants.txt");
    if(file.is_open()) {
        file << data;
        file.close();
        return true;
    }
    return false;
}

string ReadAndWrite::readDataFromFile() {
    ifstream file("plants.txt");
    string data;
    if(file.is_open()){
        stringstream ss;
        ss << file.rdbuf();
        data = ss.str();
        file.close();
    } else {
        cout<<"Unable to open file\n";
    }
    return data;
}
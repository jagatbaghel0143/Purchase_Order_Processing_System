#include <iostream>
#include <fstream>
#include <sstream>
#include "headers/ReadAndWrite.hpp"

using namespace std;

bool ReadAndWrite::writeDataToFile(string data, string filename) {
    ofstream file(filename);
    if(file.is_open()) {
        file << data;
        file.close();
        return true;
    }
    return false;
}

string ReadAndWrite::readDataFromFile(string filename) {
    ifstream file(filename);
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
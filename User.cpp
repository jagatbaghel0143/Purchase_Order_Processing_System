#include <iostream>
#include <string>
#include <cstdlib>
#include "User.hpp"
#include "ReadAndWrite.hpp"
#include "ConversionUtility.hpp"

using namespace std;

static ReadAndWrite readAndWrite;
static ConversionUtility conversionUtility;

void User::setLogins(string s1, string s2) {
    u = s1;
    p = s2;
}

void User::adminLogin() {
    system("clear");
    std::cout<<"\n \t\tEnter your username and password to continue!";
    std::cout<<"\n \t\t USERNAME: ";
    std::cin>>username;
    std::cout<<"\t\t PASSWORD: ";
    std::cin>>password;
    if(u == username && p == password) {
        std::cout<<"\n\t Congratulations!! You have successfully logged into the System!";
        std::cout<<"\n\t\t Press ENTER to continue...";
        std::cin.ignore();
        std::cin.get();

    } else {
        std::cout<<"\n \t\tAccess Denied! Unauthorized credentials!"<<"\n \t\t Press ENTER to try again...";
        std::cin.ignore();
        std::cin.get();
        adminLogin();
    }

}

void User::headLogin(string filename) {
    system("clear");
    std::cout<<"\n \t\tEnter your username and password to continue!";
    std::cout<<"\n \t\t USERNAME: ";
    std::cin>>username;
    std::cout<<"\t\t PASSWORD: ";
    std::cin>>password;
    bool changePassword = false, isCredentialsCorrect = false;
    string data = readAndWrite.readDataFromFile(filename);
    std::cout<<data;
    vector<PlantHead> heads = conversionUtility.convertPlantHeadStringToVector(data);
    for(auto i = heads.begin(); i != heads.end(); ++i) {
        if(username == to_string(i->getPlantHeadId()) && password == i->getPlantHeadPassword()) {
            isCredentialsCorrect = true;
            std::cout<<i->getPlantHeadLoggedIn();
            std::cout<<i->getPlantHeadIsVerified();
            i->setPlantHeadLoggedIn(true);
            if(!i->getPlantHeadIsVerified()) {
                std::cout<<"\n \t\tPlease change you password!";
                std::cout<<"\n \t\tEnter New Password: ";
                std::cin>>password;
                i->setPlantHeadPassword(password);
                i->setPlantHeadIsVerified(true);
                changePassword = true;
            }
            break;
        }
    }
    if(isCredentialsCorrect && changePassword) {
        data = conversionUtility.convertPlantHeadVectorToString(heads);
        if(readAndWrite.writeDataToFile(data,"plantHeadDetails.txt")) {
            std::cout<<"\t\tYou Password changed successfully!\n";
        } else {
            std::cout<<"\t\tError occurred while changing password";
        }
    }
    if(isCredentialsCorrect) {
        data = conversionUtility.convertPlantHeadVectorToString(heads);
        if(readAndWrite.writeDataToFile(data,"plantHeadDetails.txt")) {
            std::cout<<"\t\tCongratulations!! You have successfully logged into the System!\n";
        } else {
            std::cout<<"\t\tError occurred while logging";
        }
        std::cout<<"\n\t\t Press ENTER to continue...";
        std::cin.ignore();
        std::cin.get();
    } else {
        std::cout<<"\n \t\tAccess Denied! Unauthorized credentials!"<<"\n \t\t Press ENTER to try again...";
        std::cin.ignore();
        std::cin.get();
        headLogin(filename);
    }
}

void User::clientLogin(string filename) {
    system("clear");
    std::cout<<"\n \t\tEnter your username and password to continue!";
    std::cout<<"\n \t\t USERNAME: ";
    std::cin>>username;
    std::cout<<"\t\t PASSWORD: ";
    std::cin>>password;
    bool changePassword = false, isCredentialsCorrect = false;
    string data = readAndWrite.readDataFromFile(filename);
    std::cout<<data;
    vector<Client> clients = conversionUtility.convertClientStringToVector(data);
    for(auto i = clients.begin(); i != clients.end(); ++i) {
        std::cout<<"\n"<<i->isClientApprovedByAdmin();
        if(username == to_string(i->getClientID()) && password == i->getClientPassword()) {
            isCredentialsCorrect = true;
            if(i->isClientApprovedByAdmin() == "true") {
                if(i->isClientVerified() == "false") {
                    std::cout<<"\n \t\tPlease change you password!";
                    std::cout<<"\n \t\tEnter New Password: ";
                    std::cin>>password;
                    i->setClientPassword(password);
                    i->setClientVerified("true");
                    changePassword = true;
                }
            }
            break;
        }
    }
    if(isCredentialsCorrect && changePassword) {
        data = conversionUtility.convertClientVectorToString(clients);
        if(readAndWrite.writeDataToFile(data,"clientDetails.txt")) {
            std::cout<<"\t\tYou Password changed successfully!\n";
        } else {
            std::cout<<"\t\tError occurred while changing password";
        }
    }
    if(isCredentialsCorrect) {
        data = conversionUtility.convertClientVectorToString(clients);
        if(readAndWrite.writeDataToFile(data,"plantHeadDetails.txt")) {
            std::cout<<"\t\tCongratulations!! You have successfully logged into the System!\n";
        } else {
            std::cout<<"\t\tError occurred while logging";
        }
        std::cout<<"\n\t\t Press ENTER to continue...";
        std::cin.ignore();
        std::cin.get();
    } else {
        std::cout<<"\n \t\tAccess Denied! Unauthorized credentials!"<<"\n \t\t Press ENTER to try again...";
        std::cin.ignore();
        std::cin.get();
        headLogin(filename);
    }
}
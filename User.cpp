#include <iostream>
#include <string>
#include <cstdlib>
#include "headers/User.hpp"
#include "headers/ReadAndWrite.hpp"
#include "headers/ConversionUtility.hpp"

using namespace std;

static ReadAndWrite readAndWrite;
static ConversionUtility conversionUtility;

void User::setLogins(string s1, string s2) {
    u = s1;
    p = s2;
}

void User::adminLogin() {
    system("clear");
    std::cout<<"\n \t\tEnter Admin username and password to continue!";
    std::cout<<"\n \t\t USERNAME: ";
    std::cin>>username;
    std::cout<<"\t\t PASSWORD: ";
    std::cin>>password;
    if(u == username && p == password) {
        std::cout<<"\n\t Congratulations! Logged into the system successfully!";
        std::cout<<"\n\t\t Press ENTER to continue...";
        std::cin.ignore();
        std::cin.get();

    } else {
        std::cout<<"\n\t\tAccess Denied! Unauthorized credentials!"<<"\n\t\tPress ENTER to try again...";
        std::cin.ignore();
        std::cin.get();
        adminLogin();
    }

}

void User::headLogin(string filename) {
    system("clear");
    std::cout<<"\n\t\tEnter Plant Head username and password to continue!";
    std::cout<<"\n\t\tUSERNAME: ";
    std::cin>>username;
    std::cout<<"\t\tPASSWORD: ";
    std::cin>>password;
    bool changePassword = false, isCredentialsCorrect = false;
    string data = readAndWrite.readDataFromFile(filename);
    vector<PlantHead> heads = conversionUtility.convertPlantHeadStringToVector(data);
    for(auto i = heads.begin(); i != heads.end(); ++i) {
        if(username == to_string(i->getPlantHeadId()) && password == i->getPlantHeadPassword()) {
            isCredentialsCorrect = true;
            if(i->getPlantHeadIsVerified() == "false") {
                std::cout<<"\n\t\tPlease change you password!";
                std::cout<<"\n\t\tEnter New Password: ";
                std::cin>>password;
                i->setPlantHeadPassword(password);
                i->setPlantHeadIsVerified("true");
                changePassword = true;
            }
            i->setPlantHeadLoggedIn("true");
            break;
        }
    }
    if(isCredentialsCorrect && changePassword) {
        data = conversionUtility.convertPlantHeadVectorToString(heads);
        if(readAndWrite.writeDataToFile(data,"Resources/plantHeadDetails.txt")) {
            std::cout<<"\t\tYour Password changed successfully!\n";
        } else {
            std::cout<<"\t\tError occurred while changing password";
        }
    }
    if(isCredentialsCorrect) {
        data = conversionUtility.convertPlantHeadVectorToString(heads);
        if(readAndWrite.writeDataToFile(data,"Resources/plantHeadDetails.txt")) {
            std::cout<<"\t\tCongratulations! Logged into the system successfully!\n";
        } else {
            std::cout<<"\t\tError occurred while logging";
        }
        std::cout<<"\n\t\tPress ENTER to continue...";
        std::cin.ignore();
        std::cin.get();
    } else {
        std::cout<<"\n\t\tAccess Denied! Unauthorized credentials!"<<"\n\t\t Press ENTER to try again...";
        std::cin.ignore();
        std::cin.get();
        headLogin(filename);
    }
}

void User::clientLogin(string filename) {
    system("clear");
    std::cout<<"\n\t\tEnter Client username and password to continue!";
    std::cout<<"\n\t\tUSERNAME: ";
    std::cin>>username;
    std::cout<<"\t\tPASSWORD: ";
    std::cin>>password;
    bool changePassword = false, isCredentialsCorrect = false;
    string data = readAndWrite.readDataFromFile(filename);
    vector<Client> clients = conversionUtility.convertClientStringToVector(data);
    for(auto i = clients.begin(); i != clients.end(); ++i) {
        if(username == to_string(i->getClientID()) && password == i->getClientPassword()) {
            if(i->isClientApprovedByAdmin() == "true") {
                if(i->isClientVerified() == "false") {
                    std::cout<<"\n\t\tPlease change you password!";
                    std::cout<<"\n\t\tEnter New Password: ";
                    std::cin>>password;
                    i->setClientPassword(password);
                    i->setClientVerified("true");
                    changePassword = true;
                }
            } else if(i->isClientApprovedByAdmin() == "pend"){
                std::cout<<"\n\t\tYour account is NOT approved by Admin till now!";
            } else if(i->isClientApprovedByAdmin() == "false"){
                std::cout<<"\n\t\tSorry! Your account is denied by Admin!";
            }
            if((i->isClientApprovedByAdmin() == "true") && (i->isClientVerified() == "true")){
                isCredentialsCorrect = true;
            }
            break;
        }
    }
    if(isCredentialsCorrect && changePassword) {
        data = conversionUtility.convertClientVectorToString(clients);
        if(readAndWrite.writeDataToFile(data,"Resources/clientDetails.txt")) {
            std::cout<<"\t\tYou Password changed successfully!\n";
        } else {
            std::cout<<"\t\tError occurred while changing password";
        }
    } else if(isCredentialsCorrect) {
        data = conversionUtility.convertClientVectorToString(clients);
        if(readAndWrite.writeDataToFile(data,"Resources/clientDetails.txt")) {
            std::cout<<"\t\tCongratulations!! You have successfully logged into the System!\n";
        } else {
            std::cout<<"\t\tError occurred while logging";
        }
    } else if(!isCredentialsCorrect){
        std::cout<<"\n\t\tAccess Denied! Unauthorized credentials!";
        std::cout<<"\n\t\tPress ENTER to try again...";
        std::cin.ignore();
        std::cin.get();
        clientLogin(filename);
    }
    std::cout<<"\n\t\t Press ENTER...";
    std::cin.ignore();
    std::cin.get();
}
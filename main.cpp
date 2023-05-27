#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "User.hpp"
#include "Administration.hpp"
#include "AdministrationHead.hpp"
#include "ClientManagement.hpp"

using namespace std;

int main() {
    int res;
    std::cout<<"\n*****************************************************************************************************";
    std::cout<<"\n**********************---WELCOME TO PURCHASE ORDER PROCESSING SYSTEM---******************************";
    std::cout<<"\n*****************************************************************************************************";
    std::cout<<"\n \t\t\t\t To Continue, please \n\n \t\t\t\t 1. Admin \n \t\t\t\t 2. Plant Head \n \t\t\t\t 3. Client \n \t\t\t\t";
    std::cout<<"\n\t\t\t\t Enter your choice [1,2,3] : ";
    std::cin >> res;
    if(res == 1) {
        Administration admin;
        AdministrationHead adminHead;
        admin.setLogins("admin", "admin");
        admin.adminLogin();
        while(1) {
            system("clear");
            std::cout<<"\n*****************************************************************************************************";
            std::cout<<"\n*****************---Welcome to Administration Module---*************************";
            std::cout<<"\n*****************************************************************************************************";
            std::cout<<"\n\t\t1. Manage Plants";
            std::cout<<"\n\t\t2. Manage Plant Head.";
            std::cout<<"\n\t\t3. View Purchase orders";
            std::cout<<"\n\t\t4. Approve/Deny Client Request";
            std::cout<<"\n\t\t5. Logout";
            std::cout<<"\n\tEnter your choice[1,2,3,4,5]: ";
            int choice = -1;
            std::cin>>choice;
            switch(choice) {
                case 1:
                    while(1) {
                        system("clear");
                        std::cout<<"\n*****************************************************************************************************";
                        std::cout<<"\n*****************---Welcome to Plant Management---*************************";
                        std::cout<<"\n*****************************************************************************************************";
                        std::cout<<"\n\t\t1. Add New Plant";
                        std::cout<<"\n\t\t2. Update Plant.";
                        std::cout<<"\n\t\t3. Delete Plant";
                        std::cout<<"\n\t\t4. Search and View Plant";
                        std::cout<<"\n\t\t5. Back";
                        std::cout<<"\n\tEnter your choice[1,2,3,4,5]: ";
                        std::cin>>choice;
                        switch (choice)
                        {
                            case 1:
                                admin.addPlant();
                                break;
                            
                            case 2:
                                admin.updatePlant();
                                break;

                            case 3:
                                admin.deletePlant();
                                break;

                            case 4:
                                admin.searchPlant();
                                break;

                            default:
                                system("clear");
                                break;
                        }
                        if(choice == 5) {
                            break;
                        }
                    }
                case 2:
                    system("clear");
                    while(1) {
                        system("clear");
                        std::cout<<"\n*****************************************************************************************************";
                        std::cout<<"\n*****************---Welcome to Plant Head Management---*************************";
                        std::cout<<"\n*****************************************************************************************************";
                        std::cout<<"\n\t\t1. Add New Plant Head";
                        std::cout<<"\n\t\t2. Update Plant Head.";
                        std::cout<<"\n\t\t3. Delete Plant Head";
                        std::cout<<"\n\t\t4. Back";
                        std::cout<<"\n\tEnter your choice[1,2,3,4,5]: ";
                        std::cin>>choice;
                        switch (choice)
                        {
                            case 1:
                                adminHead.addPlantHead();
                                break;
                            
                            case 2:
                                adminHead.updatePlantHead();
                                break;

                            case 3:
                                adminHead.deletePlantHead();
                                break;
                                
                            default:
                                system("clear");
                                break;
                        }
                        if(choice == 4) {
                            break;
                        }
                }
                    break;
                case 3:
                    system("clear");
                    std::cout<<"List of Items manufacturing in Plants\n";
                    break;

                case 4:
                    system("clear");
                    std::cout<<"Approve/Deny Client Request\n";
                    break;

                default:
                    system("clear");
                    std::cout<<"\n\n\t\tYou have been logged out successfully! See you soon again!!\n\n";
                    exit(1);
            }
            getchar();
        }
    } else if (res == 2) {
        AdministrationHead adminHead;
        adminHead.headLogin("plantHeadDetails.txt");
        while(1) {
            system("clear");
            std::cout<<"\n*****************************************************************************************************";
            std::cout<<"\n*****************---Welcome to Plant Head Module---*************************";
            std::cout<<"\n*****************************************************************************************************";
            std::cout<<"\n\t\t1. View Purchase Orders";
            std::cout<<"\n\t\t2. Add Items";
            std::cout<<"\n\t\t3. Update Items";
            std::cout<<"\n\t\t4. Delete Items";
            std::cout<<"\n\t\t5. View Items";
            std::cout<<"\n\t\t6. Logout";
            std::cout<<"\n\tEnter your choice[1,2,3,4,5,6]: ";
            int choice = -1;
            std::cin>>choice;
            switch(choice) {
                case 1:
                    std::cout<<"Purchase Orders list will open\n";
                    break;

                case 2:
                    std::cout<<"Add Items will open\n";
                    break;

                case 3:
                    std::cout<<"Add Items will open\n";
                    break;

                case 4:
                    std::cout<<"Add Items will open\n";
                    break;

                case 5:
                    std::cout<<"Add Items will open\n";
                    break;

                default:
                    system("clear");
                    std::cout<<"\n\n\t\tYou have been logged out successfully! See you soon again!!\n\n";
                    break;
            }
            if(choice == 6) {
                break;
            }
        }
        std::cin.ignore();
        getchar();
    } else if (res == 3) {
        ClientManagement clientManagement;
        while(1) {
            system("clear");
            std::cout<<"\n*****************************************************************************************************";
            std::cout<<"\n*****************---Welcome to Client Module---*************************";
            std::cout<<"\n*****************************************************************************************************";
            std::cout<<"\n\t\t1. Register";
            std::cout<<"\n\t\t2. Login";
            std::cout<<"\n\t\t3. Check Account Status";
            std::cout<<"\n\t\t4. Back";
            std::cout<<"\n\tEnter your choice[1,2,3]: ";
            int clientChoice = -1;
            std::cin >> clientChoice;

            switch(clientChoice) {
                case 1:
                    clientManagement.addClient();
                    break;

                case 2:
                    clientManagement.clientLogin("clientDetails.txt");
                    break;

                case 3:
                    clientManagement.checkStatus();
                    break;

                default:
                    break;

            }
            if(clientChoice == 3) {
                break;
            }
        }
        std::cin.ignore();            
        getchar();
    }
    return 0;
}
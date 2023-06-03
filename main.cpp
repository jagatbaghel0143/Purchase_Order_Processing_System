#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "headers/User.hpp"
#include "headers/Administration.hpp"
#include "headers/AdministrationHead.hpp"
#include "headers/ClientManagement.hpp"
#include "headers/PlantHeadActivity.hpp"

using namespace std;

int main() {
    int res;
    std::cout<<"\n\t\t**************************************************************";
    std::cout<<"\n\t\t*        WELCOME TO PURCHASE ORDER PROCESSING SYSTEM         *";
    std::cout<<"\n\t\t**************************************************************";
    std::cout<<"\n\t\t*               1. Admin                                     *";
    std::cout<<"\n\t\t*               2. Plant Head                                *";
    std::cout<<"\n\t\t*               3. Client                                    *";
    std::cout<<"\n\t\t**************************************************************";
    std::cout<<"\n\t\tEnter your choice [1,2,3] : ";
    std::cin >> res;
    if(res == 1) {
        Administration admin;
        AdministrationHead adminHead;
        admin.setLogins("admin", "admin");
        admin.adminLogin();
        while(1) {
            system("clear");
            std::cout<<"\n\t\t*******************************************************";
            std::cout<<"\n\t\t*        Welcome to Administration Module             *";
            std::cout<<"\n\t\t*******************************************************";
            std::cout<<"\n\t\t*       1. Manage Plants                              *";
            std::cout<<"\n\t\t*       2. Manage Plant Head.                         *";
            std::cout<<"\n\t\t*       3. View Purchase orders                       *";
            std::cout<<"\n\t\t*       4. Approve/Deny Client Request                *";
            std::cout<<"\n\t\t*       5. Logout                                     *";
            std::cout<<"\n\t\t*******************************************************";
            std::cout<<"\n\tEnter your choice[1,2,3,4,5]: ";
            int choice = -1;
            std::cin>>choice;
            switch(choice) {
                case 1:
                    while(1) {
                        system("clear");
                        std::cout<<"\n\t\t************************************************";
                        std::cout<<"\n\t\t*        Welcome to Plant Management           *";
                        std::cout<<"\n\t\t************************************************";
                        std::cout<<"\n\t\t*        1. Add New Plant                      *";
                        std::cout<<"\n\t\t*        2. Update Plant                       *";
                        std::cout<<"\n\t\t*        3. Delete Plant                       *";
                        std::cout<<"\n\t\t*        4. Search and View Plant              *";
                        std::cout<<"\n\t\t*        5. Back                               *";
                        std::cout<<"\n\t\t************************************************";
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
                    break;
                case 2:
                    system("clear");
                    while(1) {
                        system("clear");
                        std::cout<<"\n\t\t************************************************";
                        std::cout<<"\n\t\t*        Welcome to Plant Head Management      *";
                        std::cout<<"\n\t\t************************************************";
                        std::cout<<"\n\t\t*        1. Add New Plant Head                 *";
                        std::cout<<"\n\t\t*        2. Update Plant Head.                 *";
                        std::cout<<"\n\t\t*        3. Delete Plant Head                  *";
                        std::cout<<"\n\t\t*        4. Back                               *";
                        std::cout<<"\n\t\t************************************************";
                        std::cout<<"\n\tEnter your choice[1,2,3,4]: ";
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
                    admin.viewOrders();
                    break;

                case 4:
                    while(1) {
                        system("clear");
                        int choice = -1;
                        std::cout<<"\n\t\t***********************************************";
                        std::cout<<"\n\t\t*            Client Request Dashboard         *";
                        std::cout<<"\n\t\t***********************************************";
                        std::cout<<"\n\t\t*             1. View Requests                *";
                        std::cout<<"\n\t\t*             2. Approve/Deny Request         *";
                        std::cout<<"\n\t\t*             3. Back                         *";
                        std::cout<<"\n\t\t***********************************************";
                        std::cout<<"\n\t\tEnter choice [1,2,3] : ";
                        std::cin>>choice;
                        switch(choice) {
                            case 1:
                                admin.viewRequests();
                                break;

                            case 2:
                                admin.approveDenyRequest();
                                break;

                            case 3:
                                break;
                        }
                        if(choice==3){
                            break;
                        }
        
                    }
                    break;

                default:
                    system("clear");
                    std::cout<<"\n\n\t\tLogged out successfully! See you soon again!!\n\n";
                    exit(1);
            }
        }
    } else if (res == 2) {
        AdministrationHead adminHead;
        PlantHeadActivity plantHeadActivity;
        adminHead.headLogin("Resources/plantHeadDetails.txt");
        while(1) {
            system("clear");
            std::cout<<"\n\t\t************************************************";
            std::cout<<"\n\t\t*        Welcome to Plant Head Module          *";
            std::cout<<"\n\t\t************************************************";
            std::cout<<"\n\t\t*        1. View Purchase Orders               *";
            std::cout<<"\n\t\t*        2. Add Items                          *";
            std::cout<<"\n\t\t*        3. Update Items                       *";
            std::cout<<"\n\t\t*        4. Delete Items                       *";
            std::cout<<"\n\t\t*        5. View Items                         *";
            std::cout<<"\n\t\t*        6. Logout                             *";
            std::cout<<"\n\t\t************************************************";
            std::cout<<"\n\tEnter your choice[1,2,3,4,5,6]: ";
            int choice = -1;
            std::cin>>choice;
            switch(choice) {
                case 1:
                    plantHeadActivity.viewPurchaseOrder();
                    break;

                case 2:
                    plantHeadActivity.addItem();
                    break;

                case 3:
                    plantHeadActivity.updateItem();
                    break;

                case 4:
                    plantHeadActivity.deleteItem();
                    break;

                case 5:
                    plantHeadActivity.viewItems();
                    break;

                default:
                    system("clear");
                    std::cout<<"\n\t\tLogged out successfully! See you soon again!!\n\n";
                    break;
            }
            if(choice == 6) {
                break;
            }
        }
    } else if (res == 3) {
        ClientManagement clientManagement;
        while(1) {
            system("clear");
            std::cout<<"\n\t\t************************************************";
            std::cout<<"\n\t\t*        Welcome to Client Module              *";
            std::cout<<"\n\t\t************************************************";            
            std::cout<<"\n\t\t*        1. Register                           *";
            std::cout<<"\n\t\t*        2. Login                              *";
            std::cout<<"\n\t\t*        3. Check Account Status               *";
            std::cout<<"\n\t\t*        4. Back                               *";
            std::cout<<"\n\t\t************************************************";
            std::cout<<"\n\t\tEnter your choice[1,2,3,4]: ";
            int clientChoice = -1;
            std::cin >> clientChoice;

            switch(clientChoice) {
                case 1:
                    clientManagement.addClient();
                    break;

                case 2:
                    clientManagement.clientLogin("Resources/clientDetails.txt");
                    clientManagement.activityClient();
                    break;

                case 3:
                    clientManagement.checkStatus();
                    break;

                default:
                    break;

            }
            if(clientChoice == 4) {
                break;
            }
        }
    }
    return 0;
}
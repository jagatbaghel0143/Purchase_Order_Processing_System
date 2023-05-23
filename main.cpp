#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "User.hpp"
#include "Administration.hpp"

using namespace std;

int main() {
    Administration admin;
    int res;
    int choice = -1;
    cout<<"\n*****************************************************************************************************";
    cout<<"\n**********************---WELCOME TO PURCHASE ORDER PROCESSING SYSTEM---******************************";
    cout<<"\n*****************************************************************************************************";
    cout<<"\n \t\t\t\t To Continue, please \n\n \t\t\t\t 1. Admin \n \t\t\t\t 2. Plant Head \n \t\t\t\t 3. Client \n \t\t\t\t";
    cout<<"\n\t\t\t\t Enter your choice [1,2,3] : ";
    cin >> res;
    if(res == 1) {
        admin.setLogins("admin", "admin");
        admin.login();
        while(1) {
            system("clear");
            cout<<"\n*****************************************************************************************************";
            cout<<"\n*****************---Welcome to Administration Module---*************************";
            cout<<"\n*****************************************************************************************************";
            cout<<"\n\t\t1. Manage Plants";
            cout<<"\n\t\t2. Manage Plant Head.";
            cout<<"\n\t\t3. View Purchase orders";
            cout<<"\n\t\t4. Logout";
            cout<<"\n\tEnter your choice[1,2,3,4]: ";
            cin>>choice;
            switch(choice) {
                case 1:
                    while(1) {
                        system("clear");
                        cout<<"\n*****************************************************************************************************";
                        cout<<"\n*****************---Welcome to Plant Management---*************************";
                        cout<<"\n*****************************************************************************************************";
                        cout<<"\n\t\t1. Add New Plant";
                        cout<<"\n\t\t2. Update Plant.";
                        cout<<"\n\t\t3. Delete Plant";
                        cout<<"\n\t\t4. Search and View Plant";
                        cout<<"\n\t\t5. Go Back in Previous menu";
                        cout<<"\n\tEnter your choice[1,2,3,4,5]: ";
                        cin>>choice;
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
                    cout<<"Manage Plant Head will Open";
                    break;
                case 3:
                    system("clear");
                    cout<<"View Purchase will Open";
                    break;
                default:
                    system("clear");
                    cout<<"\n\n\t\tYou have been logged out successfully! See you soon again!!\n\n";
                    exit(1);
            }
            getchar();
        }
    }
    return 0;
}
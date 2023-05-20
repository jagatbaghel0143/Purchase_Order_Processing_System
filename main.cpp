#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <sstream>
#include <User.hpp>
#include <Administration.hpp>
#include <Plant.hpp>

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
            cout<<"\n \t\t 1. Manage Plants";
            cout<<"\n \t\t 2. Manage Plant Head.";
            cout<<"\n \t\t 3. View Purchase orders";
            cout<<"\n \t\t 4. Logout";
            cout<<"\n\t\t Enter your choice[1,2,3,4]: ";
            cin>>choice;
            switch(choice) {
                case 1:
                    system("clear");
                    cout<<"\n*****************************************************************************************************";
                    cout<<"\n*****************---Welcome to Plant Management---*************************";
                    cout<<"\n*****************************************************************************************************";
                    cout<<"\n \t\t 1. Add New Plant";
                    cout<<"\n \t\t 2. Update Plant.";
                    cout<<"\n \t\t 3. Delete Plant";
                    cout<<"\n \t\t 4. Search Plant";
                    cout<<"\n \t\t 5. View All Plants";
                    cout<<"\n \t\t 6. Go Back in Previous menu";
                    cout<<"\n\t\t Enter your choice[1,2,3,4]: ";
                    cin>>choice;
                    switch (choice)
                    {
                        case 1:
                            admin.addPlant();
                            break;
                        
                        case 2:
                            
                            break;

                        case 3:
                            break;

                        case 4:
                            break;

                        case 5:
                            break;

                        default:
                            system("clear");
                    }
                    break;
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
                    cout<<"\nYou have been logged out successfully! See you sooon again!!\n";
                    exit(1);
            }
            getchar();
        }
    }
    return 0;
}
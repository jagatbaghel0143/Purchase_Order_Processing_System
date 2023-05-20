#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


class User {
    protected:
        string username, password, u, p;

    public:
        void setLogins(string s1, string s2);
        void login();
};

void User::setLogins(string s1, string s2) {
    u = s1;
    p = s2;
}

void User::login() {
    system("clear");
    cout<<"\n \t\t\t\tEnter your username and password to continue!"<<" ";
    cout<<"\n \t\t\t\t USERNAME: ";
    cin>>username;
    cout<<" \n \t\t\t\t PASSWORD: ";
    cin>>password;
    if(u == username && p == password) {
        cout<<"\n\n"<<"\t Congratulations!! You have successfully logged into the System!"<< "\n";
        cout<<"\n \t\t Press ENTER to continue...";
        cin.ignore();
        cin.get();

    } else {
        cout<<"\n \t\tAccess Denied! Unauthorized credentials!"<<"\n \t\t Press ENTER to try again...";
        cin.ignore();
        cin.get();
        login();
    }
}

class Administration : public User {

};


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
                    cout<<"Manage Plant will Open";
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
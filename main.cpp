#include <iostream>
#include <string>

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
    system("cls");
    cout<<"\n \t\t\t\tEnter your username and password to continue!"<<" ";
    cout<<"\n \t\t\t\t USERNAME: ";
    cin>>username;
    cout<<" \n \t\t\t\t PASSWORD: ";
    cin>>password;
    if(u == username && p == password) {
        cout<<"\n"<<"\t\tYou have successfully Logged into the system!"<< " ";
        system("pause");
    } else {
        cout<<"\n \t\tAccess Denied! Unauthorized credentials! Please try again!!"<<" ";
        system("pause");
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
    cout<<"\n*****************---WELCOME TO PURCHASE ORDER PROCESSING SYSTEM---*************************";
    // cout<<"\n*****************************************************************************************************";
    cout<<"\n \t\t\t\t To Continue, please \n\t\t\t\t 1. Admin \n\t\t\t\t 2. Plant Head \n \t\t\t\t 3. Client \n \t\t\t\t";
    cout<<"\n\t\t\t\t Enter your choice [1,2,3] : ";
    cin >> res;
    if(res == 1) {
        admin.setLogins("admin", "admin");
        admin.login();
        while(1) {
            system("cls");
            cout<<"\n*****************************************************************************************************";
            cout<<"\n*****************---Welcome to Administration Module---*************************";
            cout<<"\n*****************************************************************************************************";
            cout<<"\n \t\t 1 -> Manage Plants";
            cout<<"\n \t\t 2 -> Manage Plant Head.";
            cout<<"\n \t\t 3 -> View Purchase orders";
            cout<<"\n \t\t 4 -> Logout";
            cout<<"\n\t\t Enter your choice[1,2,3,4]: ";
            cin>>choice;
            switch(choice) {
                case 1:
                    system("cls");
                    cout<<"Manage Plant will Open";
                    break;
                case 2:
                    system("cls");
                    cout<<"Manage Plant Head will Open";
                    break;
                case 3:
                    system("cls");
                    cout<<"View Purchase will Open";
                    break;
                default:
                    system("cls");
                    cout<<"\nYou have been logged out successfully!";
                    exit(1);
            }
            getchar();
        }
    }
    return 0;
}
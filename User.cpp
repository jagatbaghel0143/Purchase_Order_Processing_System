#include <iostream>
#include <string>
#include <cstdlib>
#include "User.hpp"

using namespace std;

void User::setLogins(string s1, string s2) {
    u = s1;
    p = s2;
}

void User::login() {
    system("clear");
    cout<<"\n \t\t\t\tEnter your username and password to continue!";
    cout<<"\n \t\t\t\t USERNAME: ";
    cin>>username;
    cout<<" \n \t\t\t\t PASSWORD: ";
    cin>>password;
    if(u == username && p == password) {
        cout<<"\n\n"<<"\t Congratulations!! You have successfully logged into the System!\n";
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
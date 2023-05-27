#ifndef USER_HPP
#define USER_HPP

#include <string>

using namespace std;

class User {
    private:
        string username;
        string password;
        string u;
        string p;

    public:
        void setLogins(string s1, string s2);
        void adminLogin();
        void headLogin(string filename);
        void clientLogin(string filename);
};
#endif
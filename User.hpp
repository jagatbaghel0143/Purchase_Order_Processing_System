#ifndef USER_HPP
#define USER_HPP

#include <string>

using namespace std;

class User {
    private:
        string username, password, u, p;

    public:
        void setLogins(string s1, string s2);
        void login();
};

#endif
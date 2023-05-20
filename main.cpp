#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// User class for creating user
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

// Plant class for managing plants
class Plant {
    private:
        int plantId;
        string plantName;
        string plantLoc;
        int laborerCount;
        int capacityPerMonth;

    public:
        Plant(int id, const string name, const string location, int laborers, int capacity) {
            plantId = id;
            plantName = name;
            plantLoc = location;
            laborerCount = laborers;
            capacityPerMonth = capacity;
        }
        void getPlant() {
            cout<<"\n Plant Details...";
            cout<<"\n Plant Id: "<<plantId;
            cout<<"\n Plant Name: "<<plantName;
            cout<<"\n Plant Location: "<<plantLoc;
            cout<<"\n Laborer Count: "<< laborerCount;
            cout<<"\n Capacity Per Month: "<<capacityPerMonth;

        }
        int getPlantId() {
            return plantId;
        }
        string getPlantName() {
            return plantName;
        }        
        string getPlantLoc() {
            return plantLoc;
        }
        int getLabourerCount() {
            return laborerCount;
        }
        int getCapacityPerMonth() {
            return capacityPerMonth;
        }
};

// Public functions for general use
vector<Plant> convertStringToVector(string data) {
    vector<Plant> plants;
    stringstream ss(data);
    string line;
    while (getline(ss, line)) {
        stringstream lineStream(line);
        int id, laborers, capacity;
        string name, location;
        lineStream >> id;
        lineStream.ignore();
        getline(lineStream, name, ',');
        getline(lineStream, location, ',');
        lineStream >> laborers;
        lineStream.ignore();
        lineStream >> capacity;
        plants.emplace_back(id, name, location, laborers, capacity);
    }
    return plants;
}

string convertVectorToString(vector<Plant> plants) {
    stringstream ss;
    for (auto plant : plants) {
        ss << plant.getPlantId() << "," << plant.getPlantName() << "," << plant.getPlantLoc() << "," << plant.getLabourerCount() << "," << plant.getCapacityPerMonth() << "\n";
    }
    return ss.str();
}

void writeDataToFile(string data) {
    ofstream file("plants.txt");
    if(file.is_open()) {
        file << data;
        file.close();
        cout << "Data written to file";
    } else {
        cout << "Unable to open file";
    }
}

string readDataFromFile() {
    ifstream file("plants.txt");
    string data;
    if(file.is_open()){
        stringstream ss;
        ss << file.rdbuf();
        data = ss.str();
        file.close();
    } else {
        cout<<"Unable to open file\n";
    }
    return data;
}

// Administration class for managing  admin activities
class Administration : public User {
    public:
    void addPlant();
};

void Administration::addPlant() {
    int id = time(nullptr);
    string name;
    string loc;
    int laborers;
    int capacity;
    cout<<"\n"<<"Enter Plant Name: ";
    cin>>name;
    cout<<"Enter Plant Location: ";
    cin>>loc;
    cout<<"Enter Loborer Count: ";
    cin>>laborers;
    cout<<"Enter Capacity Per Month: ";
    cin>>capacity;
    Plant plant(id, name, loc, laborers, capacity);
    string data = readDataFromFile();
    vector<Plant> plants = convertStringToVector(data);
    plants.emplace_back(plant);
    data = convertVectorToString(plants);
    writeDataToFile(data);
    int idd = plant.getPlantId();
    cout<<"\nNew manufacturing unit with ID #"<<idd<<" is added successfully!\n";
    cin.get();
}

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
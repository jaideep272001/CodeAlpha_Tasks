// TASK 2: Login and Registration System
// Create a registration function that takes username and password as input.
// Validate the inputs and check for duplicate usernames if needed.
// Store user credentials securely in a file (one file per user or a database file).
// Implement a login function that reads credentials and verifies user identity.
// Provide appropriate success or error messages for registration and login.

#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include<string>

using namespace std;

class application_user{
    string username;
    string password;

    public:

    bool userExists(const string& uname) {
        ifstream file("data.csv");
        string line, existingUser;

        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, existingUser, ',');
            if (existingUser == uname) {
                return true;
            }
        }
        return false;
    }

    int inputRegistration(){
        ofstream file("data.csv", ios::app);
        if(!file.is_open()){
            cout<<"Error Opening File !";
        }
        jump:
        cout<<"Enter Username : ";
        cin>>username; 
        if(userExists(username)){
            cout<<"Try Another Username. Username Already Exists"<<endl;
            goto jump;
        }
        cout<<"Enter Password : ";
        cin>>password;

        file<<username<<","<<password<<endl;
        cout<<"Registration Successful";

        return 0;
    }

    int inputLogin(){
        string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("data.csv");
    string line, user, pass;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, user, ',');
        getline(ss, pass, ',');
        if (user == username && pass == password) {
            cout << "Login successful!\n";
            return 0;
        }
    }
    cout << "Incorrect Credentials\n";

     return 0;   
    }
};

int main(){
    application_user user;
    int option = 0;
    cout<<"Choose Correct Option : \n1. User registration \n2. User Login \n3. Exit Program\nEnter Your Option : ";
    cin>>option;
    switch(option){
        case 1 : user.inputRegistration();
                    break;
        case 2 : user.inputLogin();
                    break;
        case 3 : cout<<"Exiting Program"; return 0;
                    break;
        default : cout<<"Choose Correct Option\n";
                    break;
    }
    return 0;
}
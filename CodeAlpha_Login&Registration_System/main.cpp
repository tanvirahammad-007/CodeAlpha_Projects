#include <bits/stdc++.h>
using namespace std;

void registeruser()
{
    string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    ofstream file(username + ".txt");

    file << username << endl
         << password;
    file.close();
    cout << "Registration successful!\n";
}
void loginuser()
{
    string username, password, fileuser, filepass;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    ifstream file(username + ".txt");

    if (!file)
    {
        cout << "User not found!\n";
        return;
    }
    getline(file, fileuser);
    getline(file, filepass);
    if (username == fileuser && password == filepass)
    {
        cout << "Login successful!\n";
    }
    else
    {
        cout << "Wrong Password!\n";
    }
    file.close();
}

int main()
{

    int choice;
    cout << "\n============================================" << endl;
    cout << "         Login & Registration System       " << endl;
    cout << "============================================" << endl;
        cout << "\n";
    cout << "1. Register\n2. Login\nEnter choice: ";
    cin >> choice;
    if (choice == 1)
    {
        registeruser();
    }
    else if (choice == 2)
    {
        loginuser();
    }
    else
    {
        cout << "Invalid option!\n";
    }

    return 0;
}

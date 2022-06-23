#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <string>
#include <ctime>
#include "Doctors.h"
using namespace std;

class Admin : public Doctor
{
private:
    string name;
    string password;
    string id;

public:
    Admin();
    ~Admin();
    string GetName() const
    {
        return name;
    }

    void SetName(string name)
    {
        this->name = name;
    }

    string GetPassword() const
    {
        return password;
    }

    void SetPassword(string password)
    {
        this->password = password;
    }

    string GetId() const
    {
        return id;
    }

    void SetId(string id)
    {
        this->id = id;
    }
    void reg()
    {
        string name, password;
        int id;
        srand(time(0));
        id = rand() % 1000 + 1;
        cout << "\nEnter your Name: ";
        cin >> name;
        cout << "\nEnter your Password: ";
        cin >> password;
        while (password.length() != 8)
        {
            cout << "\nPassword must be 8 digits. Enter Again!\nEnter your Password: ";
            cin >> password;
        }
        string sid = "A" + to_string(id);
        cout << "\nYour Registration id is : "
             << sid << endl;
        cout << "Please not it down, it will be used for your login." << endl;
        ofstream out;
        out.open("admin.txt", ios::app);
        out << "\n"
            << sid << " " << name << " " << password;
        out.close();
        setAdmin(sid);
    }
    void displayAdmin()
    {
        cout << "\n\n\tAdmin Details";
        cout << "\nID: " << this->id;
        cout << "\nName: " << this->name;
        cout << "\nPassword: " << this->password;
    }
    void login()
    {
        string name, id, temp, text;
        string tempName, tempId, password;
    LOGIN:
        cout << "\n\n\tLogin Panel";
        cout << "\nEnter your ID: ";
        cin >> id;
        cout << "\nEnter your Name: ";
        cin >> name;
        ifstream in;
        in.open("admin.txt");
        while (!in.eof())
        {
            in >> tempId;
            in >> tempName;
            in >> password;
            getline(in, text);
            if (tempId == id && tempName == name)
            {
                cout << "\nUser Found!";
                cout << "\nEnter Your Password: ";
                cin >> temp;
                getline(in, text);
                if (temp == password)
                {
                    cout << "\nLogin Successful.";
                    setAdmin(id);
                    return;
                }
                else
                {
                    cout << "\nPassword is Wrong!";
                    goto LOGIN;
                }
            }
        }
        cout << "\nUser not Found! Please Register.\n";
        in.close();
        reg();
        return;
    }
    void setAdmin(string id)
    {
        string temp, text;
        ifstream in;
        in.open("admin.txt");
        while (!in.eof())
        {
            in >> temp;
            if (temp == id)
            {
                this->id = temp;
                in >> temp;
                this->name = temp;
                in >> temp;
                this->password = temp;
            }
            else
                getline(in, text);
        }
        in.close();
    }
    void deleteAdmin()
    {
        string doctor, txt, temp, txt2;
        ifstream in, in2;
        ofstream out;
        in2.open("admin.txt");
        in.open("admin.txt");
        out.open("admins.txt");
        while (getline(in, txt))
        {
            in2 >> temp;
            if (temp != id)
            {
                out << txt << "\n";
                getline(in2, txt2);
            }
        }
        in.close();
        in2.close();
        out.close();
        remove("admin.txt");
        rename("admins.txt", "admin.txt");
    }
    void storeAdmin()
    {
        ofstream out;
        out.open("admin.txt", ios::app);
        out << endl
            << this->id << " " << this->name << " " << this->password;
        out.close();
    }
};

Admin::Admin()
{
}

Admin::~Admin()
{
}
#endif
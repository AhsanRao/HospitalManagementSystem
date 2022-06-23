#ifndef PATIENTS_H
#define PATIENTS_H
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "Doctors.h"
#include "Feedback.h"
using namespace std;

class Patient : public Doctor
{
private:
    string id;
    string name;
    string password;
    string cnic;
    int balance;
    Feedback feedback;

public:
    Patient();

    Feedback GetFeedback()
    {
        return feedback;
    }

    void SetFeedback(Feedback feedback)
    {
        this->feedback = feedback;
    }
    string GetId() const
    {
        return id;
    }
    void SetId(string id)
    {
        this->id = id;
    }
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
    string GetCnic() const
    {
        return cnic;
    }
    void SetCnic(string cnic)
    {
        this->cnic = cnic;
    }
    int GetBalance() const
    {
        return balance;
    }
    void SetBalance(int balance)
    {
        this->balance = balance;
    }
    void updateBalance()
    {
        int pay = Doctor::GetAppointment()->GetPayment().GetPay();
        balance = balance - pay;
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
        in.open("patients.txt");
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
                    setPatient(id);
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
    void setPatient(string id)
    {
        string temp, text;
        ifstream in;
        in.open("patients.txt");
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
                in >> temp;
                this->cnic = temp;
                in >> temp;
                this->balance = stoi(temp);
            }
            else
                getline(in, text);
        }
    }
    void reg()
    {
        string name, cnic, password;
        int id;
        srand(time(0));
        id = rand() % 1000 + 1;
        cout << "\nEnter your Name: ";
        cin >> name;
        cout << "\nEnter your Password: ";
        cin >> password;
        while (password.length() != 8)
        {
            cout << "\nPassword must be atleat 8 digits. Enter Again!\nEnter your Password: ";
            cin >> password;
        }
        cout << "\nEnter your CNIC: ";
        cin >> cnic;
        while (cnic.length() != 13)
        {
            cout << "\nCNIC must 13 digits. Enter Again!\nEnter your CNIC: ";
            cin >> cnic;
        }
        string sid = "P" + to_string(id);
        cout << "\nYour Registration id is : "
             << sid << endl;
        cout << "Please not it down, it will be used for your login." << endl;
        ofstream out;
        out.open("patients.txt", ios::app);
        out << "\n"
            << sid << " " << name << " " << password << " " << cnic << " " << this->balance;
        out.close();
        setPatient(sid);
    }
    string getPatientName(string id)
    {
        string temp, name, text;
        ifstream in;
        in.open("patients.txt");
        while (!in.eof())
        {
            in >> temp;
            if (temp == id)
            {
                in >> name;
                return name;
            }
            getline(in, text);
        }
        return "\0";
    }
    void displayPatient()
    {
        cout << "\n\n\tPatient Details";
        cout << "\nID: " << this->id;
        cout << "\nName: " << this->name;
        cout << "\nPassword: " << this->password;
        cout << "\nCNIC: " << this->cnic;
        cout << "\nBalance: " << this->balance << "\n";
    }
    void deletePatient()
    {
        string doctor, txt, temp, txt2;
        ifstream in, in2;
        ofstream out;
        in2.open("patients.txt");
        in.open("patients.txt");
        out.open("patient.txt");
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
        remove("patients.txt");
        rename("patient.txt", "patients.txt");
    }
    void storePatient()
    {
        ofstream out;
        out.open("patients.txt", ios::app);
        out << endl
            << this->id << " " << this->name << " " << this->password << " " << this->cnic << " " << this->balance;
        out.close();
    }
};

Patient::Patient()
{
    this->balance = 3500;
}
#endif
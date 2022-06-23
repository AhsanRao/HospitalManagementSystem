#ifndef DOCTORS_H
#define DOCTORS_H
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "Appointments.h"
using namespace std;

class Doctor
{
private:
    string id;
    string name;
    string speciality;
    int startTime;
    int endTime;
    string cnic;
    int charges;
    string password;
    string city;
    string hospital;
    int rating;
    int appointmentCount;
    Appointment *appointment;

public:
    Doctor();
    ~Doctor();
    string GetId() const
    {
        return id;
    }

    Appointment *GetAppointment() const
    {
        return appointment;
    }

    void SetAppointment(Appointment *appointment)
    {
        this->appointment = appointment;
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

    string GetSpeciality() const
    {
        return speciality;
    }

    void SetSpeciality(string speciality)
    {
        this->speciality = speciality;
    }

    int GetStartTime() const
    {
        return startTime;
    }

    void SetStartTime(int startTime)
    {
        this->startTime = startTime;
    }

    int GetEndTime() const
    {
        return endTime;
    }

    void SetEndTime(int endTime)
    {
        this->endTime = endTime;
    }

    string GetCnic() const
    {
        return cnic;
    }

    void SetCnic(string cnic)
    {
        this->cnic = cnic;
    }

    int GetCharges() const
    {
        return charges;
    }

    void SetCharges(int charges)
    {
        this->charges = charges;
    }

    string GetPassword() const
    {
        return password;
    }

    void SetPassword(string password)
    {
        this->password = password;
    }

    string GetCity() const
    {
        return city;
    }

    void SetCity(string city)
    {
        this->city = city;
    }

    string GetHospital() const
    {
        return hospital;
    }

    void SetHospital(string hospital)
    {
        this->hospital = hospital;
    }

    int GetRating() const
    {
        return rating;
    }

    void SetRating(int rating)
    {
        this->rating = rating;
    }

    int GetAppointmentCount() const
    {
        return appointmentCount;
    }
    void deleteDoctor()
    {
        string doctor, txt, temp, txt2;
        ifstream in, in2;
        ofstream out;
        in2.open("doctors.txt");
        in.open("doctors.txt");
        out.open("doctor.txt");
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
        remove("doctors.txt");
        rename("doctor.txt", "doctors.txt");
    }
    void updateRating(string id, int rat)
    {
        setDoctor(id);
        int temp = rating * appointmentCount;
        temp += rat;
        appointmentCount++;
        rating /= appointmentCount;
        deleteDoctor();
        storeDoctor();
    }
    void storeDoctor()
    {
        ofstream out;
        out.open("doctors.txt", ios::app);
        out << endl
            << this->id << " " << this->name << " " << this->password << " " << this->cnic << " " << this->speciality << " " << this->city << " " << this->hospital << " " << this->startTime << " " << this->endTime << " " << this->charges << " " << this->rating << " " << this->appointmentCount;
        out.close();
    }
    void SetAppointmentCount(int appointmentCount)
    {
        this->appointmentCount = appointmentCount;
    }
    void reg()
    {
        string name, speciality, cnic, password, hospital, city;
        int id, starttime, endtime, charges;
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
        cout << "\nEnter your Speciality: ";
        cin >> speciality;
        cout << "\nEnter your City: ";
        cin >> city;
        cout << "\nEnter your Hospital: ";
        cin >> hospital;
        cout << "\nEnter Your Avaliable Timings\nEnter Start Time: ";
        cin >> starttime;
        cout << "\nEnter your End Time: ";
        cin >> endtime;
        cout << "\nEnter Your Charges: ";
        cin >> charges;
        cout << "\nYour Registration id is : "
             << "D" << id << endl;
        cout << "Please not it down, it will be used for your login." << endl;
        ofstream out;
        out.open("doctors.txt", ios::app);
        string sid = "D" + to_string(id);
        out << endl
            << sid << " " << name << " " << password << " " << cnic << " " << speciality << " " << city << " " << hospital << " " << starttime << " " << endtime << " " << charges << " " << this->rating << " " << this->appointmentCount;

        out.close();
        setDoctor(sid);
    }
    void setDoctor(string id)
    {
        string temp, text;
        fstream in;
        in.open("doctors.txt");
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
                this->speciality = temp;
                in >> temp;
                this->city = temp;
                in >> temp;
                this->hospital = temp;
                in >> temp;
                this->startTime = stoi(temp);
                in >> temp;
                this->endTime = stoi(temp);
                in >> temp;
                this->charges = stoi(temp);
                in >> temp;
                this->rating = stoi(temp);
                in >> temp;
                this->appointmentCount = stoi(temp);
            }
            else
                getline(in, text);
        }
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
        in.open("doctors.txt");
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
                    setDoctor(id);
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
    void searchBySpeciality(string spec)
    {
        string name, id, password, cnic, speciality, temp;
        string text;
        ifstream in;
        bool check = false;
        in.open("doctors.txt");
        while (!in.eof())
        {
            in >> id;
            in >> name;
            in >> password;
            in >> cnic;
            in >> speciality;
            if (speciality == spec)
            {
                check = true;
                cout << "\n\tDoctor Details\nName: " << name << "\nID: " << id << "\nSpeciality: " << speciality;
                in >> temp;
                cout << "\nCity: " << temp;
                in >> temp;
                cout << "\nHospital: " << temp;
                in >> temp;
                in >> text;
                cout << "\nAvaliablity: " << temp << " to " << text;
                in >> temp;
                cout << "\nFee: " << temp;
                in >> temp;
                cout << "\nRating: " << temp << "\n\n";
                getline(in, text);
            }
            else
                getline(in, text);
        }
        if (check == false)
            cout << "\nNo Doctor Found!\n";
    }
    void searchByArea(string ar)
    {
        string name, id, password, cnic, speciality, area, temp;
        string text;
        ifstream in;
        bool check = false;
        in.open("doctors.txt");
        while (!in.eof())
        {
            in >> id;
            in >> name;
            in >> password;
            in >> cnic;
            in >> speciality;
            in >> area;
            if (area == ar)
            {
                check = true;
                cout << "\n\tDoctor Details\nName: " << name << "\nID: " << id << "\nSpeciality: " << speciality;
                cout << "\nCity: " << area;
                in >> temp;
                cout << "\nHospital: " << temp;
                in >> temp;
                in >> text;
                cout << "\nAvaliablity: " << temp << " to " << text;
                in >> temp;
                cout << "\nFee: " << temp;
                in >> temp;
                cout << "\nRating: " << temp << "\n\n";
                getline(in, text);
            }
            else
                getline(in, text);
        }
        if (check == false)
            cout << "\nNo Doctor Found!\n";
    }
    void searchByHospital(string hos)
    {
        string name, id, password, cnic, speciality, area, hospital, temp;
        string text;
        bool check = false;
        ifstream in;
        in.open("doctors.txt");
        while (!in.eof())
        {
            in >> id;
            in >> name;
            in >> password;
            in >> cnic;
            in >> speciality;
            in >> area;
            in >> hospital;
            if (hospital == hos)
            {
                check = true;
                cout << "\n\tDoctor Details\nName: " << name << "\nID: " << id << "\nSpeciality: " << speciality;
                cout << "\nCity: " << area;
                cout << "\nHospital: " << hospital;
                in >> temp;
                in >> text;
                cout << "\nAvaliablity: " << temp << " to " << text;
                in >> temp;
                cout << "\nFee: " << temp;
                in >> temp;
                cout << "\nRating: " << temp << "\n\n";
                getline(in, text);
            }
            else
                getline(in, text);
        }
        if (check == false)
            cout << "\nNo Doctor Found!\n";
    }
    string getDoctorName(string id)
    {
        string temp, name, text;
        ifstream in;
        in.open("doctors.txt");
        while (!in.eof())
        {
            in >> temp;
            if (temp == id)
            {
                in >> name;
                getline(in, text);
                return name;
            }
            else
                getline(in, text);
        }
        return "\0";
    }
    void changeAppointmentStatus(string pid)
    {
        appointmentCount++;
        appointment->setAppintment(this->id, pid);
        appointment->SetStatus("Confirmed");
        appointment->deleteAppointment(id, pid);
        appointment->storeAppointment();
    }
    void displayDoctor()
    {
        cout << "\n\tDoctor Details\nName: " << name << "\nID: " << id << "\nSpeciality: " << speciality;
        cout << "\nCity: " << city;
        cout << "\nHospital: " << hospital;
        cout << "\nAvaliablity: " << startTime << " to " << endTime;
        cout << "\nFee: " << charges;
        cout << "\nRating: " << rating << "\n";
    }
};

Doctor::Doctor()
{
    this->rating = 0;
    this->appointmentCount = 0;
    appointment = new Appointment;
}

Doctor::~Doctor()
{
}
#endif
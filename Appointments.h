#ifndef APPOINTMENTS_H
#define APPOINTMENTS_H
#include <iostream>
#include <string>
#include <fstream>
#include "Payment.h"
using namespace std;

class Appointment
{
private:
    string doctor_id;
    string patient_id;
    int time;
    string location;
    string type;
    int date;
    string status;
    Payment payment;

public:
    Appointment();
    Payment GetPayment() const
    {
        return payment;
    }

    void SetPayment(int charges)
    {
        if (type == "Physical")
            payment.SetPay(charges);
        if (type == "Online")
            payment.SetPay(charges - (charges * 30 / 100));
    }
    string GetPatient_id() const
    {
        return patient_id;
    }

    void SetPatient_id(string patient_id)
    {
        this->patient_id = patient_id;
    }

    string GetDoctor_id() const
    {
        return doctor_id;
    }

    void SetDoctor_id(string doctor_id)
    {
        this->doctor_id = doctor_id;
    }

    int GetTime() const
    {
        return time;
    }

    void SetTime(int time)
    {
        while (time > 24 || time <= 0)
        {
            cout << "\nInvalid Input";
            cout << "\nEnter Time(24-hour): ";
            cin >> time;
        }
        while (!checkValidity(doctor_id, time))
        {
            cout << "\nTime is Already Appointmented to Another Patient.";
            cout << "\nEnter Time(24-hour): ";
            cin >> time;
        }
        this->time = time;
    }

    string GetLocation() const
    {
        return location;
    }

    void SetLocation(string location)
    {
        this->location = location;
    }

    string GetType() const
    {
        return type;
    }

    void SetType(string type)
    {
        this->type = type;
    }

    int GetDate() const
    {
        return date;
    }

    void SetDate(int date)
    {
        this->date = date;
    }

    string GetStatus() const
    {
        return status;
    }

    void SetStatus(string status)
    {
        this->status = status;
    }
    void storeAppointment()
    {
        fstream out;
        out.open("appointments.txt", ios::app);
        out << "\n"
            << doctor_id << " " << patient_id << " " << location << " " << type << " " << date << " " << time << " " << status << " " << payment.GetPay() << " " << payment.GetPaymentType();
        out.close();
    }
    void bookAppointment(int pay)
    {
        string temp;
        int n;
        cout << "\nLocation: " << location << " Hospital" << endl;
        cout << "\n\tSelete Appointment Type";
        cout << "\n1.Physical";
        cout << "\n2.Online";
        cout << "\n\tEnter Choice: ";
        cin >> n;
        while (n != 1 && n != 2)
        {
            cout << "\nInvalid Input";
            cout << "\n\tSelete Appointment Type";
            cout << "\n1.Physical";
            cout << "\n2.Online";
            cin >> n;
        }
        if (n == 1)
            type = "Physical";
        if (n == 2)
            type = "Online";
        cout << "\nEnter Date of this Month(i.e 6): ";
        cin >> n;
        while (n > 31 || n <= 0)
        {
            cout << "\nInvalid Input";
            cout << "\nEnter Date of this Month(i.e 6): ";
            cin >> n;
        }
        date = n;
        cout << "\nEnter Time(24-hour): ";
        cin >> n;
        SetTime(n);
        SetPayment(pay);
        payment.recievePayment();
        storeAppointment();
    }
    bool setAppintment(string did, string pid)
    {
        string temp, doctor, patient, text;
        ifstream in;
        bool check = false;
        in.open("appointments.txt");
        while (!in.eof())
        {
            in >> doctor;
            in >> patient;
            if (doctor == did && patient == pid)
            {
                this->doctor_id = did;
                this->patient_id = pid;
                in >> temp;
                this->location = temp;
                in >> temp;
                this->type = temp;
                in >> temp;
                this->date = stoi(temp);
                in >> temp;
                this->time = stoi(temp);
                in >> temp;
                this->status = temp;
                in >> temp;
                payment.SetPay(stoi(temp));
                in >> temp;
                payment.SetPaymentType(temp);
                getline(in, text);
                return true;
            }
            else
                getline(in, text);
        }
        in.close();
        if (check == false)
        {
            cout << "\nNo Appointment Found.";
            return false;
        }
        else
            return true;
    }
    void display()
    {
        cout << "\n\tAppointment Details\n";
        cout << "Doctor ID: " << doctor_id << endl;
        cout << "Patient ID: " << patient_id << endl;
        cout << "Location: " << location << " Hospital" << endl;
        cout << "Type: " << type << endl;
        cout << "Date: " << date << " of This Month" << endl;
        cout << "Time: " << time << " o'clock" << endl;
        cout << "Payment: " << payment.GetPay() << endl;
        cout << "Payment Type: " << payment.GetPaymentType() << endl;
        cout << "Status: " << status << endl;
    }
    bool displayAppointmnet(string id, int num)
    {
        string txt, temp, temp2;
        ifstream in1;
        bool check = false;
        in1.open("appointments.txt");
        while (!in1.eof())
        {
            in1 >> temp;
            in1 >> temp2;
            getline(in1, txt);
            if (num == 0)
            {
                cout << temp << endl;
                if (id == temp)
                {
                    check = true;
                    setAppintment(temp, temp2);
                    cout << "\n\n\tAppointment Details";
                    cout << "\nDoctor ID: " << doctor_id;
                    cout << "\nPatient ID: " << patient_id;
                    cout << "\nLocation: " << location << " Hospital";
                    cout << "\nDate: " << date << " of this month";
                    cout << "\nTime: " << time << " o'clock";
                    cout << "\nAppointment Type: " << type;
                    cout << "\nFee: " << payment.GetPay();
                    cout << "\nType: " << payment.GetPaymentType();
                    cout << "\nStatus: " << status << endl;
                }
            }
            if (num == 1)
            {
                if (id == temp2)
                {
                    check = true;
                    setAppintment(temp, temp2);
                    cout << "\n\n\tAppointment Details";
                    cout << "\nDoctor ID: " << doctor_id;
                    cout << "\nPatient ID: " << patient_id;
                    cout << "\nLocation: " << location << " Hospital";
                    cout << "\nDate: " << date << " of this month";
                    cout << "\nTime: " << time << " o'clock";
                    cout << "\nAppointment Type: " << type;
                    cout << "\nFee: " << payment.GetPay();
                    cout << "\nType: " << payment.GetPaymentType();
                    cout << "\nStatus: " << status << endl;
                }
            }
        }
        in1.close();
        if (check == false)
        {
            cout << "\nNo Appointment Found.\n";
            return false;
        }
        else
            return true;
    }
    void deleteAppointment(string did, string pid)
    {
        string doctor, txt, temp, temp2, txt2;
        ifstream in, in2;
        ofstream out;
        in2.open("appointments.txt");
        in.open("appointments.txt");
        out.open("appointment.txt");
        while (getline(in, txt))
        {
            in2 >> temp;
            in2 >> temp2;
            if (temp != doctor_id && temp2 != patient_id)
            {
                out << txt << "\n";
                getline(in2, txt2);
                cout << txt2 << endl;
            }
        }
        in.close();
        in2.close();
        out.close();
        remove("appointments.txt");
        rename("appointment.txt", "appointments.txt");
    }
    bool checkValidity(string did, int time)
    {
        string doctor, txt, temp;
        fstream in;
        int tt;
        in.open("appointments.txt");
        while (!in.eof())
        {
            in >> doctor;
            if (doctor == did)
            {
                in >> temp;
                in >> temp;
                in >> temp;
                in >> temp;
                in >> temp;
                tt = stoi(temp);
                if (tt == time)
                    return false;
                getline(in, txt);
            }
            else
                getline(in, txt);
        }
        in.close();
        return true;
    }

    friend istream &operator>>(istream &in, Appointment &a);
};
istream &operator>>(istream &in, Appointment &a)
{
    cout << "\nEnter Doctor ID: ";
    in >> a.doctor_id;
    cout << "\nEnter Your ID:";
    in >> a.patient_id;
    cout << "\nEnter Location:";
    in >> a.location;
    cout << "\nEnter Appointment Type:";
    in >> a.type;
    cout << "\nEnter Date:";
    in >> a.date;
    cout << "\nEnter Time:";
    in >> a.time;
    while (!a.checkValidity(a.GetDoctor_id(), a.GetTime()))
    {
        cout << "\nTime is Already Appointmented to Other Patient.";
        cout << "\nEnter Time:";
        in >> a.time;
    }

    return in;
}
Appointment::Appointment()
{
    status = "Pending";
}
#endif
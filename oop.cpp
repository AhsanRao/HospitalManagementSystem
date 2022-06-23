#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "Doctors.h"
#include "Appointments.h"
#include "Payment.h"
#include "Patients.h"
#include "Feedback.h"
#include "Admin.h"

using namespace std;

int topup()
{
    cout << "Enter the amount you want to topup: ";
    int amount;
    cin >> amount;
Menu:
    cout << "\n\tSelect The Payment Method\n1. EasyPaisa\n2. Jazzcash\n3. PayPak\n4. UnionPay\n5. Bank Transfer";
    cout << "\n\tEnter Your Choice: ";
    int choice;
    string temp;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\nEnter Your EasyPaisa Number: ";
        cin >> temp;
        cout << amount << " ruppees has been deducted from your account\n";
        break;
    case 2:
        cout << "\nEnter Your Jazzcash Number: ";
        cin >> temp;
        cout << amount << " ruppees has been deducted from your account\n";
        break;
    case 3:
        cout << "\n\tEnter Your PayPak Card Number: ";
        cin >> temp;
        cout << "\nEnter your PayPak PIN: ";
        cin >> temp;
        cout << amount << " ruppees has been deducted from your account\n";
        break;
    case 4:
        cout << "\n\tEnter Your UnionPay Card Number: ";
        cin >> temp;
        cout << "\nEnter your UnionPay PIN: ";
        cin >> temp;
        cout << amount << " ruppees has been deducted from your account\n";
        break;
    case 5:
        cout << "\nEnter Your Bank Account Number: ";
        cin >> temp;
        cout << amount << " ruppees has been deducted from your account\n";
        break;
    default:
        cout << "\nInvalid Choice\n";
        goto Menu;
        break;
    }
    return amount;
}

int main()
{
    Doctor doctor;
    Admin admin;
    Patient patient;
    Appointment appointment;
    Payment payment;
    Feedback feedback;
    int choice = 9;
    while (choice != 0)
    {
    MainMenu:
        cout << "\n\tHospital Management System\n";
        cout << "\n1. Doctor";
        cout << "\n2. Patient";
        cout << "\n3. Admin";
        cout << "\n0. Exit";
        cout << "\n\tEnter your choice: ";
        cin >> choice;
        if (choice == 0)
        {
            cout << "\n\tThank you for using Hospital Management System";
            choice = 0;
            break;
        }
        else if (choice == 1)
        {
        DoctorLogin:
            cout << "\n1. Login";
            cout << "\n2. Register";
            cout << "\n\tEnter your choice: ";
            int temp;
            cin >> temp;
            switch (temp)
            {
            case 1:
                doctor.login();
                break;
            case 2:
                doctor.reg();
                break;
            default:
                cout << "\nEnter a Valid Choice";
                goto DoctorLogin;
                break;
            }
        DoctorMenu:
            cout << "\n\n1. Edit Your Avaliability Hours"
                 << "\n2. Delete Your Avaliability Hours"
                 << "\n3. Edit Your Charges"
                 << "\n4. Edit Your Location"
                 << "\n5. Delete Your Charges"
                 << "\n6. Display Your Details"
                 << "\n7. Dispplay Your Appointments"
                 << "\n8. Confirm Appointments"
                 << "\n0. Logout"
                 << "\n\tEnter your choice: ";
            int choicee, temp1, temp2;
            string tstr1, tstr2;
            cin >> choicee;
            switch (choicee)
            {
            case 0:
                goto MainMenu;
                break;
            case 1:
                cout << "\nEnter New Start Time: ";
                cin >> temp1;
                cout << "\nEnter New End Time: ";
                cin >> temp2;
                doctor.SetStartTime(temp1);
                doctor.SetEndTime(temp2);
                doctor.deleteDoctor();
                doctor.storeDoctor();
                break;
            case 2:
                doctor.SetStartTime(0);
                doctor.SetEndTime(0);
                doctor.deleteDoctor();
                doctor.storeDoctor();
                cout << "\nAvaliablity Hours Deleted";
                break;
            case 3:
                cout << "\nEnter New Charges: ";
                cin >> temp1;
                doctor.SetCharges(temp1);
                doctor.deleteDoctor();
                doctor.storeDoctor();
                cout << "\nCharges Updated";
                break;
            case 4:
                cout << "\nEnter Name of the New City: ";
                cin >> tstr1;
                cout << "\nEnter Name of the New Hospital: ";
                cin >> tstr2;
                doctor.SetCity(tstr1);
                doctor.SetHospital(tstr2);
                doctor.deleteDoctor();
                doctor.storeDoctor();
                cout << "\nLocation Updated";
                break;
            case 5:
                doctor.SetCharges(0);
                doctor.deleteDoctor();
                doctor.storeDoctor();
                cout << "\nCharges Deleted";
                break;
            case 6:
                doctor.displayDoctor();
                break;
            case 7:
                doctor.GetAppointment()->displayAppointmnet(doctor.GetId(), 0);
                break;
            case 8:
                cout << "\nEnter Patient ID: ";
                cin >> tstr1;
                if (doctor.GetAppointment()->setAppintment(doctor.GetId(), tstr1) == false)
                {
                    cout << "\nNo appointment found with this patient";
                    goto DoctorMenu;
                }
                if (doctor.GetAppointment()->GetStatus() == "Confirmed")
                {
                    cout << "\nAppointment Already Confirmed.";
                    goto DoctorMenu;
                }
                doctor.changeAppointmentStatus("Confirmed");
                cout << "\nAppointment Confirmed";
                doctor.GetAppointment()->display();
                doctor.GetAppointment()->deleteAppointment(doctor.GetId(), tstr1);
                doctor.GetAppointment()->storeAppointment();
                cout << endl;
                break;
            default:
                cout << "\nEnter a Valid Choice";
                goto DoctorLogin;
                break;
            }
            goto DoctorMenu;
        }
        else if (choice == 2)
        {
        PatientLogin:
            cout << "\n1. Login";
            cout << "\n2. Register";
            cout << "\n\tEnter your choice: ";
            int temp;
            cin >> temp;
            switch (temp)
            {
            case 1:
                patient.login();
                break;
            case 2:
                patient.reg();
                break;
            default:
                cout << "\nEnter a Valid Choice";
                goto PatientLogin;
                break;
            }
        PatientMenu:
            cout << "\n\n1. Edit Your Details"
                 << "\n2. Display Your Details"
                 << "\n3. Display Your Appointments"
                 << "\n4. Topup Your Balace"
                 << "\n5. Seach Doctor By Speciality"
                 << "\n6. Seach Doctor By City"
                 << "\n7. Seach Doctor By Hospital"
                 << "\n8. Book Appointment"
                 << "\n9. Edit Appoinment Time"
                 << "\n10. Cancel Appointment";
            cout << "\n11. Give Feedback";
            cout << "\n0. Logout"
                 << "\n\tEnter your choice: ";
            int choicee, temp1, temp2;
            string tstr1, tstr2;
            cin >> choicee;
            switch (choicee)
            {
            case 0:
                goto MainMenu;
                break;
            case 1:
                cout << "\nYour Name: " << patient.GetName();
                cout << "\nEnter New Name: ";
                cin >> tstr1;
                cout << "\nYour Cnic: " << patient.GetCnic();
                cout << "\nEnter New Cnic: ";
                cin >> tstr2;
                patient.SetName(tstr1);
                patient.SetCnic(tstr2);
                cout << "\nYour Password: " << patient.GetPassword();
                cout << "\nEnter New Password: ";
                cin >> tstr1;
                patient.SetPassword(tstr1);
                patient.deletePatient();
                patient.storePatient();
                cout << "\nDetails Updated\n\n";
                break;
            case 2:
                patient.displayPatient();
                cout << endl
                     << endl;
                break;
            case 3:
                patient.GetAppointment()->displayAppointmnet(patient.GetId(), 1);
                break;
            case 4:
                patient.SetBalance(patient.GetBalance() + topup());
                cout << "\nBalance Updated Successfully!" << endl;
                patient.deletePatient();
                patient.storePatient();
                break;
            case 5:
                cout << "\nEnter Speciality: ";
                cin >> tstr1;
                patient.searchBySpeciality(tstr1);
                break;
            case 6:
                cout << "\nEnter City: ";
                cin >> tstr1;
                patient.searchByArea(tstr1);
                break;
            case 7:
                cout << "\nEnter Hospital: ";
                cin >> tstr1;
                patient.searchByHospital(tstr1);
                break;
            case 8:
                cout << "\nEnter Doctor ID: ";
                cin >> tstr1;
                tstr2 = patient.getDoctorName(tstr1);
                while (tstr2 == "\0")
                {
                    cout << "\nNo Doctor Found with this ID.\nEnter Valid ID To Book Appointment.";
                    cout << "\nEnter Doctor ID: ";
                    cin >> tstr1;
                }
                patient.GetAppointment()->SetDoctor_id(tstr1);
                patient.setDoctor(patient.GetAppointment()->GetDoctor_id());
                patient.GetAppointment()->SetPatient_id(patient.GetId());
                patient.GetAppointment()->SetLocation(patient.GetHospital());
                patient.GetAppointment()->bookAppointment(patient.GetCharges());
                patient.updateBalance();
                cout << "\nAppointment Booked.\n";
                patient.GetAppointment()->display();
                cout << endl;
                break;
            case 9:
                cout << "\nEnter Doctor ID: ";
                cin >> tstr1;
                tstr2 = patient.getDoctorName(tstr1);
                while (tstr2 == "\0")
                {
                    cout << "\nNo Doctor Found with this ID.\nEnter Valid ID To Book Appointment.";
                    cout << "\nEnter Doctor ID: ";
                    cin >> tstr1;
                }
                patient.GetAppointment()->setAppintment(tstr1, patient.GetId());
                cout << "\nEnter New Appoinment Time: ";
                cin >> temp1;
                patient.GetAppointment()->SetTime(temp1);
                patient.GetAppointment()->deleteAppointment(tstr1, patient.GetId());
                patient.GetAppointment()->storeAppointment();
                break;
            case 10:
                cout << "\nEnter Doctor ID: ";
                cin >> tstr1;
                tstr2 = patient.getDoctorName(tstr1);
                while (tstr2 == "\0")
                {
                    cout << "\nNo Doctor Found with this ID.\nEnter Valid ID To Book Appointment.";
                    cout << "\nEnter Doctor ID: ";
                    cin >> tstr1;
                }
                patient.GetAppointment()->setAppintment(tstr1, patient.GetId());
                patient.GetAppointment()->deleteAppointment(tstr1, patient.GetId());
                break;
            case 11:
                cout << "\nEnter Doctor ID: ";
                cin >> tstr1;
                if (patient.GetAppointment()->setAppintment(tstr1, patient.GetId()) == false)
                {
                    cout << "\nNo Appointment with this Doctor.";
                    goto PatientMenu;
                }
                if (patient.GetAppointment()->GetStatus() == "Pending")
                {
                    cout << "\nAppointment Not Approved Yet.\nYou Cannot Give Feedback Yet.\n";
                    goto PatientMenu;
                }
                cout << "\nEnter Feedback: ";
                cin >> tstr2;
                cout << "\nGive Rating (1 to 5): ";
                cin >> temp;
                feedback.SetFeed(tstr2);
                feedback.SetRating(temp);
                feedback.storeFeedback(patient.GetAppointment()->GetDoctor_id(), patient.GetId());
                patient.updateRating(tstr1, temp);
                break;
            default:
                cout << "\nEnter a Valid Choice";
                goto PatientLogin;
                break;
            }
            goto PatientMenu;
        }
        else if (choice == 3)
        {
        AdminLogin:
            cout << "\n1. Login";
            cout << "\n2. Register";
            cout << "\n\tEnter your choice: ";
            int temp;
            cin >> temp;
            switch (temp)
            {
            case 1:
                admin.login();
                break;
            case 2:
                admin.reg();
                break;
            default:
                cout << "\nEnter a Valid Choice";
                goto AdminLogin;
                break;
            }
        AdminMenu:
            cout << "\n\n1. Edit Your Details"
                 << "\n2. Display Your Details"
                 << "\n3. Delete Docotr";
            cout << "\n0. Logout"
                 << "\n\tEnter your choice: ";
            int choicee, temp1, temp2;
            string tstr1, tstr2;
            cin >> choicee;
            switch (choicee)
            {
            case 0:
                goto MainMenu;
                break;
            case 1:
                cout << "\nYour Name: " << admin.GetName();
                cout << "\nEnter New Name: ";
                cin >> tstr1;
                admin.SetName(tstr1);
                cout << "\nYour Password: " << admin.GetPassword();
                cout << "\nEnter New Password: ";
                cin >> tstr1;
                admin.SetPassword(tstr1);
                admin.deleteAdmin();
                admin.storeAdmin();
                cout << "\nDetails Updated\n\n";
                break;
            case 2:
                admin.displayAdmin();
                break;
            case 3:
                cout << "\nEnter ID: ";
                cin >> tstr1;
                admin.setDoctor(tstr1);
                admin.deleteDoctor();
                cout << "\nDoctors Deleted Successfully!";
                break;
            default:
                cout << "\nEnter a Valid Choice";
                goto AdminMenu;
                break;
            }
            goto AdminMenu;
        }
        else
        {
            cout << "\nEnter a Valid Choice";
            goto MainMenu;
        }
    }
}
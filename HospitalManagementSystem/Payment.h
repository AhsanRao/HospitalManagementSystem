#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
using namespace std;
#include <string>
class Payment
{
private:
    string paymentType;
    int payment;

public:
    Payment();
    ~Payment();
    string GetPaymentType() const
    {
        return paymentType;
    }

    void SetPaymentType(string paymentType)
    {
        this->paymentType = paymentType;
    }

    int GetPay() const
    {
        return payment;
    }

    void SetPay(int payment)
    {
        this->payment = payment;
    }
    int calculatePayment()
    {
        cout << "payment";
        return 0;
    }
    void recievePayment()
    {
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
            cout << payment << " ruppees has been deducted from your account\n";
            paymentType = "EasyPaisa";
            break;
        case 2:
            cout << "\nEnter Your Jazzcash Number: ";
            cin >> temp;
            cout << payment << " ruppees has been deducted from your account\n";
            paymentType = "Jazzcash";
            break;
        case 3:
            cout << "\nEnter Your PayPak Card Number: ";
            cin >> temp;
            cout << "\nEnter your PayPak PIN: ";
            paymentType = "PayPak";
            cin >> temp;
            cout << payment << " ruppees has been deducted from your account\n";
            break;
        case 4:
            cout << "\nEnter Your UnionPay Card Number: ";
            cin >> temp;
            cout << "\nEnter your UnionPay PIN: ";
            cin >> temp;
            cout << payment << " ruppees has been deducted from your account\n";
            paymentType = "UnionPay";
            break;
        case 5:
            cout << "\nEnter Your Bank Account Number: ";
            cin >> temp;
            cout << payment << " ruppees has been deducted from your account\n";
            paymentType = "Bank Transfer";
            break;
        default:
            cout << "\nInvalid Choice\n";
            goto Menu;
            break;
        }
        return;
    }
};
Payment::Payment()
{
}
Payment::~Payment()
{
}
#endif
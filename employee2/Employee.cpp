#pragma once
#include <bits/stdc++.h> // for range

using namespace std;

class Employee{
private:
    string name;
    int paymentPerHour;
public:
    Employee(string name, int paymentPerHour): name(name), paymentPerHour(paymentPerHour) {}
    void setName(string name){
        this->name = name;
    }
    void setPaymentPerHour(int paymentPerHour){
        this->paymentPerHour = paymentPerHour;
    }
    string getName(){
        return name;
    }
    int getPaymentPerHour() {
        return paymentPerHour;
    }
    virtual int calculateSalary() = 0;
};
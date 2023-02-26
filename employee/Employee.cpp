#pragma once
#include <bits/stdc++.h>

using namespace std;

class Employee{
private:
    string name;
    int salary;
public:
    Employee(string name, int salary) : name(name), salary(salary) {}
    void setName(string name) { this->name = name; }
    void setSalary(int salary){ this->salary = salary; }
    string getName(){ return name;}
    int getSalary(){ return salary;}
    void display(){
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};m
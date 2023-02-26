#pragma once
#include <bits/stdc++.h>

using namespace std;

class Customer {
private:
    int id;
    string name;
    int discount;
public:
    Customer(){}
    Customer(int id, string name, int discount): id(id), name(name), discount(discount) {}
    int getId(){
        return id; 
    }
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }
    void setDiscount(int discount){
        this->discount = discount;
    }
    int getDiscount(){
        return discount;
    }
};
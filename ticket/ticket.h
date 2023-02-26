#pragma once
#include <cstring>
#include <iostream>
using namespace std;
class ticket
{
protected:
    string id;
    string name;
    string namsinh;

public:
    virtual void input();
    virtual void output();
    virtual long price() = 0;
    virtual bool isPractice() = 0;
    virtual bool isStandard() = 0;
    virtual long GetExtraServices() = 0;
};
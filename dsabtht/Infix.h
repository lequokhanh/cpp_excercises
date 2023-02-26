#pragma once
#include "Stack.h"
#include <sstream>
#include <vector>

class Infix
{
public:
    Infix();
    ~Infix();
    string *parseInput(string Input, int &iLength);
    int UT(string x);
    int HT(string x);
    string calculateValue(string b, string x, string a);
    float calculateValue(vector<string> M);
};
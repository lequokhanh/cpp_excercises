#pragma once

#include <string>
using namespace std;

typedef string Data;

class Node
{
private:
    Data Info;
    Node *pNext;

public:
    friend class Stack;
    friend class Infix;
};
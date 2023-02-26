#pragma once
#include "ticket.h"
class standard : public ticket
{
private:
    /* data */
    int services;

public:
    void input();
    void output();
    long price();
    long GetExtraServices();
    bool isPractice();
    bool isStandard();
};

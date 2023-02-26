#pragma once
#include "ticket.h"
class practice : public ticket
{
private:
    /* data */
    long hour;

public:
    void input();
    void output();
    long price();
    bool isPractice();
    bool isStandard();
    long GetExtraServices();
};

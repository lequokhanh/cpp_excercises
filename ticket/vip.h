#pragma once
#include "ticket.h"
class vip : public ticket
{
public:
    void input();
    long price();
    bool isPractice();
    bool isStandard();
    long GetExtraServices();
};
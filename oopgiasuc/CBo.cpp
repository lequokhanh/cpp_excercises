#include "CBo.h"

void CBo::Keu()
{
    cout << "moo moo";
}

int CBo::Sinh()
{
    return 1 + rand() % 8;
}

int CBo::Sua()
{
    return rand() % 5;
}
string CBo::GetLoai()
{
    return "Bo";
}
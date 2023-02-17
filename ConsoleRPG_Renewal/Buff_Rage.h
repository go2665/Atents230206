#pragma once
#include <iostream>
#include "BuffBase.h"

class Buff_Rage : public BuffBase
{
public:
    Buff_Rage()
    {
        strcpy_s(name, "ºÐ³ë");
    }
};


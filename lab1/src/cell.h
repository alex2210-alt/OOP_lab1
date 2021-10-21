#pragma once
#include "entity.h"

class cell{
    bool pass;// 1 - да, 0 - нет
    entity unit;
public:
    cell(bool pass = 1, entity unit = entity());
    void set_pass();
    bool get_pass();
};

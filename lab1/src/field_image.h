#pragma once
#include <fstream>
#include <vector>
#include "field.h"


class field_image{
    field& obj;
public:
    field_image(field& obj);
    void read_features();
    void print_board();
    void modify_board();
};

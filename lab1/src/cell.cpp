#include "cell.h"
cell::cell(bool pass, entity unit):pass(pass), unit(unit){}
void cell::set_pass(){
    pass = 0;
}
bool cell::get_pass(){
    return this->pass;
}


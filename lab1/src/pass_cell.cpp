#include "pass_cell.h"
pass_cell::pass_cell(std::size_t x, std::size_t y): x(x), y(y){}
void pass_cell::set_cell(std::size_t x, std::size_t y){
    this->x = x;
    this->y = y;
}
std::vector<std::size_t> pass_cell::get_cell(){
    std::vector<std::size_t> ret;
    ret.push_back(this->x);
    ret.push_back(this->y);
    return ret;
}

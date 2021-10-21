#pragma once
#include <vector>


class pass_cell{
protected:
    std::size_t x;
    std::size_t y;
public:
    pass_cell(std::size_t x = 0, std::size_t y = 0);
    void set_cell(std::size_t x, std::size_t y);
    std::vector<std::size_t> get_cell();
};

#pragma once
#include <vector>
#include "pass_cell.h"
#include "entity.h"
#include "cell.h"

class field{
    std::size_t width;
    std::size_t height;
    cell** board;
    std::size_t q_unpass;
    pass_cell entry;
    pass_cell exit;
public:
    field(std::size_t width = 0, std::size_t height = 0, std::size_t q_unpass = 0, pass_cell entry = pass_cell(), pass_cell exit = pass_cell());
    field(const field& other);
    field& operator=(const field& other);
    field(field&& other);
    field& operator=(field&& other);
    ~field();
    void generate_io();
    void generate_unpass();
    void set_features(std::vector<std::size_t> temp);
    std::size_t get_width();
    std::size_t get_height();
    cell** get_board();
    std::vector<std::size_t> get_entry();
    std::vector<std::size_t> get_exit();
};

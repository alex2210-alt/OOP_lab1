#include "field.h"

field::field(std::size_t width, std::size_t height, std::size_t q_unpass, pass_cell entry, pass_cell exit):width(width), height(height), q_unpass(q_unpass), entry(entry), exit(exit){
    if(width && height){
        board = new cell*[width];
        for(std::size_t i = 0;i < width; i++){
            board[i] = new cell[height];
        }
    }
}
field::field(const field& other):width(other.width), height(other.height), q_unpass(other.q_unpass), entry(other.entry), exit(other.exit){
    if(width && height){
        board = new cell*[width];
        for(std::size_t i = 0; i < width; i++){
           board[i] = new cell[height];
        }
    }
    for(std::size_t i = 0; i < width; i++)
        for(std::size_t j = 0; j < height; j++)
            board[i][j] = other.board[i][j];
}
field& field::operator=(const field& other){
    if(this != &other){
        if(width && height){
            for(std::size_t i = 0; i < width; i++)
                delete[] board[i];
            delete[] board;
        }
        width = other.width;
        height = other.height;
        q_unpass = other.q_unpass;
        entry = other.entry;
        exit = other.exit;
        if(other.width && other.height){
            board = new cell*[other.width];
            for(std::size_t i = 0; i<other.width; i++)
                board[i] = new cell[other.height];
            for(std::size_t i = 0; i < other.width; i++)
                for(std::size_t j = 0; j < other.height; j++)
                    board[i][j] = other.board[i][j];
        }
    }
    return *this;
}
field::field(field&& other){
    std::swap(width, other.width);
    std::swap(height, other.height);
    std::swap(q_unpass, other.q_unpass);
    std::swap(board, other.board);
    std::swap(entry, other.entry);
    std::swap(exit, other.exit);
}
field& field::operator=(field&& other){
    if(this != &other){
        std::swap(width, other.width);
        std::swap(height, other.height);
        std::swap(board, other.board); 
        std::swap(height, other.height);
        std::swap(entry, other.entry);
        std::swap(exit, other.exit);
    }
    return *this;
}
field::~field(){
    if(width && height){
        for(size_t i = 0; i<width; i++)
            delete[] board[i];
        delete[] board;
    }
}
void field::generate_io(){
    std::size_t temp_ix, temp_iy;
    std::size_t temp_ox, temp_oy;
    temp_ix = std::rand() % (width-2) + 1;
    temp_iy = std::rand() % (height-2) + 1;
    temp_ox = std::rand() % width;
    temp_oy = std::rand() % height;
    entry.set_cell(temp_ix, temp_iy);
    while(temp_ox == temp_ix && temp_ox == temp_ix -1 && temp_ox == temp_ix +1 && temp_oy == temp_iy && temp_oy == temp_iy -1 && temp_oy == temp_iy +1){
        temp_ox = std::rand() % width;
        temp_oy = std::rand() % height;
    }
    exit.set_cell(temp_ox, temp_oy);
}
void field::generate_unpass(){
    std::size_t temp_x, temp_y;
    temp_x = std::rand() % width;
    temp_y = std::rand() % height;
    std::vector<std::size_t> check_i;
    std::vector<std::size_t> check_o;
    check_i = entry.get_cell();
    check_o = exit.get_cell();
    for(std::size_t i = 0; i < q_unpass; i++){
        while(((temp_x == check_i[0] && temp_y == check_i[1]) || (temp_x == check_o[0] && temp_y == check_o[1])) || !board[temp_x][temp_y].get_pass()){
            temp_x = std::rand() % width;
            temp_y = std::rand() % height;
        }
        board[temp_x][temp_y].set_pass();
    }
}
void field::set_features(std::vector<std::size_t> temp){
    if(width && height){
        for(std::size_t i =0; i < width; i++){
            delete[] board[i];
        }
        delete[] board;
    }
    this->width = temp[0];
    this->height = temp[1];
    this->q_unpass = temp[2];
    if(width && height){
        board = new cell*[width];
        for(std::size_t i = 0; i < width; i++){
            board[i] = new cell[height];
        }
    }
    return;
}
std::size_t field::get_width(){
    return this->width;
}
std::size_t field::get_height(){
    return this->height;
}
cell** field::get_board(){
    return this->board;
}
std::vector<std::size_t> field::get_entry(){
    return entry.get_cell();
}
std::vector<std::size_t> field::get_exit(){
    return exit.get_cell();
}

#include "field_image.h"

field_image::field_image(field& obj):obj(obj){}
void field_image::read_features(){
    std::ifstream in("../parametrs.txt");
    char word[20];
    std::vector<size_t> temp;
    for(int i = 0; i<3; i++){
        in >> word;
        temp.push_back(atoi(word));
    }
    obj.set_features(temp); 
    return;
}
void field_image::print_board(){
    remove("./board.txt");
    cell** temp_board = obj.get_board();
    std::vector<size_t> check_i = obj.get_entry();
    std::vector<size_t> check_o = obj.get_exit();
    std::ofstream out("./board.txt", std::ios::app);
    if(out.is_open()){
        for(size_t i=0; i<obj.get_width();i++){
            for(size_t j = 0; j< obj.get_height(); j++){
                if(check_i[0] == i && check_i[1] ==j){
                    out << "I";
                } else if(check_o[0] == i && check_o[1] ==j){
                    out << "O";
                } else if(temp_board[i][j].get_pass()){
                    out << ".";
                } else 
                    out << "X";
            }
            out << "\n";
        }
    }
    out.close();
}
void field_image::modify_board(){
    obj.generate_io();
    obj.generate_unpass();
}

#include "userAction.h"
void userAction(field_image& obj){
    obj.read_features();
    obj.modify_board();
    obj.print_board();
}

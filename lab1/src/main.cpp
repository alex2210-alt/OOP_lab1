#include "field.h"
#include "userAction.h"

int main(){
    srand(static_cast<unsigned int>(time(0)));
    field game{};
    field_image game_image{game};
    userAction(game_image);
    return 0;
}


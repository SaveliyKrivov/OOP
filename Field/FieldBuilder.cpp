#include "FieldBuilder.h"

FieldBuilder::FieldBuilder(Field& field, Player& player, Controller& cl, int level) : field(field), player(player), cl(cl), level(level) {}

void FieldBuilder::buildField() {
    switch(level) {
        case 1:
            field = Field(DIMENSION_X_1, DIMENSION_Y_1);
            break;
        case 2:
            field = Field(DIMENSION_X_2, DIMENSION_Y_2);
            break;
        default:
            field = Field();
    }
    for(int i = 0; i <field.getHeight(); i++){
        for(int j = 0; j < field.getWidth(); j++){
            if ((i - j) % 4 == 0 && i % 2 == 0 && j % 4 == 0){
                field.getCell(i, j).setEvent(new Heal(player));
            }
            else if (((i - j) % 6 == 0 && i % 2 == 0 && j % 5 == 0) || (i % 3 == 0 && j % 3 == 1)){
                field.getCell(i, j).setEvent(new Enemy(player));
            }
            else if ((i + j) % 4 == 0 && i % 6 == 0){
                field.getCell(i, j).setEvent(new Coin(player));
            }
            else if ((i + j) % 3 == 0 && i % 2 == 0 and j % 6 == 0){
                field.getCell(i, j).setEvent(nullptr);
                field.getCell(i, j).setState(false);
            }
            else if (i == 2 && j == 2){
                field.getCell(i, j).setEvent(new Teleport(player, cl, field));
            }
//            else if (x == (field->get_width() - 1) && y == (field->get_height() / 2))
        }
    }
}

#include "FieldBuilder.h"

FieldBuilder::FieldBuilder(Field& field, Player& player, Controller& cl) : field(field), player(player), cl(cl) {}

void FieldBuilder::buildField() {
    for(int i = 0; i <field.getHeight(); i++){
        for(int j = 0; j < field.getWidth(); j++){
            if ((i - j) % 4 == 0 && i % 2 == 0 && j % 4 == 0){
                field.getCell(i, j).setEvent(new Heal(player));
            }
            else if ((i - j) % 7 == 0 && i % 5 == 0){
                field.getCell(i, j).setEvent(new Enemy(player));
            }
            else if ((i + j) % 4 == 0 && i % 6 == 0){
                field.getCell(i, j).setEvent(new Coin(player));
            }
            else if ((i + j) % 3 == 0 && i % 2 == 0 and j % 6 == 0){
                field.getCell(i, j).setEvent(nullptr);
                field.getCell(i, j).setState(false);
            }
            else if (i == (field.getWidth() / 2 - 1) && j == (field.getHeight() / 2)){
                field.getCell(i, j).setEvent(new Teleport(player, cl, field));
            }
        }
    }
}

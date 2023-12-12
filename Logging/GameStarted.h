#include "Message.h"
#include "../Field/Field.h"
#ifndef OOP_GAMESTARTED_H
#define OOP_GAMESTARTED_H


class GameStarted: public Message {
public:
    GameStarted(Field& field);
    void print(std::ostream& os) const override;

private:
    Field &field;
};


#endif //OOP_GAMESTARTED_H

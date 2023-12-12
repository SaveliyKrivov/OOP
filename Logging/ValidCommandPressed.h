#include "Message.h"
#include "../GameExecution/ReadFile.h"

#ifndef OOP_VALIDCOMMANDPRESSED_H
#define OOP_VALIDCOMMANDPRESSED_H


class ValidCommandPressed: public Message {
public:
    ValidCommandPressed(std::string keyPressed, Direction direction);
    void print(std::ostream& os) const override;

private:
    std::string keyPressed;
    std::string str_direction;
};


#endif //OOP_VALIDCOMMANDPRESSED_H

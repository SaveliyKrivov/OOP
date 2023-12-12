#include "Message.h"
#ifndef OOP_INVALIDCOMMANDPRESSED_H
#define OOP_INVALIDCOMMANDPRESSED_H


class InvalidCommandPressed: public Message {
public:
    InvalidCommandPressed(std::string keyPressed);
    void print(std::ostream& os) const override;

private:
    std::string keyPressed;
};


#endif //OOP_INVALIDCOMMANDPRESSED_H

#include "Message.h"

std::ostream& operator<<(std::ostream& os, const Message& msg) {
    // Call the print method of the Message class
    msg.print(os);
    return os;
}
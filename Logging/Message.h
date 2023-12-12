#include <ostream>
#ifndef OOP_MESSAGE_H
#define OOP_MESSAGE_H


class Message {
public:
    virtual ~Message() = default; // Virtual destructor
    virtual void print(std::ostream& os) const = 0; // Pure virtual function
    friend std::ostream& operator<<(std::ostream& os, const Message& msg);
};

#endif //OOP_MESSAGE_H

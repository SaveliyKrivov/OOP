#include <ostream>
#include "Message.h"
#include <vector>
#ifndef OOP_MESSAGEHANDLER_H
#define OOP_MESSAGEHANDLER_H


class MessageHandler {
public:
    MessageHandler(std::ostream& os);

    void trackMessage(const Message& msg);

    void sendMessages();

private:
    std::vector<const Message*> m_messages;
    std::ostream& m_os;
};


#endif //OOP_MESSAGEHANDLER_H

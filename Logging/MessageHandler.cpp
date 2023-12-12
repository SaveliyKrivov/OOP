
#include "MessageHandler.h"

MessageHandler::MessageHandler(std::ostream& os) : m_os(os) {}


void MessageHandler::trackMessage(const Message& msg) {
    m_messages.push_back(&msg);
}

void MessageHandler::sendMessages() {
    for (const auto& msg : m_messages) {
        m_os << *msg << '\n';
        delete msg;
    }
    m_messages.clear();
}
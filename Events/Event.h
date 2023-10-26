#ifndef OOP_EVENT_H
#define OOP_EVENT_H
class Event{
public:
    virtual void execute() = 0;
    virtual ~Event() = default;

};
#endif //OOP_EVENT_H

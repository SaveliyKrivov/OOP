#ifndef OOP_MONITOR_H
#define OOP_MONITOR_H


class Monitor {
public:
    virtual ~Monitor() = default;
    virtual bool update() = 0;
};


#endif //OOP_MONITOR_H

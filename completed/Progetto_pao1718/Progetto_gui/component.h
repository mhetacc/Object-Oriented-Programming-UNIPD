#ifndef COMPONENT_H
#define COMPONENT_H
#include<QString>

class Component
{
public:
    double getScore() const;
    virtual ~Component() =default;
    QString getPrint() const;
};

#endif // COMPONENT_H

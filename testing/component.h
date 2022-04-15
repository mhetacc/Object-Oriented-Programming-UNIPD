#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
public:
    virtual double getScore() const=0;
    virtual ~Component() =default;
};



#endif // COMPONENT_H

#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include "subscriptionType.h"
#include "observer.h"
class Cell;

class Subject {
protected:
    std::vector<Observer *> observers;
public:
    Subject();
    void attach(Observer *c);
    void notifyObservers(SubscriptionType t);
    virtual ~Subject()=0;
    virtual SubscriptionType subType() = 0;
};

#endif

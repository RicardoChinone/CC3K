#ifndef __OBSERVER_H_
#define __OBSERVER_H_
#include "subscriptionType.h"

class Subject;

class Observer {
public:
    virtual void notify(Subject &whoNotified) = 0;
    virtual SubscriptionType subType()= 0;
    virtual ~Observer() = default;
};

#endif

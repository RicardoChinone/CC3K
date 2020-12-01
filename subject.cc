#include "subject.h"

//constructor
Subject::Subject() {}

//destructor
Subject::~Subject() {}

//attach a single observer object o for one subject, used for gameplay
void Subject::attach(Observer *o) {
    observers.emplace_back(o);
}

//notify the observers who have the subscriptionType t
void Subject::notifyObservers(SubscriptionType t) {
    for (auto ob: observers) {
        if(((ob->subType() == SubscriptionType::Hoard) ||
            (ob->subType() == SubscriptionType::Dragon) ||
            (ob->subType() == SubscriptionType::Enemy)) && (t == SubscriptionType::Player)) {
            ob->notify(*this);
        }
        else if ((ob->subType() == SubscriptionType::Hoard) && (t == SubscriptionType::Dragon)) {
            ob->notify(*this);
        }
    }
}


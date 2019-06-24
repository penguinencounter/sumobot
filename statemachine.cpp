#include "statemachine.h"

namespace statemachine
{

Event::Event (char * name) : name(name) {}
Event::Event () : name(nullptr) {}
void Event::markProcessed () {
    /*
    Mark a event as 'processed' and mark it for deletion from the event queue.
     */
    this->processed = true;
}
char * Event::getName () {
    return this->name;
}

EventQueue::EventQueue () {}
void EventQueue::pushEvent (Event * event) {
    for (int idx = 0; idx < 10; idx += 1) {
        if (this->queue[idx].getName() == nullptr) {
            this->queue[idx] = event;
            break;
        }
    }
}

} // namespace statemachine

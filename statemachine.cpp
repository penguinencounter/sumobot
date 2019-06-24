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
        /*
        Add an event to the queue.
        */
        for (int idx = 0; idx < 10; idx += 1) {
            if (this->queue[idx]->getName() == nullptr) {
                this->queue[idx] = event;
                break;
            }
        }
    }
    Event * EventQueue::getEventWithName (char * name) {
        /*
        Finds first event with specified name in the queue.
        Returns nullptr if not found.
        */
        for (int idx = 0; idx < 10; idx += 1) {
            if (this->queue[idx]->getName() == name) {
                return this->queue[idx];
            }
        }
        return nullptr;
    }
    void EventQueue::discard () {
        /*
        Empty the event queue
         */
        for (int itr = 0; itr < 10; itr += 1) {
            this->queue[itr] = &Event(nullptr);
        }
    }
    int EventQueue::discardProcessedEvents () {
        for (int itr = 0; itr < 10; itr += 1) {
            
        }
    }
} // namespace statemachine

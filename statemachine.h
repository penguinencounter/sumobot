#pragma once

namespace statemachine
{
    class Event
    {
        char * name;
        bool processed = false;
    public:
        Event(char * name);
        Event();
        void markProcessed();
        char * getName();
    };

    class EventQueue
    {
        Event * queue [10];
    public:
        EventQueue();
        void pushEvent(Event * event);
        Event getEventWithName(char * name);
        void discard();
        int discardProcessedEvents();
    };
} // namespace statemachine

#pragma once

namespace statemachine
{
    class Event
    {
        char * name;
        bool processed = false;
    public:
        Event(char * name);
        void mark_processed();
    };
} // namespace statemachine

//
// Created by David Price on 07/07/2020.
//

#ifndef HESTIA_GAME_ENGINE_INCLUDE_FRAMEWORK_EVENTS_EVENT_QUEUE_H
#define HESTIA_GAME_ENGINE_INCLUDE_FRAMEWORK_EVENTS_EVENT_QUEUE_H

class EventQueue {

public:
    void pushEvent();
    void registerListener();
    void deregisterListener();
};

#endif //HESTIA_GAME_ENGINE_INCLUDE_FRAMEWORK_EVENTS_EVENT_QUEUE_H

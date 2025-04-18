#include "evnotif.h"

void EvNotif_init( EvNotif *evHandler ){
    for( int i = 0; i < EVENT_TYPE_COUNT; i++ ){
        evHandler->handlerCount[i] = 0;
    }
}

EvNotifStatus EvNotif_register( EvNotif *evnHandler, EventType evType, EventHandler evHandler){
    EvNotifStatus status = EVNOTIF_ERROR;
    
    if( evnHandler->handlerCount[evType] < MAX_HANDLERS ){
        evnHandler->handlers[evType][evnHandler->handlerCount[evType]] = evHandler;
        evnHandler->handlerCount[evType]++;
        status = EVNOTIF_OK;
    }
    
    return status;
}

EvNotifStatus EvNotif_unregister( EvNotif *evnHandler, EventType evType, EventHandler evHandler){
    EvNotifStatus status = EVNOTIF_ERROR;

    int count = evnHandler->handlerCount[evType];
    for(int i = 0;i < count; ++i){
        if( evnHandler->handlers[evType][i] == evHandler ){
            evnHandler->handlers[evType][i] = evnHandler->handlers[evType][count - 1];
            evnHandler->handlerCount[evType]--;
            status = EVNOTIF_OK;
        }
    }

    return status;
}

void EvNotif_notify( EvNotif *evnHandler, EventType evType ){
    int count = evnHandler->handlerCount[evType];
    for( int i = 0; i < count; i++ ){
        evnHandler->handlers[evType][i]();
    }
}


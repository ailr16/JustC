#include "evnotif.h"

void EvNotif_init( EvNotif *evHandler ){
    for( int i = 0; i < EVENT_TYPE_COUNT; i++ ){
        evHandler->handlerCount[i] = 0;
    }
}

void EvNotif_register( EvNotif *evnHandler, EventType evType, EventHandler evHandler){
    if( evnHandler->handlerCount[evType] < MAX_HANDLERS ){
        evnHandler->handlers[evType][evnHandler->handlerCount[evType]] = evHandler;
        evnHandler->handlerCount[evType]++;
    }
}



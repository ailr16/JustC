#ifndef EVNOTIF_H
#define EVNOTIF_H

#include <stdlib.h>
#include <stdio.h>

#ifndef MAX_HANDLERS
    #define MAX_HANDLERS 10
#endif

typedef enum{
    EVENT_TYPE1,
    EVENT_TYPE2,
    EVENT_TYPE_COUNT
} EventType;

typedef enum{
    EVNOTIF_OK = 0,
    EVNOTIF_ERROR = 1
} EvNotifStatus;

typedef void (*EventHandler)(void);

typedef struct _EvNotif{
    EventHandler handlers[EVENT_TYPE_COUNT][MAX_HANDLERS];
    int handlerCount[EVENT_TYPE_COUNT];
} EvNotif;

void EvNotif_init( EvNotif *evnHandler );
EvNotifStatus EvNotif_register( EvNotif *evnHandler, EventType evType, EventHandler evHandler);
EvNotifStatus EvNotif_unregister( EvNotif *evnHandler, EventType evType, EventHandler evHandler);
void EvNotif_notify( EvNotif *evnHandler, EventType evType );

#endif
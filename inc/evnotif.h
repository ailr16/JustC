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

typedef void (*EventHandler)(void);

typedef struct _EvNotif{
    EventHandler handlers[EVENT_TYPE_COUNT][MAX_HANDLERS];
    int handlerCount[EVENT_TYPE_COUNT];
} EvNotif;

void EvNotif_init( EvNotif *evnHandler );
void EvNotif_register( EvNotif *evnHandler, EventType evType, EventHandler evHandler);

#endif
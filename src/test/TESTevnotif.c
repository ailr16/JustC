#include "TEST.h"
#include "evnotif.h"

void handler1(void){

}

void handler2(void){

}

void TEST_evnotif(void){
    EvNotif notifier;

    EvNotif_init( &notifier );
    EvNotif_register( &notifier, EVENT_TYPE1, handler1 );
    EvNotif_register( &notifier, EVENT_TYPE1, handler2 );
}
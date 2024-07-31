#include "TEST.h"
#include "evnotif.h"

void handler1(void){
    printf("Handler 1\n");
}

void handler2(void){
    printf("Handler 2\n");
}

void handler3(void){
    printf("Handler 3\n");
}

void handler4(void){
    printf("Handler 4\n");
}

void handler5(void){
    printf("Handler 5\n");
}

void handler6(void){
    printf("Handler 6\n");
}

void handler7(void){
    printf("Handler 7\n");
}

void handler8(void){
    printf("Handler 8\n");
}

void handler9(void){
    printf("Handler 9\n");
}

void handler10(void){
    printf("Handler 10\n");
}

void handler11(void){
    printf("Handler 11\n");
}

void TEST_evnotif(void){
    EvNotif notifier;
    EvNotifStatus status;

    EvNotif_init( &notifier );

    status = EvNotif_register( &notifier, EVENT_TYPE1, handler1 );
    status = EvNotif_register( &notifier, EVENT_TYPE1, handler2 );
    status = EvNotif_register( &notifier, EVENT_TYPE1, handler3 );
    status = EvNotif_register( &notifier, EVENT_TYPE1, handler4 );
    status = EvNotif_register( &notifier, EVENT_TYPE1, handler5 );
    status = EvNotif_register( &notifier, EVENT_TYPE1, handler6 );
    status = EvNotif_register( &notifier, EVENT_TYPE1, handler7 );
    status = EvNotif_register( &notifier, EVENT_TYPE2, handler8 );
    status = EvNotif_register( &notifier, EVENT_TYPE2, handler9 );
    status = EvNotif_register( &notifier, EVENT_TYPE2, handler10 );
    status = EvNotif_register( &notifier, EVENT_TYPE1, handler11 );
    

    EvNotif_notify( &notifier, EVENT_TYPE1 );
    EvNotif_notify( &notifier, EVENT_TYPE2 );
    
}
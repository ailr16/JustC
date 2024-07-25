#include "TEST.h"
#include "rbuffer.h"

#define BUFFER_SIZE 6

void TEST_rbuffer(void){
    static int a[BUFFER_SIZE];
    
    rbufferStatus status = RBUFFER_OK;
    int getted = 0;

    static rbuffer bH;

    bH.array       = (void*)a;
    bH.elementSize = sizeof(int);
    bH.size        = BUFFER_SIZE;
    rbuffer_init( &bH );

    int value;
    
    value = 16;
    status = rbuffer_put( &bH, &value );

    value = 32;
    status = rbuffer_put( &bH, &value );

    value = 64;
    status = rbuffer_put( &bH, &value );

    value = 128;
    status = rbuffer_put( &bH, &value );

    value = 256;
    status = rbuffer_put( &bH, &value );

    value = 512;
    status = rbuffer_put( &bH, &value );

    value = 1024;
    status = rbuffer_put( &bH, &value );
    
    status = rbuffer_get( &bH, &getted );
    status = rbuffer_get( &bH, &getted );
    status = rbuffer_get( &bH, &getted );
    status = rbuffer_get( &bH, &getted );

    status = rbuffer_put( &bH, &value );

    status = rbuffer_get( &bH, &getted );
    status = rbuffer_get( &bH, &getted );
    status = rbuffer_get( &bH, &getted );
    status = rbuffer_get( &bH, &getted );

    NULL;
}
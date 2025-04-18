#include "TEST.h"
#include "rbuffer.h"

#define BUFFER_SIZE 6

void TEST_rbuffer(void){
    static int a[BUFFER_SIZE];
    
    RbufferStatus status = RBUFFER_OK;
    int getted = 0;

    static Rbuffer bH;

    bH.array       = (void*)a;
    bH.elementSize = sizeof(int);
    bH.size        = BUFFER_SIZE;
    Rbuffer_init( &bH );

    int value;
    
    value = 16;
    status = Rbuffer_put( &bH, &value );

    value = 32;
    status = Rbuffer_put( &bH, &value );

    value = 64;
    status = Rbuffer_put( &bH, &value );

    value = 128;
    status = Rbuffer_put( &bH, &value );

    value = 256;
    status = Rbuffer_put( &bH, &value );

    value = 512;
    status = Rbuffer_put( &bH, &value );

    value = 1024;
    status = Rbuffer_put( &bH, &value );
    
    status = Rbuffer_get( &bH, &getted );
    status = Rbuffer_get( &bH, &getted );
    status = Rbuffer_get( &bH, &getted );
    status = Rbuffer_get( &bH, &getted );

    status = Rbuffer_put( &bH, &value );

    status = Rbuffer_get( &bH, &getted );
    status = Rbuffer_get( &bH, &getted );
    status = Rbuffer_get( &bH, &getted );
    status = Rbuffer_get( &bH, &getted );

    NULL;
}
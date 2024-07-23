#include "TEST.h"
#include "rbuffer.h"

#define BUFFER_SIZE 6

void TEST_rbuffer(void){
    int a[BUFFER_SIZE];

    rbuffer buffer1;
    
    rbufferStatus status = RBUFFER_OK;
    int getted = 0;

    rbuffer_init( &buffer1, BUFFER_SIZE, a);

    for(int i = 1; i <= 64; i<<=1){
        /*
          This attempts to store 1, 2, 4, 8, 16, 32 and 64 values
          but only will save 1, 2, 4, 8, 16 and 32
        */
        (void)rbuffer_put( &buffer1, i );
    }


    status = rbuffer_get( &buffer1, &getted );
    printf("%d ", getted);

    status = rbuffer_get( &buffer1, &getted );
    printf("%d ", getted);

    status = rbuffer_get( &buffer1, &getted );
    printf("%d ", getted);

    //Add value 64 to buffer
    status = rbuffer_put( &buffer1, 64 );

    status = rbuffer_get( &buffer1, &getted );
    printf("%d ", getted);

    status = rbuffer_get( &buffer1, &getted );
    printf("%d ", getted);

    status = rbuffer_get( &buffer1, &getted );
    printf("%d ", getted);

    status = rbuffer_get( &buffer1, &getted );
    printf("%d ", getted);

    status = rbuffer_get( &buffer1, &getted );
    printf("%d ", getted);

    status = rbuffer_put( &buffer1, 128 );
    status = rbuffer_get( &buffer1, &getted );
    printf("%d ", getted);

    status = rbuffer_put( &buffer1, 256 );
    status = rbuffer_put( &buffer1, 512 );

    status = rbuffer_get( &buffer1, &getted );
    printf("%d ", getted);

    status = rbuffer_get( &buffer1, &getted );
    printf("%d ", getted);

    status = rbuffer_get( &buffer1, &getted );
    printf("%d\n", getted);
    
    //Expected output 1 2 4 8 16 32 64 64 128 256 512 512

    printf("%d\n", rbuffer_flush( &buffer1 ));
    //Expected output 0
}
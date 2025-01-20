#include "../inc/mem_alloc.h"

#define NBLOCKS 8
#define BSIZE   16

char myMem[MM_SIZE( BSIZE, NBLOCKS )];
MMPool myPool = {
    .memory = myMem,
    .nrBlocks = NBLOCKS,
    .blockSize = BSIZE
};

int main(void){
    int *a1 = NULL;

    MMPool_Init( &myPool );
    MM_Stats( &myPool );  

    a1 = (int*)MM_Allocate( &myPool );
    printf("Addr 1: %p\n", a1);
    MM_Stats( &myPool );

    void *b2 = MM_Allocate( &myPool );
    printf("Addr 2: %p\n", b2);
    MM_Stats( &myPool );

    for( int i = 0; i < 4; i++ )
        printf("%d ", a1[i]);
    printf("\n");

    a1[0] = 16;
    a1[1] = 24;

    for( int i = 0; i < 4; i++ )
        printf("%d ", a1[i]);
    printf("\n");

    MM_Free( a1, &myPool );
    MM_Stats( &myPool );

    return 0;
}
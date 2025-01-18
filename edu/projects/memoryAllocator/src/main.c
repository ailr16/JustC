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
    MMPool_Init( &myPool );
    MM_Stats( &myPool );  
    return 0;
}
#include "../inc/mem_alloc.h"



void MMPool_Init( MMPool *pool ){
    memset( pool->memory, 0, MM_SIZE(pool->blockSize, pool->nrBlocks) );
    pool->firstFree = (MMBlockHeader*)pool->memory;

    MMBlockHeader *currentBlock = pool->firstFree;

    for( int i = 0; i < pool->nrBlocks - 1; i++ ){
        currentBlock->next = (MMBlockHeader*)(char*)(currentBlock + 1) + pool->blockSize;
        currentBlock = currentBlock->next;
        pool->nrFreeBlocks++;
    }

    currentBlock->next = NULL;
    pool->nrFreeBlocks++;
}

void  MM_Stats( MMPool *pool ){
    MMBlockHeader *block;

    printf( "N Free: %d\n", pool->nrFreeBlocks );
    block = pool->firstFree;
    while( block != NULL ){
        printf( "%p\n", block );
        block = block->next;
    }
    
}
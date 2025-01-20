#include "../inc/mem_alloc.h"



void MMPool_Init( MMPool *pool ){
    memset( pool->memory, 0, MM_SIZE(pool->blockSize, pool->nrBlocks) );
    pool->firstFree = (MMBlockHeader*)pool->memory;

    MMBlockHeader *currentBlock = pool->firstFree;

    for( int i = 0; i < pool->nrBlocks - 1; i++ ){
        currentBlock->next = (MMBlockHeader*)((char*)(currentBlock + 1) + pool->blockSize);
        currentBlock = currentBlock->next;
        pool->nrFreeBlocks++;
    }

    currentBlock->next = NULL;
    pool->nrFreeBlocks++;
}

void* MM_Allocate( MMPool *pool ){
    void *data = NULL;

    if( pool->nrFreeBlocks > 0 ){
        data = (void*)((char*)pool->firstFree + sizeof( MMBlockHeader ));
        pool->firstFree = pool->firstFree->next;
        pool->nrFreeBlocks--;
    }

    return data;
}

void  MM_Free( void *data, MMPool *pool ){
    if( pool->nrFreeBlocks < pool->nrBlocks ){
        MMBlockHeader *block = (MMBlockHeader*)((char*)data - sizeof( MMBlockHeader ));
        block->next = pool->firstFree;
        pool->firstFree = block;
        pool->nrFreeBlocks++;
    }
}

void  MM_Stats( MMPool *pool ){
    MMBlockHeader *block;

    printf( "========================\n" );
    printf( "Size: %d\n", MM_SIZE(pool->blockSize, pool->nrBlocks) );

    printf( "N Free: %d\n", pool->nrFreeBlocks );
    block = pool->firstFree;
    while( block != NULL ){
        printf( "%p\n", block );
        block = block->next;
    }
    printf( "========================\n" );
}
#ifndef MEM_ALLOC_H
#define MEM_ALLOC_H

#include <stdio.h>
#include <string.h>

#define MM_SIZE( blockSize, nBlocks ) ((blockSize) + sizeof(MMBlockHeader)) * (nBlocks)

typedef struct _MMBlockHeader{
    struct _MMBlockHeader *next;
} MMBlockHeader;

typedef struct _MMPool{
    char *memory;
    MMBlockHeader *firstFree;
    int nrBlocks;
    int blockSize;
    int nrFreeBlocks;
} MMPool;

void  MMPool_Init( MMPool *pool );
void* MM_Allocate( MMPool *pool );
void  MM_Free( void *data, MMPool *pool );
void  MM_Stats( MMPool *pool );

#endif
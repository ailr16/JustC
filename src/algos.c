#include "algos.h"


GenericStatus Search_item( void* handler, Structure_t type, int data, uint32_t **retIndex, uint32_t *retSize ){
    if( type == SLIST_T ){
        SlistStatus returnValue = SLIST_ERROR;
        Slist *slistHandler;
        SlistNode *aux;

        uint32_t currentIndex;
        uint32_t *indexArray;
        uint32_t occurrences;

        slistHandler = (Slist*)handler;
        aux = slistHandler->head;

        indexArray = (uint32_t*)malloc( sizeof(uint32_t) );

        currentIndex = 0;
        occurrences  = 0;

        #if LINEAR_SEARCH

        while( aux ){
            if( aux->data == data ){
                returnValue = SLIST_OK;
                indexArray = (uint32_t*)(realloc( indexArray, sizeof(uint32_t) ));
                indexArray[occurrences++] = currentIndex;
            }

            currentIndex++;
            aux = aux->next;
        }
        #endif

        // Return values
        *retIndex = indexArray;
        *retSize  = occurrences;
        return (GenericStatus)returnValue;
    }
}
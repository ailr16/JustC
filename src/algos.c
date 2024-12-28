#include "algos.h"

GenericStatus Search_item( void* handler, Structure_t type, int data, uint32_t *retIndex ){
    if( type == SLIST_T ){
        SlistStatus returnValue = SLIST_ERROR;
        Slist *slistHandler;
        SlistNode *aux;
        uint32_t index;

        slistHandler = (Slist*)handler;
        aux = slistHandler->head;

        index = 0;
        while( aux ){
            if( aux->data == data ){
                returnValue = SLIST_OK;
                break;
            }

            index++;
            aux = aux->next;
        }

        *retIndex = index;
        return (GenericStatus)returnValue;
    }
}
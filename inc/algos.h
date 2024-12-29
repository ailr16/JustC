#ifndef ALGOS_G
#define ALGOS_H

#include <stdint.h>
#include <string.h>

#include "algos_config.h"

typedef uint8_t GenericStatus;
typedef enum Structure_t{
    SLIST_T,
    DLIST_T,
}Structure_t;

GenericStatus Search_item( void* handler, Structure_t type, int data, uint32_t **retIndex, uint32_t *retSize );

#endif
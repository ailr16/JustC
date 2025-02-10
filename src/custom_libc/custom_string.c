#include "custom_string.h"

uint32_t c_strlen( const char* str ){
    uint32_t len = 0;

    while( *str != '\0' ){
        len++;
        str++;
    }

    return len;
}
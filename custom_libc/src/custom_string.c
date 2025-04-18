#include "custom_string.h"

uint32_t c_strlen( const char* str ){
    uint32_t len = 0;

    while( *str != '\0' ){
        len++;
        str++;
    }

    return len;
}

char *c_strchr( const char *str, int ch ){
    char *i = (char*)str;
    char c = (char)ch;

    while( *i != c && *i != '\0' ){
        i++;
    }

    return (*i == c) ? i : NULL;
}

int32_t c_strcmp( const char *str1, const char *str2 ){
    return 0;
}
#ifndef CUSTOM_STRING_H
#define CUSTOM_STRING_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stdint.h"
#include "stdlib.h"

uint32_t c_strlen( const char* str );
char *c_strchr( const char *str, int ch );
int32_t c_strcmp( const char *str1, const char *str2 );

#ifdef __cplusplus
}
#endif

#endif
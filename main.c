#include "stdio.h"

#if DATA_STRUCTS
#include "TEST.h"
#endif

#if CUSTOM_LIBC
#include "custom_string.h"
#endif

int main(void)
{
    #if DATA_STRUCTS
    TEST_slist();
    TEST_dlist();
    #endif

    #if CUSTOM_LIBC
    printf( "%u\n", c_strlen("hello") );
    printf( "%u\n", c_strlen("ailr16") );
    #endif

    return 0;
}
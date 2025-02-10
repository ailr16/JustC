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
    char str1[] = "hello";
    char str2[] = "ailr16";
    char str3[] = "hello";
    char *aux = NULL;

    printf( "%u\n", c_strlen(str1) );
    printf( "%u\n", c_strlen(str2) );
    printf("%s\n", str1);
    aux = c_strchr("hello", (int)'e');
    if( aux )
        printf( "%c\n", *aux );
    else
        printf("Not found!\n");
    aux = c_strchr("hello", (int)'m');
    if( aux )
        printf( "%c\n", aux );
    else
        printf("Not found!\n");
    printf( "%d\n", c_strcmp( str1, str2 ) );
    printf( "%d\n", c_strcmp( str1, str3 ) );
    #endif

    return 0;
}
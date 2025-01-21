#include "../inc/parser.h"
#include <stdlib.h>

int count = 0;
char *msg = NULL;

void _count( void* c ){
    count = atoi((char*)c);
}

void _msg( void* m ){
    msg = (char*)m;
}

struct Option options[] = {
    { 'm', "msg", "The message to be printed", _msg },
    { 'c', "count", "Time to print the message", _count },
    { 0 }
};

int main( int argc, char *argv[] ){
    arg_parse( options, argc, argv );
    int i = 0;
    for( ; i < count; i++ ){
        printf( "%s\n", msg );
    }

    return 0;
}
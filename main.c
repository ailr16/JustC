#include "slist.h"

list listH;

int main(void)
{
    list_init(&listH);

    list_prepend(&listH, 16);   //[ 16 ]
    list_append(&listH, 32);    //[ 16 32 ]
    list_prepend(&listH, 18);   //[ 18 16 32 ]
    list_append(&listH, 32);    //[ 18 16 32 32 ]
    list_append(&listH, 64);    //[ 18 16 32 32 64 ]
    list_append(&listH, 111);   //[ 18 16 32 32 64 111 ]

    list_print(&listH);

    printf("Pop: %d\n", list_pop(&listH)); //[ 18 16 32 32 64 ]
    list_print(&listH);

    printf("Popfront: %d\n", list_popFront(&listH)); //[ 16 32 32 64 ]
    list_print(&listH);

    list_free(&listH);

    return 0;
}
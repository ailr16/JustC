#include "slist.h"

list listH;

int main(void)
{
    list_init(&listH);

    list_prepend(&listH, 16);   //[ 16 ]
    list_append(&listH, 32);    //[ 16 32 ]
    list_prepend(&listH, 18);   //[ 18 16 32 ]
    list_append(&listH, 32);    //[ 18 16 32 32 ]


    list_print(&listH);

    return 0;
}
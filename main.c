#include "slist.h"

list listH;

int main(void)
{
    list_init(&listH);
    
    for(int i = 16; i <= 128; i += 16){
        list_append(&listH, i);
    }

    list_print(&listH);

    return 0;
}
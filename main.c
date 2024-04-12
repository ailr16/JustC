#include "slist.h"

list listH;

int main(void)
{
    list_init(&listH);
    list_prepend(&listH, 16);
    list_prepend(&listH, 18);
    list_prepend(&listH, 20);
    list_prepend(&listH, 16);

    list_print(&listH);

    return 0;
}
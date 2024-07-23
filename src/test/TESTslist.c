#include "TEST.h"
#include "slist.h"

void TEST_slist(void){
    Slist slistH;

    printf("------------slist------------\n");
    Slist_init( &slistH );



    Slist_free(&slistH);
}

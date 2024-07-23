#include "TEST.h"
#include "slist.h"

void TEST_slist(void){
    Slist slistH;
    SlistStatus status;

    status = Slist_init( &slistH );

    status = Slist_insert( &slistH, 0, 16 );
    status = Slist_insert( &slistH, 0, 17 );
    status = Slist_insert( &slistH, -1, 18 );
    status = Slist_insert( &slistH, -1, 19 );
    status = Slist_insert( &slistH, 0, 20 );
    status = Slist_insert( &slistH, -4, 20 );
    status = Slist_insert( &slistH, 1, 21 );
    status = Slist_insert( &slistH, 4, 22 );
    status = Slist_insert( &slistH, 20, 23 );

    Slist_free(&slistH);
}

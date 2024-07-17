#include "dlist.h"
#include "slist.h"
#include "rbuffer.h"

void slist_test(void);
void dlist_test(void);

#define BUFFER_SIZE 6

int a[BUFFER_SIZE];

rbuffer buffer1 = {
    .array = a,
};

int main(void)
{   
    int popped_value = 0;

    rbuffer_init( &buffer1, BUFFER_SIZE);   //_ _ _ _ _ _
    printf( "head={%d} tail={%d} status={%d}\n", buffer1.head, buffer1.tail, buffer1.status);

    rbuffer_push( &buffer1, (int)1 );   //1 _ _ _ _ _
    printf( "head={%d} tail={%d} status={%d}\n", buffer1.head, buffer1.tail, buffer1.status);
    rbuffer_push( &buffer1, (int)2 );   //1 2 _ _ _ _
    printf( "head={%d} tail={%d} status={%d}\n", buffer1.head, buffer1.tail, buffer1.status);
    rbuffer_push( &buffer1, (int)3 );   //1 2 3 _ _ _
    printf( "head={%d} tail={%d} status={%d}\n", buffer1.head, buffer1.tail, buffer1.status);
    rbuffer_push( &buffer1, (int)4 );   //1 2 3 4 _ _
    printf( "head={%d} tail={%d} status={%d}\n", buffer1.head, buffer1.tail, buffer1.status);
    rbuffer_push( &buffer1, (int)5 );   //1 2 3 4 5 _
    printf( "head={%d} tail={%d} status={%d}\n", buffer1.head, buffer1.tail, buffer1.status);
    rbuffer_push( &buffer1, (int)6 );   //1 2 3 4 5 6
    printf( "head={%d} tail={%d} status={%d}\n", buffer1.head, buffer1.tail, buffer1.status);

    if(rbuffer_pop( &buffer1, &popped_value ) == 0){
        printf( "popped_value={%d}\n", popped_value);    //1 2 3 4 5 6
    }
    printf( "head={%d} tail={%d} status={%d}\n", buffer1.head, buffer1.tail, buffer1.status);

    rbuffer_push( &buffer1, (int)7 );   //7 2 3 4 5 6
    printf( "head={%d} tail={%d} status={%d}\n", buffer1.head, buffer1.tail, buffer1.status);
    
    /*
    if(cbuffer_pop( &buffer1, &popped_value ) == 0){
        printf( "popped_value={%d}\n", popped_value);    //1 2 3 4 5 6
    }
    printf( "head={%d} tail={%d} status={%d}\n", buffer1.head, buffer1.tail, buffer1.status);

    if(cbuffer_pop( &buffer1, &popped_value ) == 0){
        printf( "popped_value={%d}\n", popped_value);    //_ _ 3 _ _ _
    }
    printf( "head={%d} tail={%d}\n", buffer1.head, buffer1.tail);

    if(cbuffer_pop( &buffer1, &popped_value ) == 0){
        printf( "popped_value={%d}\n", popped_value);    //_ _ _ _ _ _
    }
    printf( "head={%d} tail={%d}\n", buffer1.head, buffer1.tail);

    if(cbuffer_pop( &buffer1, &popped_value ) == 0){
        printf( "popped_value={%d}\n", popped_value);    //_ _ _ _ _ _
    }
    printf( "head={%d} tail={%d}\n", buffer1.head, buffer1.tail);

    */
    cbuffer_print( &buffer1 );
    return 0;
}

void slist_test(void){
    slist slistH;

    printf("------------slist------------\n");
    slist_init(&slistH);

    slist_prepend(&slistH, 16);   //[ 16 ]
    slist_append(&slistH, 32);    //[ 16 32 ]
    slist_prepend(&slistH, 18);   //[ 18 16 32 ]
    slist_append(&slistH, 32);    //[ 18 16 32 32 ]
    slist_append(&slistH, 64);    //[ 18 16 32 32 64 ]

    slist_print(&slistH);

    slist_insert(&slistH, 0, 99);     //[ 99 18 16 32 32 64 ]
    slist_insert(&slistH, 1, 55);     //[ 99 55 18 16 32 32 64 ]
    slist_insert(&slistH, 3, 66);     //[ 99 55 18 66 16 32 32 64 ]
    slist_insert(&slistH, 9, 299);    //[ 99 55 18 66 16 32 32 64 299]
    slist_insert(&slistH, 8, 699);    //[ 99 55 18 66 16 32 32 64 699 299]
    
    slist_print(&slistH);

    slist_remove(&slistH, 0);         //[ 55 18 66 16 32 32 64 699 299]
    slist_remove(&slistH, 2);         //[ 55 18 16 32 32 64 699 299]
    slist_remove(&slistH, 40);        //[ 55 18 16 32 32 64 699 ]
    slist_remove(&slistH, 40);        //[ 55 18 16 32 32 64 ]
    slist_remove(&slistH, 4);         //[ 55 18 16 32 64 ]

    slist_print(&slistH);

    slist_free(&slistH);
}

void dlist_test(void){
    dlist dlistH;

    printf("\n------------dlist------------\n");
    dlist_init(&dlistH);

    dlist_prepend(&dlistH, 16);   //[ 16 ]
    dlist_append(&dlistH, 32);    //[ 16 32 ]
    dlist_prepend(&dlistH, 18);   //[ 18 16 32 ]
    dlist_append(&dlistH, 32);    //[ 18 16 32 32 ]
    dlist_append(&dlistH, 64);    //[ 18 16 32 32 64 ]

    dlist_print(&dlistH);

    dlist_insert(&dlistH, 0, 99);     //[ 99 18 16 32 32 64 ]
    dlist_insert(&dlistH, 1, 55);     //[ 99 55 18 16 32 32 64 ]
    dlist_insert(&dlistH, 3, 66);     //[ 99 55 18 66 16 32 32 64 ]
    dlist_insert(&dlistH, 9, 299);    //[ 99 55 18 66 16 32 32 64 299]
    dlist_insert(&dlistH, 8, 699);    //[ 99 55 18 66 16 32 32 64 699 299]
    dlist_print(&dlistH);

    dlist_remove(&dlistH, 0);         //[ 55 18 66 16 32 32 64 699 299]
    dlist_remove(&dlistH, 2);         //[ 55 18 16 32 32 64 699 299]
    dlist_remove(&dlistH, 40);        //[ 55 18 16 32 32 64 699 ]
    dlist_remove(&dlistH, 40);        //[ 55 18 16 32 32 64 ]
    dlist_remove(&dlistH, 4);         //[ 55 18 16 32 64 ]

    dlist_print(&dlistH);

    dlist_free(&dlistH);
}
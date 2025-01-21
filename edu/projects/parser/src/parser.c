#include "../inc/parser.h"

static struct Option* _find_option_by_sname( struct Option *options, char sname ){
    struct Option *currentOption = options;

    while( currentOption->sname != 0 ){
        if( currentOption->sname == sname ){
            return currentOption;
        }
        currentOption++;
    }

    return NULL;
}

static struct Option* _find_option_by_lname( struct Option *options, char *lname ){
    struct Option *currentOption = options;

    while( currentOption->sname != 0 ){
        if( strcmp( currentOption->lname, lname ) ){
            return currentOption;
        }
        currentOption++;
    }

    return NULL;
}

void arg_parse( struct Option *options, int argc, char *argv[] ){
    int i = 0;
    for(; i < argc; i++){
        struct Option *op = NULL;
        if( argv[i][0] == '-' ){
            if( argv[i][1] == '-' ){
                op = _find_option_by_lname( options, &argv[i][2] );
            }
            else{
                op = _find_option_by_sname( options, argv[i][1] );
            }

            if( op != NULL ){
                if( (i <= argc - 2) && (argv[i + 1][0] != '-') ){
                    op->action((void*)argv[i + 1]);
                    i++;
                }
                else{
                    op->action(NULL);
                }
            }
            else{
                printf( "Unrecognized option: %s\n", argv[i] );
            }
        }
        else{
            printf( "Unrecognized option: %s\n", argv[i] );
        }
    }

}
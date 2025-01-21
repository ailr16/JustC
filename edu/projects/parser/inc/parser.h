#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <string.h>

struct Option{
    char sname;
    char *lname;
    char *desc;
    void (*action)(void*);
};

void arg_parse( struct Option *options, int argc, char *argv[] );

#endif
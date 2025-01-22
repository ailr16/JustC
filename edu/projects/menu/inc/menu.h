#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <string.h>

typedef struct _MenuItem{
    char letter;
    char *desc;
    int type;
    void (*func)(void);
    Menu *menu;
} MenuItem;

typedef struct _Menu{
    char *prompt;
    MenuItem *items;
} Menu;

void menuProcessUserInput( char input );

#endif
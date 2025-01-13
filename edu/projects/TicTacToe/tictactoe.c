#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct _Player_t{
    char name[21];
    char marker;
    char playerNumber;
} Player_t;

int get_player_info(Player_t *playerHandler);

int get_player_input(void);
char judge(void);
void render_playground(void);

char playground[3][3] = { {' ', ' ', ' '},
                          {' ', ' ', ' '},
                          {' ', ' ', ' '} };

int main(void){
    int empty_cells = 9;
    int input = 0;

    Player_t *currentPlayer;
    Player_t *winner;
    Player_t player1;
    Player_t player2;

    player1.playerNumber = 1;
    player2.playerNumber = 2;

    get_player_info( &player1 );
    get_player_info( &player2 );

    currentPlayer = &player1;
    winner = NULL;

    while(empty_cells != 0){
        input = 0;
        render_playground();

        printf(" %s is your turn!\n", currentPlayer->name );

        input = get_player_input();

        if( input == -1 ){
            printf("INVALID INPUT!\n");
            sleep(2);
        }
        else{
            playground[input / 10 - 1][input % 10 - 1] = currentPlayer->marker;
            if( currentPlayer->playerNumber == 1 )
                currentPlayer = &player2;
            else
                currentPlayer = &player1;
            empty_cells--;
        }
        if( judge() == player1.marker ){
            winner = &player1;
            break;
        }
        if( judge() == player2.marker ){
            winner = &player2;
            break;
        }
        
    }

    render_playground();
    if( winner != NULL )
        printf( "Congratulations %s, you win!\n", winner->name );
    else
        printf("Tie game!\n");
    sleep(2);
}

int get_player_info(Player_t *playerHandler){
    char icon[2];

    printf( "Hello Player number %d, enter your name: ", playerHandler->playerNumber );
    scanf( "%20s[^\n]", playerHandler->name );

    printf( "Now, enter your icon: " );
    scanf( "%1s[^\n]", icon );
    playerHandler->marker = icon[0];
}

/*
Reqs:
 - Receive cell index from user (e.g. 23 = row 2, col 3)
 - Check if is out of range
 - Check if cell has been already selected
*/
int get_player_input( void ){
    int cells_index[] = { 11, 12, 13, 21, 22, 23, 31, 32, 33 };
    int valid_cell = 0;
    int cell_input = 0;
    int row = 0;
    int col = 0;

    scanf( "%d", &cell_input );

    for( int i = 0; i < 9; i++ ){
        if( cell_input == cells_index[i] ){
            valid_cell = 1;
            break;
        }
    }

    if( !valid_cell )
        return -1;
    else{
        row = cell_input / 10 - 1;
        col = cell_input % 10 - 1;

        if( playground[row][col] != ' ' )
            return -1;

    }

    return cell_input;
}

char judge(void){
    int winner_flag = 0;

    if( playground[0][0] == playground[1][1] && playground[1][1] == playground[2][2] )
        return playground[0][0];

    if( playground[2][0] == playground[1][1] && playground[1][1] == playground[0][2] )
        return playground[2][0];
    
    for( int i = 0; i < 3; i++ ){
        if( playground[i][0] == playground[i][1] && playground[i][1] == playground[i][2] )
            return playground[i][0];
    }

    for( int i = 0; i < 3; i++ ){
        if( playground[0][i] == playground[1][i] && playground[1][i] == playground[2][i] )
            return playground[0][i];
    }

    return ' ';
}

/*
Reqs:
 - Clear the screen
 - Draw matrix skeleton
 - Read playground global array and draw it in skeletin
*/
void render_playground(void){
    system("clear");
    printf("     |     |     \n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", playground[0][0], playground[0][1], playground[0][2]);
    printf("     |     |     \n");
    printf("-----|-----|-----\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", playground[1][0], playground[1][1], playground[1][2]);
    printf("     |     |     \n");
    printf("-----|-----|-----\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", playground[2][0], playground[2][1], playground[2][2]);
    printf("     |     |     \n");
    printf("     |     |     \n");
}
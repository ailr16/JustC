#include <stdio.h>
#include <stdlib.h>

int get_player_input(void);
char judge(void);
void render_playground(void);

char playground[3][3] = { {' ', ' ', ' '},
                          {' ', ' ', ' '},
                          {' ', ' ', ' '} };

int main(void){
    for(int i = 0; i < 3; i++){
        printf("%d\n", get_player_input() );
        render_playground();
    }
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
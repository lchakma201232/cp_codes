#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
//#include "rand_num.h"

#define MINBOARDSIZE 5
#define MAXBOARDSIZE 26
#define MINSHIPNUM 5
#define MAXSHIPNUM 10
////////////////////////////////////////////////////////


// The seed is an arbitrary bit string derived from the time-of-day clock on the
// CPU. Type suseconds_t is long int on tuxworld.
void rand_init( void ) {
    struct timeval tv;
    
    if( gettimeofday( &tv, NULL ) != 0 ) {
        err( -1, NULL );        // Something is dreadfully wrong.
    }                           // Abort with error message and failing exit

    // srandom() wants an unsigned int as argument.  However, tv_usec is of type
    // suseconds_t which is long int on tuxworld.  Using tv.tv_usec as the
    // argument to srandom() will cause only the low-order 4 bytes of tv.tv_usec
    // to be passed to srandom(). However, this is fine since we simply want an
    // arbitrary bit string to use as the seed for the random number generator.
    srandom( tv.tv_usec );
}

// RAND_MAX is 2147483647 = 0x7fffffff (a 32-bit int) on tuxworld
int rand_num( int max ) {
    
    // random() returns a long int.  Both max and RAND_MAX are of type int.
    // Therefore there should be no overflow in the calculation of the
    // return value.
    return max*random()/RAND_MAX;
}

////////////////////////////////////////////////////
typedef struct board_position{
    unsigned int row;
    unsigned int col;
} BoardPosition;

typedef struct _game_state{
    BoardPosition position;
    unsigned int hit;
}GameState;

typedef struct _Gameboard{
    unsigned int height;
    unsigned int width;
    unsigned int num_ships;
    unsigned int num_shots;
    unsigned int *ship_position;
    GameState _GameState;
} Gameboard;



Gameboard * create_Gameboard(unsigned int rows, unsigned int cols){
    if(rows<MINBOARDSIZE || rows>MAXBOARDSIZE){
        errx(1, "Invalid row size");
    }
    if(cols<MINBOARDSIZE || cols>MAXBOARDSIZE){
        errx(1, "Invalid column size");
    }

    Gameboard * game_board = (Gameboard*)malloc(sizeof(game_board));
    game_board->height= rows;
    game_board->width= cols;
    int num_ships = 0;
    int count = 0;


    while (num_ships<5 || num_ships>10){
        num_ships = ( rand_num(20));
    }
    printf("num ships %d\n",num_ships);

    game_board->ship_position = (unsigned int*)malloc(sizeof(unsigned int*)*rows*cols);

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            game_board->ship_position[i*rows+j] =0;
        }
    }
    while(count<num_ships ){
        int randrow = rand_num(rows);
        int randcol = rand_num(cols);
        printf("rand row %d\nrand col %d\n", randrow, randcol);
        printf("grid value %d\n",game_board->ship_position[(randrow*count)+randcol]);
        if (game_board->ship_position[randrow*count+randcol]!=1){
            game_board->ship_position[randrow*count+randcol]=1;
            count++;
        }

    }
        printf("value of count %d\n",count);
        
    return game_board;
}

void print_game_state(Gameboard* game){
    for(int i=0; i<game->width; i++){
        for (int j=0; j<game->height; j++){
            printf("%d ",game->ship_position[i*(game->width)+j]);
            /*if(i==0){
                game->ship_position[i*(game->width)+j]=j;
            }
            if(j==0){
                game->ship_position[i*(game->width)+j]=(i+ 65);
            }
            if(j==0){
                printf("%c ",(char)game->ship_position[i*(game->width)+j]);
            }
            else{
                printf("%d ",game->ship_position[i*(game->width)+j]);
            }*/

            }
        printf("\n");
    }
}

int main(){
    rand_init();
    Gameboard * board;
    board = create_Gameboard(5,5);
    print_game_state(board);

}
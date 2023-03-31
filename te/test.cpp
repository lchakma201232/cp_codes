

/*----------------------------------------------------------------------------------------------------------------------
Assignment- 4
Name: Mahafujul Hamid Ananda
NSID: SEZ876
Student Number: 11345443
Instructor: Tony Kusalik
Question- 2
----------------------------------------------------------------------------------------------------------------------*/

// library headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

typedef struct _magic_square {
    int size;      // Size of the magic square .
    int* square;  // A pointer to the first element of a 1D view of
                    // a 2D array with size rows and size columns
                    // containing the values in the entries of the
                    // magic square in row - major order .
                    // ( dynamically allocated -- see Section 12.6
                    // of the textbook )
    } MagicSquare;


//1

//2
int test_magic_square(MagicSquare *new_square){
        int sum_row=0, sum_col=0, count=0;

        int size=(*new_square).size;
        int compare_row[size+size], compare_col[size+size];

        for( int j=0; j<size; j++){
            sum_row=0;
            for(int k=0; k<size; k++){
                sum_row= sum_row+(*new_square).square[j*size+k];
                sum_col= sum_col+(*new_square).square[k*size+j];
            }
            compare_row[j]= sum_row;
        }
        for( int j=0; j<size; j++){
            sum_col=0;
            for(int k=0; k<size; k++){
                sum_col= sum_col+(*new_square).square[k*size+j];
            }
            compare_col[j]= sum_col;
        }

        for (int i=0; i< size; i++){
            if( compare_row[0] != compare_row[i] ){
                return 0;}
        }

        for (int i=0; i< size; i++){
            if( compare_col[0] != compare_col[i] ){
            return 0;
            }
        }

    return 1;

}

//3


//4

MagicSquare* read_magic_square(FILE* infile){
    MagicSquare* magic_square = (MagicSquare*)malloc(sizeof(MagicSquare));

    fscanf(infile, "%d", &(*magic_square).size);

    int size = (*magic_square).size;

    (*magic_square).square = (int*)malloc(sizeof(int)*size*size);

    for(int i =0; i<(size*size); i++ ){
        fscanf(infile, "%d", &(*magic_square).square[i]);
    }
    return magic_square;


}


void free_magic_square(MagicSquare *free_square){
    free((*free_square).square);
    free(free_square);

}

int main( int argc, char* argv[]){

    int arguements = argc;
    for (int i = 1; i< arguements; i++){

        FILE* magic_file;
        magic_file = fopen(argv[i], "r");
        MagicSquare* magicsquare;
        magicsquare = read_magic_square(magic_file);
        int result = test_magic_square(magicsquare);

        if(result == 1){
            printf("%s is a valid Magic Square\n", argv[i]);
        }
        else{
            printf("%s is not a valid Magic Square\n", argv[i]);
        }

        free_magic_square(magicsquare);
        fclose(magic_file);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

int main(){
    int n;
    scanf("%d", &n);
    int **matrix = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    for(int i = 0; i < n; i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                *(*(matrix+i)+j)= 0;
            }
            else{
                *(*(matrix+i)+j)= 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", *(*(matrix+i)+j));
        }
        printf("\n");
    }
}
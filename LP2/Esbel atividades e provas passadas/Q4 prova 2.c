#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** geraImagem(int lin, int col){
    srand(time(NULL));
    int** img = (int**)malloc(lin * sizeof(int*));
    for(int i = 0; i < lin; i++){
        img[i] = (int*)malloc(col * sizeof(int));
    }
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            img[i][j] = rand() % 256;
        }
    }
    return img;
}

int main(void){
    int lin = 10, col = 10;
    int **img = geraImagem(lin, col);
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("%d\t", img[i][j]);
        }
        printf("\n");
    }
    return 0;
}
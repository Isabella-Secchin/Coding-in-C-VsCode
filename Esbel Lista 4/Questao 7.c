#include <stdio.h>
#include <stdlib.h>

void geraImgGreyW_D(unsigned char** img, int nLin, int nCol){
     for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            img[i][j] = 255;
        }
    }
}

int main(void){
    int nLin = 4, nCol = 5;
    unsigned char** img = (unsigned char**) malloc(nLin * sizeof(unsigned char*));
    for(int i = 0; i < nLin; i++){
        img[i] = (unsigned char*) malloc(nCol * sizeof(unsigned char));
    }
    geraImgGreyW_D(img, nLin, nCol);
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            printf("Posicao (%d, %d); %u\n", i, j, img[i][j]);
        } 
    }
    for(int i = 0; i < nLin; i++){
        free(img[i]);
    }
    free(img);
    return 0;
}
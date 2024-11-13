#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned char geraGreyPixel(int tipo){
    int i = rand() % 100 + 1;
    if(tipo < 0){
        if(i <= 75){
            return rand() % 128;
        }
        else{
            return 128 + rand() % (256 - 128);
        }
    }
    else if(tipo > 0){
        if(i<=75){
            return 128 + rand() % (256 - 128);
        }
        else{
            return rand() % 128;
        }
    }
    else if(tipo == 0){
        return rand() % 256;
    }
}

void geraImgGreyFull_D(unsigned char** img, int nLin, int nCol, unsigned char tipo){
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            img[i][j] = geraGreyPixel(tipo);
        }
    }
}

 int pixelMin_D(unsigned char** img, int nLin, int nCol) {
    int min = img[0][0];
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            if(img[i][j] < min){
                min = img[i][j];
            }
        }
    }
    return min;
 }

int main(void){
    int nLin = 4, nCol = 5, tipo;
    unsigned char** img = (unsigned char**) malloc(nLin * sizeof(unsigned char*));
    for(int i = 0; i < nLin; i++){
        img[i] = (unsigned char*) malloc(nCol * sizeof(unsigned char));
    }
    srand(time(NULL));
    printf("Entre com o tipo para gerar o pixel:\n");
    scanf("%d", &tipo);
    geraImgGreyFull_D(img, nLin, nCol, tipo);
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            printf("Posicao (%d, %d); %u\n", i, j, img[i][j]);
        } 
    }
    printf("O valor min e: %d\n", pixelMin_D(img, nLin, nCol));
    for(int i = 0; i < nLin; i++){
        free(img[i]);
    }
    free(img);
    return 0;
}
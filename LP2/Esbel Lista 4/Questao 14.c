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

int quantosPixelsNaInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten){
    int quant = 0;
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            if(inten == img[i][j]){
                quant++;
            }
        }
    }
    return quant;
}

int main(void){
    int nLin = 15, nCol = 15, tipo;
    unsigned char inten;
    unsigned char** img = (unsigned char**) malloc(nLin * sizeof(unsigned char*));
    for(int i = 0; i < nLin; i++){
        img[i] = (unsigned char*) malloc(nCol * sizeof(unsigned char));
    }
    srand(time(NULL));
    printf("Entre com o tipo para gerar o pixel:\n");
    scanf("%d", &tipo);
    printf("Entre com o pixel que deseja quantificar:\n");
    scanf("%u", &inten);
    geraImgGreyFull_D(img, nLin, nCol, tipo);
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            printf("%u\t", img[i][j]);
        }
        printf("\n");
    }
    printf("Quantidade de %u na int: %d\n", inten, quantosPixelsNaInt_D(img, nLin, nCol, inten));
    for(int i = 0; i < nLin; i++){
        free(img[i]);
    }
    free(img);
    return 0;
}
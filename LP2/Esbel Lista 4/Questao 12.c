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

int* somaPorColunas_D(unsigned char** img, int nLin, int nCol){
    int* soma = (int*) calloc(nCol, sizeof(int));
    for(int j = 0; j < nCol; j++){
        for(int i = 0; i < nLin; i++){
            soma[j] += img[i][j];
        }
    }
    return soma;
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
            printf("%u\t", img[i][j]);
        } 
        printf("\n");
    }
    int* soma = somaPorColunas_D(img, nLin, nCol);
    for(int i = 0; i < nCol; i++){
        printf("Coluna %d: %d\n", i, soma[i]);
    }
    for(int i = 0; i < nLin; i++){
        free(img[i]);
    }
    free(img);
    free(soma);
    return 0;
}
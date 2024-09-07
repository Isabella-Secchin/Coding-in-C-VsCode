#include <stdlib.h>
#include <stdio.h>
#include <time.h>

unsigned char geraGreyPixel(int);
void geraLinhaR(unsigned char[480][640], int, int, int);
void geraImgGrey_R(unsigned char[480][640], int, int);

int main(void){
    unsigned char img[480][640];
    int i = 479, j = 639, tipo;
    srand(time(NULL));
    printf("Entre com o tipo para preencher os pixels da imagem: \n");
    scanf("%d", &tipo);
    geraImgGrey_R(img, i, tipo);
    for(i = 0; i < 480; i++){
        for(j = 0; j < 640; j++){
            printf("%u ", img[i][j]);
        }
        printf("\n");
    }
}
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
void geraLinhaR(unsigned char img[480][640],int i, int j, int tipo){
    if(j < 0){
        return;
    }
    img[i][j] = geraGreyPixel(tipo);
    geraLinhaR(img, i, j - 1, tipo);
}
void geraImgGrey_R(unsigned char img[480][640], int i, int tipo){
    if(i < 0){
        return;
    }
    geraLinhaR(img, i, 639, tipo);
    geraImgGrey_R(img, i -1, tipo);
}
#include <stdlib.h>
#include <stdio.h>

void geraLinhaR(unsigned char[480][640], int, int, unsigned char);
void geraImgGreyFull_R(unsigned char[480][640], int, unsigned char);

int main(void){
    unsigned char pixel, img[480][640];
    int i = 479, j = 639;
    printf("Entre com o valor para preencher a imagem:\n");
    scanf("%hhu", &pixel);
    geraImgGreyFull_R(img, i, pixel);
    for(i = 0; i < 480; i++){
        for(j = 0; j < 640; j++){
            printf("%u ", img[i][j]);
        }
        printf("\n");
    }
}
void geraLinhaR(unsigned char img[480][640],int i, int j, unsigned char pixel){
    if(j < 0){
        return;
    }
    else{
        img[i][j] = pixel;
        geraLinhaR(img, i, j - 1, pixel);
    }
}
void geraImgGreyFull_R(unsigned char img[480][640], int i, unsigned char pixel){
    if(i < 0){
        return;
    }
    else{
        geraLinhaR(img, i, 639, pixel);
        geraImgGreyFull_R(img, i -1, pixel);
    }
}
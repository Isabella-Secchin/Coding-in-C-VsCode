#include <stdlib.h>
#include <stdio.h>

void geraLinhaR(unsigned char[480][640], int, int);
void geraImgGreyW_R(unsigned char[480][640], int);

int main(void){
    unsigned char img[480][640];
    int i = 479, j = 639;
    geraImgGreyW_R(img, i);
    for(i = 0; i < 480; i++){
        for(j = 0; j < 640; j++){
            printf("%u ", img[i][j]);
        }
        printf("\n");
    }
}
void geraLinhaR(unsigned char img[480][640],int i, int j){
    if(j < 0){
        return;
    }
    else{
        img[i][j] = 255;
        geraLinhaR(img, i, j - 1);
    }
}
void geraImgGreyW_R(unsigned char img[480][640], int i){
    if(i < 0){
        return;
    }
    else{
        geraLinhaR(img, i, 639);
        geraImgGreyW_R(img, i -1);
    }
}
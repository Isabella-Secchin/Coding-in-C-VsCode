#include <stdio.h>
#include <stdlib.h>

void geraImgGreyW(unsigned char img[480][640]);

int main(void){
    int i, j;
    unsigned char img[480][640];
    geraImgGreyW(img);
    for(i = 0; i < 480; i++){
        for(j = 0; j < 640; j++){
            printf("%u ", img[i][j]);
        }
        printf("\n");
    }
}

void geraImgGreyW(unsigned char img[480][640]){
    int i, j;
    for(i = 0; i < 480; i++){
        for(j = 0; j < 640; j++){
            img[i][j] = 255;
        }
    }
}
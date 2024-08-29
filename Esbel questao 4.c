#include <stdio.h>
#include <stdlib.h>

void geraImgGreyW(unsigned char img[640][480]);

int main(void){
    int i, j;
    unsigned char img[640][480];
    geraImgGreyW(img);
    for(i = 0; i < 640; i++){
        for(j = 0; j < 480; j++){
            printf("%d e %d : %u \n", i+1, j+1, img[i][j]);
        }
    }
}

void geraImgGreyW(unsigned char img[640][480]){
    int i, j;
    for(i = 0; i < 640; i++){
        for(j = 0; j < 480; j++){
            img[i][j] = 255;
        }
    }
}
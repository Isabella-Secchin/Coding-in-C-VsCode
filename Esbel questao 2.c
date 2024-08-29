#include <stdlib.h>
#include <stdio.h>

void geraImgGreyFull(unsigned char img[480][640], unsigned char pixel);

int main(void){
    unsigned char pixel, img[480][640];
    int i, j;
    printf("Entre com o valor para preencher a imagem:\n");
    scanf("%u", &pixel);
    geraImgGreyFull(img, pixel);
    for(i = 0; i < 480; i++){
        for(j = 0; j < 640; j++){
            printf("%u ", img[i][j]);
        }
    }
}
void geraImgGreyFull(unsigned char img[480][640], unsigned char pixel){
    int i, j;
    for(i = 0; i < 480; i++){
        for(j = 0; j < 640; j++){
            img[i][j] = pixel;
        }
    }
}
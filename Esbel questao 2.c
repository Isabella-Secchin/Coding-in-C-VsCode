#include <stdlib.h>
#include <stdio.h>

void geraImgGreyFull(unsigned char img[640][480], unsigned char pixel);

int main(void){
    unsigned char pixel, img[640][480];
    int i, j;
    printf("Entre com o valor para preencher a imagem:\n");
    scanf("%u", &pixel);
    geraImgGreyFull(img, pixel);
    for(i = 0; i < 640; i++){
        for(j = 0; j < 480; j++){
            printf("%d e %d : %u \n", i+1, j+1, img[i][j]);
        }
    }
}
void geraImgGreyFull(unsigned char img[640][480], unsigned char pixel){
    int i, j;
    for(i = 0; i < 640; i++){
        for(j = 0; j < 480; j++){
            img[i][j] = pixel;
        }
    }
}
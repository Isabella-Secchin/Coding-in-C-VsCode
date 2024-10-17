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

void geraImgGreyFull_D(unsigned char* img, int nLin, int nCol, unsigned char pixel){
    for(int i = 0; i < nLin * nCol; i++){
        img[i] = pixel;
    }
}

int main(void){
    int nLin = 4, nCol = 5, tipo;
    unsigned char* img = (unsigned char*) malloc(nLin * nCol * sizeof(unsigned char));
    unsigned char pixel;
    srand(time(NULL));
    printf("Entre com o tipo para gerar o pixel:\n");
    scanf("%d", &tipo);
    pixel = geraGreyPixel(tipo);
    printf("%u\n", pixel);
    geraImgGreyFull_D(img, nLin, nCol, pixel);
    for(int i = 0; i < nLin* nCol; i++){
        printf("Posicao %d: %u\n", i, img[i]);
    }
    free(img);
    return 0;
}
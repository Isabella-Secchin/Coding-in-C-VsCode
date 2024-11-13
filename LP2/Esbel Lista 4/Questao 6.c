#include <stdio.h>
#include <stdlib.h>

void geraImgGreyB_D(unsigned char* img, int nLin, int nCol){
    for(int i = 0; i < nLin * nCol; i++){
        img[i] = 0;
    }
}

int main(void){
    int nLin = 4, nCol = 5;
    unsigned char* img = (unsigned char*) malloc(nLin * nCol * sizeof(unsigned char));
    geraImgGreyB_D(img, nLin, nCol);
    for(int i = 0; i < nLin* nCol; i++){
        printf("Posicao %d: %u\n", i, img[i]);
    }
    free(img);
    return 0;
}
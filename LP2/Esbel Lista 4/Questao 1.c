#include <stdio.h>
#include <stdlib.h>

unsigned char* alocaImagem1D(int nLin, int nCol){
    int tamanho = nLin * nCol;
    unsigned char* img = (unsigned char*) calloc(tamanho, sizeof(unsigned char));
    return img;
}
int main(void){
    int nLin = 4, nCol = 5;
    unsigned char* img = alocaImagem1D(nLin, nCol);
    for(int i = nLin * nCol - 1; i >= 0; i--){
        printf("Posicao %d: %u\n", i, img[i]);
    }
    free(img);
    return 0;
}
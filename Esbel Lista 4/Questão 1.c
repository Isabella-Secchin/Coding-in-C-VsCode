#include <stdio.h>
#include <stdlib.h>

unsigned char* alocaImagem1D(int nLin, int nCol){
    int tamanho = nLin * nCol;
    unsigned char* img = (unsigned char*) calloc(tamanho, sizeof(unsigned char));
    return 0;
}
int main(void){
    int nLin = 4, nCol = 5;
    unsigned char* img = alocaImagem1D(nLin, nCol);
    for(int i = nLin * nCol; i >= 0; i--){
        printf("%d\n", img[i]);
    }
    free(img);
}
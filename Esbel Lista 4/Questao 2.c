#include <stdio.h>
#include <stdlib.h>

unsigned char** alocaImagem2D(unsigned char* img1D, int nLin, int nCol){
    unsigned char** img2D = (unsigned char**) calloc(nLin, sizeof(unsigned char*));
    for(int i = 0; i < nLin; i++){
        img2D[i] = &img1D[i * nCol];
    }
    return img2D;
}
int main(void){
    int nLin = 4, nCol = 5;
    unsigned char* img1D = (unsigned char*) calloc(nLin * nCol, sizeof(unsigned char));
    unsigned char** img2D = alocaImagem2D(img1D, nLin, nCol);
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            printf("Posicao (%d, %u): %d\n", i, j, img2D[i][j]);
        }
    }
    free(img2D);
    free(img1D);
    return 0;
}
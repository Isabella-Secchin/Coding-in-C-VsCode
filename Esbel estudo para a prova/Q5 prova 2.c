#include <stdio.h>
#include <stdlib.h>

int** filtroMaximo(int **img, int lin, int col) {
    int** nova_img = (int**) malloc(lin * sizeof(int*));
    for (int i = 0; i < lin; i++) {
        nova_img[i] = (int*) malloc(col * sizeof(int));
    }
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 || i == lin - 1 || j == 0 || j == col - 1) {
                nova_img[i][j] = img[i][j]; 
            } else {
                int max_val = img[i][j];
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int vizinho = img[i + di][j + dj];
                        if (vizinho > max_val) {
                            max_val = vizinho;
                        }
                    }
                }
                nova_img[i][j] = max_val;
            }
        }
    }
    return nova_img;
}

void liberarImagem(int **img, int lin) {
    for (int i = 0; i < lin; i++) {
        free(img[i]);
    }
    free(img);
}

int main() {
    int lin = 5, col = 5;
    int** img = (int**) malloc(lin * sizeof(int*));
    for (int i = 0; i < lin; i++) {
        img[i] = (int*) malloc(col * sizeof(int));
        for (int j = 0; j < col; j++) {
            img[i][j] = i * col + j;  
        }
    }
    int** nova_img = filtroMaximo(img, lin, col);
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", nova_img[i][j]);
        }
        printf("\n");
    }
    liberarImagem(img, lin);
    liberarImagem(nova_img, lin);

    return 0;
}

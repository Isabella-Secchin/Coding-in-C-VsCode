#include <stdio.h>
#include <stdlib.h>

int guardaImagem(unsigned char** img, int lin, int col, char* fileName) {
    // Abre o arquivo para escrita em modo binário
    FILE* file = fopen(fileName, "wb");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }
    // Escreve o número de linhas e colunas no arquivo
    if (fwrite(&lin, sizeof(int), 1, file) != 1 || fwrite(&col, sizeof(int), 1, file) != 1) {
        perror("Erro ao escrever dimensões");
        fclose(file);
        return -1;
    }
    // Escreve os valores da matriz no arquivo
    for (int i = 0; i < lin; i++) {
        if (fwrite(img[i], sizeof(unsigned char), col, file) != col) {
            perror("Erro ao escrever os dados da matriz");
            fclose(file);
            return -1;
        }
    }
    // Fecha o arquivo
    fclose(file);
    return 0;
}

int main() {
    // Exemplo de criação de uma matriz de 10x10
    int lin = 10, col = 10;
    unsigned char** img = malloc(lin * sizeof(unsigned char*));
    for (int i = 0; i < lin; i++) {
        img[i] = malloc(col * sizeof(unsigned char));
        for (int j = 0; j < col; j++) {
            img[i][j] = i * 10 + j; // Exemplo de preenchimento
        }
    }
    // Salva a imagem em um arquivo
    if (guardaImagem(img, lin, col, "imagem.bin") == 0) {
        printf("Imagem salva com sucesso.\n");
    } else {
        printf("Erro ao salvar a imagem.\n");
    }
    // Libera a memória alocada
    for (int i = 0; i < lin; i++) {
        free(img[i]);
    }
    free(img);
    return 0;
}

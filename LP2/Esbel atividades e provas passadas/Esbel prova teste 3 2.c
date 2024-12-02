#include <stdio.h>
#include <stdlib.h>

unsigned char** carregaImagem(int* col, int* lin, char* fileName) {
    // Abre o arquivo para leitura em modo binário
    FILE* file = fopen(fileName, "rb");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }
    // Lê o número de linhas e colunas do arquivo
    if (fread(lin, sizeof(int), 1, file) != 1 || fread(col, sizeof(int), 1, file) != 1) {
        perror("Erro ao ler dimensões");
        fclose(file);
        return NULL;
    }
    // Aloca a matriz de ponteiros para as linhas
    unsigned char** img = malloc(*lin * sizeof(unsigned char*));
    if (!img) {
        perror("Erro ao alocar memória para linhas");
        fclose(file);
        return NULL;
    }
    // Aloca cada linha da matriz e lê os dados do arquivo
    for (int i = 0; i < *lin; i++) {
        img[i] = malloc(*col * sizeof(unsigned char));
        if (!img[i]) {
            perror("Erro ao alocar memória para colunas");
            // Libera a memória já alocada antes de retornar NULL
            for (int j = 0; j < i; j++) {
                free(img[j]);
            }
            free(img);
            fclose(file);
            return NULL;
        }
        if (fread(img[i], sizeof(unsigned char), *col, file) != *col) {
            perror("Erro ao ler os dados da matriz");
            // Libera a memória antes de retornar NULL
            for (int j = 0; j <= i; j++) {
                free(img[j]);
            }
            free(img);
            fclose(file);
            return NULL;
        }
    }
    // Fecha o arquivo
    fclose(file);
    // Retorna a matriz carregada
    return img;
}

int main() {
    int lin, col;
    char* fileName = "imagem.bin";
    // Carrega a imagem do arquivo
    unsigned char** img = carregaImagem(&col, &lin, fileName);
    if (!img) {
        printf("Erro ao carregar a imagem.\n");
        return 1;
    }
    // Exibe os valores carregados (para teste)
    printf("Imagem carregada com %d linhas e %d colunas:\n", lin, col);
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("%3d ", img[i][j]);
        }
        printf("\n");
    }
    // Libera a memória alocada
    for (int i = 0; i < lin; i++) {
        free(img[i]);
    }
    free(img);
    return 0;
}

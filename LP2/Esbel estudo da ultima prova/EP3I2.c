#include <stdio.h>
#include <stdlib.h>

unsigned char** carregaImagem(int* col, int* lin, char* fileName){
    FILE *fp = fopen(fileName, "rb");
    if(!fp){
        perror("Erro ao abrir o arquivo!");
        return NULL;
    }
    if(fread(lin, sizeof(int), 1, fp) != 1 || fread(col, sizeof(int), 1, fp) != 1 ){
        perror("Erro ao ler o conteudo do arquivo!");
        fclose(fp);
        return NULL;
    }
    int i;
    unsigned char **matriz = (unsigned char**)malloc(*lin * sizeof(unsigned char*));
    for(i = 0; i < *lin; i++){
        matriz[i] = (unsigned char*)malloc(*col * sizeof(unsigned char));
    }
    for(i = 0; i < *lin; i++){
        if(fread(matriz[i], sizeof(unsigned char), *col, fp) != *col){
            perror("Erro ao ler o conteudo do arquivo!");
            fclose(fp);
            return NULL;
        }
    }
    fclose(fp);
    return matriz;
}

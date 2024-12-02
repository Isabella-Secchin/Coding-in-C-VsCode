#include <stdlib.h>
#include <stdio.h>

int guardaImagem(unsigned char** img, int lin, int col, char* fileName){
    FILE *fp = fopen(fileName, "wb");
    if(!fp){
        perror("Erro ao abrir o arquivo!");
        return -1;
    }
    if(fwrite(&lin, sizeof(int), 1, fp) != 1 || fwrite(&col, sizeof(int), 1, fp) != 1){
        perror("Erro ao escrever no arquivo!");
        fclose(fp);
        return -1;
    }
    for(int i = 0; i < lin; i++){
        if(fwrite(img[i], sizeof(unsigned char), col, fp) != col){
            perror("Erro ao escrever no arquivo!");
            fclose(fp);
            return -1;
        }
    }
    if(fclose(fp) != 0){
        perror("Erro ao fechar o arquivo!");
        return -1;
    }
    return 0;
}
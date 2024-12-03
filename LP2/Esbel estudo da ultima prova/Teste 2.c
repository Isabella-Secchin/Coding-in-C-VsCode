#include <stdlib.h>
#include <stdio.h>


// Questao 1

int guardaImagem(unsigned char** img, int lin, int col, char* fileName){
    FILE *fp = fopen(fileName, "wb");
    if(!fp){
        perror("Erro ao abrir o arquivo!");
        return -1;
    }
    if(fwrite(&lin, sizeof(int), 1, fp) != 1 || fwrite(&col, sizeof(int), 1, fp) != 1 ){
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
    fclose(fp);
    return 0;
}

// Questao 2

unsigned char** carregaImagem(int* col, int* lin, char* fileName){
    FILE *fp = fopen(fileName, "rb");
    int i;
    if(!fp){
        perror("Erro ao abrir o arquivo!");
        return NULL;
    }
    if(fread(lin, sizeof(int), 1, fp) != 1 || fread(col, sizeof(int), 1, fp) != 1){
        perror("Erro ao ler conteudo do arquivo!");
        fclose(fp);
        return NULL;
    }
    unsigned char **img = (unsigned char**)malloc(*lin * sizeof(unsigned char*));
    for(i = 0; i < *lin; i++){
        img[i] = (unsigned char*)malloc(*col * sizeof(unsigned char));
    }
    for(i = 0; i < *lin; i++){
        if(fread(img[i], sizeof(unsigned char), *col, fp) != *col){
            perror("Erro ao ler conteudo do arquivo!");
            fclose(fp);
            return NULL;
        }
    }
    fclose(fp);
    return img;
}

//Questao 3

int main(void){
    char fn[] = "arquivo.bin", fn2[] = "arquivo.txt";
    FILE *fp = fopen(fn, "rb");
    if(!fp){
        perror("Erro ao abrir arquivo binario!");
        return 1;
    }
    FILE *fp2 = fopen(fn2, "w");
    if(!fp2){
        perror("Erro ao abrir arquivo de texto!");
        fclose(fp);
        return 1;
    }
    int valor;
    while(fread(&valor, sizeof(int), 1, fp) == 1){
        fprintf(fp2, "%d\n", valor);
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}
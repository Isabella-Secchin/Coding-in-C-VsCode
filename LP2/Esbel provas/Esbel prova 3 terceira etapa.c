#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Questão 1

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

// Questão 2

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

//Questão 3

int lerChar(char* fileName){
    FILE *fp = fopen(fileName, "r");
    if(!fp){
        perror("Erro ao abrir o arquivo!");
        return -1;
    }
    char aux;
    int cont = 0;
    while(fread(&aux, sizeof(char), 1, fp) == 1){
        cont++;
        if(cont > 1200){
            return 0;
        }
    }
    fclose(fp);
    return cont;
}

//Main para testar as funções

int main(void){

    //Questão 1

    int lin = 10, col = 10, i, j;
    char fileName[] = "Imagem cinza.bin";
    unsigned char** imgAux = (unsigned char**)calloc(lin, sizeof(unsigned char*));
    for(i = 0; i < lin; i++){
        imgAux[i] = (unsigned char*)calloc(col, sizeof(unsigned char));
    }
    guardaImagem(imgAux, lin, col, fileName);

    printf("\nQUESTAO 1:\n\n");
    printf("Matriz gerada pela questao 1: (toda preenchida com 0 por conta do calloc)\n\n");
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            printf("%u\t", imgAux[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    //Questão 2
    
    unsigned char** imgAux2 = carregaImagem(&col, &lin, fileName);
    printf("QUESTAO 2:\n\n");
    printf("Matriz lida pela questao 2: (Matriz gerada pela funcao da questao 1)\n\n");

    // A matriz lida é gerada pela função da questão 1, impressa toda com 0 por conta do calloc.

    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            printf("%u\t", imgAux2[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    
    //Questão 3
    
    //Código auxiliar para gerar arquivo de texto para ser lido pela função da questão 3:

    char arquivoAux[] = "Arquivo.txt";
    FILE *fp2 = fopen(arquivoAux, "w");
    if(!fp2){
        perror("Erro ao abrir arquivo!");
        return -1;
    }
    srand(time(NULL));
    j = rand()% 1200;
    int tipo;
    char cAux;
    for(i = 0; i < j; i++){
        tipo = rand() % 3;
        if (tipo == 0) {
            cAux = '0' + (rand() % 10); 
        }
        else if (tipo == 1) {
            cAux = 'A' + (rand() % 26); 
        }
        else {
            cAux = 'a' + (rand() % 26); 
        }
        fprintf(fp2, "%c", cAux);
    }
    fclose(fp2);
    printf("QUESTAO 3:\n\n");
    printf("Quantidade de caracteres que deve ser retornada pela funcao: %d\n\n", j);

    //Uso da função da questão 3

    int cont2 = lerChar(arquivoAux);
    printf("Quantidade de caracteres no arquivo txt de acordo com a funcao da questao 3: %d\n\n", cont2);
    if(j == cont2){
        printf("%d == %d Funcao da questao 3 funcionou!\n\n", j, cont2);
    }
    return 0;
}
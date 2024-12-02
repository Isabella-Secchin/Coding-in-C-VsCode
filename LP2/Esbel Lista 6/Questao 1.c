#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;

typedef struct{
    uchar *_img;
    uchar **img;
    int nLin, nCol;
}imgGray;

int saveImgGray(imgGray img, char desc[], char fileName[]){
    char dataFileName[256], headerFileName[256];
    FILE *dataFile, *headerFile;

    snprintf(dataFileName, sizeof(dataFileName), "%s.data", fileName);
    snprintf(headerFileName, sizeof(headerFileName), "%s", fileName);

    dataFile = fopen(dataFileName, "wb");
    if(!dataFile){
        return 0;
    }
    if(fwrite(img._img, sizeof(uchar), img.nLin * img.nCol, dataFile) != img.nLin * img.nCol){
        fclose(dataFile);
        return 0;
    }
    fclose(dataFile);

    headerFile = fopen(headerFileName, "w");
    if(!headerFile){
        return 0;
    }
    fprintf(headerFile, "Descrição: %s\n", desc);
    fprintf(headerFile, "Largura: %d\n", img.nCol);
    fprintf(headerFile, "Altura: %d\n", img.nLin);
    fprintf(headerFile, "Arquivo de dados: %s\n", dataFileName);
    fclose(headerFile);

    return 1;
}

int main(void){
    char desc[80], nomeArquivo[80];
    imgGray img;
    img.nLin = 10;
    img.nCol = 10;
    img._img = (uchar*) calloc(img.nLin * img.nCol, sizeof(uchar));
    printf("Entre com o nome do arquivo:\n");
    fgets(nomeArquivo, sizeof(nomeArquivo), stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';
    printf("Entre com a descrição da imagem:\n");
    fgets(desc, sizeof(desc), stdin);
    desc[strcspn(desc, "\n")] = '\0';
    if(!saveImgGray(img, desc, nomeArquivo)){
        printf("Erro ao salvar a imagem\n");
    }
    else{
        printf("Imagem salva com sucesso\n");
    }
    free(img._img);
    return 0;
}
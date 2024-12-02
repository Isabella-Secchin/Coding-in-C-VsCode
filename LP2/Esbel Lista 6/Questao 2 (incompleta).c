#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;

typedef struct{
    uchar R, G, B;
}tRGB;

typedef struct{
    tRGB *_img;
    tRGB **img;
    int nLin, nCol;
}imgRGB;

int saveImgRGB(imgRGB img, char[] fileName){
    char dataFileName[256], headerFileName[256];
    FILE *dataFile, *headerFile;

    snprintf(dataFileName, sizeof(dataFileName), "%s.data", fileName);
    snprintf(headerFileName, sizeof(headerFileName), "%s", fileName);

    dataFile = fopen(dataFileName, "wb");
    if(!dataFile){
        return 0;
    }
    if(fwrite(img._img, sizeof(tRGB), img.nLin * img.nCol, dataFile) != img.nLin * img.nCol){
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
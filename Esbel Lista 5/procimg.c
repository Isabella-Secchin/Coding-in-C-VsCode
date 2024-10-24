#include <stdio.h>
#include <stdlib.h>
#include "procimg.h"

int nLin = 10;
int nCol = 10;

typedef unsigned char uchar;

typedef struct{
    int nLin, nCol;
    uchar *pixels;
}imgGray;

typedef struct{
    unsigned char *R;
    unsigned char *G;
    unsigned char *B;
    int nLin, nCol;
}imgRGB;

typedef struct{
    uchar R, G, B;
}tRGB;

//Anteriores

unsigned char geraGreyPixel(int tipo){
    int i = rand() % 100 + 1;
    if(tipo < 0){
        if(i <= 75){
            return rand() % 128;
        }
        else{
            return 128 + rand() % (256 - 128);
        }
    }
    else if(tipo > 0){
        if(i<=75){
            return 128 + rand() % (256 - 128);
        }
        else{
            return rand() % 128;
        }
    }
    else if(tipo == 0){
        return rand() % 256;
    }
}

//Questao 1

imgGray alocaImagemGray(int nLin, int nCol){
    imgGray _img;

    _img.nLin = nLin;
    _img.nCol = nCol;
    _img.pixels = NULL;

    _img.pixels = (unsigned char*) malloc(nLin * nCol * sizeof(unsigned char));
    if(_img.pixels == NULL){
        return _img;
    }
    return _img;
}

//Questao 2

imgRGB alocaImagemRGB(int nLin, int nCol){
    imgRGB _img;

    _img.nLin = nLin;
    _img.nCol = nCol;
    _img.R = NULL;
    _img.G = NULL;
    _img.B = NULL;

    _img.R = (unsigned char*) malloc(nLin * nCol * sizeof(unsigned char));
    _img.G = (unsigned char*) malloc(nLin * nCol * sizeof(unsigned char));
    _img.B = (unsigned char*) malloc(nLin * nCol * sizeof(unsigned char));

    if (_img.R == NULL || _img.G == NULL || _img.B == NULL){
        if(_img.R) free(_img.R);
        if(_img.G) free(_img.G);
        if(_img.B) free(_img.B);
        _img.R = _img.G = _img.B = NULL;
        return _img;
    }
    return _img;
}

//Questao 3

int geraImgGrayFull(imgGray _img, uchar pixel){
    if (_img.pixels == NULL){
        return 0;
    }
    for(int i = 0; i < _img.nLin * _img.nCol; i++){
        _img.pixels[i] = pixel;
    }
    return 1;
}

//Questao 4

int geraImgRGBFull(imgRGB _img, tRGB pixel){
    if(_img.R == NULL || _img.G == NULL || _img.B == NULL){
        if(_img.R) free(_img.R);
        if(_img.G) free(_img.G);
        if(_img.B) free(_img.B);
        _img.R = _img.G = _img.B = NULL;
        return 0;
    }
    for(int i = 0;  i < _img.nLin * _img.nCol; i++){
        _img.R[i] = pixel.R;
        _img.G[i] = pixel.G;
        _img.B[i] = pixel.B;
    }
    return 1;
}

//Questao 5

int geraImgGrayB(imgGray _img){
    if (_img.pixels == NULL){
        return 0;
    }
    for(int i = 0; i < _img.nLin * _img.nCol; i++){
        _img.pixels[i] = 0;
    }
    return 1;
}

//Questao 6

int geraImgRGBB(imgRGB _img){
    if(_img.R == NULL || _img.G == NULL || _img.B == NULL){
        if(_img.R) free(_img.R);
        if(_img.G) free(_img.G);
        if(_img.B) free(_img.B);
        _img.R = _img.G = _img.B = NULL;
        return 0;
    }
    for(int i = 0;  i < _img.nLin * _img.nCol; i++){
        _img.R = 0;
        _img.G = 0;
        _img.B = 0;
    }
    return 1;
}

//Questao 7

int geraImgGrayW(imgGray _img){
    if (_img.pixels == NULL){
        return 0;
    }
    for(int i = 0; i < _img.nLin * _img.nCol; i++){
        _img.pixels[i] = 255;
    }
    return 1;
}

//Questao 8

int geraImgRGBW(imgRGB _img){
    if(_img.R == NULL || _img.G == NULL || _img.B == NULL){
        if(_img.R) free(_img.R);
        if(_img.G) free(_img.G);
        if(_img.B) free(_img.B);
        _img.R = _img.G = _img.B = NULL;
        return 0;
    }
    for(int i = 0;  i < _img.nLin * _img.nCol; i++){
        _img.R = 255;
        _img.G = 255;
        _img.B = 255;
    }
    return 1;
}

//Questao 9

int geraImgGray(imgGray _img, int tipo){
    if (_img.pixels == NULL){
        return 0;
    }
    for(int i = 0; i < _img.nLin * _img.nCol; i++){
        _img.pixels[i] = geraGreyPixel(tipo);
    }
    return 1;
}

//Questao 10

int geraImgRGB(imgRGB _img, int tipo){
    if(_img.R == NULL || _img.G == NULL || _img.B == NULL){
        if(_img.R) free(_img.R);
        if(_img.G) free(_img.G);
        if(_img.B) free(_img.B);
        _img.R = _img.G = _img.B = NULL;
        return 0;
    }
    for(int i = 0;  i < _img.nLin * _img.nCol; i++){
        _img.R = geraGreyPixel(tipo);
        _img.G = geraGreyPixel(tipo);
        _img.B = geraGreyPixel(tipo);
    }
    return 1;
}

//Questao 11

int pixelGrayMax(imgGray _img){
    int max = 0;
    for(int i = 0; i < _img.nLin * _img.nCol; i++){
        if(max < _img.pixels[i]){
            max = _img.pixels[i];
        }
    }
    return max;
}

int pixelGrayMin(imgGray _img){
    int min = 255;
    for(int i = 0; i < _img.nLin * _img.nCol; i++){
        if(min < _img.pixels[i]){
            min = _img.pixels[i];
        }
    }
    return min;
}

//Questao 12

tRGB pixelRGBMax(imgRGB _img){
    tRGB max = {0, 0, 0};
    for(int i = 0; i < _img.nLin * _img.nCol; i++){
        if(max.R < _img.R[i]){
            max.R = _img.R[i];
        }
        if(max.G < _img.G[i]){
            max.G = _img.G[i];
        }
        if(max.B < _img.B[i]){
            max.B = _img.B[i];
        }
    }
    return max;
}

tRGB pixelRGBMin(imgRGB _img){
     tRGB min = {255, 255, 255};
    for(int i = 0; i < _img.nLin * _img.nCol; i++){
        if(min.R > _img.R[i]){
            min.R = _img.R[i];
        }
        if(min.G > _img.G[i]){
            min.G = _img.G[i];
        }
        if(min.B > _img.B[i]){
            min.B = _img.B[i];
        }
    }
    return min;
}

//Questao 13

int* somaPorLinhasGray(imgGray _img){
    int* soma = (int*) calloc(_img.nLin, sizeof(int));
    for(int i = 0; i < _img.nLin; i++){
        for(int j = 0; j < _img.nCol; j++){
            soma[i] += _img.pixels[i * _img.nCol + j];
        }
    }
    return soma;
}

int* somaPorColunasGray(imgGray _img){
    int* soma = (int*) calloc(_img.nCol, sizeof(int));
    for(int j = 0; j < _img.nCol; j++){
        for(int i = 0; i < _img.nLin; i++){
            soma[j] += _img.pixels[i * _img.nCol + j];
        }
    }
    return soma;
}

//Questao 14

tRGB* somaPorLinhasRGB(imgRGB _img){
    tRGB* soma = (tRGB*) calloc(_img.nLin, sizeof(tRGB));
    for(int i = 0; i < _img.nLin; i++){
        for(int j = 0; j < _img.nCol; j++){
            soma[i].R += _img.R[i * _img.nCol + j];
            soma[i].G += _img.G[i * _img.nCol + j];
            soma[i].B += _img.B[i * _img.nCol + j];
        }
    }
    return soma;
}

tRGB* somaPorColunasRGB(imgRGB _img){
    tRGB* soma = (tRGB*) calloc(_img.nCol, sizeof(tRGB));
    for(int j = 0; j < _img.nCol; j++){
        for(int i = 0; i < _img.nLin; i++){
            soma[j].R += _img.R[i * _img.nCol + j];
            soma[j].G += _img.G[i * _img.nCol + j];
            soma[j].B += _img.B[i * _img.nCol + j];
        }
    }
    return soma;
}




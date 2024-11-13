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

unsigned char geraGreyPixel(int tipo);

// Questao 1

imgGray alocaImagemGray(int nLin, int nCol);

//Questao 2

imgRGB alocaImagemRGB(int nLin, int nCol);

//Questao 3

int geraImgGrayFull(imgGray _img, uchar pixel);

//Questao 4

int geraImgRGBFull(imgRGB _img, tRGB pixel);

//Questao 5

int geraImgGrayB(imgGray _img);

//Questao 6

int geraImgRGBB(imgRGB _img);

//Questao 7

int geraImgGrayW(imgGray _img);

//Questao 8

int geraImgRGBW(imgRGB _img);

//Questao 9

int geraImgGray(imgGray _img, int tipo);

//Questao 10

int geraImgRGB(imgRGB _img, int tipo);

//Questao 11

int pixelGrayMax(imgGray _img);
int pixelGrayMin(imgGray _img);

//Questao 12

tRGB pixelRGBMax(imgRGB _img);
tRGB pixelRGBMin(imgRGB _img);

//Questao 13

int* somaPorLinhasGray(imgGray _img);
int* somaPorColunasGray(imgGray _img);

//Questao 14

tRGB* somaPorLinhasRGB(imgRGB _img);
tRGB* somaPorColunasRGB(imgRGB _img);

//Questao 15

int somaTotalGray(imgGray _img);

//Questao 16

tRGB somaTotalRGB(imgRGB _img);

//Questao 17

int quantosPixelsGrayNaInt(imgGray _img, uchar inten);

//Questao 18

int quantosPixelsRGBNaInt(imgRGB _img, tRGB inten);

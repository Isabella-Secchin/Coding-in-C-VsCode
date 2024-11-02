#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Questao 3:

typedef struct{
    int num;
    int den;
    double valor;
}frac;

frac* geraRadomArray(int tam){
    srand(time(NULL));
    frac* array = NULL;
    array = (frac*)malloc(tam * sizeof(frac));
    if(array == NULL){
        return array;
    }
    for(int i = 0; i < tam; i++){
        array[i].num = rand() % 101;
        int aux = rand() % 2;
        if(aux == 1){
            array[i].num *= -1;
        }
        array[i].den = rand() % 101;
        aux = rand() % 2;
        if(aux == 1){
            array[i].den *= -1;
        }
        array[i].valor = (array[i].den != 0) ? (double) array[i].num/array[i].den : 1000000.0;
    }
    return array;
}

//Questao 4:

typedef unsigned char uchar;

typedef struct{
    uchar R, G, B;
}tRGB;

typedef struct{
    uchar *_img;
    uchar **img;
    int nLin, nCol;
}imgGray;

typedef struct{
    tRGB *_img;
    tRGB **img;
    int nLin, nCol;
}imgRGB;

imgRGB geraRandomImage(int nLin, int nCol){
    imgRGB imagem;
    imagem.nLin = nLin;
    imagem.nCol = nCol;
    imagem._img = NULL;
    imagem._img = (tRGB*)malloc(nLin * nCol * sizeof(tRGB));
    if(imagem._img == NULL){
        return imagem;
    }
    for(int i = 0; i < nLin * nCol; i++){
        imagem._img[i].R = rand() % 256;
        imagem._img[i].G = rand() % 256;
        imagem._img[i].B = rand() % 256;
    }
    return imagem;
}

//Questao 5: (utiliza os structs da questao 4)

imgGray convert(imgRGB img){
    imgGray imagem;
    imagem.nLin = img.nLin;
    imagem.nCol = img.nCol;
    imagem._img = NULL;
    imagem._img = (uchar*)malloc(img.nLin * img.nCol * sizeof(uchar));
    if(imagem._img == NULL){
        return imagem;
    }
    for(int i = 0; i < img.nLin * img.nCol; i++){
        imagem._img[i] = (uchar) (0.299 * img._img[i].R + 0.587 * img._img[i].G + 0.114 * img._img[i].B);
    }
    return imagem;
}

//Main para testar as funcoes

int main(void){
    printf("\n\nQuestao 3:\n\n");
    int tam = 10, i;
    frac* array = geraRadomArray(tam);
    for(i = 0; i < tam; i++){
        printf("Iteração %d:\n\n", i + 1);
        printf("Valor no numerador: %d\n", array[i].num);
        printf("Valor no denominador%d\n", array[i].den);
        printf("Valor da divisão (1000000.0 se o denominador for 0):%lf\n", array[i].valor);
        printf("\n");
    }

    printf("\nQuestao 4:\n\n");
    int nLin = 10, nCol = 10;
    imgRGB imagem = geraRandomImage(nLin, nCol);
    printf("Matriz da cor vermelha:\n");
    //i inicializado como 1 para o print da matriz ficar no formato certo na hora de aparecer no terminal
    //Por isso utilizei i - 1 na hora de acessar os valores
    for(i = 1; i < nLin * nCol + 1; i++){
        printf("%u\t", imagem._img[i - 1].R);
        if(i > 1 && i%10 == 0){
            printf("\n");
        }
    }
    printf("\n\nMatriz da cor verde:\n");
    for(i = 1; i < nLin * nCol + 1; i++){
        printf("%u\t", imagem._img[i - 1].G);
        if(i > 1 && i%10 == 0){
            printf("\n");
        }
    }
    printf("\n\nMatriz da cor azul:\n");
    for(i = 1; i < nLin * nCol + 1; i++){
        printf("%u\t", imagem._img[i - 1].B);
        if(i > 1 && i%10 == 0){
            printf("\n");
        }
    }

    printf("\nQuestao 5:\n\n");
    //Vou utilizar a imagem feita pela questao anterior para realizar o teste
    imgGray ImagemCinza = convert(imagem);
    printf("Imagem cinza:\n");
     //i inicializado como 1 para o print da matriz ficar no formato certo na hora de aparecer no terminal
    //Por isso utilizei i - 1 na hora de acessar os valores
    for(i = 1; i < nLin * nCol + 1; i++){
        printf("%u\t", ImagemCinza._img[i - 1]);
        if(i > 1 && i%10 == 0){
            printf("\n");
        }
    }
    return 0;
}
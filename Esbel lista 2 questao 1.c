#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned char geraGreyPixel(int);
void geraLinhaR(unsigned char[], int, int);

int main(void){
    int tipo, n = 639;
    unsigned char lin[640];
    srand(time(NULL));
    printf("Entre com o tipo para gerar os pixels:\n");
    scanf("%d", &tipo);
    geraLinhaR(lin, n, tipo);
    printf("Como esta o array: \n");
    for(n = 0; n < 640; n++){
        printf("Posicao %d: %u\n", n + 1, lin[n]);
    }
    return 0;
}

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
void geraLinhaR(unsigned char lin[640], int n, int tipo){
    if(n < 0){
        return;
    }
    lin[n] = geraGreyPixel(tipo);
    geraLinhaR(lin, n - 1, tipo);
}

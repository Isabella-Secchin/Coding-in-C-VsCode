#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(void){
    char frase[100], tempc;
    int temp1, temp2, i, j, tamanho;
    printf("Entre com uma frase:\n");
    fgets(frase, 100, stdin);
    tamanho = strlen(frase);
    if(frase[tamanho-1] == '\n'){
        frase[tamanho - 1] = '\0';
        tamanho--;
    }
    for(i = 0; i <= tamanho - 1; i++){
        frase[i] = tolower(frase[i]);
    }
    for(i = 0; i <= tamanho - 1; i++){
        for(j = 0; j < tamanho - 1 - i; j++) {
            if(frase[j] > frase[j + 1]) {
                tempc = frase[j];
                frase[j] = frase[j + 1];
                frase[j + 1] = tempc;
            }
        }
    }
    printf("Frase em ordem alfabetica:\n");
    for(i = 0; i <= tamanho - 1; i++){
        if(frase[i] == ' '){
            continue;
        }
        else{
            printf("%c", frase[i]);
        }
    }
    return 0;
}
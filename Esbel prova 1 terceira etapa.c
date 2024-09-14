#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int quantChar(char str[], char ch){
    int j = strlen(str) - 1, cont = 0;
    for( ; j >= 0; j--){
        if(str[j] == ch){
            cont++;
        }
    }
    return cont;
}

int quantMaiorZeros(float vet[], int n){
    int cont = 0;
    for( ;n > 0; n--){
        if(vet[n] > (float) 0){
            cont++;
        }
    }
    return cont;
}

int quantMaiorZerosR(float vet2[], int n){
    if(n < 0){
        return 0;
    }
    if(vet2[n] > (float) 0){
        return 1 + quantMaiorZerosR(vet2, n - 1);
    }
    return quantMaiorZerosR(vet2, n - 1);
}

int quantosParesR(int vet3[], int n){
    if(n < 0){
        return 0;
    }
    if(vet3[n] % 2 == 0){
        return 1 + quantosParesR(vet3, n - 1);
    }
    return quantosParesR(vet3, n - 1);
}

int quantosPares(int vet4[], int n){
    int cont = 0;
    for( ; n >= 0; n--){
        if(vet4[n] % 2 == 0){
            cont++;
        }
    }
    return cont;
}

int main(void){

    printf("\n\nQuestão 3:\n\n");
    char str[50] = "Ola mundo", ch = 'o';
    int j = strlen(str) - 1;
    for( ; j >= 0; j--){
        str[j] = tolower(str[j]);
    }
    j = 0;
    printf("A string:\n");
    for( ; j <= strlen(str) - 1; j++){
        printf("%c", str[j]);
    }
    printf("\n\nQuantidade de %c na string: %d\n\n", ch, quantChar(str, ch));

    printf("Questão 4.a (funcao nao recursiva):\n\n");
    float vet[10] = {0, 1, 2, 3, 0, 5, 6, 7, 0, 8};
    int n = 9, i;
    printf("O vetor é:\n");
    for(i = 0; i <= 9; i++){
        printf("%.2f  ", vet[i]);
    }
    printf("\n\nQuantidade de numeros maiores do que zero no array: %d\n\n", quantMaiorZeros(vet, n));

    printf("Questão 4.b (funcao recursiva):\n\n");
    float vet2[10] = {1, 3, 0, 5, 7, 8, 0, 3, 0, 0};
    printf("O vetor é:\n");
    for(i = 0; i <= 9; i++){
        printf("%.2f  ", vet2[i]);
    }
    printf("\n\nQuantidade de numeros maiores do que zero no array: %d\n\n", quantMaiorZerosR(vet2, n));
    
    printf("Questão 5.a (funcao recursiva):\n\n");
    int vet3[10] = {5, 4, 6, 0, 8, 9, 7, 3, 8, 10};
     printf("O vetor é:\n");
    for(i = 0; i <= 9; i++){
        printf("%d  ", vet3[i]);
    }
    printf("\n\nQuantidade de pares no vetor: %d\n\n", quantosParesR(vet3, n));

    printf("Questão 5.b (funcao nao recursiva):\n\n");
    int vet4[10] = {4, 8, 6, 10, 9, 7, 5, 3, 3, 5};
     printf("O vetor é:\n");
    for(i = 0; i <= 9; i++){
        printf("%d  ", vet4[i]);
    }
    printf("\n\nQuantidade de pares no vetor: %d\n\n", quantosPares(vet4, n));

    return 0;
}
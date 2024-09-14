#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Questão 3
int lenstr(char str[]){
    int i, j = 0, cont = strlen(str) - 1;
    for(i = cont; i >= 0; i--){
        if(str[i] != ' ' && str[i] != '\n'){
            j++;
        }
    }
    return j;
}

int main(void){
    char str[50];
    printf("Entre com uma frase: \n");
    fgets(str, 50, stdin);
    printf("Quantidade de caracteres na string: %d", lenstr(str));
    return 0;
}
*/
/* Questão 4
int quantZeros(int vet[], int n){
    int cont = 0;
    for( ; n >= 0; n--){
        if(vet[n] != 0){
            cont++;
        }
    }
    return cont;
}

int main(void){
    int vet[20], n = 19;
    srand(time(NULL));
    for(int i = 0; i <= 19; i++){
        vet[i] = rand() % 10;
    }
    for(int i = 0; i <= 19; i++){
        printf("Posição %d: %d\n", i + 1, vet[i]);
    }
    printf("A quantidade de numeros diferentes de 0 e: %d\n", quantZeros(vet, n));
    return 0;
}
*/
/* Questão 4.b
int quantZeros(int vet[], int n, int cont){
    if(n < 0){
        return cont;
    }
    if(vet[n] != 0){
        return quantZeros(vet, n - 1, cont + 1);
    }
    else{
        return quantZeros(vet, n - 1, cont);
    }
}

int main(void){
    int vet[20], n = 19, cont = 0;
    srand(time(NULL));
    for(int i = 0; i <= 19; i++){
        vet[i] = rand() % 10;
    }
    for(int i = 0; i <= 19; i++){
        printf("Posição %d: %d\n", i + 1, vet[i]);
    }
    printf("A quantidade de numeros diferentes de 0 e: %d\n", quantZeros(vet, n, cont));
    return 0;
}
*/
/* Questão 5
#include <stdio.h>

int strcmpR(const char str1[], const char str2[]) {
    if (*str1 == '\0' && *str2 == '\0') {
        return 0;
    }
    if (*str1 == '\0') {
        return -1;
    }
    if (*str2 == '\0') {
        return 1;
    }
    if (*str1 != *str2) {
        return *str1 - *str2;
    }
    return strcmpR(str1 + 1, str2 + 1);
}

int main(void) {
    const char *str1 = "amaciante";
    const char *str2 = "abacate";
    int result = strcmpR(str1, str2);

    if (result == 0) {
        printf("As strings são iguais.\n");
    } else if (result < 0) {
        printf("A primeira string vem antes da segunda na ordem alfabética.\n");
    } else {
        printf("A primeira string vem depois da segunda na ordem alfabética.\n");
    }

    return 0;
}
*/
/* Questão 5.b
#include <stdio.h>

int strcmpNR(const char str1[], const char str2[]) {
    for (; *str1 && *str2; str1++, str2++) {
        if (*str1 != *str2) {
            return *str1 - *str2;
        }
    }
    return *str1 - *str2;
}

int main(void) {
    const char *s1 = "amarelo";
    const char *s2 = "abacaxi";
    int result = strcmpNR(s1, s2);

    if (result == 0) {
        printf("As strings são iguais.\n");
    } else if (result < 0) {
        printf("A primeira string vem antes da segunda na ordem alfabética.\n");
    } else {
        printf("A primeira string vem depois da segunda na ordem alfabética.\n");
    }

    return 0;
}
*/

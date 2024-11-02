#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* geraPalavra(int tam){
    if(tam < 2){
        return NULL;
    }
    char vogais[] = "aeiou";
    char consoantes[] = "bcdfghjklmnpqrstvwxyz";
    char* palavra = NULL;
    palavra = (char*)malloc((tam + 1) * sizeof(char));
    if(palavra == NULL){
        return palavra;
    }
    for(int i = 0; i < tam; i++){
        if(i%2 == 0){
            palavra[i] = vogais[rand() % 5];
        }
        else{
            palavra[i] = consoantes[rand() % 21];
        }
    }
    palavra[tam] = '\0';
    return palavra;
}

int main(void){
    int tam = 4;
    srand(time(NULL));
    for(int j = 0; j <= 100; j++){
        char* palavra = geraPalavra(tam);
        for(int i = 0; i < tam; i++){
            printf("%c", palavra[i]);
        }
        free(palavra);
        printf("\n");
    }
    return 0;
}
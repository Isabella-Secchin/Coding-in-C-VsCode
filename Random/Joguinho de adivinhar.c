#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(void){
    int nc, nm, j, min = 1, max = 100;
    srand(time(NULL));
    printf("Entre com 1 para adivinhar e 2 para a maquina adivinhar: \n");
    scanf("%d", &j);
    if(j == 1){
        nm = rand()%100 + 1;
        printf("Entre com a suposicao (1-100): \n");
        for( ; ; ){
            scanf("%d", &nc);
            if(nc > nm){
                printf("Numero muito alto, tente novamente: \n");
                continue;
            }
            else if(nc < nm){
                printf("Numero muito baixo, tente novamente: \n");
                continue;
            }
            else{
                printf("Voce acertou o numero, parabens!\n");
                break;
            }
        }
    }
    else if(j == 2){
        printf("Entre com o numero para maquina adivinhar: \n");
        scanf("%d", &nm);
        for( ; ; ){
           nc = (min + max) / 2;
            printf("A maquina adivinha: %d\n", nc);
            if(nc > nm){
                printf("Numero muito alto.\n");
                max = nc - 1;  
            } 
            else if(nc < nm){
                printf("Numero muito baixo.\n");
                min = nc + 1; 
            } 
            else{
                printf("A maquina acertou o numero!\n");
                break;
            }
        }
    }
    return 0;
}
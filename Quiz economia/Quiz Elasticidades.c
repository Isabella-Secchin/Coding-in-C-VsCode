#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void laranja(){
  printf("\033[1;31m");
}

void azul(){
  printf("\033[1;34m");
}

void lilas(){
  printf("\033[1;35m");
}

void branco(){
  printf("\033[1;37m");
}

void ciano(){
  printf("\033[1;36m");
}

void reset(){
  printf("\033[0m");
}

int main(void){
    int i, j = 0, k;
    laranja();
    printf("\n\nQUIZ DE ECONOMIA - Elasticidades\n");
    printf("Grupo: Isabella Secchin, Guilherme Torres, João Rupp e Gustavo Souza\n\n");
    reset();
    for(i = 0; i < 11; i++){
        switch(i){
            case 0:
            for( ; ; ){
                azul();
                printf("QUESTÃO 1:\n");
                printf("A variação percentual na quantidade demandada, dada a variação percentual no preço de outro bem, se refere a...\n\n");
                reset();
                branco();
                printf("1.Elasticidade-renda da demanda\n");
                printf("2.Elasticidade-preço da demanda\n");
                printf("3.Elasticidade-preço da oferta\n");
                printf("4.Elasticidade-preço cruzada da demanda\n\n");
                reset();
                lilas();
                printf("Entre com a opção correta:");
                reset();
                scanf("%d", &k);
                if(k == 4){
                    ciano();
                    printf("\nParabéns você acertou a questão! :)\n\n");
                    reset();
                    j++;
                    break;
                }
                else if(k > 4 || k < 0){
                    printf("\nResposta inválida! Insira um número de 1 a 4\n\n");
                    continue;
                }
                else{
                    laranja();
                    printf("\nQue pena, você errou a questão ;(\n\n");
                    reset();
                    break;
                }
            }
            case 2:
        }
    }
    return 0;
}
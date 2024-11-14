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
          if(scanf("%d", &k) != 1){
            laranja();
            printf("\nResposta inválida! Insira um número de 1 a 4\n\n");
            reset();
            while (getchar() != '\n');
            continue;
          }
          else if( k != 4 && k != 3 && k != 2 && k != 1){
            laranja();
            printf("\nResposta inválida! Insira um número de 1 a 4\n\n");
            reset();
            continue;
          }
          else if(k == 4){
            ciano();
            printf("\nParabéns você acertou a questão! :)\n\n");
            reset();
            j++;
            break;
          }
          else{
            laranja();
            printf("\nQue pena, você errou a questão ;(\n\n");
            reset();
            break;
          }
        }
        break;
      case 2:
        for( ; ; ){
          azul();
          printf("QUESTÃO 2:\n");
          printf("Se o preço de um produto aumentar, a demanda desse porduto diminuir e a renda total aumentar,essa demanda é considerada...\n\n");
          reset();
          branco();
          printf("1.Elástica\n");
          printf("2.Inelástica\n");
          printf("3.Unitária\n");
          printf("4.Nenhuma das opções anteriores\n\n");
          reset();
          lilas();
          printf("Entre com a opção correta:");
          reset();
          if(scanf("%d", &k) != 1){
            laranja();
            printf("\nResposta inválida! Insira um número de 1 a 4\n\n");
            reset();
            while (getchar() != '\n');
            continue;
          }
          else if( k != 4 && k != 3 && k != 2 && k != 1){
            laranja();
            printf("\nResposta inválida! Insira um número de 1 a 4\n\n");
            reset();
            continue;
          }
          else if(k == 2){
            ciano();
            printf("\nParabéns você acertou a questão! :)\n\n");
            reset();
            j++;
            break;
          }
          else{
            laranja();
            printf("\nQue pena, você errou a questão ;(\n\n");
            reset();
            break;
          }
        }
        break;
    }
  }
    return 0;
}
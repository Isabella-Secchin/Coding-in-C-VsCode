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
  char array[10];
  int array2[10];
  for(i = 0; i <= 10; i++){
    array[i] = ' ';
    array2[i] = 0;
  }
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
            array[0] = 'x';
            array2[0] = (char) k;
            break;
          }
          else{
            laranja();
            printf("\nQue pena, você errou a questão ;(\n\n");
            array2[0] = (char) k;
            reset();
            break;
          }
        }
        break;
      case 1:
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
            array[1] = 'x';
            array2[1] = (char) k;
            break;
          }
          else{
            laranja();
            printf("\nQue pena, você errou a questão ;(\n\n");
            array2[1] = (char) k;
            reset();
            break;
          }
        }
        break;
      case 2:

    }
  }
  laranja();
  printf("RESULTADOS:\n\n");
  reset();
  branco();
  printf("         |               |                  |         \n");
  printf(" QUESTÂO | RESPOSTA DADA | RESPOSTA CORRETA | ACERTOS \n");
  printf("_________|_______________|__________________|_________\n");
  printf("         |               |                  |         \n");
  printf("    1    |       %d       |        4         |    %c   \n", array2[0], array[0]);
  printf("_________|_______________|__________________|_________\n");
  printf("         |               |                  |         \n");
  printf("    2    |       %d       |        2         |    %c   \n", array2[1], array[1]);
  printf("_________|_______________|__________________|_________\n");
  printf("         |               |                  |         \n");
  printf("    3    |       %d       |                  |    %c   \n", array2[2], array[2]);
  printf("_________|_______________|__________________|_________\n");
  printf("         |               |                  |         \n");
  printf("    4    |       %d       |                  |    %c   \n", array2[3], array[3]);
  printf("_________|_______________|__________________|_________\n");
  printf("         |               |                  |         \n");
  printf("    5    |       %d       |                  |    %c   \n", array2[4], array[4]);
  printf("_________|_______________|__________________|_________\n");
  printf("         |               |                  |         \n");
  printf("    6    |       %d       |                  |    %c   \n", array2[5], array[5]);
  printf("_________|_______________|__________________|_________\n");
  printf("         |               |                  |         \n");
  printf("    7    |       %d       |                  |    %c   \n", array2[6], array[6]);
  printf("_________|_______________|__________________|_________\n");
  printf("         |               |                  |         \n");
  printf("    8    |       %d       |                  |    %c   \n", array2[7], array[7]);
  printf("_________|_______________|__________________|_________\n");
  printf("         |               |                  |         \n");
  printf("    9    |       %d       |                  |    %c   \n", array2[8], array[8]);
  printf("_________|_______________|__________________|_________\n");
  printf("         |               |                  |         \n");
  printf("   10    |       %d       |                  |    %c   \n", array2[9], array[9]);
  printf("         |               |                  |         \n\n");
  reset();
  ciano();
  printf("Quantidade de acertos: %d/10\n\n", j);
  reset();
  return 0;
}
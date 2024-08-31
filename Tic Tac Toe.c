#include <stdlib.h>
#include <stdio.h>

int main(void){
    char array[9];
    int i, j;
    for(i=0; i<=8; i++){
        array[i] = ' ';
    }
    for(i=0; i<=8; i++){
        printf("Entre com a posição(1-9) e o simbolo(X ou O) que deseja jogar: \n");
        scanf("%d", &j);
        scanf(" %c", &array[j - 1]);
        printf("Como o jogo esta agora:\n");
        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c  \n", array[0], array[1], array[2]);
        printf("_____|_____|_____\n");
        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c  \n", array[3], array[4], array[5]);
        printf("_____|_____|_____\n");
        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c  \n", array[6], array[7], array[8]);
        printf("     |     |     \n");
        if(array[0] == array[1] && array[1] == array[2] && array[0] != ' '){
            printf("Jogador (%c) ganhou o jogo!\n", array[0]);
            break;
        }
        else if(array[3] == array[4] && array[4] == array[5] && array[3] != ' '){
            printf("Jogador (%c) ganhou o jogo!\n", array[3]);
            break;
        }
        else if(array[6] == array[7] && array[7] == array[8] && array[6] != ' '){
            printf("Jogador (%c) ganhou o jogo!\n", array[6]);
            break;
        }
        else if(array[0] == array[3] && array[3] == array[6] && array[0] != ' '){
            printf("Jogador (%c) ganhou o jogo!\n", array[0]);
            break;
        }
        else if(array[1] == array[4] && array[4] == array[7] && array[1] != ' '){
            printf("Jogador (%c) ganhou o jogo!\n", array[1]);
            break;
        }
        else if(array[2] == array[5] && array[5] == array[8] && array[2] != ' '){
            printf("Jogador (%c) ganhou o jogo!\n", array[2]);
            break;
        }
        else if(array[0] == array[4] && array[4] == array[8] && array[0] != ' '){
            printf("Jogador (%c) ganhou o jogo!\n", array[0]);
            break;
        }
        else if(array[2] == array[4] && array[4] == array[6] && array[2] != ' '){
            printf("Jogador (%c) ganhou o jogo!\n", array[2]);
            break;
        }
        else if(i == 8){
            printf("O jogo empatou!\n");
        }
    }
    return 0;
}

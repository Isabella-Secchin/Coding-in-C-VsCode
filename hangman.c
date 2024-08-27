#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){
    int i, j = 0, k, aux = 0, acertou;
    char ps[15], adv[20] = {0};
    printf("Entre com a palavra secreta: \n");
    fgets(ps, sizeof(ps), stdin);
    ps[strcspn(ps, "\n")] = '\0';
    char ps2[strlen(ps) + 1];
    for(i = 0; i < strlen(ps); i++){
        ps[i] = tolower(ps[i]);
        ps2[i] = '?';
    }
    ps2[i] = '\0';
    for(i = 10; i > 0; ){
        printf("\nEntre com a letra para adivinhar a palavra: \n");
        scanf(" %c", &adv[j]);
        adv[j] = tolower(adv[j]);
        acertou = 0;
        for(k = 0; k < strlen(ps); k++){
            if(adv[j] == ps[k]){
                ps2[k] = adv[j];
                aux += 1;
                acertou = 1;
            }
            else{
                continue;
            }
        }
        j++;
        if(!acertou){
            i--;
        }
        printf("Letras que ja foram adivinhadas: \n");
        for(k = 0; k < strlen(adv); k++){
            printf("%c ", adv[k]);
        }
        printf("\nComo a palavra esta agora:\n");
        for(k = 0; k < strlen(ps2); k++){
            printf("%c", ps2[k]);
        }
        if(aux == strlen(ps)){
            printf("\nParabens, voce encontrou a palavra!");
            break;
        }
    }
    if(aux != strlen(ps)){
        printf("\nQue pena, voce nao conseguiu acertar a palavra");
    }
    return 0;
}
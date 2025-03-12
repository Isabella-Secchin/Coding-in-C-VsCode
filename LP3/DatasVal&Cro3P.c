#include <stdlib.h>
#include <stdio.h>

int main(void){
    int quant, ***data, i;
    printf("Entre com a quantidade de datas deseja inserir:\n");
    scanf("%d", &quant);
    data = (int ***) malloc(quant * sizeof(int **));
    if (data == NULL){
        printf("Erro na alocacao de memoria!\n");
        return -1;
    }
    for (i = 0; i < quant; i++){
        data[i] = (int **) malloc(sizeof(int *));
        if (data[i] == NULL){
            printf("Erro na alocacao de memoria!\n");
            return -1;
        }
        data[i][0] = (int *) malloc(3 * sizeof(int));
        if (data[i][0] == NULL){
            printf("Erro na alocacao de memoria!\n");
            return -1;
        }
    }
    for (i = 0; i < quant; i++){
        printf("Entre com a data %d: (no formato dd/mm/aa)\n", i + 1);
        scanf("%d/%d/%d", &data[i][0][0], &data[i][0][1], &data[i][0][2]);
        if (data[i][0][1] < 1 || data[i][0][1] > 12){
            printf("Mes invalido!\n");
            i--;
            continue;
        }
        if (data[i][0][0] < 1 || data[i][0][0] > 31){
            printf("Dia invalido!\n");
            i--;
            continue;
        }
        if ((data[i][0][1] == 4 || data[i][0][1] == 6 || data[i][0][1] == 9 || data[i][0][1] == 11) && data[i][0][0] > 30){
            printf("Dia invalido!\n");
            i--;
            continue;
        }

        if (data[i][0][1] == 2){
            int bissexto = (data[i][0][2] % 4 == 0 && data[i][0][2] % 100 != 0) || (data[i][0][2] % 400 == 0);
            if (data[i][0][0] > 29 || (data[i][0][0] == 29 && !bissexto)){
                printf("Dia invalido!\n");
                i--;
                continue;
            }
        }
    }
    for (i = 0; i < quant; i++){
        free(data[i][0]);  
        free(data[i]); 
    }
    free(data);
    return 0;
}

#include <stdlib.h>
#include <stdio.h>

void troca(int*, int*);
int comparar(const void*, const void*);
int particionar(int**, int, int);
void quickSort(int**, int, int);

int main(void){
    int quant, i;
    int **data;
    printf("Entre com a quantidade de datas que deseja inserir:\n");
    scanf("%d", &quant);
    data = (int**) malloc(quant * sizeof(int*));
    if (data == NULL){
        printf("Erro na alocacao de memoria!\n");
        return -1;
    }
    for (i = 0; i < quant; i++){
        data[i] = (int*) malloc(3 * sizeof(int));
        if (data[i] == NULL){
            printf("Erro na alocacao de memoria!\n");
            return -1;
        }
    }
    for (i = 0; i < quant; i++){
        printf("Entre com a data %d: (no formato dd/mm/aa)\n", i + 1);
        scanf("%d/%d/%d", &data[i][0], &data[i][1], &data[i][2]);
        if (data[i][1] < 1 || data[i][1] > 12){
            printf("Mes invalido!\n");
            i--;
            continue;
        }
        if (data[i][0] < 1 || data[i][0] > 31){
            printf("Dia invalido!\n");
            i--;
            continue;
        }
        if ((data[i][1] == 4 || data[i][1] == 6 || data[i][1] == 9 || data[i][1] == 11) && data[i][0] > 30){
            printf("Dia invalido!\n");
            i--;
            continue;
        }
        if (data[i][1] == 2){
            int bissexto = (data[i][2] % 4 == 0 && data[i][2] % 100 != 0) || (data[i][2] % 400 == 0);
            if (data[i][0] > 29 || (data[i][0] == 29 && !bissexto)){
                printf("Dia invalido!\n");
                i--;
                continue;
            }
        }
    }
    quickSort(data, 0, quant - 1);
    printf("Datas ordenadas:\n");
    for (i = 0; i < quant; i++){
        printf("%02d/%02d/%04d\n", data[i][0], data[i][1], data[i][2]);
    }
    for (i = 0; i < quant; i++){
        free(data[i]);
    }
    free(data);
    return 0;
}

void troca(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int comparar(const void* a, const void* b){
    int* data1 = *(int**)a;
    int* data2 = *(int**)b;
    if (data1[2] != data2[2]){
        return data1[2] - data2[2];  
    } 
    if (data1[1] != data2[1]) {
        return data1[1] - data2[1];  
    }
    return data1[0] - data2[0];  
}

int particionar(int** data, int baixo, int alto){
    int* pivote = data[alto];  
    int i = baixo - 1; 
    for (int j = baixo; j < alto; j++) {
        if (comparar(&data[j], &pivote) < 0){
            i++;
            troca(&data[i][0], &data[j][0]);  
            troca(&data[i][1], &data[j][1]);  
            troca(&data[i][2], &data[j][2]);  
        }
    }
    troca(&data[i + 1][0], &data[alto][0]);  
    troca(&data[i + 1][1], &data[alto][1]);  
    troca(&data[i + 1][2], &data[alto][2]);  
    return i + 1;  
}

void quickSort(int** data, int baixo, int alto){
    if (baixo < alto) {
        int pivôIndex = particionar(data, baixo, alto);
        quickSort(data, baixo, pivôIndex - 1);
        quickSort(data, pivôIndex + 1, alto);
    }
}
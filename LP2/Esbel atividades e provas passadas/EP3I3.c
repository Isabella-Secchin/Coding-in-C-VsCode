#include <stdio.h>
#include <stdlib.h>

int main(void){
    char fileName[] = "Binario", fileName2[] = "Txt";
    int valor;
    FILE *fp = fopen(fileName, "rb");
    if(!fp){
        perror("Erro ao abrir o arquivo binario!");
        return 0;
    }
    FILE *fp2 = fopen(fileName2, "w");
    if(!fp2){
        perror("Erro ao abrir o arquivo txt!");
        fclose(fp);
        return 0;
    }
    while(fread(&valor, sizeof(int), 1, fp) == 1){
        fprintf(fp2, "%d\n", valor);
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}
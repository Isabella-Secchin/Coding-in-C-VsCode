#include <stdio.h>
#include <stdlib.h>

int main(void){
    char fn[] = "arquivo.bin", fn2[] = "arquivo.txt";
    FILE *fp = fopen(fn, "rb");
    if(!fp){
        perror("Erro ao abrir arquivo binario!");
        return 1;
    }
    FILE *fp2 = fopen(fn2, "w");
    if(!fp2){
        perror("Erro ao abrir arquivo de texto!");
        fclose(fp);
        return 1;
    }
    int valor;
    while(fread(&valor, sizeof(int), 1, fp) == 1){
        fprintf(fp2, "%d\n", valor);
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}
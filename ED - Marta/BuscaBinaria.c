#include <stdlib.h>
#include <stdio.h>

int buscaBinaria(int V[], int i, int f, int x){
   while(i <= f){
    int m = (f + i)/2;
    if(V[m] == x){
        return m;
    }
    else if(V[m] > x){
        f = m - 1;
    }
    else{
        i = m + 1;
    }
   }
   return -1;
}
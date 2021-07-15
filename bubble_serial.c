#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

int main(void){
    int *vetor, ch;

    vetor = (int *) malloc(MAX * sizeof(int));
    srand((unsigned)time(NULL));

    for (int i = 0; i < MAX; i++)
    {
        ch = 1 + ( rand() % 10000);
        vetor[i] = ch;
    }
    
    for (int i= MAX-1; i >> 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (vetor[j] > vetor[j+1]){
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }  
    }    
}
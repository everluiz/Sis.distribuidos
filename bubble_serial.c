#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

void bubble(int vet[], int inicio, int fim){
    for (int i = fim-1; i > inicio; i--)
    {
        for (int j = inicio; j < i; j++)
        {
            if(vet[j] > vet[j+1]){
                int aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
        
    }
    
}

int main(void){
    int *vetor, ch;

    vetor = (int *) malloc(MAX * sizeof(int));
    srand((unsigned)time(NULL));

    // Cria vetor randomizado de 1 a 100000.
    for (int i = 0; i < MAX; i++)
    {
        ch = 1 + ( rand() % 10000);
        vetor[i] = ch;
    }
    
    bubble(vetor, 0, MAX);
    return 0;    
}
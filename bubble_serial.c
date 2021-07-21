#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define MAX 100000

void bubble(int vet[]){
    double start = omp_get_wtime();
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX-1; j++)
        {
            if(vet[j] > vet[j+1]){
                int aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }        
    }
    double end = omp_get_wtime();
    printf("tempo serial: %f\n",end-start);
}

void imprime(int vet[]){
    for (int i = 0; i < MAX; i++)
    {
        if (i<30)
        {
            printf("%d ", vet[i]);
        }else if (i == 31)
        {
            printf("-- ");
        }else if (i > (MAX-30)){
            printf("%d ", vet[i]);
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
        ch = 1 + ( rand() % MAX);
        vetor[i] = ch;
    }

    imprime(vetor);
    printf("\n\n");
    // chama a funcao bubblesort
    bubble(vetor);

    imprime(vetor);
    free(vetor);
    return 0;    
}
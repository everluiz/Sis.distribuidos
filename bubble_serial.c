#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <stdbool.h>

#define MAX 100000

void swap(int *valor1, int *valor2){
    int aux = *valor1;
    *valor1 = *valor2;
    *valor2 = aux;
}

void bubble(int vet[], int inicio, int fim){
    double start = omp_get_wtime();
    for (int i = inicio; i < fim; i++)
    {
        bool stop = true;
        for (int j = inicio; j < fim-1; j++)
        {
            if(vet[j] > vet[j+1]){
                swap(&vet[j], &vet[j+1]);
                stop = false;
            }
        }
        if (stop)
        {
            break;
        }
        
    }
    double end = omp_get_wtime();
    printf("tempo serial: %f\n",end-start);
}


void bubble_par(int vet[], int inicio, int fim){
    int first;
    double start = omp_get_wtime();
    for (int i = 0; i < MAX; i++)
    {
        first = i % 2; 
        // 0 para 0,2,4...
        // 1 para 1,3,5...
        #pragma omp parallel for shared(vet, first),num_threads(8) 
        for (int j = first; j < MAX-1; j+=2)
        {
            if(vet[j] > vet[j+1]){
                swap(&vet[j], &vet[j+1]);
            }
        }
        
    }
    double end = omp_get_wtime();
    printf("tempo paralelo: %f\n",end-start);
}


int main(void){
    int *vetor, *vetor2, ch;

    vetor = (int *) malloc(MAX * sizeof(int));
    vetor2 = (int *) malloc(MAX * sizeof(int));
    srand((unsigned)time(NULL));

    // Cria vetor randomizado de 1 a 100000.
    for (int i = 0; i < MAX; i++)
    {
        ch = 1 + ( rand() % MAX);
        vetor[i] = ch;
        vetor2[i] = ch;
    }
    // chama a funcao bubblesort serial
    //bubble(vetor, 0, MAX);
    /*
    for (int i = 0; i < 100; i++)
    {
        printf("%d ",vetor[i]);
    }
    */
    printf("\n\n");
    // chama a funcao bubblesort paralela
    bubble_par(vetor2, 0, MAX);

    
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", vetor2[i]);
    }
    
    return 0;    
}
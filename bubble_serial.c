#include <stdio.h>

int n=5;
int a[] = {4,3,5,1,2};

int main(void){
    for (int i= n-1; i >> 0; i--)
    {
        /* code */
        for (int j = 0; j < i; j++)
        {
            /* code */
            if (a[j] > a[j+1]){
                int aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
            }
        }  
    }
    printf("%d\n\r",a[0]);
    printf("%d\n\r",a[1]); 
    printf("%d\n\r",a[2]);
    printf("%d\n\r",a[3]);
    printf("%d\n\r",a[4]);
}
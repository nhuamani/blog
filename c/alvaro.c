#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a,*suma, n=2;
    
    a=(int *)malloc(n*sizeof(int));
    suma=(int *)malloc(sizeof(int));

    for(int i = 0; i < n; i ++ ){
        printf("Ingrese el %d valor:",i+1);
        scanf("%d", &a[i]);
        *suma=*suma+a[i];
    }
    printf("La suma es: %d ", *suma);
}

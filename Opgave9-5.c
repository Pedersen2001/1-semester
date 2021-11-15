#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int int_compare(const void *ip1, const void *ip2){
    int result;

    int *ipi1 = (int *)ip1,
    *ipi2 = (int *)ip2;
    
    if (*ipi1 < *ipi2)
        result = -1;
    else if (*ipi1 > *ipi2)
        result = 1;
    else
        result = 0;
    return result;
}

int main(){

    srand(time(0));

    double* ptr;
    double n = 100;
    int i;
 
    ptr = (double*)malloc(n * sizeof(double));
 
    if (ptr == NULL) {
        printf("Pladser ikke fundet\n");
        exit(0);
    }
    else {

        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }

        printf("Dine 100 usorterede tal er: \n");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i] = rand() % 500+1);
        }
    }

    qsort(ptr, 100, sizeof(double), int_compare);

    for (i = 0; i < n; ++i) {
        printf("%d ", ptr[i]);
    }
    
 
    return 0;
}
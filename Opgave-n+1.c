#include <stdio.h>
#include <math.h>

int main (void){

    int n, i, sum = 0, tjek;

    printf("Skriv dit antal af hele numre: \n");
    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        sum += i;
    }

    printf("Sum = %d \n", sum);

    tjek = (n * (n + 1)) / 2;
    printf("Sum ved det opgivne udtryk ((n*(n+1)/2)) er = %d \n", tjek);

    return 0;
    
}
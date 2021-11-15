#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

    int n, i, sum = 0;

    printf("Skriv dit antal af hele numre: \n");
    scanf("%d", &n);

    printf("Sum = %d \n", summen(n));

    return 0;
}

int summen(n) {

      for (i = 1; i <= n; ++i); 
        sum += i;

   return EXIT_SUCCESS;

}

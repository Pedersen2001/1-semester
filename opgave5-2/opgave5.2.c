#include <stdio.h>
#include <stdlib.h>
#include "primes.h"

int main(){
//første 100 primes
int count = 0, primeCount = 0;

while(primeCount < 100){
    if(is_prime(count)){
        primeCount++;
        printf("prime %d: %d \n", primeCount, count);
    } 
    count++;
}

}
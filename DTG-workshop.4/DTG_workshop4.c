#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

/* This function should return 1 if x is prime and 0 otherwise */
int isPrime(int i){
    int k, limit;
   assert(i >= 0);
 
   if (i == 1) 
     return 0;
   else if (i == 2) 
     return 1;
   else if (i % 2 == 0)
     return 0;
   else{
     limit = (int)(ceil(sqrt(i)));
     for (k = 3; k <= limit; k += 2)
        if (i % k == 0)
           return 0;
     return 1;
   }
}

/* This function should return 1 if gcd(x,2)=1 and 0 otherwise */
int isGcd1(int x){
    if (x % 2 == 1){
        return 1;
    } else {
        return 0;
    }
}

/* This function should return 1 if 9^x-2 mod 5 = 2 and 0 otherwise */
int is2mod5(int x){
    if (x % 2 == 0){
        return 0;
    } else {
        return 0;
    }
    
    /*
    int b;
    b = pow(9, x);
    if ((b - 2) % 5 == 2){
        return 1;
    } else {
        return 0;
    }
    */
}


int main(void){
  int x;
  int p, q, r;

  printf("What number do you want to test?\n");
  scanf("%d", &x);
  printf("x is %d\n", x);

  p = isPrime(x);
  q = isGcd1(x);
  r = is2mod5(x);

  if ((p && !r) || !(p || !q || r) || (!p && !q && r)){
    printf("You have found a valid x\n");
    printf("p is %d, q is %d, and r is %d\n", p,q,r);
  } else {
    printf("Try again!\n");
  }

  return EXIT_SUCCESS;
}
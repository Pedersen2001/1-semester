/* Opgave a i opgave 2.1 

#include <stdio.h>

int main(void) {

  int sum1 =    10  +   11  +  12,
      sum2  =  010 +   011 +  012,
      sum3  = 0x10 +  0x11 + 0x12;

*/

/* Der er tre forskellige måder at skrive tal på - 3 af disse er vist i summen af de 3. Sum nr.1 er f.eks. binære tal */
/*
  printf("sum1 =  %d\n", sum1);
  printf("sum2 =  %d\n", sum2);
  printf("sum3 =  %d\n", sum3);

  return 0;

}
*/

/* Opgave b i opgave 2.1 */
/*
#include <stdio.h>

int main(void) {

  int x, y, z, sum;

  printf("Enter three integers: ");
  scanf("%d %d %d", &x, &y, &z);

  sum =    x + y + z;

  printf("sum =  %d\n", sum);

  return 0;
}
*/


/* Opgave c i opgave 2.1 */
#include <stdio.h>

int main(void) {

  int x, y, z, sum;

  printf("Enter three integers: ");
  scanf("%o %o %o", &x, &y, &z);

  sum =    x + y + z;

  printf("sum =  %d\n", sum);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DELTA 0.000001

int main(void){
  double r = 0.0, x = 0.0, y = 0.0;
  int inside = 0, on_circle = 0, outside = 0;

  /* Prompt for input: */
  printf("Enter radius, x, and y:\n");
  scanf(" %lf %lf %lf", &r, &x, &y);

  /* Calculate inside, on circle, or outside */
  on_circle = fabs(x*x + y*y - r*r) < DELTA;
  inside = x*x + y*y < r*r;
  outside = !(inside || on_circle);

  /* Print results: */
  printf("The point (%1.4f,%1.4f) is %s with center point (0,0).\n",
         x, y, 
         on_circle ? "on circle" : inside ? "inside circle" : "outside circle");
  
  return EXIT_SUCCESS;
}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double circumference(double,  double,  double, double ,  double, double);
double side_length(double x1, double y1,  double x2, double y2);
double square(double x);


int main(void) {
  double p1_x, p1_y;
  double p2_x, p2_y;
  double p3_x, p3_y;

  prompt_for_point(&p1_x, &p1_y);
  prompt_for_point(&p2_x, &p2_y);
  prompt_for_point(&p3_x, &p3_y);

  printf("The circumference is: %f\n", circumference(p1_x, p1_y, p2_x, p2_y, p3_x, p3_y));

  return EXIT_SUCCESS;
}

void prompt_for_point(double* x, double *y) {
  printf("Please, enter a point: ");
  scanf(" %lf %lf", x, y);
}

double circumference(double x1, double y1,  double x2, double y2,  double x3, double y3){
  double side_length_1_2 = side_length(x1, y1, x2, y2);
  double side_length_2_3 = side_length(x2, y2, x3, y3);
  double side_length_3_1 = side_length(x3, y3, x1, y1);

  return side_length_1_2 + side_length_2_3 + side_length_3_1;
}

double side_length(double x1, double y1,  double x2, double y2){
  return sqrt(square(x1-x2) + square(y1-y2));
}

double square(double x){
  return x*x;
}
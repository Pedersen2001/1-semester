#include <stdio.h>
#include <math.h>


double diskriminant_value(double a, double b, double c);
double roden(double a, double b);
double rod1_value(double a, double b, double c);
double rod2_value(double a, double b, double c);
void solveQuadraticEquation(double a, double b, double c);


int main(void){
  double a, b, c, r1, r2;
  printf("Indtast dine koefficienter, som er a, b og c: \n");
  scanf("%lf %lf %lf", &a, &b, &c);
  solveQuadraticEquation(a, b, c);
  return 0;

}

/* Dette udgører en funktion, som udregner diskriminanten ud fra et givent input*/
double diskriminant_value(double a, double b, double c){
    double d;
    d = b * b - 4 * a * c;
    return d;
}

/* Dette udgør en funktion, som udregner roden, hvis der kun er én rod.
   Regner ud fra et givent input*/
double roden(double a, double b){
  double roden = -b / (2*a);
  return roden;
}

/* Dette udgør en funktion, som udregner den første rod, hvis der er 2.
   Regner ud fra et givent input*/
double rod1_value(double a, double b, double c){
  double rod1 = (-b + sqrt(diskriminant_value(a, b, c))) / (2 * a);
  return rod1;
}

/* Dette udgør en funktion, som udregner den anden rod, hvis der er 2.
   Regner ud fra et givent input*/
double rod2_value(double a, double b, double c){
  double rod2 = (-b - sqrt(diskriminant_value(a, b, c))) / (2 * a);
  return rod2;
}

/* Dette udgør en funktion, som samler de forskellige funktioner i én funktion
   og kalder dem på samme tid i en if-else kæde */
void solveQuadraticEquation(double a, double b, double c){
  if (diskriminant_value(a, b, c) < 0) 
    printf("Der er ingen roedder!");
  else if (diskriminant_value(a, b, c) == 0){
  roden(a, b);
  printf("Der er en rod: %f \n", roden(a, b));
  }
  else {
    rod1_value(a, b, c);
    rod2_value(a, b, c);
    printf("Der er 2 roedder: %f og %f \n", rod1_value(a, b, c), rod2_value(a, b, c));
  }
}

#include <stdio.h>
#include <math.h>

#define EURO 0.89
#define KRONER 6.66
#define RUBLER 66.43
#define YEN 119.9

double valuta(double dollar);
double valuta_tabel(double dollar);

double main(void) {
    /* Dette er til 1. del af opgaven

    double a;
    printf("Indtast, hvor mange dollars du har: \n");
    scanf("%lf", &a);
    valuta(a);
    */
   
   /* Dette er til tabellen i opgaven */
    int i;

    for ( i = 0; i <= 100; i++)
    {
        valuta_tabel(i);
    }
    
    return 0;
}
/* Dette er til 1. løsning af opgaven

double valuta(double a) {
    double euro = a * EURO;
    double kroner = a * KRONER;
    double rubler = a * RUBLER;
    double yen = a * YEN;

    printf("Dit antal dollars (%lf) svarer derfor til: \n %lf euro \n %lf kroner \n %lf rubler \n %lf yen \n", a, euro, kroner, rubler, yen);

    return 0;
}
*/ 

/* Dette er til tabellen i opgaven */

double valuta_tabel(double a) {
    double euro = a * EURO;
    double kroner = a * KRONER;
    double rubler = a * RUBLER;
    double yen = a * YEN;

    printf("%4.0lf dollars svarer derfor til: %7.2lf euro | %6.2lf kroner | %7.2lf rubler | %7.2lf yen\n", a, euro, kroner, rubler, yen);

    return 0;
}

/* printf("%lf dollars svarer derfor til: \n %lf euro \n %lf kroner \n %lf rubler \n %lf yen \n", a, euro, kroner, rubler, yen); */
/*  Navn:       Lucas Lybek Højlund Pedersen
    email:      llhp21@student.aau.dk
    Gruppe:     B217
    Retning:    SW 
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Der laves prototyper af de forskellige funktioner i programmet */
double do_next_op1(char , double , double);
double do_next_op2(char , double , double);
int binaer(char );
int unaer(char );
void scan_data(int*, double*);
void run_calculator(void);

/* Den primære funktion, som udfører programmet, kaldes i main */
int main(void) {
    printf("Dine mulige binaere operatorer er: + (plus), - (minus), * (gange), / (divider), ^ (potensoploeftning) \n");
    printf("De mulige unaere operatorer er: # (kvadratrod), %% (Skifter fortegn), ! (Dividerer akkumulatoren med 1) \n");
    printf("For at afslutte, indtast q \n\n");
    run_calculator();

    return EXIT_SUCCESS;
}

/* Denne switch finder den givne operation, udregner resultat, og fortsætter hvis nødvendigt. Dette er gældende for de binære tal */
double do_next_op1(char operator, double operand, double akkumulator) {
    double udregning1 = akkumulator;
    switch (operator)
    {
    case '-':
        udregning1 = udregning1 - operand;
    break;

    case '+':
        udregning1 = udregning1 + operand;
    break;
    
    case '*':
        udregning1 = udregning1 * operand;
    break;

    case '/':
    if (udregning1 >= 0) 
    {
        udregning1 = udregning1 / operand;
    }
    break;

    case '^':
        udregning1 = pow(udregning1, operand);
    break;

    default:;
    }
    return udregning1;
}

/* Denne switch finder den givne operation, udregner resultat, og fortsætter hvis nødvendigt. Dette er gældende for de unære tal */
double do_next_op2(char operator, double operand, double akkumulator) {
    double udregning2 = akkumulator;
    switch (operator)
    {
    case '#':
        udregning2 = sqrt(udregning2);
    break;

    case '%':
        udregning2 = udregning2 * -1;
    break;

    case '!':
        udregning2 = 1 / udregning2;
    break;

    default:;
    }
    return udregning2;
}

/* En funktion, som finder ud af, om input er en binær operator - en form for input validering, da man finder ud af, om input kan bruges i den switch med binære operatorer */
int binaer(char operator) {
    if (operator == '^' || operator == '/' || 
        operator == '*' || operator == '+' ||
        operator == '-')
    {
        return 1;
    } else {
        return 0;
    }
    
}

/* En funktion, som finder ud af, om input er en unær operator en form for input validering, da man finder ud af, om input kan bruges i den switch med unære operatorer */
int unaer(char operator) {
    if (operator == '#' || operator == '%' || operator == '!')
    {
        return 1;
    } else {
         return 0;
     }
}

/* Tager input fra bruger, og finder ud af, om man skal lave udregning med unær eller binær operator */
void scan_data(int *done, double *akkumulator) {
    double operand = 0.0;
    char operator;

    printf("Indskriv operator, og en valgfri operand: ");
    scanf(" %c", &operator);

    if (binaer(operator)) {
        scanf(" %lf", &operand);
        *akkumulator = do_next_op1(operator, operand, *akkumulator);

    } else if (unaer(operator)) {
        *akkumulator = do_next_op2(operator, 0.0, *akkumulator);

    } else if (operator == 'q') {
        *done = 1;
        return;
    }
    
    printf("Dit resultat indtil videre er %lf \n\n", *akkumulator);
}

/*Funktionen, som får hele lommeregneren til at køre */
void run_calculator(void) {
    int done = 0;
    double akkumulator = 0.0;

    while (done != 1) {
        scan_data(&done, &akkumulator);
    }
    printf("Dit slutresultat er: %lf", akkumulator);
}
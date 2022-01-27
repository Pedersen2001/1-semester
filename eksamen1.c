/*  Navn:       Lucas Lybek Højlund Pedersen
    email:      llhp21@student.aau.dk
    Gruppe:     B217
    Retning:    SW 
*/

/*Preprocessor directive */
/*Inkluderinger i form af Library header inclusions */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*Prototypes for each function - funktioner, som er erklærede*/
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
    run_calculator(); /*Dette funktionskald er en kommando*/

    return EXIT_SUCCESS;
}

/* Denne switch finder den givne operation, udregner resultat, og fortsætter hvis nødvendigt. Dette er gældende for de binære tal */
double do_next_op1(char operator, double operand, double akkumulator) {
    double udregning1 = akkumulator; /*Lokal variabel, som bliver initialiseret - tilskrevet en startværdi - er også ekspressionstatement*/
    /*En switch tager talværdien af ens input i form af operatoren. Dette er talværdien, som man får fra ASCII-tabellen. Switchen læser derfor tal, og ikke f.eks. +*/
    switch (operator) /*Selektiv konstrolstruktur i form af en multivejsudvælgelse på basis af en heltallig variabel, hvor der udvælges netop én af de cases som en switch består af*/
    {
    case '-':
        udregning1 = udregning1 - operand;
    break; /*Er en hopkommando - de statements der er i en case vil fortsætte, indtil der mødes en break. */

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

    default:; /*Hvis ingen af de ovennævnte cases rammes, så vil en default udføre en opgave - default udfører dog ikke noget i dette tilfælde*/
    }
    return udregning1;
}

/* Denne switch finder den givne operation, udregner resultat, og fortsætter hvis nødvendigt. Dette er gældende for de unære tal */
double do_next_op2(char operator, double operand, double akkumulator) {
    double udregning2 = akkumulator; /*Lokal variabel, som bliver initialiseret - tilskrevet en startværdi*/
    /*En switch tager talværdien af ens input i form af operatoren. Dette er talværdien, som man får fra ASCII-tabellen. Switchen læser derfor tal, og ikke f.eks. #*/
    switch (operator) /*Selektiv konstrolstruktur i form af en multivejsudvælgelse på basis af en heltallig variabel, hvor der udvælges netop én af de cases som en switch består af*/
    {
    case '#':
        udregning2 = sqrt(udregning2);
    break; /*Er en hopkommando - de statements der er i en case vil fortsætte, indtil der mødes en break. */

    case '%':
        udregning2 = udregning2 * -1;
    break;

    case '!':
        udregning2 = 1 / udregning2;
    break;

    default:; /*Hvis ingen af de ovennævnte cases rammes, så vil en default udføre en opgave - default udfører dog ikke noget i dette tilfælde*/
    }
    return udregning2;
}

/* 
En funktion, som finder ud af, om input er en binær (tager to operander f.eks. x+y) operator
En form for input validering, da man finder ud af, om input kan bruges i den switch med binære operatorer
*/
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

/* 
En funktion, som finder ud af, om input er en unær (tager én operand f.eks. #sqrt) operator
En form for input validering, da man finder ud af, om input kan bruges i den switch med unære operatorer 
*/
int unaer(char operator) {
    if (operator == '#' || operator == '%' || operator == '!')
    {
        return 1;
    } else {
         return 0;
     }
}

/* Tager input fra bruger, og finder ud af, om man skal lave udregning med unær eller binær operator */
void scan_data(int *done, double *akkumulator) { /*Vi sender en pointer med, og når værdien i funktionen ændrer sig, så ændres den også, når funktionen kaldes*/
    double operand = 0.0;
    char operator;

    /*printf (output) er styret af en formateringsstreng, som gør brug af placeholders %, som modsvarer parameterne, som hedder en prinlist*/
    printf("Indskriv operator, og en valgfri operand: "); 

    /*scanf (input) bliver styret af en kontrolstreng, som gør brug af placeholders %, som angiver hvordan vi skal konvetere det input vi læser*/
    scanf(" %c", &operator); /*Placeholder & bliver brugt, for at ændre værdien af "operator"*/

    if (binaer(operator)) {
        /*scanf (input) bliver styret af en kontrolstreng, som gør brug af placeholders %, som angiver hvordan vi skal konvetere det input vi læser*/
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
        scan_data(&done, &akkumulator); /*Call by reference, da man sender adressen af variablerne med, som faktiske parametre, som kan ændres. */
    }
    printf("Dit slutresultat er: %lf", akkumulator); 
    /*printf (output) er styret af en formateringsstreng, som gør brug af placeholders %, som modsvarer parameterne, som hedder en prinlist*/
}
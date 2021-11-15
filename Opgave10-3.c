#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_ord 20

void flertal(char ord[]);

int main(void){
    char substantiv[max_ord];

    for (;;) {
        printf("Enter a noun in singular form: ");
        scanf("%s", substantiv);
        
    if ((strcmp(substantiv, "done")) == 0)
        break;

    flertal (substantiv);
    printf("The plural form of your word is: %s\n", substantiv);
    }

    return EXIT_SUCCESS;
}


void flertal(char ord[]) {
    int laengde;
    char substantiv;
    laengde = 1;
    laengde = strlen(ord);

    if (ord[laengde - 1] == 'y') {
        ord[laengde - 1] = 'i';
        ord[laengde    ] = 'e';
        ord[laengde + 1] = 's';
        ord[laengde + 2] = '\0';
        
    } else if (ord[laengde - 1] == 's' ||
              (ord[laengde - 2] == 'c' && ord[laengde - 1] == 'h') ||
              (ord[laengde - 2] == 's' && ord[laengde - 1] == 'h')) {
        strcat(ord, "es");

    } else {
        strcat(ord, "s");
        printf("New word is: ", &substantiv);
    }
}
/*  Navn:       Lucas Lybek Højlund Pedersen
    email:      llhp21@student.aau.dk
    Gruppe:     B217
    Retning:    SW - Software

    Inspiration til if-else kæde er fået fra Kristian Sørensen - Havde gang i en switch, som ikke fungerede, og han forklarede if-else kæde, og hvordan man kunne lave den
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Prototyper */
int terninge_slag(int, int*);
int terningen(int, int*, int);
int *start_kast(int);
int ens_terninger(int, int*, int, int);
int par_terninger(int, int*);
int straight(int, int*, int);
int fuldt_hus(int, int*);
int chancen(int []);
void scoreboard(int []);
void yatzy_spillet(int, int []);
void spil_yatzy(void);



int main (void) {
    srand(time(NULL));
    spil_yatzy();
    return EXIT_SUCCESS;
}

/* En funktion, som starter Yatzy-spillet, og tager brugerens input om terninger */
void spil_yatzy(){
    int terninger = 0;
    int resultat[17];

    printf("Indtast, hvor mange terninger du vil bruge (Minimum 5 terninger): ");
    scanf("%d", &terninger);

    if (terninger < 5){
        printf("Du har valgt mindre end 5 terninger, og kan ikke spille - Der skal bruges minimum 5");

    } else {
        yatzy_spillet(terninger, resultat);
        scoreboard(resultat);
    }
}


/* Genererer et tilfældigt kast med terninger */
int terninge_slag(int terninger, int *resultat_terning){
    int i;
    for (i = 0; i < terninger; i++){
        resultat_terning[i] = (rand() % 6) + 1;
    }
    return EXIT_SUCCESS;
}


/* Allokerer lager til det tilfældige slag med terninger */
int *start_kast(int terninger){
    int *resultat_terning;

    resultat_terning = (int*)malloc(terninger * sizeof(int));

    if (resultat_terning == NULL){
        printf("Det er ikke muligt at allokere nok lager");
        exit(EXIT_FAILURE);
    }
    return resultat_terning;
}


/* En funktion, som er med til at finde specifikke terninger i et tilfældigt kast, såsom 1, 2, 3... */
int terningen(int terninger, int *resultat_terning, int spillet){
    int i = 0, sum = 0, optal = 0;

    while (i < terninger){
        if(resultat_terning[i] == spillet){
            if (optal < 5){
                optal++;
                sum = sum + resultat_terning[i];
            }
        }
        i++;
    }
    return sum;
}


/* Undersøger, om der er nogle ens terninger */
int ens_terninger(int terninger, int *resultat_terning, int spillet, int udgangspunkt){
    int i, j;
    int optal = 0;

    for (j = udgangspunkt; j > 0; j--){
        for (i = 0; i < terninger; i++){
            if (resultat_terning[i] == j){
                optal++;
            }
            if (optal == spillet){
                return j * spillet;
            }
        }
        optal = 0;
    }
    return 0;
}


/* Finder ud af, om der er par i et tilfældigt kast, 
   ved at finde det største par, og derefter det næste højeste osv. */
int par_terninger(int terninger, int *resultat_terning){
    int udgangspunkt = 6;
    int par1 = 0, par2 = 0;

    par1 = ens_terninger(terninger, resultat_terning, 2, udgangspunkt);
    udgangspunkt = (par1 / 2) - 1;
    par2 = ens_terninger(terninger, resultat_terning, 2, udgangspunkt);

    if (par1 > 0 && par2 > 0){
        return par1 + par2;

    } else {
        return 0;
    }
}


/* Undersøger, om der er en straight i det tilfældige terninge kast */
int straight(int terninger, int *resultat_terning, int spillet){
    int i;
    int optal = 0, sum = 0, hop = 0;

    while (hop < terninger){
        for (i = 0; i < terninger; i++){
            if (resultat_terning[i] == spillet){
                sum = sum + resultat_terning[i];
                optal++;
                spillet--;
            }
            if (optal == 5){
                return sum;
            }
        }
        hop++;
    }
    return 0;
}


/* Undersøger, om der er fuldt hus i det tilfældige terninge kast */
int fuldt_hus(int terninger, int *resultat_terning){
    int udgangspunkt = 6, tre_ens = 0, par = 0;

    tre_ens = ens_terninger(terninger, resultat_terning, 3, udgangspunkt);
    par = ens_terninger(terninger, resultat_terning, 2, udgangspunkt);

    if (tre_ens > 0){
        while ((par / 2) == (tre_ens / 3)){
            par = ens_terninger(terninger, resultat_terning, 2, --udgangspunkt);
        }
        
    } if (tre_ens > 0 && par > 0){
        return tre_ens + par;

    } else {
        return 0;
    }
}


/* Undersøger, om chancen er i det tilfældige terninge kast, og tager summen af alle terninger */
int chancen(int antal_terninger[]){
    int i;
    int sum = 0, chance[6];

    for (i = 0; i < 6; i++){
        chance[i] = antal_terninger[i];
    }
        sum += chance[6] * 6;
        for ( i = 4; i > -1; i--){
            while (chance[i] && sum < 30){
                sum += i + 1;
                chance[i]--;
            }
        }
        return sum;
    }


/* En lang if-else kæde, som foretager selve Yatzy spillet */
void yatzy_spillet(int terninger, int resultat[]){
    int i, j;
    int sum = 0, udgangspunkt = 6;
    int *tilfaeldigt_kast;
    
    tilfaeldigt_kast = start_kast(terninger);

    for (i = 0; i < 18; i++){
        if (i < 6){
            /* Tager igen summen af de point man får ved slagene 1, 2, 3..., og undersøger om evt. bonus */
            terninge_slag(terninger, tilfaeldigt_kast);
            resultat[i] = terningen(terninger, tilfaeldigt_kast, (i+1));
            sum = sum + resultat[i];

        } else if (i == 6){
            /* Tillægger summen igen */
            resultat[i] = sum;

        } else if (i == 7){
            /* Tjekker om bonus */
            resultat[i] = (sum >= 63) ? 50 : 0;
            sum = 0;

        } else if (i == 8){
            /* Undersøger, om der er to ens */
            terninge_slag(terninger, tilfaeldigt_kast);
            resultat[i] = ens_terninger(terninger, tilfaeldigt_kast, 2, udgangspunkt);

        } else if (i == 9){
            /* Undersøger, om der er nogle par */
            terninge_slag(terninger, tilfaeldigt_kast);
            resultat[i] = par_terninger(terninger, tilfaeldigt_kast);

        } else if (i == 10){
            /* Undersøger, om der er 3 ens */
            terninge_slag(terninger, tilfaeldigt_kast);
            resultat[i] = ens_terninger(terninger, tilfaeldigt_kast, 3, udgangspunkt);

        } else if (i == 11){
            /* Undersøger, om der er 4 ens */
            terninge_slag(terninger, tilfaeldigt_kast);
            resultat[i] = ens_terninger(terninger, tilfaeldigt_kast, 4, udgangspunkt);

        } else if (i == 12){
            /* Undersøger, om der er en straight fra 1-5 */
            terninge_slag(terninger, tilfaeldigt_kast);
            resultat[i] = straight(terninger, tilfaeldigt_kast, 5);

        } else if (i == 13){
            /* Undersøger, om der er en straight fra 2-6 */
            terninge_slag(terninger, tilfaeldigt_kast);
            resultat[i] = straight(terninger, tilfaeldigt_kast, 6);

        } else if (i == 14){
            /* Undersøger, om der er fuldt hus */
            terninge_slag(terninger, tilfaeldigt_kast);
            resultat[i] = fuldt_hus(terninger, tilfaeldigt_kast);

        } else if (i == 15){
            /* Undersøger, om chancen er tilstede */
            terninge_slag(terninger, tilfaeldigt_kast);
            resultat[i] = chancen(tilfaeldigt_kast);

        }else if (i == 16){
            /* Undersøger, om der er Yatzy */
            terninge_slag(terninger, tilfaeldigt_kast);
            resultat[i] = ens_terninger(terninger, tilfaeldigt_kast, 5, udgangspunkt);

            if (resultat[i] > 0){
                resultat[i] = 50;
            }
            
        } else if (i == 17){
            /* Tager den endelige sum */
            for (j = 6; j < 17; j++){
                sum = sum + resultat[j];
            }
            resultat[i] = sum;
        }
    }
    free(tilfaeldigt_kast);
}


/* Printer scoreboardet for brugeren, så man kan se sine point */
void scoreboard(int resultat[]){
    int i;
    printf("\n \n------Dit endelige scoreboard------\n"); 
    printf("Oevre sektion: \n");
    printf(" Det vi leder efter:    Dine point: \n");
    for(i = 0; i < 6; i++){
        printf("       %8d'ere %14d\n", (i+1), resultat[i]);
    }
    printf("-----------------------------------\n");
    printf(" Sum indtil videre  %14d\n", resultat[6]);
    printf("-----------------------------------\n");
    printf("Nedre sektion: \n");
    printf(" Det vi leder efter:    Dine point: \n");
    printf("              Bonus %14d\n", resultat[7]);
    printf("              1 par %14d\n", resultat[8]);
    printf("              2 par %14d\n", resultat[9]);
    printf("              3 ens %14d\n", resultat[10]);
    printf("              4 ens %14d\n", resultat[11]);
    printf("          1-2-3-4-5 %14d\n", resultat[12]);
    printf("          2-3-4-5-6 %14d\n", resultat[13]);
    printf("          Fuldt hus %14d\n", resultat[14]);
    printf("             Chance %14d\n", resultat[15]);
    printf("              YATZY %14d\n", resultat[16]);
    printf("-----------------------------------\n");
    printf(" Total Sum:         %14d\n", resultat[17]);
}
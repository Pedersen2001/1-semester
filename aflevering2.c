#include <stdio.h>

#define SEK_TIL_MIN 60
#define SEK_TIL_TIMER (60*SEK_TIL_MIN)


int main(void) {

    int sek, min, timer, rest, input;

printf("Skriv, hvor mange sekunder du vil konverter: ");

scanf("%d", &input);

timer = input / SEK_TIL_TIMER;
rest  = input % SEK_TIL_TIMER;
min   = rest  / SEK_TIL_MIN;
rest  = rest  % SEK_TIL_MIN;
sek   = rest;

printf("Dette svarer til: \n");

if (timer > 1){
    printf("%d timer \n", timer);
} else if(timer == 1){
        printf("%d time \n", timer);
    }


if (min > 1){
    printf("%d minutter \n", min);
} else if(min == 1){
        printf("%d minut \n", min);
    }


if (sek > 1){
    printf("%d sekunder \n", sek);
} else if(sek == 1){
        printf("%d sekund \n", sek);
    }

return 0;

}
#include <stdio.h>

#define SEK_TIL_MIN 60
#define SEK_TIL_TIMER (60*60)
#define SEK_TIL_DAGE (60*60*24)
#define SEK_TIL_UGER (60*60*24*7)

int main(void) {

    int sek, min, timer, dage, uger, rest;

printf("Skriv, hvor mange sekunder du vil konverter: ");

scanf("%d", &sek);

uger = sek / SEK_TIL_UGER;
rest = sek % SEK_TIL_UGER;
dage = rest / SEK_TIL_DAGE;
rest = rest % SEK_TIL_DAGE;
timer = rest / SEK_TIL_TIMER;
rest = rest % SEK_TIL_TIMER;
min = rest / SEK_TIL_MIN;
rest = rest % SEK_TIL_MIN;
sek = rest;

printf("Dette svarer til uger: %d, dage: %d, timer: %d, minutter: %d, sekunder %d", uger, dage, timer, min, sek);

return 0;

}

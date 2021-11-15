#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANTAL_FORRETTER 4
#define ANTAL_HOVEDRETTER 4
#define ANTAL_DESSERTER 4

typedef enum forret   {guacamole, tarteletter, lakserulle, graeskarsuppe} forret;   
typedef enum hovedret {gyldenkaal, hakkeboef, gullash, forloren_hare} hovedret;              
typedef enum dessert  {pandekager_med_is, gulerodskage, chokolademousse, citronfromage} dessert;  

void maaltid(void);
void prnt_forret(forret fr);
void prnt_hovedret(hovedret hr);
void prnt_dessert(dessert d);
forret make_random_forret(void);
hovedret make_random_hovedret(void);
dessert make_random_dessert(void);
        
int main(void){
 int i;

 srand(time(NULL));
 for (i=0; i < 20; i++) maaltid();

 return 0;
}

void maaltid(void){
  forret f = make_random_forret();
  hovedret h = make_random_hovedret();
  dessert d = make_random_dessert();

  prnt_forret(f);     printf("  ");
  prnt_hovedret(h); printf("  ");
  prnt_dessert(d);   printf("\n");
}

forret make_random_forret(void){
  int ret = rand() % ANTAL_FORRETTER;
  return (forret)ret;
}

hovedret make_random_hovedret(void){
  int ret = rand() % ANTAL_HOVEDRETTER;
  return (hovedret)ret;
}

dessert make_random_dessert(void){
  int ret = rand() % ANTAL_DESSERTER;
  return (dessert)ret;
}

void prnt_forret(forret fr){
 switch (fr){
  case guacamole:     printf("%20s", "Guacamode"); break;
  case tarteletter:   printf("%20s", "Tarteletter"); break;
  case lakserulle:    printf("%20s", "Lakserulle"); break;
  case graeskarsuppe: printf("%20s", "Graeskarsuppe"); break;
  default: printf("Forkert forret"); exit(-1);
 }
}

void prnt_hovedret(hovedret hr){
 switch (hr){
  case gyldenkaal:    printf("%20s", "Gyldenkaal"); break;
  case hakkeboef:     printf("%20s", "Hakkeboef"); break;
  case gullash:       printf("%20s", "Gullash"); break;
  case forloren_hare: printf("%20s", "Forloren_hare"); break;
  default: printf("Forkert hovedret"); exit(-1);
 }
}

void prnt_dessert(dessert d){
 switch (d){
  case pandekager_med_is: printf("%20s", "Pandekager med is"); break;
  case gulerodskage:      printf("%20s", "Gulerodskage"); break;
  case chokolademousse:   printf("%20s", "Chokolademousse"); break;
  case citronfromage:     printf("%20s", "Citronfromage"); break;
  default: printf("Forkert dessert"); exit(-1);
 }
}
/* Her er en variant som bruger en array datastruktur til håndtering af retternes navne, så vi kan undgå at bruge en selektiv kontrolstruktur til printning:

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANTAL_FORRETTER 4
#define ANTAL_HOVEDRETTER 4
#define ANTAL_DESSERTER 4

typedef enum forret   {guacamole, tarteletter, lakserulle, graeskarsuppe} forret;   
typedef enum hovedret {gyldenkaal, hakkeboef, gullash, forloren_hare} hovedret;              
typedef enum dessert  {pandekager_med_is, gulerodskage, chokolademousse, citronfromage} dessert;  

void maaltid(void);
void prnt_forret(forret fr);
void prnt_hovedret(hovedret hr);
void prnt_dessert(dessert d);
forret make_random_forret(void);
hovedret make_random_hovedret(void);
dessert make_random_dessert(void);

char *forret_navne[] = {"guacamole", "tarteletter", "lakserulle", "graeskarsuppe"};
char *hovedret_navne[] = {"gyldenkaal", "hakkeboef", "gullash", "forloren_hare"};
char *dessert_navne[] = {"pandekager_med_is", "gulerodskage", "chokolademousse", "citronfromage"};
        
int main(void){
 int i;

 srand(time(NULL));
 for (i=0; i < 20; i++) maaltid();

 return 0;
}

void maaltid(void){
  forret f = make_random_forret();
  hovedret h = make_random_hovedret();
  dessert d = make_random_dessert();

  prnt_forret(f);     printf("  ");
  prnt_hovedret(h); printf("  ");
  prnt_dessert(d);   printf("\n");
}

forret make_random_forret(void){
  int ret = rand() % ANTAL_FORRETTER;
  return (forret)ret;
}

hovedret make_random_hovedret(void){
  int ret = rand() % ANTAL_HOVEDRETTER;
  return (hovedret)ret;
}

dessert make_random_dessert(void){
  int ret = rand() % ANTAL_DESSERTER;
  return (dessert)ret;
}

void prnt_forret(forret fr){
  printf("%20s", forret_navne[(int)fr]);
}

void prnt_hovedret(hovedret hr){
  printf("%20s", hovedret_navne[(int)hr]);
}

void prnt_dessert(dessert d){
  printf("%20s", dessert_navne[(int)d]);
}

*/


/*  Navn:       Lucas Lybek Højlund Pedersen
    email:      llhp21@student.aau.dk
    Gruppe:     B217
    Retning:    SW 
*/

/*Preprocessor directive */
/*Inkluderinger i form af Library header inclusions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Konstante definitioner - symbolske konstanter*/
#define MATCHES_PLAYED 132
#define TEAMS_TOTAL 12
#define MAX_CHAR 100
#define NAME 10

/*A struct for all the values concerning each team*/
typedef struct { /*Giver typen struct et nyt navn vha. typedef*/
    char team_name[NAME];
    int points;
    int goals_scored;
    int goal_let_in;
} Team;

/*A struct for all values concerning each match - består af felter af forskellige typer*/
typedef struct { /*Giver typen struct et nyt navn vha. typedef*/
    char day_of_week[MAX_CHAR];
    int day_of_month;
    int month;
    int hour;
    int minute;
    char first_team[MAX_CHAR];
    char second_team[MAX_CHAR];
    int first_team_score;
    int second_team_score;
    int viewers; 
} Match;


/*Prototypes for each function - funktioner, som er erklærede*/
void file_with_mathes(Match []);
int team_names(char []);
void making_teams(Match [], Team []);
void update_teams(Team [], Match []);
int points_award(int, int);
void team_score(Team);
void team_scoreboard_print(Team []);
int compare(const void *, const void *);


int main(void){
    Match Matches[MATCHES_PLAYED]; /*Her bliver der lavet en struct variabel ud af "Match" - denne bliver sendt videre til de andre funktioner*/
    Team Teams[TEAMS_TOTAL]; /*Her bliver der lavet en struct variabel ud af "Team" - denne bliver sendt videre til de andre funktioner*/

    file_with_mathes(Matches);

    making_teams(Matches, Teams);

    update_teams(Teams, Matches);

    qsort(Teams, TEAMS_TOTAL, sizeof(Team), compare); 
    /*qsort er en funktion fra stdlib library. Den tager 4 parametre: 
    1. Pointer til det der skal sorteres
    2. Antal af elementer i det der skal sorteres
    3. Størrelsen i bites for elementet der skal sorteres
    4. Funktionen, som skal sammenligne elementerne */

    team_scoreboard_print(Teams);

    return 0;
}

/*Openning the file and scanning each line, to add value into structs*/
void file_with_mathes(Match Matches[]){
    FILE *input_file_pointer; /*En struct FILE fra stdio.h, som samler alle filens egenskaber, hvoraf en pointer dertil er den måde, hvorpå vi arbejder med filen*/
    int i = 0; /*Lokal variabel, som bliver initialiseret - tilskrevet en startværdi - er også expressionstatement*/

    input_file_pointer = fopen("kampe-2020-2021.txt", "r");/*fopen tager to parametre: filnavn og hvad man vil gøre med filen, hvoraf "r" fortæller, at man åbner og læser i en fil*/

    if (input_file_pointer == NULL){
        /*printf (output) er styret af en formateringsstreng, som gør brug af placeholders %, som modsvarer parameterne, som hedder en prinlist*/
        printf("It is not possible to open the input file");
        exit(EXIT_FAILURE);
    }else{
        while (i < MATCHES_PLAYED){ /*%s er for en string of characters, hvor %d er for (decimal) integer*/
            fscanf(input_file_pointer, " %s %d/%d %d.%d %s - %s %d - %d %d ", /*Tager 2 parametre: 1. Pointer til en fil. 2. En string  -  fscanf læser formateret input fra en pointer*/
            Matches[i].day_of_week, &Matches[i].day_of_month, &Matches[i].month, 
            &Matches[i].hour, &Matches[i].minute, Matches[i].first_team,  /*Felter i en struct tilgås vha. dotnotation også kalde direte komponentselektion*/
            Matches[i].second_team, &Matches[i].first_team_score,
            &Matches[i].second_team_score, &Matches[i].viewers);
            i++;
        }
    }
    fclose(input_file_pointer); /*Lukker filen, og bryder alt forbindelsen til filen*/
}

/*Creating each team*/
void making_teams(Match Matches[], Team Teams[]){ /*Jeg sender min struct by value, hvilket vil sige, at funktionen modtager en kopi af structen, som den kan arbejde med*/
    int m, t1 /*t2*/; /*Lokal variabel, som bliver initialiseret*/

    for (m = 0; m < MATCHES_PLAYED; m++){
        t1 = team_names(Matches[m].first_team);
        /* t2 = team_names(Matches[m].second_team); */

        /* create new teams */
        if (*(Teams[t1].team_name) == 0){ /*Hvis værdien/pladsen, som pointeren peger på er 0, så tildeles de følgende værdier. Pladsen burde være 0, da denne ikke er brugt i andre funktioner*/
            /* sprintf sender data videre til en string, som er pointet på, at den første parameter, hvorefter den anden parameter er det, som man indskriver i stringen */
            sprintf(Teams[t1].team_name, Matches[m].first_team); 
            Teams[t1].goals_scored = 0;
            Teams[t1].goal_let_in = 0;
            Teams[t1].points = 0;
        }
        /*    
        if (*(Teams[t2].team_name) == 0){
            sprintf(Teams[t2].team_name, Matches[m].second_team);
            Teams[t2].goals_scored = 0;
            Teams[t2].goal_let_in = 0;
            Teams[t2].points = 0;
        }
        */
    }
}
/*
strcmp tager to strings og sammenligner dem. Hvis string 1 er større end string 2 retunerer funktionen 1. Hvis string 2 er større end string 1 retunerer funktionen -1.
Er de lige store (identiske) retunerer funktionen 0, hvilket er false i boolean (0), så man negerer med ! for at mit statement bliver true.
*/
/*Identifying each team*/
int team_names(char team[]){
    if (! strcmp(team, "SDR")){
        return 0; 

    }else if (! strcmp(team, "FCM")){
        return 1;

    }else if (! strcmp(team, "ACH")){
        return 2;

    }else if (! strcmp(team, "RFC")){ 
        return 3;

    }else if (! strcmp(team, "LBK")){
        return 4;
        
    }else if (! strcmp(team, "AaB")){
        return 5;

    }else if (! strcmp(team, "BIF")){
        return 6;

    }else if (! strcmp(team, "FCN")){
        return 7;

    }else if (! strcmp(team, "OB")){
        return 8;

    }else if (! strcmp(team, "FCK")){
        return 9;

    }else if (! strcmp(team, "AGF")){
        return 10;

    }else if (! strcmp(team, "VB")){
        return 11;

    }else{
        return 12;
    }
}

/*Updating each team with their points from each match*/
void update_teams(Team Teams[], Match Matches[]){
    int i; /*Lokal variabel, som bliver initialiseret*/
    int j;
    int ret; /*Unødvendig*/
    int played = MATCHES_PLAYED;
    int total = TEAMS_TOTAL;

    for (i = 0; i < played; i++){
        for (j = 0; j < total; j++){
            /*
            strcmp tager to strings og sammenligner dem. Hvis string 1 er større end string 2 retunerer funktionen 1. Hvis string 2 er større end string 1 retunerer funktionen -1.
            Er de lige store (identiske) retunerer funktionen 0, hvilket er false i boolean (0), så man negerer med ! for at mit statement bliver true.
            */
            if (!strcmp(Teams[j].team_name, Matches[i].first_team)){ 
            /*Bruger værdier fra ASCII-tabel, hvor talværdier er højere end bogstavsværdier, og derfor er string 2 større end string 1, og man får en værdi på -1, som negeres til true*/
                Teams[j].goals_scored = Teams[j].goals_scored + Matches[i].first_team_score;
                Teams[j].goal_let_in = Teams[j].goal_let_in + Matches[i].second_team_score;
                Teams[j].points = Teams[j].points + points_award(Matches[i].first_team_score, Matches[i].second_team_score);  
            }

            if (!strcmp(Teams[j].team_name, Matches[i].second_team)){
            /*Bruger værdier fra ASCII-tabel, hvor talværdier er højere end bogstavsværdier, og derfor er string 2 større end string 1, og man får en værdi på -1, som negeres til true*/
                Teams[j].goals_scored = Teams[j].goals_scored + Matches[i].second_team_score;
                Teams[j].goal_let_in = Teams[j].goal_let_in + Matches[i].first_team_score;
                Teams[j].points = Teams[j].points + points_award(Matches[i].second_team_score, Matches[i].first_team_score);
            }         
        }
    }
}

/*Awarding points to each team - if they win, draw or lose*/
int points_award(int first_team, int second_team){
    if (first_team > second_team){
        return 3;

    }else if (first_team < second_team){
        return 0;

    }else{
        return 1;
    }
}

/*Printing the name, gols scored and goals let in, and points for each team*/
void team_score(Team Team){
    printf("  %3s    |  %d - %d |    %d\n", Team.team_name, Team.goals_scored, Team.goal_let_in, Team.points);
}/*%3s tildeler værdien 3 pladser, som den kan bruge.*/

/*Printing the scoreboard*/
void team_scoreboard_print(Team Teams[]){
    int i; /*Lokal variabel, som bliver initialiseret*/

    /*printf (output) er styret af en formateringsstreng, som gør brug af placeholders %, som modsvarer parameterne, som hedder en prinlist*/
    printf("\n Team    |   Score  |   Points\n_________|__________|__________\n         |          |  \n");

    for(i = 0; i < TEAMS_TOTAL; i++){
        team_score(Teams[i]);
    }
    printf("\n");
}

/*Comparing each team, where the team with the most points are highest on the scoreboard*/
int compare(const void *ep1, const void *ep2){
    Team *pt1 = (Team *)ep1; /*Typecaster de generiske pointer til en anden type pointer, som er struct pointer*/
    Team *pt2 = (Team *)ep2;

    if (pt1->points != pt2->points){
        return pt2->points - pt1->points; /*Hvis værdien er større end 0 (x>0), så kommer pt2 før pt1. Hvis værdien er mindre end 0 (<0), så kommer pt1 før pt2*/

    }else{
        return pt2->goal_let_in - pt1->goal_let_in; /*Hvis værdien er større end 0 (x>0), så kommer pt2 før pt1. Hvis værdien er mindre end 0 (<0), så kommer pt1 før pt2*/
    }
}

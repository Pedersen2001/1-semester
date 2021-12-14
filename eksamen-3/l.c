/*
Moritz Hönscheidt
mhoens21@student.aau.dk
B217
Software
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
brug malloc i stedet for
*/
#define NUMBER_OF_MATCHES 132
#define NUMBER_OF_TEAMS 12

#define VICTORY_BONUS 3
#define DRAW_BONUS 1
#define MAX_CHAR 30
#define TEAM_NAME_MAX 3

typedef struct
{
    char name[TEAM_NAME_MAX];
    int point, score, opp_score;
} Team;

typedef struct
{
    char weekday[MAX_CHAR], team_1[MAX_CHAR], team_2[MAX_CHAR];
    int day, month, hour, minute, score_team_1, score_team_2, spectators;
} Match;

enum match_data { weekday, day, month, hour, team_1, team_2, score_team_1, score_team_2, spectators };

int team_compare(const void *, const void *);
void read_file(Match []);
void create_teams(Match [], Team []);
int index_of_team(char []);
void print_team_score(Team);
void prnt_scoreboard(Team []);

int main(void)
{
    Match Matches[NUMBER_OF_MATCHES];
    Team Teams[NUMBER_OF_TEAMS];

    read_file(Matches);

    create_teams(Matches, Teams);

    qsort(Teams, NUMBER_OF_TEAMS, sizeof(Team), team_compare);

    prnt_scoreboard(Teams);

    return 0;
}

void read_file(Match Matches[])
{
    FILE *ifp;
    int i;

    ifp = fopen("kampe-2020-2021.txt", "r");

    if (! ifp)
    {
        printf("Could not open input file. Bye.");
        exit(EXIT_FAILURE);
    }
    else
    {
        for (i = 0; i < NUMBER_OF_MATCHES; i++)
        {
            fscanf(ifp, " %s %d/%d %d.%d %s - %s %d - %d %d ",
                   Matches[i].weekday, &(Matches[i].day), &(Matches[i].month), &(Matches[i].hour), &(Matches[i].minute), Matches[i].team_1, Matches[i].team_2,
                   &(Matches[i].score_team_1), &(Matches[i].score_team_2), &(Matches[i].spectators));
        }
        /* prnt_matches(Matches); */
    }
}


void create_teams(Match Matches[], Team Teams[])
{
    int m, t1, t2;

    for (m = 0; m < NUMBER_OF_MATCHES; m++)
    {
        t1 = index_of_team(Matches[m].team_1);
        t2 = index_of_team(Matches[m].team_2);

        /* create new teams */
        if (*(Teams[t1].name) == 0) 
        {
            sprintf(Teams[t1].name, Matches[m].team_1);
            Teams[t1].score = 0;
            Teams[t1].opp_score = 0;
            Teams[t1].point = 0;
        }
            
        if (*(Teams[t2].name) == 0) 
        {
            sprintf(Teams[t2].name, Matches[m].team_2);
            Teams[t2].score = 0;
            Teams[t2].opp_score = 0;
            Teams[t2].point = 0;
        }       

        /* update teams */
        if (Matches[m].score_team_1 > Matches[m].score_team_2)
            Teams[t1].point += VICTORY_BONUS;
        else if (Matches[m].score_team_1 < Matches[m].score_team_2)
            Teams[t2].point += VICTORY_BONUS;
        else 
        {
            Teams[t1].point += DRAW_BONUS;
            Teams[t2].point += DRAW_BONUS;
        }
        
        Teams[t1].score += Matches[m].score_team_1;
        Teams[t1].opp_score += Matches[m].score_team_2;
        
        Teams[t2].score += Matches[m].score_team_2;
        Teams[t2].opp_score += Matches[m].score_team_1;
    }
}

int index_of_team(char team_name[])
{
    if (! strcmp(team_name, "SDR"))
        return 0; 
    else if (! strcmp(team_name, "FCM")) 
        return 1;
    else if (! strcmp(team_name, "ACH")) 
        return 2;
    else if (! strcmp(team_name, "RFC")) 
        return 3;
    else if (! strcmp(team_name, "LBK")) 
        return 4;
    else if (! strcmp(team_name, "AaB")) 
        return 5;
    else if (! strcmp(team_name, "BIF")) 
        return 6;
    else if (! strcmp(team_name, "FCN")) 
        return 7;
    else if (! strcmp(team_name, "OB")) 
        return 8;
    else if (! strcmp(team_name, "FCK")) 
        return 9;
    else if (! strcmp(team_name, "AGF")) 
        return 10;
    else if (! strcmp(team_name, "VB")) 
        return 11;
    else
        return 12;
}

void prnt_scoreboard(Team Teams[])
{
    int i;

    printf("\n Team |   Point  |   Score\n____________________________\n");

    for(i = 0; i < NUMBER_OF_TEAMS; i++)
    {
        print_team_score(Teams[i]);
    }
}

void print_team_score(Team Team)
{            
    printf("  %3s |    %d    |  %d - %d\n", Team.name, Team.point, Team.score, Team.opp_score);
}

/*
compares primary after point and secondary after score diff
*/
int team_compare(const void *pt1, const void *pt2)
{
    Team *pt11 = (Team *)pt1, *pt22 = (Team *)pt2;
    if (pt11->point != pt22->point)
        return pt22->point - pt11->point;
    else 
        return pt22->score - pt11->score;
}

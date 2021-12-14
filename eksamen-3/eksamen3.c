#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATCHES_PLAYED 132
#define TEAMS_TOTAL 12
#define POINTS_WIN 3
#define POINTS_DRAW 1
#define MAX_CHAR 100
#define NAME 10

typedef struct {
    char team_name[NAME];
    int points;
    int goals_scored;
    int goal_let_in;
} Team;

typedef struct {
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

void file_with_mathes(Match []);
int team_names(char []);
void making_teams(Match [], Team []);
void update_teams(Team [], Match []);
int points_award(int, int);
void team_score(Team);
void team_scoreboard_print(Team []);
//void team_scoreboard(Match [], Team []);
int compare(const void *, const void *);

int main(void){
    Match Matches[MATCHES_PLAYED];
    Team Teams[TEAMS_TOTAL];

    file_with_mathes(Matches);

    making_teams(Matches, Teams);

    update_teams(Teams, Matches);

    qsort(Teams, TEAMS_TOTAL, sizeof(Team), compare);

    team_scoreboard_print(Teams);

    return 0;
}

void file_with_mathes(Match Matches[]){
    FILE *input_file_pointer;
    int i = 0;

    input_file_pointer = fopen("kampe-2020-2021.txt", "r");

    if (input_file_pointer == NULL){
        printf("It is not possible to open the input file");
        exit(EXIT_FAILURE);
    } else {
        while (i < MATCHES_PLAYED){
            fscanf(input_file_pointer, " %s %d/%d %d.%d %s - %s %d - %d %d ", 
            Matches[i].day_of_week, &Matches[i].day_of_month, &Matches[i].month, 
            &Matches[i].hour, &Matches[i].minute, Matches[i].first_team,
            Matches[i].second_team, &Matches[i].first_team_score,
            &Matches[i].second_team_score, &Matches[i].viewers);
            i++;
        }
    }
    fclose(input_file_pointer);
}

void making_teams(Match Matches[], Team Teams[]){
    int m, t1, t2;

    for (m = 0; m < MATCHES_PLAYED; m++){
        t1 = team_names(Matches[m].first_team);
        t2 = team_names(Matches[m].second_team);

        /* create new teams */
        if (*(Teams[t1].team_name) == 0){
            sprintf(Teams[t1].team_name, Matches[m].first_team);
            Teams[t1].goals_scored = 0;
            Teams[t1].goal_let_in = 0;
            Teams[t1].points = 0;
        }
            
        if (*(Teams[t2].team_name) == 0){
            sprintf(Teams[t2].team_name, Matches[m].second_team);
            Teams[t2].goals_scored = 0;
            Teams[t2].goal_let_in = 0;
            Teams[t2].points = 0;
        }
    }
}


int team_names(char team[]){

    if (! strcmp(team, "SDR"))
        return 0; 
    else if (! strcmp(team, "FCM")) 
        return 1;
    else if (! strcmp(team, "ACH")) 
        return 2;
    else if (! strcmp(team, "RFC")) 
        return 3;
    else if (! strcmp(team, "LBK")) 
        return 4;
    else if (! strcmp(team, "AaB")) 
        return 5;
    else if (! strcmp(team, "BIF")) 
        return 6;
    else if (! strcmp(team, "FCN")) 
        return 7;
    else if (! strcmp(team, "OB")) 
        return 8;
    else if (! strcmp(team, "FCK")) 
        return 9;
    else if (! strcmp(team, "AGF")) 
        return 10;
    else if (! strcmp(team, "VB")) 
        return 11;
    else
        return 12;
}

void update_teams(Team Teams[], Match Matches[]){
    int i;
    int j;
    int played = MATCHES_PLAYED;
    int total = TEAMS_TOTAL;

    for (i = 0; i < played; i++){
        for (j = 0; j < total; j++){
            if (!strcmp(Teams[j].team_name, Matches[i].first_team)){
                Teams[j].goals_scored += Matches[i].first_team_score;
                Teams[j].goal_let_in += Matches[i].second_team_score;
                Teams[j].points += points_award(Matches[i].first_team_score, Matches[i].second_team_score);  
            }
            if (!strcmp(Teams[j].team_name, Matches[i].second_team)){
                Teams[j].goals_scored += Matches[i].second_team_score;
                Teams[j].goal_let_in += Matches[i].first_team_score;
                Teams[j].points += points_award(Matches[i].second_team_score, Matches[i].first_team_score);
            } 
        }
    }
}

int points_award(int first_team, int second_team){
    if (first_team > second_team){
        return 3;
    } else if (first_team < second_team){
        return 0;
    } else {
        return 1;
    }
}


void team_score(Team Team){
    printf("  %3s    |  %d - %d |    %d\n", Team.team_name, Team.goals_scored, Team.goal_let_in, Team.points);
}

void team_scoreboard_print(Team Teams[]){
    int i;

    printf("\n Team    |   Score  |   Points\n_________|__________|__________\n         |          |  \n");

    for(i = 0; i < TEAMS_TOTAL; i++){
        team_score(Teams[i]);
    }
    printf("\n");
}

int compare(const void *ep1, const void *ep2){
    Team *pt1 = (Team *)ep1;
    Team *pt2 = (Team *)ep2;

    if (pt1->points != pt2->points){
        return pt2->points - pt1->points;
    }else{
        return pt2->goal_let_in - pt1->goal_let_in;
    }
}
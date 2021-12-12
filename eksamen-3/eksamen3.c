#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATCHES_PLAYED 132
#define TEAMS 12
#define POINTS_WIN 3
#define POINTS_DRAW 1
#define MAX_CHAR 100
#define NAME 10

typedef struct {
    char name[NAME];
    int points;
    int goal_home;
    int goal_away;
} Team;

typedef struct {
    char day_of_week[NAME];
    char first_team[NAME];
    char second_team[NAME];
    int day_of_month;
    int month;
    int hour;
    int minute;
    int first_team_score;
    int second_team_score;
    int viewers; 
} Match;


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

int team_names(char team_name[]){

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


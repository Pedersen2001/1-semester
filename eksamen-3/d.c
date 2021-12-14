/*
 * Programmør: Kristian Krarup Sørensen     Dato: Aflevering 10/12-2021
 * Underviser: Kurt Nørmark                 Fag: Imperativ Programmering
 * 
 * Eksamensopgave 3 - Fodbold resultater
 * 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LEN 50
#define MAX_CHAR 400

typedef struct {
    char matchDay[MAX_LEN];
    char matchDate[MAX_LEN];
    char matchTime[MAX_LEN];
    char homeTeam[MAX_LEN];
    char awayTeam[MAX_LEN];
    int homeGoals;
    int awayGoals;
    int spectators;
} Match;

typedef struct {
    char teamName[MAX_LEN];
    int point;
    int scoredGoals;
    int goalsAgainst;
} Team;


void runScoreCard();

/* Match specific prototypes */
int readLineCount();
Match *readMatchFile(int);
Match *allocate_memory(int);

/* Team specific prototypes */
int numberOfTeams(Match *, int);
Team *setTeams(Match *, int);
Team *setTeamMemory(int);

/* updating scorebord, sorting, points and print prototypes */
void updateScoreboard(Team *, Match *, int, int);
int returnPoint(int, int);
void sortArray(Team *, int);
int elComp (const void *, const void *);
void printScoreboard(Team *, int);

int main(void){
    runScoreCard();
    return EXIT_SUCCESS;
}

void runScoreCard(void){
    Match * Matches;
    Team * Teams;
    int matchCount, teams;
    matchCount = readLineCount();
    Matches = readMatchFile(matchCount);
    teams = numberOfTeams(Matches, matchCount);
    Teams = setTeams(Matches, teams);
    updateScoreboard(Teams, Matches, teams, matchCount);
    sortArray(Teams, teams);
    printScoreboard(Teams, teams);

    free(Matches);
    free(Teams);
}

/* Finding amount of matches, assuming 1 match on each line */
int readLineCount(void){
    FILE * fp;
    int lineCount = 0;
    char line[MAX_CHAR];
    fp = fopen("kampe-2020-2021.txt", "r");
    while (fgets(line, MAX_CHAR, fp)){
        ++lineCount;
    }
    fclose(fp);
    return lineCount;
}

/* Read matches from file */
Match *readMatchFile(int matchCount){
    FILE * fp;
    char line[MAX_CHAR];
    int i = 0;
    Match * Matches = allocate_memory(matchCount);
    fp = fopen("kampe-2020-2021.txt", "r");

    /* Scans for variables in every line */
    while (fgets(line, MAX_CHAR, fp))
    {
        sscanf(line, "%s %s %s %s - %s %d - %d %d", Matches[i].matchDay, Matches[i].matchDate, Matches[i].matchTime, Matches[i].homeTeam, Matches[i].awayTeam, &Matches[i].homeGoals, &Matches[i].awayGoals, &Matches[i].spectators);
        i++;
    }

    fclose(fp);
    return Matches;
}

Match *allocate_memory(int matchCount){
    Match *Matches = (Match*) malloc(matchCount*sizeof(Match));
    if(Matches == NULL){
        printf("Memory could not allocated");
        exit(EXIT_FAILURE);
    }
    return Matches;
} 

/* Logic: Ive found number of matches, i assume every team play exactly equal amount of matches
    therefor if I find how many times 1 team is the home team, I can divide that with 
    amount of total matches. */
int numberOfTeams(Match *Matches, int matchCount){
    int differentTeams = 0;
    int i;
    for(i = 0; i < matchCount; i++){
        if(!strcmp(Matches[0].homeTeam, Matches[i].homeTeam)){
            differentTeams++;
        }
    }
    return matchCount/differentTeams;
}

/* Logic: if there is 12 teams, all teams must be represented in number of teams/2 games (1 playround) */
Team *setTeams(Match *Matches, int teams){
    Team *Teams = (Team*) setTeamMemory(teams);
    int playRounds = teams/2;
    int i, j;
    /* get home teams*/
    for(i = 0; i < playRounds; i++){
        strcpy(Teams[i].teamName, Matches[i].homeTeam);
    }
    /* Get away teams */
    for(i = 0, j = playRounds; j < teams; i++, j++){
        strcpy(Teams[j].teamName, Matches[i].awayTeam);
    }

    /* sets the values to 0, for alle teams, so its easy updateable in the update function */
    for(i = 0; i < teams; i++){
        Teams[i].goalsAgainst = 0;
        Teams[i].point = 0;
        Teams[i].scoredGoals = 0;
    }
    return Teams;
}

Team *setTeamMemory(int teams){
    Team *Teams = malloc(teams*sizeof(Team));
    if(Teams == NULL){
        printf("Memory could not allocated");
        exit(EXIT_FAILURE);
    }
    return Teams;
}

/* This function takes the team, adding their points, and all goals as home team and away team */
void updateScoreboard(Team *Teams, Match *Matches, int teams, int matchCount){
    int i, j;
    for(i = 0; i < matchCount; i++){
        for(j = 0; j < teams; j++){
            if(!strcmp(Teams[j].teamName, Matches[i].homeTeam)){
                Teams[j].scoredGoals += Matches[i].homeGoals;
                Teams[j].goalsAgainst += Matches[i].awayGoals;
                Teams[j].point += returnPoint(Matches[i].homeGoals, Matches[i].awayGoals);
            }
            if(!strcmp(Teams[j].teamName, Matches[i].awayTeam)){
                Teams[j].scoredGoals += Matches[i].awayGoals;
                Teams[j].goalsAgainst += Matches[i].homeGoals;
                Teams[j].point += returnPoint(Matches[i].awayGoals, Matches[i].homeGoals);
            }

        }
    }
}

int returnPoint(int home, int away){
    if(home > away){
        return 3;
    } else if(home < away){
        return 0;
    } else {
        return 1;
    }
}

void sortArray(Team *Teams, int teams){
    qsort(Teams, teams, sizeof(Team), elComp);
}

/* Comparing points to find the winning team, if the points are equal, goals scored decides which gets highest then */
int elComp (const void *ep1, const void *ep2){
    int goals;
    Team *tp1 = (Team*) ep1;
    Team *tp2 = (Team*) ep2;

    if(tp1->point < tp2->point){
        return -1;
    } 
    if (tp1->point > tp2->point){
        return 1;
    } 
    goals = tp1->scoredGoals - tp2->scoredGoals;
    return goals; 
}

void printScoreboard(Team * Teams, int teams){
    int i;
    printf("Team   Score      Point\n");
    for(i = teams-1; i >= 0; i--){
        printf("%-5s %3d - %2d %5d\n", Teams[i].teamName, Teams[i].scoredGoals, Teams[i].goalsAgainst, Teams[i].point);
    }
}

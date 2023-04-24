#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[31];
    char city[31];
    int runways;
    int time;
}AIRPORT;

int cmp(const void *a, const void *b){
    AIRPORT *left = (AIRPORT *) a;
    AIRPORT *right = (AIRPORT *) b;

    if(left->runways != right->runways){
        return -(left->runways - right->runways);
    }
    if(left->time != right->time){
        return -(left->time - right->time);
    }
    return strcmp(left->name, right->name);
}

int main(){
    char line[101];
    gets(line);
    int num = atoi(line);
    
    AIRPORT airport[num];

    for(int i = 0; i < num; i++){
        gets(line);
        char *name = strtok(line, ";");
        char *city = strtok(NULL, ";");
        int runways = atoi(strtok(NULL, ";"));
        int time = atoi(strtok(NULL, ";"));
        strcpy(airport[i].name, name);
        strcpy(airport[i].city, city);
        airport[i].runways = runways;
        airport[i].time = time;
    }

    qsort(airport, num, sizeof(AIRPORT), cmp);
    for(int i=0; i<num; i++) {
        printf("%s (%s): %d\n", 
            airport[i].name, airport[i].city,
                airport[i].time);
    }
    return 0;
}
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
    AIRPORT *l = (AIRPORT *)a;
    AIRPORT *r = (AIRPORT *)b;
    if(l->runways !=r->runways)
        return -(l->runways - r->runways);
    if(l->time!=r->time)
        return -(l->time - r->time);
    return strcmp(l->name,r->name);
}
int query(AIRPORT *airports, int len){
    int max = airports[0].runways;
    for(int i = 0; i < len; i++){
        if(max < airports[i].runways){
            max = airports[i].runways;
        }
    }
    return max;
}

int main(int argc, char *argv[]){
    FILE *fp;
    AIRPORT airports[20];
    char line[102];
    int len = 0;
    if(argc < 2){
        fprintf(stderr, "not present\n");
        return 1;
    }
    fp = fopen(argv[1], "r");
    if(!fp){
        fprintf(stderr, "does not exit\n");
    }
    while(fgets(line,100,fp)){
        strcpy(airports[len].name, strtok(line, ";"));
        strcpy(airports[len].city, strtok(NULL, ";"));
        airports[len].runways = atoi(strtok(NULL, ";"));
        airports[len].time = atoi(strtok(NULL, ";"));
        len += 1;
    }
    fclose(fp);
    qsort(airports, len, sizeof(AIRPORT), cmp);
    if(argc < 3){
        fprintf(stderr, "not present\n");
        return 3;
    }
    fp = fopen(argv[2], "w");
    if(!fp){
        fprintf(stderr, "cannot be open\n");
        return 4;
    }
    for(int i = 0; i < len; i++){
        fprintf(fp, "%s;%s;%d;%d\n", airports[i].name, airports[i].city, airports[i].runways, airports[i].time);

    }
    fclose(fp);
    printf("%d\n", query(airports, len));
    return 0;
}
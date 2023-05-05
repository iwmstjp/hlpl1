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
    if(l->runways != r->runways)
        return -(l->runways - r->runways);
    if(l->time != r->time)
        return -(l->time - r->time);
    return strcmp(l->name, r->name);

}

int query(AIRPORT *a, int lenght){
    int g = a[0].runways;
    for(int i = 0; i < lenght; i++){
        if(g < a[i].runways){
            g = a[i].runways;
        }
    }
    return g;
}

int main(int argc, char *argv[]){
    char line[101];
    AIRPORT airports[20];
    FILE *fp;
    int lenght = 0;
    if(argc < 2){
        fprintf(stderr, "No input file was given.\n");
        return 1;
    }
    fp = fopen(argv[1], "r");
    if(!fp){
        fprintf(stderr, "The file does not exist.\n");
        return 2;
    }
    while(fgets(line, 100,fp)){
        strcpy(airports[lenght].name, strtok(line, ";"));
        strcpy(airports[lenght].city, strtok(NULL, ";"));
        airports[lenght].runways = atoi(strtok(NULL, ";"));
        airports[lenght].time = atoi(strtok(NULL, ";"));
        lenght += 1;
    }
    fclose(fp);
    qsort(airports, lenght, sizeof(AIRPORT), cmp);
    if (argc < 3){
        fprintf(stderr, "No input file was given.\n");
        return 3;
    }
    fp = fopen(argv[2], "w");
    if(!fp){
        fprintf(stderr, "the file cannot be opened.");
        return 4;
    }
    for(int i = 0; i < lenght; i++){
        fprintf(fp, "%s;%s;%d;%d\n", airports[i].name, airports[i].city, airports[i].runways, airports[i].time);
    }
    fclose(fp);
    printf("%d\n", query(airports, lenght));
    return EXIT_SUCCESS;
}
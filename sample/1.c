#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    /* data */
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
    return strcmp(l->name ,r->name);
    
}

int query(AIRPORT *a, int len){
    int max = a[0].runways;
    for(int i = 0; i < len; i++){
        if(max < a[i].runways){
            max = a[i].runways;
        }
    }
    return max;
}

int main(int argc, char *argv[]){
    FILE *fp;
    AIRPORT airport[20];
    char line[101];
    int len= 0;
    if(argc < 2){
        fprintf(stderr, "an error messeage 1");
        return 1;
    }
    fp = fopen(argv[1], "r");
    if(!(fp)){
        fprintf(stderr, "an error messeage 2");
        return 2;
    }
    while(fgets(line, 100, fp)){
        strcpy(airport[len].name, strtok(line, ";"));
        strcpy(airport[len].city, strtok(NULL, ";"));
        airport[len].runways = atoi(strtok(NULL, ";"));
        airport[len].time = atoi(strtok(NULL, ";"));
        len += 1;
    }
    fclose(fp);
    qsort(airport, len, sizeof(AIRPORT), cmp);
    if(argc<3){
        fprintf(stderr, "an error messeage 3");
        return 3;
    }
    fp = fopen(argv[2], "w");
    if(!(fp)){
        fprintf(stderr, "an error messeage 4");
        return 4;
    }
    for(int i = 0; i < len; i++){
        fprintf(fp, "%s;%s;%d;%d\n", airport[i].name, airport[i].city, airport[i].runways, airport[i].time);
    }
    fclose(fp);
    printf("%d\n", query(airport, len));
    return EXIT_SUCCESS;
}
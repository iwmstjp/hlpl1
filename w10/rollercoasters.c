#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
    char name[31];
    char world[31];
    int height;
    int time;
}COASTERS;

int cmp(const void *a, const void *b){
    COASTERS *left = (COASTERS *)a;
    COASTERS *right = (COASTERS *)b;
    if(left->time != right->time){
        return (left->time - right->time);
    }
    if(left->height != right->height){
        return -(left->height - right->height);
    }
    return strcmp(left->name, right->name);
}
int main(){
    int n;
    char line[101];
    gets(line);
    n = atoi(line);
    COASTERS coasters[n];
    for(int i = 0; i < n; i++){
        gets(line);
        char *name = strtok(line, ";");
        char *world = strtok(NULL, ";");
        char *height = strtok(NULL, ";");
        char *time = strtok(NULL, ";");
        strcpy(coasters[i].name, name);
        strcpy(coasters[i].world, world);
        coasters[i].height = atoi(height);
        coasters[i].time = atoi(time);
    }
    qsort(coasters, n, sizeof(COASTERS), cmp);
    for(int i=0; i<n; i++) {
        printf("%s (%s): %d\n", 
            coasters[i].name,
            coasters[i].world,
            coasters[i].time);
    }
    return 0;
}
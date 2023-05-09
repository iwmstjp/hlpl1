#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct{
    char code[6];
    char name[51];
    char theme[30];
    int bricks;
}LEGO_SET;

int cmp(const void *a, const void *b){
    LEGO_SET *l = (LEGO_SET *)a;
    LEGO_SET *r = (LEGO_SET *)b;
    if(l->bricks != r->bricks)
        return -(l->bricks - r->bricks);
    if(strcmp(l->theme,r->theme) != 0)
        return strcmp(l->theme,r->theme);
    if(strcmp(l->name,r->name) != 0)
        return strcmp(l->name,r->name);
    if(strcmp(l->code,r->code) != 0)
        return strcmp(l->code,r->code);
}
int main(){
    LEGO_SET lego[20];
    char line[201];
    int n = atoi(gets(line));
    for(int i = 0; i<n; i++){
        gets(line);
        strcpy(lego[i].code, strtok(line, ";"));
        strcpy(lego[i].name, strtok(NULL, ";"));
        strcpy(lego[i].theme, strtok(NULL, ";"));
        lego[i].bricks = atoi(strtok(NULL, ";"));
    }
    qsort(lego, n, sizeof(LEGO_SET), cmp);
    for(int i = 0; i < n; i++){
        printf("%s (%s): %d - %s\n", lego[i].name, lego[i].code, lego[i].bricks, lego[i].theme);
    }
    return EXIT_SUCCESS;
}
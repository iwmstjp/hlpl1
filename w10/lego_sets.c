#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char code[6];
    char name[51];
    char theme[31];
    int bricks;

}LEGO_SET;

int cmp(const void *a, const void *b){
    LEGO_SET *left = (LEGO_SET *)a;
    LEGO_SET *right = (LEGO_SET *)b;
    if(left->bricks != right->bricks){
        return -(left->bricks - right->bricks);
    }
    if(strcmp(left->theme, right->theme)){
        return strcmp(left->theme, right->theme);
    }
    if(strcmp(left->name, right->name)){
        return strcmp(left->name, right->name);
    }
    if(strcmp(left->code, right->code)){
        return strcmp(left->code, right->code);
    }
}
int main(){
    char line[201];
    int n;
    gets(line);
    n = atoi(line);
    LEGO_SET lego[n];
    for(int i = 0; i < n; i++){
        gets(line);
        char *code = strtok(line, ";");
        char *name = strtok(NULL, ";");
        char *theme = strtok(NULL, ";");
        int bricks = atoi(strtok(NULL, ";"));
        strcpy(lego[i].code, code);
        strcpy(lego[i].name, name);
        strcpy(lego[i].theme, theme);
        lego[i].bricks = bricks;
    }
    qsort(lego, n, sizeof(LEGO_SET), cmp);
    for(int i = 0; i < n; i++){
        printf("%s (%s): %d - %s\n", lego[i].name, lego[i].code, lego[i].bricks, lego[i].theme);
    }
    return 0;
}
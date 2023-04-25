#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
    int min = strlen(argv[1]);
    for(int i = 2; i < argc; i++){
        if(min > strlen(argv[i])){
            min = strlen(argv[i]);
        }
    }
    for(int i = 1; i < argc; i++){
        if(min == strlen(argv[i])){
            printf("%s\n", argv[i]);
        }
    }
    return 0;
}
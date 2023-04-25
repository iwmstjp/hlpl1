#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
    int max = atoi(argv[1]);
    for(int i = 2; i < argc; i++){
        if (max < atoi(argv[i])){
            max = atoi(argv[i]);
        }
    }
    printf("%d\n", max);
    return 0;
}
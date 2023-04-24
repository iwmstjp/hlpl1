#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
    int ans = 0;
    for(int i = 1; i < argc; i++){
        if (strcmp(argv[1], argv[i]) == 0){
            ans += 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
    // if(argc == 1)
    //     return 0;
    int result = atoi(argv[1]);
    for (int i = 1; i < argc; i++)
    {
        if (result < atoi(argv[i]))
        {
            result = atoi(argv[i]);
        }
    }
    printf("%d\n", result);
    return 0;
}
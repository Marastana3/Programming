/*Write a C program that accepts 4 arguments on command line. The program shall print 
a different message for each argument and an error message if the arguments 
are not present, are not enough or are too many.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

    if(argc < 5){
        printf("Not enough arguments arguments!\n");
        exit(-1);
    }

    if(argc > 5){
        printf("Too many arguments!\n");
        exit(-1);
    }

    for(int i = 1; i < argc; ++i){
        printf("%s is argument number %d !\n", argv[i], i);
    }

    return 0;
}

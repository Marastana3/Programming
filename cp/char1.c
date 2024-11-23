#include <stdio.h>
#include <ctype.h>

void clean_up(){

    char c;
    freopen("file.txt", "r", stdin);

    while((c = getchar()) != EOF){

        if(isspace(c)){
            while(isspace(c) && c != '\n'){
                c = getchar();
            }
            if(c == '\n'){
                putchar('\n');
                continue;
            }
            else putchar(' ');
        }

        putchar(c);
    }
}

int main(){

    clean_up();

    return 0;
}
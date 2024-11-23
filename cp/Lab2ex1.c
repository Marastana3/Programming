#include <stdio.h>
#include <ctype.h>

int main(void){
    freopen("file.txt", "r", stdin );
    char c;
    while((c=getchar())!= EOF){

        if(isspace(c)){
            while(isspace(c) && c != '\n'){
                c = getchar();
            }
            if(c == '\n'){
                putchar('\n');
                continue;
            }
            else 
              putchar(' ');
        }
      putchar(c);
    }
    return 0;
}
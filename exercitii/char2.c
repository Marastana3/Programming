#include <stdio.h>
#include <ctype.h>

unsigned read_CSV(){

    int c;
    unsigned count_fileds = 0;

    while((c = getchar()) != EOF){
        if(c == ','){
            count_fileds++;
        }
        
    }



}

int main(){

    return 0;
}
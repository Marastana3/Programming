#include <stdio.h>
#include <stdlib.h>

typedef enum{
    white, yellow, red, green, blue, black
}type_color;

type_color sol[3] = {7,7,7};

int is_acceptable(int step, type_color new_sol){
    if(step >= 3)
        return 0; //the sol must have maximum 3 elem
    else
        if (step == 1 && (new_sol == white || new_sol == red || new_sol == blue || new_sol == black || sol[0] == new_sol))
            return 0;// the sol must be yellow or green and different from the first
        else
            if (step == 2 && (new_sol == sol[1] || new_sol == sol[0]))
                return 0;//the 3rd elem must be diff from the 2nd
        
    return 1;
}

void backtrack(int step){
    for(type_color j = white; j <= black; ++j){
        if(is_acceptable(step, j)){
            sol[step] = j;
            if(step == 2){
                printf("%d", sol[step]);
            }
            else{
                backtrack(step++);
            }
            sol[step] = 7; //erase current sol
        }
    }
}

int main(void){
    backtrack(0);
    return 0;
}
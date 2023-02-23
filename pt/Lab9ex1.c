/*
-------backtracking--------
1. array : x
2. len(x)- finite
3. x[i] belong to a finite set

void back(int step){
    for each poss value (pv) for x[step]
        if(pv is acceptable){
            record pv
            if solution
                print solution
            else 
                back(step)
            erase pv
        }

   1. permutari de n: 12345
                      12354
                      13254
            1. is an array; 2. len(x) = n; 3. x belongs to {1, 2, ..., n};
    function : 
      -  int acceptable(pv, step)
            for(int i = 0; i < step; ++i){
                ...
            }
      - step == n (the end);-solution

    2. combinari de 5 luate cate 3 : 123
                                     345
        1. is an array; 2. len(x) = k; 3. x[i] belongs to {1, 2, .. ,  n};
        2. pv > x[step-1];
        3. x[step] = pv
        4. step == n (n-1)
        5. ...
        6. x[step] = -i;

        
}*/



#include <stdio.h>

int main(void){

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(void) {
    clock_t start, end;
    double cpu_time_used;
    set < int > s;
 
    // Inserting elements in random order
    start = clock();
    for (int i = 0; i < 1000000; ++i){
        int key = rand() % 1000000 + 1;
        s.insert(key);
    }
    end = clock();
    
    cpu_time_used  = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time used for inserting 1000000 random keys in a Set : %f\n", cpu_time_used);

    // Inserting elements in increasing order
    start = clock();
    for ( int i = 0; i < 1000000; ++i){
        s.insert(i);
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time used for inserting 1000000 increasing keys in a Set : %f\n", cpu_time_used);
    
    return 0 ;
}
#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int xi, xj, n, m;
int a[25][25];
int step, maxim;

void init_code(){
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //ONLINE_JUDGE
}

void bkt(int i, int j, int step){
    if(i == n || i == 1 || j == n || j == 1){
        if(step > maxim)
            maxim = step;
    }
    else{
        if(a[i+1][j] < a[i][j])
            bkt(i+1, j, step+1); //south
        if(a[i-1][j] < a[i][j])
            bkt(i-1, j, step+1); //north
        if(a[i][j+1] < a[i][j])
            bkt(i, j+1, step+1); //east
        if(a[i][j-1] < a[i][j])
            bkt(i, j-1, step+1); //west
    }
}

int main(void){
    init_code();
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    cin >> xi >> xj;
    bkt(xi, xj, 1);
    cout << maxim;  
    return 0;
}
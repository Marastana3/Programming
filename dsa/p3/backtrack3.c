/*Un teren este reprezentabil sub forma unei matrice A cu m linii si n coloane.Elementele A(i,j) ce apartin multimii numerelor reale,
reprezinta cotele(inaltimea) diferitelor portiuni din acest teren.Se presupune ca o bila se gasete pe o portiune A(a,b)(citit de la tastatura).
Sa se reprezinte toate traseele ce pot fi urmate de bila pentru ca ea sa iasa din teren,stiind ca se poate deplasa pe orice portiune de teren
invecinata cu o cota strict inferioara cotei terenului pe care se gaseste bila.

Sa se prezinte si sa se motiveze alegerea structurilor de date si a algoritmului.
Sa se exemplifice functionarea lui pe o matrice de 3x3.*/

#include <stdio.h>

#define N 3
#define M 3

int matrice[N][M] = {{3, 2, 1}, {1, 1, 2}, {2, 1, 3}};
int x[] = {-1, 0, 1, 0};
int y[] = {0, 1, 0, -1};

int valid(int linie, int coloana, int matr[N][M], int vis[N][M])
{
    if ((linie >= 0 && linie < N) && (coloana >= 0 && coloana < M) && matr[linie][coloana] < (matrice[linie][coloana] && !vis[linie][coloana]))
    {
        return 1;
    }
    return 0;
}

void afisare(int matr[N][M])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", matr[i][j]);
        }
        printf("\n");
    }
}

int backtrack(int matr[N][M], int linie, int coloana, int vis[N][M])
{
    if (linie == 0 || linie == N - 1 || coloana == 0 || coloana == M - 1)
    {
        afisare(matr);
        return 1;
    }
    int k = 0;
    vis[linie][coloana] = 1;
    for (int i = 0; i < 4; i++)
    {
        int linie_noua = linie + x[i];
        int coloana_noua = coloana + y[i];
        if (valid(linie, coloana, matr, vis))
        {
            k = backtrack(matr, linie_noua, coloana_noua, vis);
            if (k == 1)
            {
                return 1;
            }
        }
    }
    vis[linie][coloana] = 0;
    return 0;
}

int main(void)
{
    int matrice_s[N][M] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int linie = 1;
    int coloana = 1;
    backtrack(matrice, linie, coloana, matrice_s);

    return 0;
}
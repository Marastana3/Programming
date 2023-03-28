/*Fie o suprafata caroiata, reprezentata printr-o matrice patratica de dimensiune n*m si 4 culori
Sa se implementeze structurile de date necesare si urmatoarele functionalitati:
Coloreaza harta - functia propune un mod de colorare al suprafetei, folosind cele 4 culori astfe
incat vecinii pe diagonala ai unei celule sa aiba culori diferite decat cea a celulei
Sa se aleaga un exemplu de suprafata de cel putin 3*3 element si sa se reprezinte suprafata dupa apelul functiei Coloreaza harta.
Nota:
Algoritmul poate fi scris in pseudocod (C like).
Este obligatorie comentarea algoritmului si specificarea complexitati acestuia in termeni
de O(f(n)), comentarea structurilor de date alese, precum si justificarea alegerii acestora,
Este obligatorie exemplificarea efectului apelului functiilor implementate pe un exemplu ales*/

#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 3

int culori[4] = {1, 2, 3, 4};
int a[N][M];

void afiseaza()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int valid(int linie, int coloana)
{
    if (linie > N || linie < 0 || coloana < 0 || coloana > M)
    {
        return 0;
    }
    if ((a[linie - 1][coloana - 1] == a[linie][coloana]) || (a[linie - 1][coloana + 1] == a[linie][coloana]) || (a[linie + 1][coloana - 1] == a[linie][coloana]) || (a[linie + 1][coloana + 1] == a[linie][coloana]))
    {
        return 0;
    }
    return 1;
}

int solutie(int pas)
{
    if (pas == N * M)
    {
        return 1;
    }
    return 0;
}

void backtrack(int pas, int linie, int coloana)
{
    for (int i = 0; i < 3; i++)
    {
        a[linie][coloana] = culori[i];
        if (valid(linie, coloana))
        {
            if (solutie(pas))
            {
                afiseaza();
            }
            else
            {
                if (coloana == (M - 1))
                {
                    backtrack(pas + 1, linie + 1, 0);
                }
            }
            backtrack(pas + 1, linie, coloana + 1);
        }
        a[linie][coloana] = 0;
    }
}

int main(void)
{
    afiseaza();
    backtrack(1, 0, 0);
    return 0;
}
/*Se dau urmatoarele 6 culori : alb,galben,rosu,verde,albastru,negru.
Sa se implementeze structurile de date necesare si urmatoarele functionalitati:
*Construit toate steagurile din 3 culori care indeplinesc urmatoarele conditii :
-orice steag trebuie sa contina culoarea erde sau culoarea galben la mijloc
-culorile din fiecare steag trebuie sa fie distincte*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char culori[6][10] = {"alb", "galben", "rosu", "verde", "albastru", "negru"};
int f[5] = {0}; // f de la folosit

void afisare(int a, int b, int c)
{
    printf("%s %s %s\n", culori[a], culori[b], culori[c]);
}

int solutie(int pas)
{
    if (pas == 3)
    {
        afisare(f[0], f[1], f[2]);
        return 1;
    }
    else
    {
        return 0;
    }
}

void backtrack(int pas)
{
    int i;
    if (solutie(pas))
    {
        return;
    }
    for (i = 0; i < 6; i++)
    {
        if ((pas == 1) && (i != 1) && (i != 3))
        {
            continue; // culorile din mijloc sa fie verde sau galben
        }
        if ((f[0] == i) || (f[1] == i) || (f[2] == i))
        {
            continue; // culorile trebuie sa fie distincte
        }
        f[pas] = i;
        backtrack(pas + 1);
        f[pas] = 0;
    }
}

int main(void)
{
    backtrack(0);

    return 0;
}
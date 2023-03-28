/*Se da multimea M = {a,b,c}
Sa se implementeze structurile de date necesare si urmatoarele functionalitati :
*Genereaza cuvinte - functia determina totate cuvintele ce contin numai litere din multimea M de lungime 10,
care contin exact 3 simboluri 'a',4 simboluri 'b' si 3 simboulri 'c'.
*Sa se noteze primele 5 cuvinte generate in ordine
*/

#include <stdio.h>
#include <stdlib.h>

char multime[3] = {'a', 'b', 'c'};

int valid(char *solutie, int pas)
{
    int i = 0;
    int v[3] = {};
    if (pas <= 3)
    {
        return 1;
    }
    for (i = 0; i <= pas; i++)
    {
        if (solutie[i] == 'a')
        {
            v[0]++;
        }
        else if (solutie[i] == 'b')
        {
            v[1]++;
        }
        else if (solutie[i] == 'c')
        {
            v[2]++;
        }
    }
    if (v[0] > 3 || v[1] > 4 || v[2] > 3)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int solutie(int pas)
{
    if (pas == 9)
    {
        return 1;
    }
    return 0;
}

void backtrack(int pas, char *sol)
{
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        sol[pas] = multime[i];
        if (valid(sol, pas))
        {
            if (solutie(pas))
            {
                sol[pas + 1] = '\0';
                printf("%s\n", sol);
            }
            backtrack(pas + 1, sol);
        }
        sol[pas] = "";
    }
}

int main(void)
{
    char sol[10] = "";
    backtrack(0, sol);

    return 0;
}
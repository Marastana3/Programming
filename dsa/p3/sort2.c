/*Fie un tablou de elemente a caror valori sunt numere intregi,pozitive sau negative
Sa se alega si sa se modifice doi algoritmi de sortare studiati,astfel incat:
-valorile negative vor fi aduse la inceputul tabloului(elementele negative la inceput,dupa elementele pozitive)
-valorile pozitive vor fi sortate crescator

Algoritmul modificat sa fie cat mai eficient
Motivati alegerea algoritmului.Exemplificati functionarea algoritmului pe un tablou de 6 elemente
*/

#include <stdio.h>

#define MAX 6

#define tt 4 // dimensiune pentru tablou de la shellsort

void citire_vector(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
}

void afisare_vecor(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }
}

void quicksort(int *a, int s, int d) //am folosit quicksort pentru ca este printre cel mai performati algoritmi de sortare
{
    int i = s, j = d;
    int x = a[(s + d) / 2];
    do 
    {
        while ((a[i] < x) && (a[i] < 0)) //daca elementul din vector este mai mic decat pivotul si inacelasi timp,elementul este negativ,atunci creste indexul i
            i++;
        while ((a[j] > x) && (a[i] > 0)) //daca elementul din vector este mai mare decat pivotul si inacelasi timp,elementul este pozitiv,atunci scade indexul j
            j--;
        if (i <= j) //pasul de sortare
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if (s < j)  //aplicarea recursivitati daca se indeplineste conditia din if
        quicksort(a, s, j);
    if (d > i)
        quicksort(a, i, d);
}

void shellsort(int a[], int n)
{
    int i, j, pas;
    int temp;
    unsigned char m;
    int h[tt];
    /ex. de atribuire directa incrementi pentru un tablou h de 4 elemente/
    h[0] = 9;
    h[1] = 5;
    h[2] = 3;
    h[3] = 1;
    for (m = 0; m < tt; ++m)
    {
        pas = h[m];
        for (i = pas; i < n; ++i)
        {
            temp = a[i];
            for (j = i; j >= pas && ((a[j - pas] > 0) && (a[j - pas] > temp)); j = j - pas) //daca elementul de la pozitia indicata este pozitiv si este mai mare
            {                                                                               //decat elementul auxiliar,atunci se produce sortarea
                a[j] = a[j - pas];
            }
            a[j] = temp;
        }
    }
}

int main(void)
{
    int array[MAX];
    printf("Introduceti elementele vectorului : \n");
    citire_vector(array, MAX);
    quicksort(array, 0, MAX - 1);
    printf("Afisare duapa prima soratre :\n");
    afisare_vecor(array, MAX);
    shellsort(array,MAX);
    printf("Afisare duapa a doua soratre :\n");
    afisare_vecor(array,MAX);

    return 0;
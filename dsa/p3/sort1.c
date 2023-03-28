/*Fie un tablou de forma struct agenda {char nume[25],char telefon[10],int an,int venit}
Stiind ca tabloul are dimeniunea N sa se implementeze cate o functie pentru :
a.Mutarea pe ultimele pozitii din vector a primeleor persoane cu venit mai mic de 1000.
b.Soratrea eficienta ,in ordine alfabetica a numelor,persoanele cu varsta intre 30 si 40 ani

Sa se considere un tablou cu minim 5 astfel de agende si sa se exemplifice cum va arata tabloul dupa
apelul fiecareia din functiile de mai sus*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tt 4

typedef struct Agenda
{
    char nume[25];
    char telefon[10];
    int an; // asta cred ca se refera la varsta:))
    int venit;
} Agenda;

void citire_vector_structura(Agenda *persoane, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Introduceti numele : ");
        scanf("%s", persoane[i].nume);
        printf("Introduceti numar telefon : ");
        scanf("%s", persoane[i].telefon);
        printf("Introduceti varsta : ");
        scanf("%d", &persoane[i].an);
        printf("Introduceti venitul : ");
        scanf("%d", &persoane[i].venit);
    }
}

void afisare_vector_structura(Agenda *persoane, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nume : %s ; Telefon : %s ; Varsta : %d ; Venit : %d \n", persoane[i].nume, persoane[i].telefon, (persoane[i].an), persoane[i].venit);
    }
}

void bubblesort(Agenda a[], int n) // bubblesort folosit pentru a muta pe ultimele pozitii din vector persoanele care au un venit < 1000
{
    int i, j;
    Agenda temp;
    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j > i; j--)
            if ((a[j - 1].venit < 1000) && (a[j - 1].venit < a[j].venit)) // daca se indeplineste conditia(venitul persoanei este mai mic < 1000,iar venitul persoanei
            {                                                             // urmatoare este mai mare,are loc interschimbarea
                temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
    }
}

int compare(Agenda persoana1, Agenda persoana2) // functia de comparare dintre doua peroane care va fi folosita ulterior in algoritmul de shellsort
{
    if ((((persoana1.an >= 30) && (persoana1.an <= 40)) || ((persoana2.an >= 30) && (persoana2.an <= 40))) && (((persoana1.venit < 1000) && (persoana2.venit < 1000))))
    { // daca persoanele au varste cuprinse intre 30 si 40 de ani,dar au un venit mai mic de 1000,atunci nu se produce interschimbarea i functia de sortare
        return 0;
    }
    else if ((((persoana1.an >= 30) && (persoana1.an <= 40)) || ((persoana2.an >= 30) && (persoana2.an <= 40))) && (strcmp(persoana1.nume, persoana2.nume) > 0) && (((persoana1.venit > 1000) && (persoana2.venit > 1000))))
    { // daca persoanele au varste cuprinse intre 30 si 40 de ani,au un venit mai mare de 1000 si numele primei persone este mai mare decat numele urmatoare pesoane,se produce interschimbarea
        return 1;
    }
    return 0;
}

void shellsort(Agenda a[], int n)
{
    int i, j, pas;
    Agenda temp;
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
            for (j = i; j >= pas && compare(a[j - pas], temp); j = j - pas) // daca se indeplineste conditia din functia compare si j >= pas se produce interschimbarea
            {
                a[j] = a[j - pas];
            }
            a[j] = temp;
        }
    }
}

int main(void)
{
    int n;
    printf("Introduceti un numar pentru a defini dimensiunea stucturii : ");
    scanf("%d", &n);
    Agenda persoane[n];
    citire_vector_structura(persoane, n);
    printf("Afisarea vectorului : \n");
    bubblesort(persoane, n);
    afisare_vector_structura(persoane, n);
    printf("Afisarea vectorului : \n");
    shellsort(persoane, n);
    afisare_vector_structura(persoane, n);

    return 0;
}
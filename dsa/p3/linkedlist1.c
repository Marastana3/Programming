/*Fie un sistem de gestionare a unor paleti din cadrul unor depozite.Depozitul este caracterizat print-un nume unic,iar paletii print-un cod numeric(max 8 cifre).
Sa se scrie si sa se implementeze o structura multilista adecvata pentru gestionarea acestor depozite.Structura va acea urmatoarea componenta :
Fiecare depozit va reprezenta o intrare seprata intr-o lista principala si ficare depozit contine o lista secundara ordonata dupa cod a paletiolor din acel depozit
(cel putin una din liste va fi implemetata in mod dinamic)
Sa se imlementeze structurile de date necesare si urmatoarele functionalitati :
*eliminare palet - se sterge un palet identificat dupa cod din toate depozitele

Sa se alega un exempul de lista care sa cuprinda cel putin 3 depozite,ficare cu cel putin 5 paleti.*/

// Am folosit implementare ca lista principala sa fie un tablou,iar lista secundara o lista simpul inalntuita

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Paleti
{
    int cod;
    struct Paleti *urmator;
} Paleti;

typedef struct Depozit
{
    char nume[100];
    Paleti *inceput;
} Depozit;

Depozit depozit[MAX];
int nr_depozite = 0;

Paleti *adauga_lista_simpla(int cod, Paleti *urmator) // adauga paleti
{
    Paleti *nou_nod = (Paleti *)malloc(sizeof(Paleti));
    nou_nod->cod = cod;
    nou_nod->urmator = urmator;
    return nou_nod;
}

Paleti *adauga_lista_simpla_sortat(Paleti *lista, Paleti *element) // adauga paleti sortati dupa cod
{
    if (lista == NULL)
    {
        return element;
    }
    Paleti *current = lista;
    Paleti *predecesor = NULL;
    while (current != NULL)
    {
        if (current->cod >= element->cod)
        {
            break;
        }
        predecesor = current;
        current = current->urmator;
    }
    if (predecesor == NULL)
    {
        lista = element;
    }
    else
    {
        predecesor->urmator = element;
    }
    element->urmator = current;
    return lista;
}

Paleti *stergere_paleti(Paleti *lista, int cod) // sterge paleti dupa cod(implicit cauta paletii pentru a-i sterge)
{
    Paleti *predecesor = NULL;
    Paleti *current = lista;
    while (current != NULL)
    {
        if (current->cod == cod)
        {
            if (predecesor == NULL)
            {
                lista = lista->urmator;
            }
            else
            {
                predecesor->urmator = current->urmator;
            }
            free(current);
            return lista;
        }
        predecesor = current;
        current = current->urmator;
    }
    return lista;
}

void adauga_depozit(char *nume, Paleti *lista) // adauga depozit si lista cu paleti in depozit
{
    Depozit *nou = (Depozit *)malloc(sizeof(Depozit));
    strncpy(nou->nume, nume, strlen(nume) + 1);
    depozit[nr_depozite] = *nou;
    depozit[nr_depozite].inceput = lista;
    nr_depozite++;
}

void sterge_paleti_dupa_cod_din_depozite(int cod) // sterge din toate depozitele paletii dupa codul dat ca parametru
{
    Paleti *aux;
    for (int i = 0; i < nr_depozite; i++)
    {
        aux = depozit[i].inceput;
        while (aux != NULL)
        {
            stergere_paleti(aux, cod);
            aux = aux->urmator;
        }
    }
}

void afiseara_depozit_si_paleti() // afiseaza multilista
{
    for (int i = 0; i < nr_depozite; i++)
    {
        printf("Nume depozit - %s -> \n", depozit[i].nume);
        Paleti *aux = depozit[i].inceput;
        while (aux != NULL)
        {
            printf("Cod : %d \n", aux->cod);
            aux = aux->urmator;
        }
    }
}

int main(void)
{
    Paleti *lista1 = adauga_lista_simpla(123, adauga_lista_simpla(234, adauga_lista_simpla(789, NULL)));
    lista1 = adauga_lista_simpla_sortat(lista1, adauga_lista_simpla(457, NULL));
    adauga_depozit("Dep1", lista1);
    Paleti *lista2 = adauga_lista_simpla(223, adauga_lista_simpla(434, adauga_lista_simpla(89, NULL)));
    lista2 = adauga_lista_simpla_sortat(lista2, adauga_lista_simpla(457, NULL));
    adauga_depozit("Dep2", lista2);
    afiseara_depozit_si_paleti();
    sterge_paleti_dupa_cod_din_depozite(457);
    printf("Afisare dupa stergere : \n");
    afiseara_depozit_si_paleti();

    free(lista1);
    free(lista2);
    return 0;
}
/*Fie un sistem de gestionare a unor produse intr-un lant de magazine.Magazinul este caracterizat print-un nume unic,
iar produsele printr-un cod numeric(max 8 cifre).Se se scrie si sa se implementeze o structura multilista adecvata
pentru gestionarea acestor magazine.Structura va avea urmatoarea componenta : Fiecare magazin reprezinta o intrare separata
intr-o lista principala,si ficare magazin contine o lista secundara ordonata dupa codul produselor din acel magazin
(cel putin o lista va fi impelementata dinamic)
Sa se implementeze structurile de date necesare si urmatoarele functionalitati :
*eliminare produs - se sterge un produs identificat dupa cod din toate magazinele

Sa se alega un exempul de lista care sa cuprinda cel putin 3 magazine,fiecare cu cel putin 5 produse.*/

// Implementare ca lista principala sa fie simplu inalntuita,iar lista secundara sa fie un tablou cu maxim 5 elemente;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct Produs // structura pentru lista secundara(statica)
{
    int cod;
} Produs;

typedef struct Magazine // structura pentru lista principala(dinamica)
{
    char nume[50];
    Produs produse[MAX];
    int ultim_ls;
    struct Magazine *urmator;
} Magazine;

Magazine *creaza_lista_magazine(char *nume, Magazine *urmator) // functie care adauga magazie in lista principala
{
    Magazine *nod_nou = (Magazine *)malloc(sizeof(Magazine));
    strncpy(nod_nou->nume, nume, strlen(nume) + 1);
    nod_nou->ultim_ls = 0;
    if (urmator == NULL)
    {
        urmator = nod_nou;
    }
    else
    {
        nod_nou->urmator = urmator;
    }
    return nod_nou;
}

void adauga_produse(Magazine *lista, int cod) // functie care adauga produse in lista secundara,lista fiind adaugata in lista principala la nodul corespunzator
{
    Magazine *lista_n = lista;
    lista_n->produse[lista_n->ultim_ls].cod = cod;
    lista_n->ultim_ls++;
}

void afisare_lista_de_magazine_cu_produse(Magazine *lista) // afiseaza multilista
{
    Magazine *aux = lista;
    while (aux != NULL)
    {
        printf("Nume magazin : %s\nCoduri : \n", aux->nume);
        for (int i = 0; i < aux->ultim_ls; i++)
        {
            printf("%d\n", aux->produse[i].cod);
        }
        aux = aux->urmator;
    }
}

void stergere_produs_din_magazine(int cod, Magazine *lista)//functia care sterge dupa cod elementele din lista secundara,parcurgand lista principala
{
    Magazine *aux = lista;
    while (aux != NULL)
    {
        for (int i = 0; i < aux->ultim_ls; i++)
        {
            if (aux->produse[i].cod == cod)
            {
                for (int j = i + 1; j < aux->ultim_ls; j++)
                {
                    aux->produse[j - 1] = aux->produse[j];
                }
                aux->ultim_ls--;
                i--;
            }
        }
        aux = aux->urmator;
    }
}

int main(void)
{
    Magazine *lista = NULL;
    lista = creaza_lista_magazine("AnaSRL", lista);
    adauga_produse(lista, 123);
    adauga_produse(lista, 567);
    adauga_produse(lista, 87939);
    adauga_produse(lista, 8737);
    adauga_produse(lista, 27378);
    lista = creaza_lista_magazine("MariaSRL", lista);
    adauga_produse(lista, 2657);
    adauga_produse(lista, 27864278);
    adauga_produse(lista, 123);
    adauga_produse(lista, 2736);
    adauga_produse(lista, 7832682);
    lista = creaza_lista_magazine("IoanaSRL", lista);
    adauga_produse(lista, 2663);
    adauga_produse(lista, 233627);
    adauga_produse(lista, 1263728);
    adauga_produse(lista, 89379);
    adauga_produse(lista, 123);
    printf("Afisare lista :\n");
    afisare_lista_de_magazine_cu_produse(lista);
    printf("Afisare dupa stergere : \n");
    stergere_produs_din_magazine(123,lista);
    afisare_lista_de_magazine_cu_produse(lista);

    free(lista);

    return 0;
}
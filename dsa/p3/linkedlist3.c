/*Fie un sistem ge gestionare a unor GPS-uri instalate pe camioane in cadrul unor firme de transport.Firma de transport este caracterizata
printr-un nume unic,iar GPS-urile print-un cod numeric(max 8 cifre).Sa se scrie si sa se implementeze o structura multilista adecvata
pentru gestionarea acestor GPS-uri.Structura va avea urmatoarea componenta : Fiecare firma de transport reprezinta o intrare separa intr-o
lista principala,si fiecare firma de transport contine o lista secundara ordonata dupa cod a GPS-urilor
(corespunzatoare acelei firme).Cel putin una din liste va fi implementata dinamic.
Sa se implementeze structurile de date necesare si urmatoarele functionalitati :
*Eliminare GPS - Se sterge un GPS indentificat dupa cod din toate firmele

Sa se alega un exemplu de lista care sa cuprinda cel putin 3 firme,fiecare cu cel putin 5 GPS-uri*/

//Lista principala dinamica,lista secundara dinamica(lista de lista)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct gps
{ // stuctura pentru lista de gps-uri alocata dinamic
    char cod[9];
    struct gps *urmator_gps;
} gps;

typedef struct firma_transport
{ // structura folosita pentru lista de fime de trasport care contine "ndul de inceput" pentru lista de gps-uri
    char nume[100];
    gps *inceput_gps;
    struct firma_transport *urmator_firma;
} firma_transport;

gps *adauga_gps(char *cod, gps *urmator) // functie pentru adaugarea unui gps intr-0 lista de gps-uri
{
    gps *nod_nou = (gps *)malloc(sizeof(gps));
    strncpy(nod_nou->cod, cod, strlen(cod) + 1);
    nod_nou->cod[strlen(cod)] = '\0';
    nod_nou->urmator_gps = urmator;
    return nod_nou;
}

firma_transport *adauga_firma(char *nume, gps *lista, firma_transport *urmator) // functie pentru crearea unei liste de firme si adauagare in fiecare nod a listei de gps-uri
{
    firma_transport *nod_nou_firma = (firma_transport *)malloc(sizeof(firma_transport));
    strncpy(nod_nou_firma->nume, nume, strlen(nume));
    nod_nou_firma->inceput_gps = lista;
    nod_nou_firma->urmator_firma = urmator;
    return nod_nou_firma;
}

gps *sterge_gps(char *cod, gps *lista) // functie de sters codul dintr-o lista de gps-uri
{
    gps *predecesor = NULL;
    gps *current = lista;
    while (current != NULL)
    {
        if (strcmp(current->cod, cod) == 0)
        {
            if (predecesor == NULL)
            {
                lista = lista->urmator_gps;
            }
            else
            {
                predecesor->urmator_gps = current->urmator_gps;
            }
            free(current);
            return lista;
        }
        predecesor = current;
        current = current->urmator_gps;
    }
    return lista;
}

firma_transport *sterge_cod_din_firme(char *cod, firma_transport *lista) // functie care sterge din toate listele secundare codul dat,cautand in lista principala
{
    firma_transport *aux = lista;
    while (aux != NULL)
    {
        gps *aux_gps = aux->inceput_gps;
        while (aux_gps != NULL)
        {
            sterge_gps(cod, aux_gps);
            aux_gps = aux_gps->urmator_gps;
        }
        aux = aux->urmator_firma;
    }
    return lista;
}

void afisare_multiliste(firma_transport *lista) // afiseaza multilista
{
    firma_transport *aux = lista;
    while (aux != NULL)
    {
        gps *aux_gps = aux->inceput_gps;
        printf("Nume : %s \n", aux->nume);
        while (aux_gps != NULL)
        {
            printf("Cod : %s\n", aux_gps->cod);
            aux_gps = aux_gps->urmator_gps;
        }
        aux = aux->urmator_firma;
    }
}

int main(void)
{
    gps *lista1 = adauga_gps("1234", adauga_gps("3458", adauga_gps("6792", adauga_gps("4738", adauga_gps("9824", NULL)))));
    gps *lista2 = adauga_gps("6623", adauga_gps("3672", adauga_gps("3458", adauga_gps("4738", adauga_gps("736718", NULL)))));
    gps *lista3 = adauga_gps("189279", adauga_gps("3626", adauga_gps("26537", adauga_gps("4738", adauga_gps("3458", NULL)))));
    firma_transport *lista = adauga_firma("MariaSRL", lista1, adauga_firma("IonSRL", lista2, adauga_firma("AlinaSRL", lista3, NULL)));
    printf("Afiseaza multilista :\n");
    afisare_multiliste(lista);
    printf("Afiseaza dupa stergere :\n");
    lista = sterge_cod_din_firme("3458", lista);
    afisare_multiliste(lista);

    free(lista1);
    free(lista2);
    free(lista3);
    free(lista);

    return 0;
}
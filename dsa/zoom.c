#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student {
    char name[10];
    struct student *next;
} student_t;

typedef struct zoom_conference {
    int ID;
    char password[10];
    struct zoom_conference *next;
    struct student *first;
} zoom_conference_t;

zoom_conference_t *head_conf = NULL;

void add_zoom_list(zoom_conference_t **head_conf, zoom_conference_t *node) {
    if((*head_conf) == NULL) {
        *head_conf = node;
        return;
    }

    zoom_conference_t *temp;
    temp = *head_conf;

    while(temp->next!=NULL)
        temp = temp->next;

    temp->next = node;
}

void add_student_list(int i, zoom_conference_t **head_conf, student_t *node) {
    zoom_conference_t *temp;
    temp = *head_conf;

    while(i>1) {
        temp = temp->next;
        i--;
    }

    if(temp->first==NULL || strcmp(node->name, temp->first->name)<0 ) {
        node->next = temp->first;
        temp->first = node;
        return;
    }

    student_t *aux;
    aux = temp->first;

    while(aux->next!=NULL && (strcmp(aux->next->name, node->name)<0))
        aux = aux->next;

    node->next = aux->next;
    aux->next = node;
}

void delete_node(student_t **root, student_t *node) {
    if((*root) == node) {
        (*root) = (*root)->next;
        free(node);
        return;
    }

    student_t *aux;
    aux = (*root);

    while(aux->next!=node)
        aux = aux->next;

    aux->next = aux->next->next;
    free(node);
}

void acceptance(char letter[], int no_conf, zoom_conference_t *head_conf) {
    for(int i=1;i<=no_conf;i++) {
        student_t *temp;
        temp = head_conf->first;

        while(temp) {
            char *s = strstr(temp->name, letter);
            if(s-temp->name+1 == 1) {
                student_t *to_delete;
                to_delete = temp;
                temp = temp->next;
                delete_node(&head_conf->first, to_delete);
            }
            else
                temp = temp->next;
        }

        head_conf = head_conf->next;
    }
}

void print_zoom_list() {
    zoom_conference_t *temp;
    temp = head_conf;

    while(temp) {
        printf("%d %s\n", temp->ID, temp->password);
        printf("Students: ");
        student_t *aux = temp->first;
        while(aux) {
            printf("%s ", aux->name);
            aux = aux->next;
        }
        printf("\n");
        temp = temp->next;
    }
}

int main() {
    int conf_no;

    FILE *f = fopen("zoom_doc.txt","r");
    if(!f) {
        printf("could not open file\n");
        exit(1);
    }

    //printf("Please entry how many zoom conference meeting there will be: ");
    fscanf(f,"%d", &conf_no);

    for(int i=1;i<=conf_no;i++) {
        zoom_conference_t *node;
        node = (zoom_conference_t*) malloc(sizeof(zoom_conference_t));

        if(node==NULL) {
            printf("error at malloc");
            exit(1);
        }

        //printf("For conference %d enter the meeting ID and password: ", i);

        fscanf(f,"%d", &node->ID);
        fscanf(f,"%s", node->password);
        node->first = NULL;
        node->next = NULL;

        add_zoom_list(&head_conf, node);
    }

    int no_participants;
    for(int i=1;i<=conf_no;i++) {
        fscanf(f,"%d", &no_participants);

        for(int j=1;j<=no_participants;j++) {
            student_t *node;
            node = (student_t*) malloc(sizeof(student_t));
            if(node == NULL) {
                printf("error at mallc");
                exit(1);
            }

            fscanf(f,"%s",node->name);
            node->next = NULL;

            add_student_list(i, &head_conf, node);
        }
    }

    print_zoom_list();

    char letter[1];
    fscanf(f, "%s", letter);
    printf("%s\n",letter);

    acceptance(letter, conf_no, head_conf);
    print_zoom_list();

    return 0;
}
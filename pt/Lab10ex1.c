//dynamic data structures

/*
pasul 1:
    n->next = p->next;
pasul 2:
    p->next = n;

primul elem:
    n->next = root->next;
    root = r;

stergere element p:
    r->next ==p;
    r->next = p->next;
    free(p);

stergere primul elem:
    p = root;
    root = root->next;
    free(p);

void add(char name[100], int age, ST *root){
    ST *p = root;
    while(p != NULL && p->next != NULL && p->next->age <= age)
         p = p->next;
    if(p == root){
        if(root->age > age)
            insert_before_root;
        else
            insert_after_root;
    }
}

stergere toate elemente din lista
 recursiv:
    if(p != NULL){
        del(p->next);
        free(p);
    }
 iterativ:
    while(p != NULL){
        
    }

    */
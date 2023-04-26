#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STORE_NAME 50
#define MAX_CODE_LENGTH 9

typedef struct Product {
    char code[MAX_CODE_LENGTH];
    struct Product *next;
} Product;

typedef struct Store {
    char name[MAX_STORE_NAME];
    Product *products;
    struct Store *next;
} Store;

void addStore(Store **head, char *name) {
    Store *newStore = (Store*) malloc(sizeof(Store));
    strcpy(newStore->name, name);
    newStore->products = NULL;
    newStore->next = *head;
    *head = newStore;
}

void addProduct(Store *store, char *code) {
    Product *newProduct = (Product*) malloc(sizeof(Product));
    strcpy(newProduct->code, code);
    newProduct->next = NULL;

    if (store->products == NULL) {
        store->products = newProduct;
    } else {
        Product *cur = store->products;
        Product *prev = NULL;

        while (cur != NULL && strcmp(cur->code, code) < 0) {
            prev = cur;
            cur = cur->next;
        }

        if (prev == NULL) {
            newProduct->next = store->products;
            store->products = newProduct;
        } else {
            newProduct->next = prev->next;
            prev->next = newProduct;
        }
    }
}

void removeProduct(Store *store, char *code) {
    Product *cur = store->products;
    Product *prev = NULL;

    while (cur != NULL && strcmp(cur->code, code) != 0) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Product with code %s not found in store %s\n", code, store->name);
        return;
    }

    if (prev == NULL) {
        store->products = cur->next;
    } else {
        prev->next = cur->next;
    }

    free(cur);
}

void printMultilist(Store *head) {
    printf("Multilist:\n");

    while (head != NULL) {
        printf("Store %s:\n", head->name);

        Product *cur = head->products;

        while (cur != NULL) {
            printf("  Product code: %s\n", cur->code);
            cur = cur->next;
        }

        head = head->next;
    }
}

int main() {
    // Create initial multilist with 4 stores, each with 4 products
    Store *head = NULL;

    addStore(&head, "Store 1");
    addProduct(head, "1234");
    addProduct(head, "2345");
    addProduct(head, "3456");
    addProduct(head, "4567");

    addStore(&head, "Store 2");
    addProduct(head, "2345");
    addProduct(head, "3456");
    addProduct(head, "4567");
    addProduct(head, "5678");

    addStore(&head, "Store 3");
    addProduct(head, "3456");
    addProduct(head, "4567");
    addProduct(head, "5678");
    addProduct(head, "6789");

    addStore(&head, "Store 4");
    addProduct(head, "4567");
    addProduct(head, "5678");
    addProduct(head, "6789");
    addProduct(head, "7890");

    // Print initial multilist
    printMultilist(head);
    printMultilist(head);

}
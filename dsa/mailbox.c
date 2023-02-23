#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Message {
    int priority;
    char destination[100];
    char content[1000];
    struct Message *next;
};

struct Mailbox {
    struct Message *first;
};

void Initialize(struct Mailbox *mb) {
    mb->first = NULL;
}

void Send_message(struct Mailbox *mb, int priority, char *destination, char *content) {
    struct Message *new_message = (struct Message*)malloc(sizeof(struct Message));
    new_message->priority = priority;
    strcpy(new_message->destination, destination);
    strcpy(new_message->content, content);

    if (priority == 1) {
        new_message->next = mb->first;
        mb->first = new_message;
    } else {
        struct Message *current = mb->first;
        struct Message *previous = NULL;
        while (current != NULL && strcmp(current->destination, destination) < 0) {
            previous = current;
            current = current->next;
        }

        if (previous == NULL) {
            new_message->next = mb->first;
            mb->first = new_message;
        } else {
            new_message->next = previous->next;
            previous->next = new_message;
        }
    }
}

void Receive_message(struct Mailbox *mb, char *destination) {
    struct Message *current = mb->first;
    struct Message *previous = NULL;
    while (current != NULL && strcmp(current->destination, destination) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("No messages for destination: %s\n", destination);
        return;
    }

    printf("Priority: %d\nDestination: %s\nContent: %s\n", current->priority, current->destination, current->content);

    if (previous == NULL) {
        mb->first = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

void Display(struct Mailbox *mb) {
    struct Message *current = mb->first;
    while (current != NULL) {
        if (current->priority == 0) {
            printf("Destination: %s\nContent: %s\n", current->destination, current->content);
        }
        current = current->next;
    }
}

int main() {
    struct Mailbox box;
    Initialize(&box);

    Send_message(&box, 1, "Ana", "Urgent message for Ana");
    Send_message(&box, 0, "Ionel", "Usual message for Ionel");
    Send_message(&box, 0, "Maria", "Usual message for Maria");
    Send_message(&box, 1, "Ionel", "Urgent message for Ionel");

    Receive_message(&box, "Ionel");

    Display(&box);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

// Trie node structure
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool is_end_of_word;
};

// Initialize a new Trie node
struct TrieNode* initialize_node() {
    struct TrieNode* new_node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    new_node->is_end_of_word = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        new_node->children[i] = NULL;
    }

    return new_node;
}

// Insert a new word into the Trie
void insert_word(struct TrieNode* root, char* word) {
    int n = strlen(word);
    struct TrieNode* current_node = root;

    for (int i = 0; i < n; i++) {
        int index = word[i] - 'a';

        if (!current_node->children[index]) {
            current_node->children[index] = initialize_node();
        }

        current_node = current_node->children[index];
    }

    current_node->is_end_of_word = true;
}

// Recursively print all the words in the Trie in alphabetical order
void print_words(struct TrieNode* node, char* buffer, int size) {
    if (node->is_end_of_word) {
        buffer[size] = '\0';
        printf("%s\n", buffer);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            buffer[size] = i + 'a';
            print_words(node->children[i], buffer, size + 1);
        }
    }
}

// Print all the words in the Trie in alphabetical order
void print_alphabetical(struct TrieNode* root) {
    char buffer[100];
    print_words(root, buffer, 0);
}

// Test program
int main(void) {
    struct TrieNode* root = initialize_node();
    insert_word(root, "hello");
    insert_word(root, "world");
    insert_word(root, "cat");
    insert_word(root, "dog");
    insert_word(root, "apple");
    insert_word(root, "banana");
    insert_word(root, "kilogram");
    insert_word(root, "velociraptor");
    insert_word(root, "zebra");
    insert_word(root, "elephant");
    insert_word(root, "helicopter");

    printf("Words in alphabetical order:\n");
    print_alphabetical(root);

    return 0;
}

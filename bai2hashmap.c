#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 100000

typedef struct node {
    int key;
    int value;
    struct node *next;
}Node_t;

struct node *hash_table[MAX_KEYS];

int hash_function(int key) {
    return key % MAX_KEYS;
}

void insert(int key, int value) {
    int index = hash_function(key);

    struct node *new_node = malloc(sizeof(struct node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

int find(int key) {
    int index = hash_function(key);

    struct node *ptr = hash_table[index];
    while (ptr != NULL && ptr->key != key) {
        ptr = ptr->next;
    }

    if (ptr != NULL) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int key;
    char cmd[10];

    while (scanf("%d", &key) == 1 && key != (int)'*') {

        insert(key, 1);

    }

    while (scanf("%s", cmd) == 1 && strcmp(cmd, "***") != 0) {
        scanf("%d", &key);
        if (strcmp(cmd, "find") == 0) {
            printf("%d\n", find(key));
        } else if (strcmp(cmd, "insert") == 0) {
            int k = find(key);
            if (k == 0)
            {
            insert(key, 1);
            printf("1\n");
            }
            else printf("0\n");
        }
    }

    return 0;
}

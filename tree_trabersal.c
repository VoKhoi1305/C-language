#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int id;
    struct node* firstChild;
    struct node* nextSibling;
} Node_t, *Root_t;

Node_t* NewNode(int id) {
    Node_t* new_node = (Node_t*)malloc(sizeof(Node_t));
    if (new_node == NULL)
        return NULL;

    new_node->id = id;
    new_node->firstChild = NULL;
    new_node->nextSibling = NULL;
    return new_node;
}

Node_t* getNode(Node_t* root, int id) {
    if (root != NULL) {
        if (root->id == id) {
            return root;
        } else {
            Node_t* foundChild = getNode(root->firstChild, id);
            if (foundChild != NULL) {
                return foundChild;
            }
            Node_t* foundSibling = getNode(root->nextSibling, id);
            if (foundSibling != NULL) {
                return foundSibling;
            }
        }
    }
    return NULL;
}

void makeRoot(Node_t** tree, int id) {
    *tree = NewNode(id);
}

void insert(Node_t* root, int u, int v) {
    Node_t* parent = getNode(root, v);
    if (parent != NULL) {
        Node_t* new_node = NewNode(u);
        if (new_node != NULL) {
            if (parent->firstChild == NULL) {
                parent->firstChild = new_node;
            } else {
                Node_t* current = parent->firstChild;
                while (current->nextSibling != NULL) {
                    current = current->nextSibling;
                }
                current->nextSibling = new_node;
            }
        }
    }
}

void preOrder(Node_t* tree) {
    if (tree != NULL) {
        printf("%d ", tree->id);
        Node_t* p= tree->firstChild;
        while(p!= NULL)
        {
            preOrder(p);
            p=p->nextSibling;
        }
    }
}

void inOrder(Node_t* tree) {
    if (tree != NULL) {
        Node_t *p=tree->firstChild;
        inOrder(p);
        printf("%d ", tree->id);
        if(p!= NULL)
            p=p->nextSibling;
        while(p!= NULL){
            inOrder(p);
            p = p->nextSibling;
        }
    }
}

void postOrder(Node_t* tree) {
    if (tree != NULL) {
            Node_t *p= tree->firstChild;
       while(p!= NULL)
       {
           postOrder(p);
           p = p->nextSibling;
       }
        printf("%d ", tree->id);
    }
}

int main() {
    char action[100];
    Node_t* tree = NULL;
    int u, v;

    while (scanf("%s", action) && strcmp(action, "*") != 0) {
        if (strcmp(action, "MakeRoot") == 0) {
            scanf("%d", &u);
            makeRoot(&tree, u);
        } else if (strcmp(action, "Insert") == 0) {
            scanf("%d %d", &u, &v);
            insert(tree, u, v);
        } else if (strcmp(action, "PreOrder") == 0) {
            preOrder(tree);
            printf("\n");
        } else if (strcmp(action, "InOrder") == 0) {
            inOrder(tree);
            printf("\n");
        } else if (strcmp(action, "PostOrder") == 0) {
            postOrder(tree);
            printf("\n");
        }
    }

    return 0;
}

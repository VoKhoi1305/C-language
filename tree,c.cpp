#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int key;
    struct node* left;
    struct node* right;
} Node_t, *Root_t;

Node_t* newNode(int data) {
    Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
    if (newNode == NULL)
        return NULL;

    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node_t* timkiem(Node_t* root, int u) {
    if (root != NULL) {
        if (root->key == u) {
            return root;
        } else {
            Node_t* foundLeft = timkiem(root->left, u);
            Node_t* foundRight = timkiem(root->right, u);
            if (foundLeft != NULL) {
                return foundLeft;
            }
            if (foundRight != NULL) {
                return foundRight;
            }
        }
    }
    return NULL;
}

void makeRoot(Node_t** tree, int u) {
    *tree = newNode(u);
}

void Inorder(Node_t* tree) {
    if (tree != NULL) {
        Inorder(tree->left);
        printf("%d ", tree->key);
        Inorder(tree->right);
    }
}

void Preorder(Node_t* tree) {
    if (tree != NULL) {
        printf("%d ", tree->key);
        Preorder(tree->left);
        Preorder(tree->right);
    }
}

void Postorder(Node_t* tree) {
    if (tree != NULL) {
        Postorder(tree->left);
        Postorder(tree->right);
        printf("%d ", tree->key);
    }
}


Node_t* insert(Node_t* root, int u) {
    if (root == NULL) {
        return newNode(u);
    }
    if (u < root->key) {
        root->left = insert(root->left, u);
    } else if (u > root->key) {
        root->right = insert(root->right, u);
    }
    return root;
}


int main() {
    char slc[100];
    Node_t* tree = NULL;
    int u, v;
    scanf("%s", slc);
    scanf("%d", &u);
    makeRoot(&tree,u);
    while (scanf("%s", slc) && strcmp(slc, "#") != 0) {
            if (strcmp(slc, "insert") == 0) {
            scanf("%d", &u);
            insert(tree, u);
        } /*else if (strcmp(slc, "preorder") == 0) {
            Preorder(tree);
            printf("\n");
        } else if (strcmp(slc, "inorder") == 0) {
            Inorder(tree);
            printf("\n");
        } else if (strcmp(slc, "postorder") == 0) {
            Postorder(tree);
            printf("\n");
        }*/
    }
     Preorder(tree);
            printf("\n");
            return 0;
}



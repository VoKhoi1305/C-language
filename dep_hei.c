#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int id;
    struct node* parent;
    struct node* firstChild;
    struct node* nextSibling;
} Node_t, *Root_t;

Node_t* NewNode(int id) {
    Node_t* new_node = (Node_t*)malloc(sizeof(Node_t));
    if (new_node == NULL)
        return NULL;

    new_node->id = id;
    new_node->parent = NULL;
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
        Node_t* existingNode = getNode(root, u);
        if (existingNode == NULL) {
            Node_t* new_node = NewNode(u);
            if (new_node != NULL) {
                new_node->parent = parent;
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
}

int height(Node_t* root) {
  if (root == NULL) {
    return 0;
  }

  int max_height = 0;
  for (Node_t* child = root->firstChild; child != NULL; child = child->nextSibling) {
    int child_height = height(child);
    if (child_height > max_height) {
      max_height = child_height;
    }
  }

  return max_height + 1;
}

int depth(Node_t* node) {
  int d = 0;
  Node_t* current = node;

  while (current != NULL) {
    d++;
    current = current->parent;
  }
  return d;
}

int main() {
    char action[100];
    Node_t* tree = NULL;
    int u, v;

    scanf("%s", action);
    if (strcmp(action, "MakeRoot") == 0) {
        scanf("%d", &u);
        makeRoot(&tree, u);
    }

    while (scanf("%s", action) && strcmp(action, "*") != 0) {
        if (strcmp(action, "Insert") == 0) {
            scanf("%d %d", &u, &v);
            insert(tree, u, v);
        } else if (strcmp(action, "Height") == 0) {
            scanf("%d", &u);
            printf("%d\n", height(getNode(tree, u)));
        } else if (strcmp(action, "Depth") == 0) {
            scanf("%d", &u);
            printf("%d\n", depth(getNode(tree, u)));
        }
    }

    return 0;
}

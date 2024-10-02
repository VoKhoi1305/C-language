#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    char key;
    struct Node *left, *right;
};

struct Node* newNode(char key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, char key) {
    if (root == NULL) return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

struct Node* delete(struct Node* root, char key) {
    if (root == NULL) return root;
    if (key < root->key)
        root->left = delete(root->left, key);
    else if (key > root->key)
        root->right = delete(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = root->right;
        while (temp && temp->left != NULL)
            temp = temp->left;
        root->key = temp->key;
        root->right = delete(root->right, temp->key);
    }
    return root;
}

void printPostorder(struct Node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%c ", node->key);
}

int main() {
    struct Node* root = NULL;
    char s[20];
    while(scanf("%s",s) && strcmp(s,"#") !=0){
    	if(strcmp(s,"insert")==0){
    		char u;
    		scanf("%c",u);
    		insert(root,u);
		}
		else if(strcmp(s,"del")==0){
			char u;
    		scanf("%c",u);
    		delete(root,u);
		}
	}
    printPostorder(root);

    return 0;
}

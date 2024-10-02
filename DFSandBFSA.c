
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 5
#define MAX_NUM_VERTICES 5758
typedef struct {
    int **adjMatrix;
    int numVertices;
} Graph;


Graph* newGraph(int numVertices) {
    Graph *G = malloc(sizeof(Graph));
    G->numVertices = numVertices;
    G->adjMatrix = malloc(sizeof(int*) * numVertices);
    for (int i = 0; i < numVertices; i++) {
        G->adjMatrix[i] = calloc(numVertices, sizeof(int));
    }
    return G;
}


void addEdge(Graph *G, int src, int dest) {
    G->adjMatrix[src][dest] = 1;
    G->adjMatrix[dest][src] = 1;
}


int numConnectedComponents(Graph *G) {
    int *visited = calloc(G->numVertices, sizeof(int));
    int num_components = 0;
    for (int i = 0; i < G->numVertices; i++) {
        if (!visited[i]) {
            num_components++;
            dfs(G, i, visited);
        }
    }
    free(visited);
    return num_components;
}


void dfs(Graph *G, int vertex, int *visited) {
    visited[vertex] = 1;
    for (int i = 0; i < G->numVertices; i++) {
        if (G->adjMatrix[vertex][i] && !visited[i]) {
            dfs(G, i, visited);
        }
    }
}


int findWord(char **words, int num_words, char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i], word) == 0) {
            return i;
        }
    }
    return -1;
}


int* bfs(Graph *G, int start, int end) {
    int *visited = calloc(G->numVertices, sizeof(int));
    int *queue = malloc(sizeof(int) * G->numVertices);
    int *prev = calloc(G->numVertices, sizeof(int));
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front != rear) {
        int current = queue[front++];
        for (int i = 0; i < G->numVertices; i++) {
            if (G->adjMatrix[current][i] && !visited[i]) {
                visited[i] = 1;
                prev[i] = current;
                queue[rear++] = i;
                if (i == end) {
                    free(visited);
                    free(queue);
                    return prev;
                }
            }
        }
    }

    free(visited);
    free(queue);
    free(prev);
    return NULL;
}
void printPath(char **words, int *path, int start, int end) {
    if (path[end] == -1) {
        printf("khong co duong di tu %s den %s\n", words[start], words[end]);
        return;
    }
    int *reverse_path = malloc(sizeof(int) * MAX_NUM_VERTICES);
    int num_vertices = 0;
    int current = end;
    while (current != start) {
        reverse_path[num_vertices++] = current;
        current = path[current];
    }
    reverse_path[num_vertices++] = start;
    for (int i = num_vertices-1; i >= 0; i--) {
        printf("%s ", words[reverse_path[i]]);
    }
    printf("\n");
    free(reverse_path);
}

int numDiffs(char *word1, char *word2) {
    int num_diffs = 0;
    for (int i = 0; i < MAX_WORD_LEN; i++) {
        if (word1[i] != word2[i]) {
            num_diffs++;
        }
    }
    return num_diffs;
}
int main() {

   FILE *fp = fopen("F:\\fiveletterwords.txt", "r");
char **words = malloc(sizeof(char*) * MAX_NUM_VERTICES);
int num_words = 0;
char word[MAX_WORD_LEN+1];
while (fscanf(fp, "%s", word) == 1) {
    words[num_words] = strdup(word);
    num_words++;
}
fclose(fp);
Graph *G = newGraph(num_words);
    for (int i = 0; i < num_words; i++) {
        for (int j = i+1; j < num_words; j++) {
            if (numDiffs(words[i], words[j]) == 1) {
                addEdge(G, i, j);
            }
        }
    }

    int num_components = numConnectedComponents(G);
    printf("so thanh phan lien thong la: %d\n", num_components);

     char word1[MAX_WORD_LEN+1], word2[MAX_WORD_LEN+1];
    printf("nhap 2 tu 5 chu cai can tim ");
    scanf("%s %s", word1, word2);
    int start = findWord(words, num_words, word1);
    int end = findWord(words, num_words, word2);
    int *path = bfs(G, start, end);
    printPath(words, path, start, end);


    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
    for (int i = 0; i < num_words; i++) {
        free(G->adjMatrix[i]);
    }
    free(G->adjMatrix);
    free(G);
    free(path);

    return 0;
}


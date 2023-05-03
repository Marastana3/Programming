#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_LEN 4

//helper function that returns the vertex with the minimum key value that is not yet in the MST
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < MAX_LEN; ++v)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}
//helper function that prints the edges in the MST
void printMST(int parent[], int graph[MAX_LEN][MAX_LEN]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < MAX_LEN; ++i)
        printf("%d - %d \t%d \n", parent[i] + 1, i + 1, graph[i][parent[i]]);
}

void primMST(int graph[MAX_LEN][MAX_LEN]) {
    int parent[MAX_LEN];
    int key[MAX_LEN];
    bool mstSet[MAX_LEN];
    for (int i = 0; i < MAX_LEN; ++i)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    for (int i = 0; i < MAX_LEN - 1; ++i) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 1; v < MAX_LEN; ++v)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
}

int main(void) {
    //represents the adjancency matrix for an undirected weighted graph (for the hw graph)
    int graph[MAX_LEN][MAX_LEN] = {
        { 0, 5, 6, 0 },
        { 5, 0, 9, 0 },
        { 6, 9, 0, 4 },
        { 0, 0, 4, 0 },
    };
    primMST(graph);
    return 0;
}
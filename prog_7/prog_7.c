#include <stdio.h>

#define N 5
#define INF 9999

int graph[N][N] = {
    {0, 10, 0, 0, 5},
    {10, 0, 1, 0, 2},
    {0, 1, 0, 4, 0},
    {0, 0, 4, 0, 3},
    {5, 2, 0, 3, 0}
};

int findMin(int dist[], int visited[]) {
    int min = INF, idx = 0;
    for (int i = 0; i < N; i++)
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            idx = i;
        }
    return idx;
}

void dijkstra(int start) {
    int dist[N], visited[N] = {0};
    
    for (int i = 0; i < N; i++) dist[i] = INF;
    dist[start] = 0;
    
    for (int c = 0; c < N - 1; c++) {
        int u = findMin(dist, visited);
        visited[u] = 1;
        
        for (int v = 0; v < N; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    
    printf("Node\tDistance\n");
    for (int i = 0; i < N; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    dijkstra(0);
    return 0;
}
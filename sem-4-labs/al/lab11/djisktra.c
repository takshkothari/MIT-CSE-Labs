#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define max 9
int n, graph[max][max];
int minDistance(int dist[], bool sptSet[]) {
	int min = INT_MAX, min_index;
	for (int v = 0; v < n; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void printSolution(int dist[]) {
	printf("\ndistance from source\n");
	for (int i = 0; i < n; i++)
		printf("%d: %d\n", i, dist[i]);
}

void dijkstra(int graph[n][n], int src) {
	int dist[n]; 
	bool sptSet[n];
	for (int i = 0; i < n; i++)
		dist[i] = INT_MAX, sptSet[i] = false;
	dist[src] = 0;
	for (int count = 0; count < n - 1; count++) {
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < n; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	printSolution(dist);
}

void main() {
	int i, j, x;
    printf("enter number of vertices: ");
    scanf("%d", &n);
    printf("\nenter adjacency matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }
    printf("\nenter source: ");
    scanf("%d", &x);
	dijkstra(graph, x);
}
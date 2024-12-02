#include <stdio.h>
#define INF 99999
#define N 12 // Número de bairros, conforme o grafo

void floydWarshall(int graph[N][N]) {
    int dist[N][N];
// Inicializa a matriz de distâncias com os valores do grafo
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = graph[i][j];
        }
    }
// Aplica o algoritmo de Floyd-Warshall
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
// Imprime a matriz de menor caminho
    printf("Matriz de menor caminho entre os bairros:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dist[i][j] == INF) {
                printf("%4s", "INF");
            } else {
                printf("%4d", dist[i][j]);
            }
        }
        printf("\n");
    }
}
int main() {
// Grafo com as distâncias, INF representa ausência de conexão direta
    int graph[N][N] = {
        {0, 2, INF, INF, 3, INF, INF, INF, INF, INF, INF, INF}, // A
        {2, 0, 3, INF, INF, 1, INF, INF, INF, INF, INF, INF}, // B
        {INF, 3, 0, 1, INF, INF, 2, INF, INF, INF, INF, INF}, // C
        {INF, INF, 1, 0, INF, INF, INF, 5, INF, INF, INF, INF}, // D
        {3, INF, INF, INF, 0, 4, INF, INF, 4, INF, INF, INF}, // E
        {INF, 1, INF, INF, 4, 0, 3, INF, INF, 2, INF, INF}, // F
        {INF, INF, 2, INF, INF, 3, 0, 3, INF, INF, 4, INF}, // G
        {INF, INF, INF, 5, INF, INF, 3, 0, INF, INF, INF, 3}, // H
        {INF, INF, INF, INF, 4, INF, INF, INF, 0, 3, INF, INF}, // I
        {INF, INF, INF, INF, INF, 2, INF, INF, 3, 0, 3, 1}, // J
        {INF, INF, INF, INF, INF, INF, 4, INF, INF, 3, 0, INF}, // K
        {INF, INF, INF, INF, INF, INF, INF, 3, INF, 1, INF, 0} // L
    };
    
floydWarshall(graph);

return 0;
}
/*
Algoritmo de Dijkstra em C

Descrição:
O algoritmo de Dijkstra é utilizado para encontrar o caminho mais curto entre dois vértices em um grafo ponderado (com pesos nas arestas) e sem ciclos negativos.
A ideia básica é manter um conjunto de vértices cuja distância mínima do vértice de origem é já conhecida e ir expandindo esse conjunto baseando-se no vértice de menor distância disponível.

Passos do algoritmo:
1. Inicialize distâncias mínimas de todos os vértices como infinito e distância do vértice de origem como 0.
2. Enquanto existirem vértices não visitados:
   a. Escolha o vértice com a menor distância (inicialmente, o vértice de origem).
   b. Atualize a distância dos vértices adjacentes ao vértice escolhido.
   c. Marque o vértice escolhido como visitado.
3. Repita os passos até que todos os vértices sejam visitados.

Estrutura do Grafo:
- O grafo é representado por uma matriz de adjacências, onde o valor na célula [i][j] representa o peso da aresta entre os vértices i e j.
*/

#include <stdio.h>
#include <limits.h>

#define V 9 // Número de vértices no grafo

// Função para encontrar o vértice com a distância mínima, dentre o conjunto de vértices ainda não incluídos no caminho mais curto
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Função para imprimir o array de distâncias calculado
void printSolution(int dist[]) {
    printf("Vértice \t Distância da Origem\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Função que implementa o algoritmo de Dijkstra para um grafo representado por matriz de adjacência
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // dist[i] será a distância mínima de src até i
    int sptSet[V]; // sptSet[i] será verdadeiro se o vértice i estiver incluído no caminho mais curto da origem até i

    // Inicializa todas as distâncias como INFINITO e stpSet[] como falso
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;

    // Distância do vértice de origem de si mesmo é sempre 0
    dist[src] = 0;

    // Encontre o caminho mais curto para todos os vértices
    for (int count = 0; count < V - 1; count++) {
        // Escolha o vértice de distância mínima do conjunto de vértices ainda não processados
        int u = minDistance(dist, sptSet);

        // Marque o vértice escolhido como processado
        sptSet[u] = 1;

        // Atualize o valor da distância dos vértices adjacentes do vértice escolhido
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Imprime o array de distâncias construído
    printSolution(dist);
}

// Função principal para testar as funções acima
int main() {
    /* Exemplo de grafo representado por uma matriz de adjacências */
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}
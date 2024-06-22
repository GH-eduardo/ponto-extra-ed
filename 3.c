// Este código cria um grafo e executa a busca em profundidade (DFS) a partir de um vértice específico.
// Ele demonstra a implementação básica de um grafo usando listas de adjacências e a execução do algoritmo DFS.

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para a lista de adjacências
typedef struct adjListNode {
    int dest;
    struct adjListNode* next;
} AdjListNode;

// Definição da estrutura para a lista de adjacências
typedef struct adjList {
    AdjListNode *head; 
} AdjList;

// Definição da estrutura do grafo
typedef struct graph {
    int V;
    AdjList* array;
} Graph;

// Função para criar um novo nó da lista de adjacência
AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*) malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo de V vértices
Graph* createGraph(int V) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;

    // Cria um array de listas de adjacências. Tamanho do array será V
    graph->array = (AdjList*) malloc(V * sizeof(AdjList));

    // Inicializa cada lista de adjacência como vazia, fazendo head = NULL
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Adiciona uma aresta ao grafo não direcionado
void addEdge(Graph* graph, int src, int dest) {
    // Adiciona uma aresta de src a dest. Um novo nó é adicionado à lista de adjacências de src
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Função DFS recursiva
void DFSUtil(Graph* graph, int v, int visited[]) {
    // Marca o nó atual como visitado e imprime
    visited[v] = 1;
    printf("%d ", v);

    // Recur para todos os vértices adjacentes a este vértice
    AdjListNode* node = graph->array[v].head;
    while (node != NULL) {
        if (!visited[node->dest])
            DFSUtil(graph, node->dest, visited);
        node = node->next;
    }
}

// A função DFS. Usa DFSUtil()
void DFS(Graph* graph, int startVertex) {
    // Marca todos os vértices como não visitados
    int *visited = (int*) malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    // Chama a função auxiliar DFSUtil para imprimir a DFS do grafo
    DFSUtil(graph, startVertex, visited);
}

int main() {
    // Criação do grafo dado no exemplo
    int V = 5; // Número de vértices
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Executa a DFS a partir do vértice 0
    printf("DFS a partir do vértice 0:\n");
    DFS(graph, 0);

    return 0;
}
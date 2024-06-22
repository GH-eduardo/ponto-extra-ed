// Estrutura do Grafo

// Estrutura AdjListNode para representar um nó na lista de adjacências.
// Estrutura AdjList para a lista de adjacências.
// Estrutura Graph contendo um array de AdjList.
// Criar Grafo

// Alocar memória para o grafo.
// Inicializar as listas de adjacências para cada vértice.
// Adicionar Aresta

// Criar um novo nó na lista de adjacências do vértice de origem.
// Adicionar o nó de forma que a lista permaneça ordenada (opcional).
// Remover Aresta

// Localizar o vértice de destino na lista de adjacências do vértice de origem.
// Remover o nó correspondente da lista.
// Mostrar Grafo

// Para cada vértice, imprimir sua lista de adjacências.

#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó na lista de adjacências
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Estrutura para a lista de adjacências
struct AdjList {
    struct AdjListNode* head;
};

// Estrutura para o grafo
struct Graph {
    int V;
    struct AdjList* array;
};

// Função para criar um novo nó de adjacência
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo de V vértices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Adiciona aresta ao grafo
void addEdge(struct Graph* graph, int src, int dest) {
    // Adiciona uma aresta de src para dest
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Remove aresta do grafo
void removeEdge(struct Graph* graph, int src, int dest) {
    struct AdjListNode* temp = graph->array[src].head;
    struct AdjListNode* prev = NULL;
    while (temp != NULL && temp->dest != dest) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return; // Aresta não encontrada
    if (prev == NULL) // Aresta é a primeira da lista
        graph->array[src].head = temp->next;
    else
        prev->next = temp->next;
    free(temp);
}

// Função para imprimir o grafo
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Lista de adjacências do vértice %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main() {
    int V = 5; // Número de vértices no grafo
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    removeEdge(graph, 1, 3);
    printf("\nGrafo após remover a aresta 1-3:\n");
    printGraph(graph);

    return 0;
}
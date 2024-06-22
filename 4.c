/*
Busca em Largura (BFS - Breadth-First Search) em C

Descrição:
A busca em largura é um algoritmo para percorrer ou buscar elementos em uma estrutura de dados de grafo. 
Partindo de um nó inicial, a BFS explora todos os vizinhos deste nó no nível atual antes de mover-se para os nós no próximo nível de profundidade.

Passos do algoritmo:
1. Inicialize uma fila Q.
2. Marque o nó inicial como visitado e insira-o em Q.
3. Enquanto Q não estiver vazia:
   a. Remova um elemento de Q e o chame de 'v'.
   b. Para cada nó 'w' adjacente a 'v' que não foi visitado:
      i. Marque 'w' como visitado.
      ii. Insira 'w' em Q.

Estrutura do Grafo:
- O grafo é representado por listas de adjacências, onde cada nó possui uma lista contendo seus vizinhos diretos.

*/

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para um nó em uma lista de adjacências
typedef struct node {
    int vertex;
    struct node* next;
} Node;

// Definição da estrutura para o grafo
typedef struct graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

// Função para criar um nó
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Função para adicionar aresta
void addEdge(Graph* graph, int src, int dest) {
    // Adiciona aresta de src para dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Adiciona aresta de dest para src, para grafos não direcionados
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Função para realizar a BFS no grafo
void BFS(Graph* graph, int startVertex) {
    int* visited = graph->visited;
    int numVertices = graph->numVertices;

    int* queue = malloc(numVertices * sizeof(int));
    int front = 0;
    int rear = -1;

    // Marca o nó inicial como visitado e o enfileira
    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("Visitado %d\n", currentVertex);

        Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }

    free(queue);
}

// Função principal para demonstrar a operação de BFS
int main() {
    Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    BFS(graph, 0);

    return 0;
}
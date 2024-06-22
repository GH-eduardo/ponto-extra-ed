// Algoritmo para inserir uma nova rua (aresta) entre duas interseções (nós) em um grafo representado por uma matriz de adjacências:

// - estrutura do grafo, incluindo o número de nós e a matriz de adjacências.
// - função para inicializar o grafo, definindo o número de nós e inicializando a matriz de adjacências com zeros, indicando que não há ruas conectando as interseções inicialmente.
// - função para adicionar uma rua (aresta) entre duas interseções (nós). Esta função:
//    a. Recebe os índices dos dois nós entre os quais a rua será inserida e o peso da aresta, se o grafo for ponderado.
//    b. Atualiza a matriz de adjacências para refletir a inserção da nova rua. Isso é feito definindo a célula correspondente na matriz (para ambos os nós, se o grafo for não direcionado) para 1 (ou para o peso da aresta, se o grafo for ponderado).
// - Cria uma função para imprimir a matriz de adjacências, para facilitar a visualização do grafo após a inserção de ruas.

#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um grafo
typedef struct {
    int numNos;
    int **adjMatriz;
} Grafo;

// Função para criar um novo grafo
Grafo* criarGrafo(int numNos) {
    Grafo *grafo = (Grafo*) malloc(sizeof(Grafo));
    grafo->numNos = numNos;
    grafo->adjMatriz = (int**) malloc(numNos * sizeof(int*));
    for (int i = 0; i < numNos; i++) {
        grafo->adjMatriz[i] = (int*) calloc(numNos, sizeof(int));
    }
    return grafo;
}

// Função para adicionar uma aresta ao grafo
void adicionarAresta(Grafo *grafo, int origem, int destino) {
    grafo->adjMatriz[origem][destino] = 1; // Para grafos direcionados
    grafo->adjMatriz[destino][origem] = 1; // Para grafos não direcionados
}

// Função para imprimir a matriz de adjacências do grafo
void imprimirGrafo(Grafo *grafo) {
    for (int i = 0; i < grafo->numNos; i++) {
        for (int j = 0; j < grafo->numNos; j++) {
            printf("%d ", grafo->adjMatriz[i][j]);
        }
        printf("\n");
    }
}

// Função principal para demonstrar a adição de arestas
int main() {
    int numNos = 5; // Exemplo com 5 interseções
    Grafo *grafo = criarGrafo(numNos);

    // Adicionando algumas ruas (arestas)
    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 4);
    adicionarAresta(grafo, 1, 2);
    adicionarAresta(grafo, 1, 3);
    adicionarAresta(grafo, 1, 4);
    adicionarAresta(grafo, 2, 3);
    adicionarAresta(grafo, 3, 4);

    // Imprimindo a matriz de adjacências para visualização
    printf("Matriz de Adjacências:\n");
    imprimirGrafo(grafo);

    // Liberando a memória alocada para o grafo
    for (int i = 0; i < numNos; i++) {
        free(grafo->adjMatriz[i]);
    }
    free(grafo->adjMatriz);
    free(grafo);

    return 0;
}
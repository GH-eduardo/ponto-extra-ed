/*
Algoritmo Selection Sort em C

Descrição:
Selection Sort é um algoritmo de ordenação que divide a lista de entrada em duas partes: a sublista de itens já ordenados, que é construída da esquerda para a direita na frente (lado esquerdo) da lista, e a sublista dos itens restantes a serem ordenados que ocupam o resto da lista. Inicialmente, a sublista ordenada está vazia e a sublista não ordenada é a lista inteira. O algoritmo procede encontrando o menor (ou maior, dependendo da ordem de ordenação) elemento na sublista não ordenada, trocando-o com o elemento não ordenado mais à esquerda (colocando-o na ordem correta), e movendo os limites da sublista um elemento para a direita.

Funcionamento:
1. Procure o menor elemento na lista
2. Troque-o com o primeiro elemento
3. Procure o menor elemento restante na lista
4. Troque-o com o segundo elemento
5. Repita o processo até que toda a lista esteja ordenada

Vantagens:
- Simples e fácil de implementar
- Não requer espaço adicional

Desvantagens:
- Ineficiente para listas grandes, com complexidade de tempo O(n^2) em média e no pior caso
*/

#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    // Mova o limite da sublista não ordenada
    for (i = 0; i < n-1; i++) {
        // Encontre o mínimo elemento na sublista não ordenada
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Troque o elemento mínimo encontrado com o primeiro elemento
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Função para imprimir o vetor
void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal para testar o algoritmo de ordenação
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Array ordenado: \n");
    printArray(arr, n);
    return 0;
}
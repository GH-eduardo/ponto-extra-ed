/*
Algoritmo Insertion Sort em C

Descrição:
Insertion Sort é um algoritmo de ordenação que constrói a lista ordenada um elemento por vez. Ele pega cada elemento da lista e o coloca na posição correta na parte já ordenada, movendo os elementos maiores uma posição para frente para acomodar o novo elemento.

Funcionamento:
1. Comece com o segundo elemento da lista (o primeiro elemento por si só já é considerado ordenado).
2. Compare este elemento com os elementos anteriores; mova todos os elementos que são maiores que o elemento atual uma posição para frente.
3. Insira o elemento atual na posição correta.
4. Repita os passos 2 e 3 para cada elemento da lista.

Vantagens:
- Simples de implementar.
- Eficiente para listas pequenas.
- Mais eficiente que outros algoritmos de ordenação quadrática (como Bubble Sort e Selection Sort) em certos casos.

Desvantagens:
- Ineficiente para listas grandes, com complexidade de tempo O(n^2) em média e no pior caso.
*/

#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Mova os elementos de arr[0..i-1], que são
          maiores que key, para uma posição à frente
          de sua posição atual */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Função para imprimir o vetor
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal para testar o algoritmo de ordenação
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    printf("Array ordenado: \n");
    printArray(arr, n);
    return 0;
}
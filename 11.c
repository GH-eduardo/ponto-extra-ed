/*
Algoritmo Quick Sort em C

Descrição:
Quick Sort é um algoritmo de ordenação muito eficiente, baseado na técnica de dividir para conquistar. Ele seleciona um elemento como pivô e particiona o array ao redor do pivô escolhido.

Funcionamento:
1. Escolha um elemento do array como pivô (existem várias maneiras de selecionar o pivô, uma abordagem comum é escolher o último elemento).
2. Reposicione os elementos do array de forma que todos os elementos menores que o pivô venham antes dele, enquanto todos os elementos maiores venham depois. Esta operação é conhecida como partição.
3. Recursivamente aplique os passos acima para as sub-listas de elementos com valores menores e maiores.

Vantagens:
- Tem uma performance muito boa em média, com complexidade de tempo O(n log n).
- Mais eficiente na prática do que outros algoritmos de ordenação de complexidade O(n log n), como Merge Sort e Heap Sort.

Desvantagens:
- No pior caso, pode ter complexidade de tempo O(n^2), embora isso possa ser mitigado de várias maneiras.
- Não é um algoritmo de ordenação estável; ou seja, a ordem relativa de registros iguais pode não ser preservada.
*/

#include <stdio.h>

// Função para trocar dois elementos
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* Esta função pega o último elemento como pivô, coloca
   o elemento pivô em sua posição correta no array ordenado,
   e coloca todos menores (menores que o pivô) à esquerda do pivô
   e todos maiores à direita do pivô */
int partition (int arr[], int low, int high) {
    int pivot = arr[high];    // pivô
    int i = (low - 1);  // Índice do menor elemento

    for (int j = low; j <= high- 1; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++;    // incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* A função principal que implementa QuickSort
 arr[] --> Array a ser ordenado,
  low  --> Índice inicial,
  high --> Índice final */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        /* pi é o índice de particionamento, arr[p] agora
           está no lugar certo */
        int pi = partition(arr, low, high);

        // Ordena separadamente os elementos antes
        // e depois da partição
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal para testar o algoritmo de ordenação
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Array ordenado: \n");
    printArray(arr, n);
    return 0;
}
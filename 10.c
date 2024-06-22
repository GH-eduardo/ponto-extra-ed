/*
Algoritmo Merge Sort em C

Descrição:
Merge Sort é um algoritmo de ordenação baseado na técnica de dividir para conquistar. Ele divide o array em duas metades, chama a si mesmo para as duas metades e, em seguida, mescla as duas metades ordenadas.

Funcionamento:
1. Divida o array em duas metades.
2. Chame recursivamente o merge sort para cada metade.
3. Mescla as duas metades para formar um array ordenado.

Vantagens:
- Eficiente para listas grandes.
- Tem complexidade de tempo O(n log n) em todos os casos (melhor, médio e pior).
- É estável (mantém a ordem de registros iguais).

Desvantagens:
- Requer espaço adicional proporcional ao tamanho do array.
- Ligeiramente mais complexo que os algoritmos de ordenação quadrática.
*/

#include <stdio.h>
#include <stdlib.h>

// Função para mesclar duas metades de um array
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Crie arrays temporários
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copie os dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mescla os arrays temporários de volta para arr[l..r]
    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = l; // Índice inicial do subarray mesclado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copie os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copie os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal que implementa o MergeSort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Encontre o ponto médio para dividir o array em duas metades
        int m = l + (r - l) / 2;

        // Chame o mergeSort para as primeiras e segundas metades
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Mescla as duas metades ordenadas
        merge(arr, l, m, r);
    }
}

// Função para imprimir o array
void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Função principal para testar o algoritmo de ordenação
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Array dado: \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nArray ordenado: \n");
    printArray(arr, arr_size);
    return 0;
}
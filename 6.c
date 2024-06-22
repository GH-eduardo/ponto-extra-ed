/*
Algoritmo Bubble Sort em C

Descrição:
Bubble Sort é um algoritmo simples de ordenação que percorre repetidamente a lista, compara elementos adjacentes e os troca de lugar se estiverem na ordem errada. Este processo se repete até que mais nenhuma troca seja necessária, indicando que a lista está ordenada.

Funcionamento:
1. Começando do primeiro elemento da lista, compare o elemento atual com o próximo;
2. Se o elemento atual for maior que o próximo, troque-os de lugar;
3. Avance para o próximo par de elementos e repita o processo;
4. Continue este processo até o final da lista. Isso completa uma "passagem";
5. Repita as passagens até que nenhuma troca seja necessária na passagem inteira, o que indica que a lista está ordenada.

Vantagens:
- Simples de entender e implementar.

Desvantagens:
- Ineficiente para listas grandes, com complexidade de tempo O(n^2) em média e no pior caso.
*/

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        // A flag para verificar se alguma troca foi feita na passagem
        int swapped = 0;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Troca arr[j] e arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        // Se não houve trocas, então o array já está ordenado
        if (swapped == 0)
            break;
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Array ordenado: \n");
    printArray(arr, n);
    return 0;
}
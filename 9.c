/*
Algoritmo Shell Sort em C

Descrição:
Shell Sort é uma extensão do algoritmo de ordenação por inserção. Ele permite a troca de itens que estão distantes um do outro. A ideia é que a ordenação de itens distantes uns dos outros inicialmente, leva a uma lista parcialmente ordenada, o que torna mais rápido e fácil a ordenação final dos itens com o algoritmo de inserção.

Funcionamento:
1. Comece com um grande valor de gap (distância entre os itens a serem comparados) e vá reduzindo o gap até que ele chegue a 1.
2. Com cada valor de gap, faça uma passagem pelo array para um "gapped insertion sort". Isso significa que ao invés de considerar todos os itens em sequência para a ordenação por inserção, o array é dividido em subarrays usando o gap, e cada subarray é ordenado.
3. A última passagem pelo array (quando o gap é 1) é simplesmente uma ordenação por inserção, mas a esta altura, o array já está parcialmente ordenado, o que torna o processo mais rápido.

Vantagens:
- Mais eficiente que os algoritmos de ordenação por inserção, bolha e seleção para listas maiores.

Desvantagens:
- A escolha do valor inicial de gap e da sequência de redução do gap pode afetar significativamente o desempenho do algoritmo.
- Mais complexo que os algoritmos de ordenação por inserção, bolha e seleção.
*/

#include <stdio.h>

void shellSort(int arr[], int n) {
    // Comece com um grande gap, depois reduza o gap
    for (int gap = n/2; gap > 0; gap /= 2) {
        // Faça um gapped insertion sort para este gap.
        // Os primeiros elementos gap a[i-gap], a[i-2*gap], a[i-3*gap]... já estão em gap order
        for (int i = gap; i < n; i += 1) {
            // Adicione a[i] aos elementos que foram gap sorted
            // Salve a[i] em temp e faça um buraco na posição i
            int temp = arr[i];

            // Desloque elementos anteriores até encontrar a posição correta de a[i]
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            
            // Coloque temp (o original a[i]) na sua posição correta
            arr[j] = temp;
        }
    }
}

// Função para imprimir o vetor
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal para testar o algoritmo de ordenação
int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    shellSort(arr, n);
    printf("Array ordenado: \n");
    printArray(arr, n);
    return 0;
}
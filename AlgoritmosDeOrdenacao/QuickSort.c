#include "QuickSort.h"
#include "../Vetor.h"
#include <time.h>

int partition(Vetor* v, int low, int high);
clock_t QuickSort(Vetor* v, int low, int high);

/*
 * Quick Sort
 * \Complexidade Temporal: O(n log n) no caso médio e melhor caso, O(n^2) no pior caso
 * \Complexidade Espacial: O(log n) devido à pilha de chamadas recursivas
 * \Retorna clock_t com o tempo gasto na ordenação
 * */
clock_t QuickSort(Vetor *v, int low, int high) {
  // Cronometro
  clock_t inicio = clock();

  if (low < high) {
    // Índice de partição
    int pi = partition(v, low, high);

    // Ordenar recursivamente os elementos antes e depois da partição
    QuickSort(v, low, pi);
    QuickSort(v, pi + 1, high);
  }

  return clock() - inicio;
}

int partition(Vetor* v, int low, int high) {
  int pivot = obterElemento(v, high - 1); // Pivô
  int i = (low - 1); // Índice do menor elemento

  for (int j = low; j < high - 1; j++) {
    // Se o elemento atual é menor ou igual ao pivô
    if (obterElemento(v, j) <= pivot) {
      i++; // Incrementar o índice do menor elemento
      // Trocar v[i] e v[j]
      int temp = obterElemento(v, i);
      definirElemento(v, i, obterElemento(v, j));
      definirElemento(v, j, temp);
    }
  }
  // Trocar v[i + 1] e v[high - 1] (ou pivô)
  int temp = obterElemento(v, i + 1);
  definirElemento(v, i + 1, obterElemento(v, high - 1));
  definirElemento(v, high - 1, temp);
  return (i + 1);
}

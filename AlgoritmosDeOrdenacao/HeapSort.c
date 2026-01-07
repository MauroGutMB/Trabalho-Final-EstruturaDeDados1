#include "HeapSort.h"
#include "../Vetor.h"
#include <time.h>

void heapify(Vetor* v, int n, int i);
clock_t HeapSort(Vetor* v);

/* 
 * Heap Sort
 * \Complexidade Temporal: O(n log n) no pior caso
 * \Complexidade Espacial: O(1)
 * \Retorna clock_t com o tempo gasto na ordenação
 * */
clock_t HeapSort(Vetor* v) {
  // Cronometro
  clock_t inicio = clock();

  /* Lógica do Heap Sort */
  int n = obterTamanhoVetor(v);
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(v, n, i);
  for (int i = n - 1; i > 0; i--) {
    // Trocar v[0] e v[i]
    swapElementos(v, 0, i);
    heapify(v, i, 0);
  }

  return clock() - inicio;
}

// n e i são, respectivamente, o tamanho do heap e o índice do elemento raiz
void heapify(Vetor* v, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && obterElemento(v, left) > obterElemento(v, largest))
    largest = left;

  if (right < n && obterElemento(v, right) > obterElemento(v, largest))
    largest = right;

  if (largest != i) {
    swapElementos(v, i, largest);
    heapify(v, n, largest);
  }
}

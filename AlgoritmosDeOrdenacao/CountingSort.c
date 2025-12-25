#include "CountingSort.h"
#include "../Vetor.h"
#include <time.h>
#include <stdlib.h>

/*
 * Counting Sort
 * \Complexidade Temporal: O(n + k), onde n é o número de elementos no vetor e k é o valor máximo dos elementos
 * \Complexidade Espacial: O(k)
 * \Retorna clock_t com o tempo gasto na ordenação
 * */
clock_t CountingSort(Vetor* v){
  // Cronometro
  clock_t inicio = clock();

  int n = obterTamanhoVetor(v);
  if (n == 0) return clock() - inicio;

  // Encontrar o valor máximo no vetor
  int max = obterElemento(v, 0);
  for (int i = 1; i < n; i++) {
    if (obterElemento(v, i) > max) {
      max = obterElemento(v, i);
    }
  }

  // Criar o array de contagem
  int* count = (int*)calloc(max + 1, sizeof(int));

  // Contar a ocorrência de cada elemento
  for (int i = 0; i < n; i++) {
    count[obterElemento(v, i)]++;
  }

  // Reconstituir o vetor ordenado
  int index = 0;
  for (int i = 0; i <= max; i++) {
    while (count[i] > 0) {
      definirElemento(v, index, i);
      index++;
      count[i]--;
    }
  }

  // Liberar o array de contagem
  free(count);

  return clock() - inicio;
}

#include "InsertionSort.h"
#include "../Vetor.h"
#include <time.h>

/*
 * Insertion Sort
 * \Complexidade Temporal: O(n^2) no pior caso
 * \Complexidade Espacial: O(1)
 * \Retorna clock_t com o tempo gasto na ordenação
 * */
clock_t InsertionSort(Vetor* v){

  // Cronometro
  clock_t inicio = clock();

  /* Lógica do Insertion Sort */

  for(int i = 1; i < obterTamanhoVetor(v); i++){
    int key = obterElemento(v, i);
    int j = i - 1;
    while(j >= 0 && obterElemento(v, j) > key){
      definirElemento(v, j + 1, obterElemento(v, j));
      j--;
    }
    definirElemento(v, j+1, key);
  }

  return clock() - inicio;
}

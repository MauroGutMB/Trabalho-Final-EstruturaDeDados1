#include "BubbleSort.h"
#include "../Vetor.h"
#include <time.h>

/*
 * Bubble Sort
 * \Complexidade Temporal: O(n^2) no pior caso
 * \Complexidade Espacial: O(1)
 * \Retorna clock_t com o tempo gasto na ordenação
 * */
clock_t BubbleSort(Vetor* v){

  // Cronometro
  clock_t inicio = clock();

  /* Lógica do Bubble Sort */

  for(int i = 0; i < obterTamanhoVetor(v) - 1; i++){ // Passar por todos os elementos do vetor
    for(int j = 0; j < obterTamanhoVetor(v) - 1 - i; j++){ // Comparar elementos adjacentes
      if(obterElemento(v, j) > obterElemento(v, j+1)){  // Se o elemento atual for maior que o próximo, trocar
        swapElementos(v, j, j+1); // Troca dos elementos
      }
    }
  }

  return clock() - inicio;
}

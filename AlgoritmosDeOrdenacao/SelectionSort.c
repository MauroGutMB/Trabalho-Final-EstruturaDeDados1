#include "SelectionSort.h"
#include "../Vetor.h"
#include <time.h>

/*
 * Selection Sort
 * \Complexidade Temporal: O(n^2) em todos os casos
 * \Complexidade Espacial:  O(1)
 * \Retorna clock_t com o tempo gasto na ordenação
 * */
clock_t SelectionSort(Vetor* v){

  // Cronometro
  clock_t inicio = clock();
  
  /* Lógica do Selection Sort */
  for(int i = 0; i < obterTamanhoVetor(v) - 1; i++){ // Passar por todos os elementos do vetor
    int minIndex = i; // Índice do menor elemento encontrado
    for(int j = i + 1; j < obterTamanhoVetor(v); j++){ // Procurar o menor elemento no restante do vetor
      if(obterElemento(v, j) < obterElemento(v, minIndex)){ // Se o elemento atual for menor que o menor encontrado
        minIndex = j; // Atualizar o índice do menor elemento
      }
    }
    int temp = obterElemento(v, minIndex); // Trocar o menor elemento com o primeiro elemento não ordenado
    definirElemento(v, minIndex, obterElemento(v, i));
    definirElemento(v, i, temp);
  }

  return clock() - inicio;
}

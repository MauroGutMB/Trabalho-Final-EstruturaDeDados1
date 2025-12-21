#include "AlgoritmosDeOrdenacao/BubbleSort.h"
#include "AlgoritmosDeOrdenacao/CountingSort.h"
#include "AlgoritmosDeOrdenacao/HeapSort.h"
#include "AlgoritmosDeOrdenacao/InsertionSort.h"
#include "AlgoritmosDeOrdenacao/MergeSort.h"
#include "AlgoritmosDeOrdenacao/QuickSort.h"
#include "AlgoritmosDeOrdenacao/SelectionSort.h"
#include "Vetor.h"
#include <stdio.h>
#include <time.h>

int n = 20000; // numero de elementos

int main(){
  Vetor* vetor = criarVetor(n);
  preencherVetorAleatorio(vetor, n, 100);

  clock_t t_bubbleSort = BubbleSort(vetor); // tempo do bubble sort

  imprimirVetor(vetor);

  printf("\n\nTempo gasto na ordenação: %.5f segundos\n", ((double)t_bubbleSort) / CLOCKS_PER_SEC);


  liberarVetor(vetor);
  return 0;
}

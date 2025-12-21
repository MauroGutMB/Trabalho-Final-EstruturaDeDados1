#include "AlgoritmosDeOrdenacao/BubbleSort.h"
#include "AlgoritmosDeOrdenacao/CountingSort.h"
#include "AlgoritmosDeOrdenacao/HeapSort.h"
#include "AlgoritmosDeOrdenacao/InsertionSort.h"
#include "AlgoritmosDeOrdenacao/MergeSort.h"
#include "AlgoritmosDeOrdenacao/QuickSort.h"
#include "AlgoritmosDeOrdenacao/SelectionSort.h"
#include "Vetor.h"

int main(){

  Vetor* vetor = criarVetor(100);
  preencherVetorAleatorio(vetor, 100, 100);
  imprimirVetor(vetor);


  liberarVetor(vetor);

  return 0;
}

#include "MergeSort.h"
#include "../Vetor.h"
#include <time.h>

clock_t MergeSort(Vetor *v, int left, int right);
void MergeVetores(Vetor *v, int left, int mid, int right);

/*
 * Merge Sort
 * \Complexidade Temporal: O(n log n) no pior caso
 * \Complexidade Espacial: O(n)
 * \Retorna clock_t com o tempo gasto na ordenação
 * */
clock_t MergeSort(Vetor *v, int left, int right) {
  // Cronometro
  clock_t inicio = clock();

  if (left < right) {
    // Encontrar o ponto médio
    int mid = left + (right - left) / 2;

    // Ordenar a primeira e segunda metades
    MergeSort(v, left, mid);
    MergeSort(v, mid + 1, right);

    // Mesclar as metades ordenadas
    MergeVetores(v, left, mid, right);
  }

  return clock() - inicio;
}

void MergeVetores(Vetor *v, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Criar vetores temporários
  Vetor *L = criarVetor(n1);
  Vetor *R = criarVetor(n2);

  // Copiar dados para os vetores temporários L[] e R[]
  for (int i = 0; i < n1; i++)
    definirElemento(L, i, obterElemento(v, left + i));
  for (int j = 0; j < n2; j++)
    definirElemento(R, j, obterElemento(v, mid + 1 + j));

  // Mesclar os vetores temporários de volta em v[left..right]
  int i = 0;    // Índice inicial do primeiro subvetor
  int j = 0;    // Índice inicial do segundo subvetor
  int k = left; // Índice inicial do subvetor mesclado
  while (i < n1 && j < n2) {
    if (obterElemento(L, i) <= obterElemento(R, j)) {
      definirElemento(v, k, obterElemento(L, i));
      i++;
    } else {
      definirElemento(v, k, obterElemento(R, j));
      j++;
    }
    k++;
  }

  // Copiar os elementos restantes de L[], se houver
  while (i < n1) {
    definirElemento(v, k, obterElemento(L, i));
    i++;
    k++;
  }

  // Copiar os elementos restantes de R[], se houver
  while (j < n2) {
    definirElemento(v, k, obterElemento(R, j));
    j++;
    k++;
  }

  // Liberar memória dos vetores temporários
  liberarVetor(L);
  liberarVetor(R);
}

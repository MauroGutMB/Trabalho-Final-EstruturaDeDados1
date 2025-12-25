#include "AlgoritmosDeOrdenacao/BubbleSort.h"
#include "AlgoritmosDeOrdenacao/CountingSort.h"
#include "AlgoritmosDeOrdenacao/HeapSort.h"
#include "AlgoritmosDeOrdenacao/InsertionSort.h"
#include "AlgoritmosDeOrdenacao/MergeSort.h"
#include "AlgoritmosDeOrdenacao/QuickSort.h"
#include "AlgoritmosDeOrdenacao/SelectionSort.h"
#include "Vetor.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define lim 100 // geração de números aleatórios de 1 à lim

/*
 * Enum dos algoritmos de ordenação
 * */
enum {BUBBLESORT, SELECTIONSORT, INSERTIONSORT, MERGESORT, QUICKSORT, HEAPSORT, COUNTINGSORT};

int MenuSelecaoOrdenacao(); // menu pra selecionar o algoritmo de ordenação
void GerenciarVetor(); // menu pra gerenciar o vetor
void limparTela(); // limpar a tela
void FuncaoErro(); // função caso alguma opção inválida seja selecionada
void preenchimentoManual(); // função de preechimento manual do vetor
void preenchimentoAutomatico(); // função de preenchimento automatico do vetor
void limparVetor(); // função pra limpar o vetor
void fazerOrdenacao(int algoritmo);
void limparBuffer();

Vetor* vetor; // vetor utilizado

/*
 * Função principal que inicializa o programa de ordenação
 * */
int main(){
  /*
  Vetor* vetor = criarVetor(n);
  preencherVetorAleatorio(vetor, n, 100);

  imprimirVetor(vetor);
  // clock_t t_bubbleSort = BubbleSort(vetor); // tempo do bubble sort
  clock_t t_selectionSort = SelectionSort(vetor); // tempo do bubble sort

  imprimirVetor(vetor);

  printf("\n\nTempo gasto na ordenação: %.5f segundos\n", ((double)t_selectionSort) / CLOCKS_PER_SEC);


  liberarVetor(vetor);
  return 0;
  */

  GerenciarVetor();

  fazerOrdenacao(MenuSelecaoOrdenacao());

  limparVetor();

  return 0;
}

/*
 * */
int MenuSelecaoOrdenacao(){

  char x;
  int y;

  printf("+----------------------------------+\n");
  printf("|      Algoritmos de Ordenação     |\n");
  printf("+----------------------------------+\n");
  printf("| 1. Bubble Sort    (Implementado) |\n");
  printf("| 2. Selection Sort (Implementado) |\n");
  printf("| 3. Insertion Sort (...)          |\n");
  printf("| 4. Merge Sort     (...)          |\n");
  printf("| 5. Quick Sort     (...)          |\n");
  printf("| 6. Heap Sort      (...)          |\n");
  printf("| 7. Counting Sort  (...)          |\n");
  printf("+----------------------------------+\n");

  printf("\n\n\n");

  printf("- Escolha um dos algoritmos de ordenação acima -\n");
  printf("- algoritmos funcionando: 1, 2, ... -\n");
  printf("-> ");

  scanf("%c", &x);

  y = x - '0';

  if(x != '1' && x != '2'){
    FuncaoErro();
    return 0;
  }

  limparTela();
  limparBuffer();

  return y-1;
}

/*
 * */
void GerenciarVetor(){

  char x;
  int y;

  printf("+--------------------------------------+\n");
  printf("|        Gerenciamento do Vetor        |\n");
  printf("+--------------------------------------+\n");
  printf("| 1.   Preencher o vetor manualmente   |\n");
  printf("| 2. Preencher o vetor automaticamente |\n");
  printf("| 3.         Esvaziar o vetor          |\n");
  printf("+--------------------------------------+\n");

  printf("\n\n\n");

  scanf("%c", &x);
  limparBuffer();
  y = x - '0';

  switch (y){
    case 1: preenchimentoManual(); break;
    case 2: preenchimentoAutomatico(); break;
    case 3: limparVetor(); break;
    default: printf("Opção não presente.\n"); break;
  }

}

/*
 * */
void limparTela(){
  system("clear");
}

/*
 * */
void FuncaoErro(){
  printf("ALGORITMO NÃO IMPLEMENTADO. UTILIZE OUTRA OPÇÃO.\n");
}

/*
 * */
void preenchimentoManual(){

  if(vetor != NULL){
    printf("O vetor não está vazio. Por favor, libere-o e tente de novo.\n");
    return;
  }

  int sz;
  printf("Insira o tamanho do vetor a ser preenchido -> ");
  scanf("%i", &sz);
  limparBuffer();

  vetor = criarVetor(sz);

  for(int i = 0; i < sz; i++){
    int val;
     
    printf("Valor do elemento de índice %i -> ", i);
    scanf("%i", &val);
    limparBuffer();
    definirElemento(vetor, i, val);
  }

  limparTela();
  printf("Vetor de %i elementos criado com sucesso!\n", sz);
  printf("Elementos do vetor: ");
  imprimirVetor(vetor);

  limparBuffer();
  limparTela();

}

/*
 * */
void preenchimentoAutomatico(){

  if(vetor != NULL){
    printf("O vetor não está vazio. Por favor, libere-o e tente de novo.\n");
    return;
  }

  int sz;
  printf("Insira o tamanho do vetor a ser preenchido -> ");
  scanf("%i", &sz);
  limparBuffer();

  vetor = criarVetor(sz);

  preencherVetorAleatorio(vetor, sz, lim);

  limparTela();
  printf("Vetor de %i elementos criado com sucesso!\n", sz);
  printf("Elementos do vetor: ");
  imprimirVetor(vetor);

  limparTela();

}

/*
 * */
void limparVetor(){
  liberarVetor(vetor);

  printf("Vetor liberado com sucesso!\n");

  limparBuffer();
  limparTela();

}

void fazerOrdenacao(int algoritmo){
  if(algoritmo == BUBBLESORT){
    printf("Iniciando a ordenação com o algorítmo BUBBLESORT\n");
    clock_t tempo = BubbleSort(vetor);
    printf("\n\nTempo gasto na ordenação: %.5f segundos\n", ((double)tempo) / CLOCKS_PER_SEC);
  }
  if(algoritmo == SELECTIONSORT){
    printf("Iniciando a ordenação com o algorítmo SELECTIONSORT\n");
    clock_t tempo = SelectionSort(vetor);
    printf("\n\nTempo gasto na ordenação: %.5f segundos\n", ((double)tempo) / CLOCKS_PER_SEC);
  }
}

void limparBuffer(){
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

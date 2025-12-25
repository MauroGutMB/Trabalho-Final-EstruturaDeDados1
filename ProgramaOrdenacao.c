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
#include <stdbool.h>

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
void fazerOrdenacao(int algoritmo); // faz a ordenação 
void limparBuffer(); // limpa o buffer / também utilizo como confirmação pra prosseguir

Vetor* vetor; // vetor utilizado
bool programa = true; // programa rodando

// ---------------------------------------------------------------------------------------------------------------------- //
// ---------------------------------------------------------------------------------------------------------------------- //
// ---------------------------------------------------------------------------------------------------------------------- //

/*
 * Função principal que inicializa o programa de ordenação
 * */
int main(){

  while(programa){

    int opt = 0;
    char c;
    
    printf("+---------------------------------------+\n");
    printf("|         Programa de Ordenação         |\n");
    printf("+---------------------------------------+\n");
    printf("| 1. Gerenciar o Vetor utilizado        |\n");
    printf("| 2. Utilizar um algoritmo de ordenação |\n");
    printf("| 3. Mostrar o vetor                    |\n");
    printf("| 4. Sair do programa                   |\n");
    printf("+---------------------------------------+\n");

    printf("\n\n\n");
    printf("- Selecione uma opção -\n");
    printf("-> ");

    scanf("%c", &c);
    limparBuffer();

    opt = c - '0';

    switch (opt) {
      case 1: limparTela(); GerenciarVetor(); limparTela(); continue;
      case 2: limparTela(); if(vetor == NULL){printf("Vetor vazio.\n"); continue;} fazerOrdenacao(MenuSelecaoOrdenacao()); limparBuffer(); limparTela();  continue;
      case 3: limparTela(); if(vetor == NULL){printf("Vetor vazio.\n"); continue;} imprimirVetor(vetor); limparBuffer(); limparTela();  continue;
      case 4: limparTela(); if(vetor != NULL){printf("Por favor, libere o vetor\n"); continue;} programa = 0; limparTela(); break;
      default: limparTela(); printf("Por favor, selecione uma opção válida!\n");
    }

  }

  limparTela();
  printf("+-------------------------------+\n");
  printf("| Obrigado por usar o programa! |\n");
  printf("+-------------------------------+\n");

  return 0;
}

// ---------------------------------------------------------------------------------------------------------------------- //
// ---------------------------------------------------------------------------------------------------------------------- //
// ---------------------------------------------------------------------------------------------------------------------- //

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
  printf("| 3. Insertion Sort (Implementado) |\n");
  printf("| 4. Merge Sort     (Implementado) |\n");
  printf("| 5. Quick Sort     (...)          |\n");
  printf("| 6. Heap Sort      (...)          |\n");
  printf("| 7. Counting Sort  (...)          |\n");
  printf("+----------------------------------+\n");

  printf("\n\n\n");

  printf("- Escolha um dos algoritmos de ordenação acima -\n");
  printf("- algoritmos funcionando: 1, 2, 3, 4, ... -\n");
  printf("-> ");

  scanf("%c", &x);

  y = x - '0';

  if(x != '1' && x != '2' && x != '3' &&
     x != '4'){
    FuncaoErro();
    return -1;
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
  printf("-> ");

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
    limparBuffer();
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
    limparBuffer();
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

  limparBuffer();
  limparTela();

}

/*
 * */
void limparVetor(){
  liberarVetor(vetor);
  vetor = NULL;

  printf("Vetor liberado com sucesso!\n");

  limparBuffer();
  limparTela();

}

/*
 * */
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
  if(algoritmo == INSERTIONSORT){
    printf("Iniciando a ordenação com o algorítmo INSERTIONSORT\n");
    clock_t tempo = InsertionSort(vetor);
    printf("\n\nTempo gasto na ordenação: %.5f segundos\n", ((double)tempo) / CLOCKS_PER_SEC);
  }
  if(algoritmo == MERGESORT){
    printf("Iniciando a ordenação com o algorítmo MERGESORT\n");
    clock_t tempo = MergeSort(vetor, 0, obterTamanhoVetor(vetor)-1); // é necessário passar os índices inicial e final pois é um algoritmo recursivo
    printf("\n\nTempo gasto na ordenação: %.5f segundos\n", ((double)tempo) / CLOCKS_PER_SEC);
  }
}

/*
 * */
void limparBuffer(){
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

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

#ifdef _WIN32
 #include <windows.h>
 #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif

#define lim 1000 // geração de números aleatórios de 1 à lim

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
void restaurarVetor(); // restaura o vetor a partir do backup

Vetor* vetor; // vetor utilizado
Vetor* backupVetor; // backup do vetor utilizado para comparação posteriores

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
  printf("| 5. Quick Sort     (Implementado) |\n");
  printf("| 6. Heap Sort      (Implementado) |\n");
  printf("| 7. Counting Sort  (Implementado) |\n");
  printf("+----------------------------------+\n");

  printf("\n\n\n");

  printf("- Escolha um dos algoritmos de ordenação acima -\n");
  printf("- algoritmos funcionando: 1, 2, 3, 4, 5, 6, 7 -\n");
  printf("-> ");

  scanf("%c", &x);

  y = x - '0';

  if(x != '1' && x != '2' && x != '3' &&
     x != '4' && x != '5' && x != '6' && x != '7'){
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

  printf("+----------------------------------------+\n");
  printf("|         Gerenciamento do Vetor         |\n");
  printf("+----------------------------------------+\n");
  printf("| 1. Configurações predefinidas do vetor |\n");
  printf("| 2. Preencher o vetor automaticamente   |\n");
  printf("| 3.         Restaurar Vetor             |\n");
  printf("| 4.         Esvaziar vetor              |\n");
  printf("+---------------------------------------+\n");

  printf("\n\n\n");
  printf("-> ");

  scanf("%c", &x);
  limparBuffer();
  y = x - '0';

  switch (y){
    case 1: preenchimentoManual(); break;
    case 2: preenchimentoAutomatico(); break;
    case 3: restaurarVetor(); return;
    case 4: limparVetor(); return;
    default: printf("Opção não presente.\n"); return;
  }

  backupVetor = copiarVetor(vetor);

}

/*
 * */
void limparTela(){
  system(CLEAR);
}

/*
 * */
void FuncaoErro(){
  printf("ALGORITMO NÃO IMPLEMENTADO. UTILIZE OUTRA OPÇÃO.\n");
}

/*
 * */
// refatorar pra seguir o pedrao do trabalho
void preenchimentoManual(){

  if(vetor != NULL){
    printf("O vetor não está vazio. Por favor, libere-o e tente de novo.\n");
    limparBuffer();
    return;
  }

  int sz;
  char x;

  printf("+--------------------------------------+\n");
  printf("|        Gerenciamento do Vetor        |\n");
  printf("+--------------------------------------+\n");
  printf("| 1. Vetor com 100 elementos           |\n");
  printf("| 2. Vetor com 1.000 elementos         |\n");
  printf("| 3. Vetor com 10.000 elementos        |\n");
  printf("| 4. Vetor com 100.000 elementos       |\n");
  printf("+--------------------------------------+\n");

  printf("\n\n-> ");
  scanf("%c", &x);
  limparBuffer();

  sz = (x - '0');

  switch (sz){
    case 1: sz = 100; break;
    case 2: sz = 1000; break;
    case 3: sz = 10000; break;
    case 4: sz = 100000; break;
    default: printf("Opção inválida.\n"); return;
  }

  printf("+--------------------------------------+\n");
  printf("|        Gerenciamento do Vetor        |\n");
  printf("+--------------------------------------+\n");
  printf("| 1. Preencher com números aleatórios  |\n");
  printf("| 2. Preencher em ordem decrescente    |\n");
  printf("| 3. Preencher em ordem crescente      |\n");
  printf("+--------------------------------------+\n");

  printf("\n\n-> ");

  scanf("%c", &x);
  limparBuffer();

  int metodo = (x - '0');

  switch (metodo){
    case 1:
      vetor = criarVetor(sz);
      preencherVetorAleatorio(vetor, sz, lim);
      break;
    case 2:
      vetor = criarVetor(sz);
      preencherVetorOrdenadoDecrescente(vetor, sz);
      break;
    case 3:
      vetor = criarVetor(sz);
      preencherVetorOrdenadoCrescente(vetor, sz);
      break;
    default:
      printf("Opção inválida.\n");
      return;
  }

  limparTela();
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
  liberarVetor(backupVetor);
  vetor = NULL;
  backupVetor = NULL;
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

  if(algoritmo == QUICKSORT){
    printf("Iniciando a ordenação com o algorítmo QUICKSORT\n");
    clock_t tempo = QuickSort(vetor, 0, obterTamanhoVetor(vetor)); // é necessário passar os índices inicial e final pois é um algoritmo recursivo
    printf("\n\nTempo gasto na ordenação: %.5f segundos\n", ((double)tempo) / CLOCKS_PER_SEC);
  }

  if(algoritmo == HEAPSORT){
    printf("Iniciando a ordenação com o algorítmo HEAPSORT\n");
    clock_t tempo = HeapSort(vetor);
    printf("\n\nTempo gasto na ordenação: %.5f segundos\n", ((double)tempo) / CLOCKS_PER_SEC);
  }

  if(algoritmo == COUNTINGSORT){
    printf("Iniciando a ordenação com o algorítmo COUNTINGSORT\n");
    clock_t tempo = CountingSort(vetor);
    printf("\n\nTempo gasto na ordenação: %.5f segundos\n", ((double)tempo) / CLOCKS_PER_SEC);
  }
}

/*
 * */
void limparBuffer(){
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void restaurarVetor(){
  vetor = copiarVetor(backupVetor);

  printf("+-------------------------------+\n");
  printf("|       Vetor restaurado!       |\n");
  printf("+-------------------------------+\n");

  limparBuffer();
  limparTela();
}

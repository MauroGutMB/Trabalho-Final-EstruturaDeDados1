#include "Vetor.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Estrutura do Vetor:
 * \int *elementos
 * \int tamanho
 * \int index_atual*/
typedef struct Vetor {
  int *elementos;
  int tamanho;
  int index_atual;
} Vetor;

/*
 * Função pra criar um Vetor que contém elementos e índice
 * */
Vetor *criarVetor(int tamanho) {
  Vetor *v = (Vetor *)malloc(sizeof(Vetor));
  v->elementos = (int *)malloc(tamanho * sizeof(int));
  v->tamanho = tamanho;
  v->index_atual = 0;
  return v;
}


/*
 * Função pra definir o valor de um elemento no Vetor.
 * \Se indice for -1, adiciona no próximo índice disponível.
 * \Se indice for maior que o tamanho do vetor, imprime erro.
 * \Se indice já estiver ocupado, substitui o valor.
 * \Se indice for válido e vazio, adiciona o valor.
 * */
void definirElemento(Vetor *v, int indice, int valor) {
  if (indice == -1) {
    if (v->index_atual < v->tamanho) {
      v->elementos[v->index_atual] = valor;
      v->index_atual++;
    } else {
      printf("Erro: Vetor cheio, não é possível adicionar mais elementos.\n");
    }
  } else if (indice >= v->tamanho) {
    printf("Erro: Índice fora dos limites do vetor.\n");
  } else {
    v->elementos[indice] = valor;
    if (indice >= v->index_atual) {
      v->index_atual = indice + 1;
    }
  }
}

/*
 * Imprimir o vetor até o index_atual
 * */
void imprimirVetor(Vetor *v) {
  for (int i = 0; i < v->index_atual; i++) {
    printf("%d", v->elementos[i]);
    if(i < v->index_atual - 1) {
      printf(", ");
    }
  }
  printf("\n");
}

/*
 * Preencher n inteiros aleatórios no vetor
 * */
void preencherVetorAleatorio(Vetor *v, int n, int cap) {
  // seed para números aleatórios
  srand((unsigned int)time(NULL));

  if (n > v->tamanho) {
    printf("Erro: Número de elementos a preencher excede o tamanho do vetor.\n");
    return;
  }
  for (int i = 0; i < n; i++) {
    int valor_aleatorio = (rand() % cap) + 1; // Gera um número aleatório entre 1 e cap
    definirElemento(v, -1, valor_aleatorio);
  }
}

/*
 * Função pra liberar vetor e seus elementos
 * */
void liberarVetor(Vetor *v) {
  free(v->elementos);
  free(v);
}

/*
 * Função pra obter o tamanho atual do vetor
 * */
int obterTamanhoVetor(Vetor *v) {
  return v->index_atual;
}

/*
 * Função pra obter o elemento em um índice específico
 * */
int obterElemento(Vetor *v, int indice) {
  if (indice < 0 || indice >= v->index_atual) {
    printf("Erro: Índice fora dos limites do vetor.\n");
    return -1; // Retorna -1 em caso de erro
  }
  return v->elementos[indice];
}

/*
 * Função pra trocar dois elementos no vetor
 * */
void swapElementos(Vetor *v, int indice1, int indice2) {
  if (indice1 < 0 || indice1 >= v->index_atual || indice2 < 0 || indice2 >= v->index_atual) {
    printf("Erro: Índices fora dos limites do vetor.\n");
    return;
  }
  int temp = v->elementos[indice1];
  v->elementos[indice1] = v->elementos[indice2];
  v->elementos[indice2] = temp;
}

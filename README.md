# Projeto final de Estrutura de Dados  
Este repositório contém o projeto final da disciplina de Estrutura de Dados, desenvolvido por Mauro Gutemberg Magalhães Barros como requisito do curso de Análise e Desenvolvimento de Sistemas no Instituto Federal do Piauí.

## Descrição do Projeto
O projeto se trata de um programa que contém os seguintes algoritmos de ordenação:  
- Bubble Sort
- Insertion Sort
- Selection Sort
- Merge Sort
- Quick Sort
- Heap Sort
- Counting Sort

O projeto conta com um tipo abstrato de dados chamado "Vetor", que encapsula um array dinâmico de inteiros, seu número de elementos e fornece métodos para manipulação e ordenação dos dados.

A função principal do projeto é fazer com que o usuário consiga comparar o tempo de ordenação de todos os algoritmos implementados.
O usuário terá um menu interativo pra poder manipular o Vetor e selecionar o algoritmo desejado.

## Estrutura do Código
O código está organizado nos seguintes arquivos:
- `vetor.h`: Contém a definição do tipo abstrato de dados "Vetor" e as declarações das funções associadas.
- `vetor.c`: Implementa as funções declaradas em `vetor.h`, incluindo a criação, manipulação e os algoritmos de ordenação do vetor.
- `ProgramaOrdenacao.c`: Contém a função `main`, que serve como ponto de entrada para o programa, permitindo ao usuário interagir com o vetor e aplicar os algoritmos de ordenação.
- `AlgoritmosDeOrdenacao/`: Diretório que contém implementações separadas dos algoritmos de ordenação. 

## Compilação e Execução
Para compilar o programa, utilize o seguinte comando no terminal:
``` bash
gcc AlgoritmosDeOrdenacao/* Vetor.c ProgramaOrdenacao.c -o ProgramaOrdenacao
```
Para executar o programa, utilize o comando:
``` bash
./ProgramaOrdenacao
```

Obs: caso esteja utilizando o Windows, substitua `./ProgramaOrdenacao` por `ProgramaOrdenacao.exe`, bem como na compilação.

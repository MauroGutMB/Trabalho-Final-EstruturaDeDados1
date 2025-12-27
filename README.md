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

## Clonagem, Compilação e Execução

### 1. Clone o repositório através do seguinte comando no terminal:
``` bash
git clone https://github.com/MauroGutMB/Trabalho-Final-EstruturaDeDados1.git
```

### 2. Para compilar o programa e rodar, respectivamente, utilize os seguintes comandos no terminal:

### --- Windows ---
``` bash
gcc AlgoritmosDeOrdenacao/* Vetor.c ProgramaOrdenacao.c -o ProgramaOrdenacao.exe
```
``` bash
./ProgramaOrdenacao.exe
```

###  --- Linux ---
``` bash
gcc AlgoritmosDeOrdenacao/* Vetor.c ProgramaOrdenacao.c -o ProgramaOrdenacao
```
``` bash
./ProgramaOrdenacao
```

## Como usar
Ao executar o programa, você será apresentado a um menu interativo com as seguintes opções:
1. Gerenciar Vetor (preencher e liberar)
2. Utilizar Algoritmos de Ordenação
3. Imprimir o Vetor
4. Sair  

Siga as instruções na tela para manipular o vetor e aplicar os algoritmos de ordenação conforme desejado.  
Para cada algoritmo de ordenação, o programa exibirá o tempo gasto para ordenar o vetor.  
Você terá que criar um novo Vetor para cada algoritmo.  
Para sair do programa, você precisará liberar o Vetor.

## Contribuição
Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou pull requests para melhorias ou correções.  
Caso queira indicar algum outro algoritmo de ordenação, abra um issue apenas citando o algoritmo.  

# Análise e Desenvolvimento de Sistemas - IFPI Campus Corrente - 2025.2

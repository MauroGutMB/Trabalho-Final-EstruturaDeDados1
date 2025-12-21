typedef struct Vetor Vetor;
Vetor *criarVetor(int tamanho);
void definirElemento(Vetor *v, int indice, int valor);
void imprimirVetor(Vetor *v);
void preencherVetorAleatorio(Vetor *v, int n, int cap);
void liberarVetor(Vetor *v);


#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

typedef struct No {
    int valor;
    struct No* proximo;
    struct No* anterior;
} No;

typedef struct ListaDupla {
    No* cabeca;
    No* cauda;
    int tamanho;
} ListaDupla;

ListaDupla* criarListaDupla();
void destruirListaDupla(ListaDupla* lista);
void inserirNoInicio(ListaDupla* lista, int valor);
void inserirNoFim(ListaDupla* lista, int valor);
void inserirNaPosicao(ListaDupla* lista, int valor, int posicao);
int removerDoInicio(ListaDupla* lista);
int removerDoFim(ListaDupla* lista);
int removerValor(ListaDupla* lista, int valor);
int removerNaPosicao(ListaDupla* lista, int posicao);
No* buscar(ListaDupla* lista, int valor);
void exibirFrente(ListaDupla* lista);
void exibirTras(ListaDupla* lista);

#endif 

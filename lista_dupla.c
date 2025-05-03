// lista_dupla.c
#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

ListaDupla* criarListaDupla() {
    ListaDupla* lista = malloc(sizeof(ListaDupla));
    if (lista) {
        lista->cabeca = NULL;
        lista->cauda = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

void destruirListaDupla(ListaDupla* lista) {
    No* atual = lista->cabeca;
    while (atual) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(lista);
}

void inserirNoInicio(ListaDupla* lista, int valor) {
    No* novo = malloc(sizeof(No));
    if (!novo) return;
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = lista->cabeca;

    if (lista->cabeca)
        lista->cabeca->anterior = novo;
    else
        lista->cauda = novo;

    lista->cabeca = novo;
    lista->tamanho++;
}

void inserirNoFim(ListaDupla* lista, int valor) {
    No* novo = malloc(sizeof(No));
    if (!novo) return;
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = lista->cauda;

    if (lista->cauda)
        lista->cauda->proximo = novo;
    else
        lista->cabeca = novo;

    lista->cauda = novo;
    lista->tamanho++;
}

void inserirNaPosicao(ListaDupla* lista, int valor, int posicao) {
    if (posicao <= 0) {
        inserirNoInicio(lista, valor);
        return;
    } else if (posicao >= lista->tamanho) {
        inserirNoFim(lista, valor);
        return;
    }

    No* atual = lista->cabeca;
    for (int i = 0; i < posicao; i++) atual = atual->proximo;

    No* novo = malloc(sizeof(No));
    if (!novo) return;
    novo->valor = valor;
    novo->anterior = atual->anterior;
    novo->proximo = atual;
    atual->anterior->proximo = novo;
    atual->anterior = novo;
    lista->tamanho++;
}

int removerDoInicio(ListaDupla* lista) {
    if (!lista->cabeca) return -1;
    No* temp = lista->cabeca;
    int valor = temp->valor;
    lista->cabeca = temp->proximo;
    if (lista->cabeca)
        lista->cabeca->anterior = NULL;
    else
        lista->cauda = NULL;
    free(temp);
    lista->tamanho--;
    return valor;
}

int removerDoFim(ListaDupla* lista) {
    if (!lista->cauda) return -1;
    No* temp = lista->cauda;
    int valor = temp->valor;
    lista->cauda = temp->anterior;
    if (lista->cauda)
        lista->cauda->proximo = NULL;
    else
        lista->cabeca = NULL;
    free(temp);
    lista->tamanho--;
    return valor;
}

int removerValor(ListaDupla* lista, int valor) {
    No* atual = lista->cabeca;
    while (atual && atual->valor != valor) {
        atual = atual->proximo;
    }
    if (!atual) return -1;

    if (atual->anterior)
        atual->anterior->proximo = atual->proximo;
    else
        lista->cabeca = atual->proximo;

    if (atual->proximo)
        atual->proximo->anterior = atual->anterior;
    else
        lista->cauda = atual->anterior;

    free(atual);
    lista->tamanho--;
    return valor;
}

int removerNaPosicao(ListaDupla* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) return -1;
    No* atual = lista->cabeca;
    for (int i = 0; i < posicao; i++) atual = atual->proximo;
    int valor = atual->valor;

    if (atual->anterior)
        atual->anterior->proximo = atual->proximo;
    else
        lista->cabeca = atual->proximo;

    if (atual->proximo)
        atual->proximo->anterior = atual->anterior;
    else
        lista->cauda = atual->anterior;

    free(atual);
    lista->tamanho--;
    return valor;
}

No* buscar(ListaDupla* lista, int valor) {
    No* atual = lista->cabeca;
    while (atual) {
        if (atual->valor == valor) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

void exibirFrente(ListaDupla* lista) {
    No* atual = lista->cabeca;
    printf("Lista (frente): ");
    while (atual) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void exibirTras(ListaDupla* lista) {
    No* atual = lista->cauda;
    printf("Lista (trás): ");
    while (atual) {
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }
    printf("\n");
}

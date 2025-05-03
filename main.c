
#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

int main() {
    ListaDupla* lista = criarListaDupla();
    if (!lista) {
        printf("Erro\n");
        return 1;
    }

    printf("\nInserção no início\n");
    inserirNoInicio(lista, 10);
    inserirNoInicio(lista, 20);
    inserirNoInicio(lista, 30);
    exibirFrente(lista);
    exibirTras(lista);

    printf("\nInserção no fim\n");
    inserirNoFim(lista, 40);
    inserirNoFim(lista, 50);
    exibirFrente(lista);
    exibirTras(lista);

    printf("\nInserção em posições\n");
    inserirNaPosicao(lista, 25, 2);
    inserirNaPosicao(lista, 5, 0);
    inserirNaPosicao(lista, 60, 100); 
    exibirFrente(lista);
    exibirTras(lista);

    printf("\nRemoções\n");
    printf("Removido início: %d\n", removerDoInicio(lista));
    printf("Removido fim: %d\n", removerDoFim(lista));
    printf("Removido valor 25: %d\n", removerValor(lista, 25));
    printf("Removido na posição 1: %d\n", removerNaPosicao(lista, 1));
    exibirFrente(lista);
    exibirTras(lista);

    printf("\nBusca\n");
    No* achado = buscar(lista, 20);
    printf("Valor 20 %s\n", achado ? "encontrado" : "não encontrado");
    achado = buscar(lista, 999);
    printf("Valor 999 %s\n", achado ? "encontrado" : "não encontrado");

    printf("\n=== Destruindo ===\n");
    destruirListaDupla(lista);
    printf("Lista destruída.\n");

    return 0;
}

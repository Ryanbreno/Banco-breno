#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lista.h"

void inicializar_lista(Lista* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

void adicionar_cliente(Lista* lista, Cliente cliente) {
    No* novo_cliente = malloc(sizeof(No));
    if (novo_cliente == NULL) {
        printf("Erro: Memoria insuficiente!\n");
        return;
    }

    novo_cliente->cliente = cliente;
    novo_cliente->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo_cliente;
    }
    else {
        lista->fim->proximo = novo_cliente;
    }
    
    lista->fim = novo_cliente; //fim agora aponta para o ultimo nó adicionado
    lista->tamanho++;

}

void imprimir_lista(Lista* lista) {
    No* atual = lista->inicio;

    printf("IMPRIMINDO CLIENTES DO BANCO\n");

    if (lista->tamanho == 0) {
        printf("Nao ha clientes\n");
    }

    while(atual != NULL) {
        printf("nome: %s", atual->cliente.nome);
        printf("cpf: %s", atual->cliente.cpf);
        printf("Saldo: %d", atual->cliente.saldo);

        atual = atual->proximo;
    }

    printf("--------------------------");
}

No* buscar_cliente(Lista* lista, char cpf[]) {
    No* atual = lista->inicio;

    while(atual != NULL) {
        if (strcmp(cpf, atual->cliente.cpf) == 0) {
            return atual; 
        }
        atual = atual->proximo;
    }

    return NULL;
}

bool remover_cliente(Lista* lista, char cpf[]) {
    No* atual = lista->inicio;
    No* anterior = NULL;

    while(atual != NULL && strcmp(cpf, atual->cliente.cpf) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        return false;
    }

    // Caso for o primeiro elemento
    if (anterior == NULL) {
        lista->inicio = atual->proximo;
    }
    else {
        // Caso ele estiver no meio ou no fim
        anterior->proximo = atual->proximo;
    }

    // Garantir que a lista aponta para o anterior que se tornou o ultimo da lista
    if (atual == lista->fim) {
        lista->fim = anterior;
    }

    free(atual);
    lista->tamanho--;
    return true;


}

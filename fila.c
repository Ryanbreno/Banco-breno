#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "fila.h"

void inicializar_fila(Fila* fila){
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

bool fila_vazia(Fila* fila){
    return fila->tamanho == 0;
}

void enfileirar(Fila* fila, Cliente cliente){
    NoFila* novo_no = malloc(sizeof(NoFila));

    if (novo_no == NULL)
    {
        printf("Erro: Memoria insuficiente!\n");
        return;
    }

    novo_no -> cliente = cliente;
    novo_no ->proximo = NULL;
    if(fila_vazia(fila)){
        fila->inicio = novo_no;
    }
    else{
        fila->fim->proximo = novo_no;
    }

    fila->fim = novo_no;
    fila->tamanho++;
}


void imprimir_fila(Fila* fila){
    NoFila *atual = fila->inicio;
    int posicao = 1;

    printf("IMPRIMINDO CLIENTES DO BANCO\n");

    if(fila->tamanho == 0){
        printf("Nao ha clientes\n");
    }

    while (atual != NULL)
    {   
        printf("%dº a ser chamado: %s (CPF: %s)\n", posicao, atual->cliente.nome, atual->cliente.cpf);
        atual = atual->proximo;
        posicao++;
    }


}

bool desenfileirar(Fila* fila){
    if(fila_vazia(fila)){
        return false;
    }
    NoFila* no_remover = fila->inicio;

    printf("\n>> GUICHE 01: Chamando cliente %s CPF: %s <<\n\n", no_remover->cliente.nome, no_remover->cliente.cpf);

    fila->inicio = no_remover->proximo;


    if(fila->inicio == NULL){
        fila->fim=NULL;
    }

    free(no_remover);
    fila->tamanho--;
    return true;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lista.h"

void inicializar_lista(Lista *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

void adicionar_cliente(Lista *lista, Cliente cliente)
{
    No *novo_cliente = malloc(sizeof(No));
    if (novo_cliente == NULL)
    {
        printf("Erro: Memoria insuficiente!\n");
        return;
    }

    novo_cliente->cliente = cliente;
    novo_cliente->proximo = NULL;

    if (lista->inicio == NULL)
    {
        lista->inicio = novo_cliente;
    }
    else
    {
        lista->fim->proximo = novo_cliente;
    }

    lista->fim = novo_cliente; // fim agora aponta para o ultimo nó adicionado
    lista->tamanho++;
}

void imprimir_lista(Lista *lista)
{
    No *atual = lista->inicio;

    printf("IMPRIMINDO CLIENTES DO BANCO\n");

    if (lista->tamanho == 0)
    {
        printf("Nao ha clientes\n");
    }

    while (atual != NULL)
    {
        printf("nome: %s", atual->cliente.nome);
        printf("cpf: %s", atual->cliente.cpf);
        printf("Saldo: %f", atual->cliente.saldo);

        atual = atual->proximo;
    }

    printf("--------------------------");
}

No *buscar_cliente(Lista *lista, char cpf[])
{
    No *atual = lista->inicio;

    while (atual != NULL)
    {
        if (strcmp(cpf, atual->cliente.cpf) == 0)
        {
            return atual;
        }
        atual = atual->proximo;
    }

    return NULL;
}

bool remover_cliente(Lista *lista, char cpf[])
{
    No *atual = lista->inicio;
    No *anterior = NULL;

    while (atual != NULL && strcmp(cpf, atual->cliente.cpf) != 0)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL)
    {
        return false;
    }

    // Caso for o primeiro elemento
    if (anterior == NULL)
    {
        lista->inicio = atual->proximo;
    }
    else
    {
        // Caso ele estiver no meio ou no fim
        anterior->proximo = atual->proximo;
    }

    // Garantir que a lista aponta para o anterior que se tornou o ultimo da lista
    if (atual == lista->fim)
    {
        lista->fim = anterior;
    }

    free(atual);
    lista->tamanho--;
    return true;
}

void transferir_cliente(Lista *lista, char cpf_remetente[], char cpf_destinatario[])
{
    if (!buscar_cliente(lista, cpf_destinatario))
    {
        printf("Destinatário não existe");
        return;
    }
    if (!buscar_cliente(lista, cpf_remetente))
    {
        printf("Remetente não existe");
        return;
    }
    No *remetente = NULL;
    No *destinatario = NULL;
    No *temp = lista->inicio;
    float valor_transferencia = 0;

    while (temp != NULL)
    {
        if (strcmp(cpf_remetente, temp->cliente.cpf) == 0){
            remetente = temp;
        }
        if (strcmp(cpf_destinatario, temp->cliente.cpf) == 0){
            destinatario = temp;
        }
        temp = temp->proximo;
    }

    printf("quanto deseja transferir? ");
    scanf("%f", &valor_transferencia);
    if(remetente->cliente.saldo < valor_transferencia){
        printf("não tem money! ");
        return;
    }
    remetente->cliente.saldo -= valor_transferencia;
    destinatario->cliente.saldo += valor_transferencia;
    printf("%.2f saldo do remetente: \n", remetente->cliente.saldo);
    printf("%.2f saldo do destinatario: \n ", destinatario->cliente.saldo);

}

void busca_cliente(Lista *lista){
    char cpf_digitado[100];
    printf("digite o cpf: ");
    scanf("%s", cpf_digitado);
    No* cliente_encontrado = buscar_cliente(lista, cpf_digitado);

    if(cliente_encontrado != NULL){
        printf("cpf encontrado\n");
        printf("%s\n", cliente_encontrado->cliente.nome);
        printf("%s\n", cliente_encontrado->cliente.cpf);
        printf("%.2f", cliente_encontrado->cliente.saldo);


    }
    else{
        printf("cpf nao encontrado");
    }
}

void somageral_cliente(Lista *lista){

    if (lista == NULL || lista->inicio == NULL) {
        printf("A lista esta vazia! Nenhum saldo para somar.\n");
        return;
    }

    No *atual = lista->inicio;
    float soma = 0;

    while(atual != NULL){
        soma += atual->cliente.saldo;
        atual = atual ->proximo;

    }   

    printf("%.2f", soma);

}

void clientevip_cliente(Lista *lista){

    if (lista == NULL || lista->inicio == NULL) {
        printf("A lista esta vazia!\n");
        return;
    }
    
    No *atual = lista->inicio;
    No *cliente_rico = atual;

    while(atual != NULL){
        if(atual->cliente.saldo > cliente_rico->cliente.saldo){
            cliente_rico = atual;

        }
        atual = atual->proximo;

    }
    printf("CLIENTE VIP \n");
    printf("Nome: %s\n", cliente_rico->cliente.nome);
    printf("CPF: %s\n", cliente_rico->cliente.cpf);
    printf("Saldo: R$ %.2f\n", cliente_rico->cliente.saldo );
}

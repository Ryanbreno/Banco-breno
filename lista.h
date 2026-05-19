#ifndef LISTA_H
#define LISTA_H
#include "banco.h"

typedef struct No {
    Cliente cliente;
    struct No* proximo;
} No;

typedef struct Lista {
    No* inicio;
    No* fim; 
    int tamanho;
} Lista;

void inicializar_lista(Lista* lista);
void adicionar_cliente(Lista* lista, Cliente cliente);
void imprimir_lista(Lista* lista);
No* buscar_cliente(Lista* lista, char cpf[]);
bool remover_cliente(Lista* lista, char cpf[]);
void transferir_cliente(Lista* lista, char cpf_remetente[], char cpf_destinatario[]);
void busca_cliente(Lista *lista);
void somageral_cliente(Lista *lista);
void clientevip_cliente(Lista *lista);

#endif // LISTA_H
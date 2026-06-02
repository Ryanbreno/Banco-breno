#ifndef FILA_H
#define FILA_H
#include "banco.h"

typedef struct NoFila {
    Cliente cliente;
    struct NoFila* proximo;
} NoFila;

typedef struct Fila {
    NoFila* inicio;
    NoFila* fim; 
    int tamanho;
} Fila;

void inicializar_fila(Fila* fila);
bool fila_vazia(Fila* fila);
void enfileirar(Fila* fila, Cliente cliente);
void imprimir_fila(Fila* fila);
bool desenfileirar(Fila* fila);
void transferir_cliente(Lista *lista, char cpf_remetente[], char cpf_destinatario[]);



#endif
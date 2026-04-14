#include <stdio.h>
#ifndef BANCO_H
#define BANCO_H

typedef struct Cliente
{
    char nome[100];
    char cpf[100];
    float saldo;
} Cliente;

bool cliente_existe(Cliente *clientes, char cpf[], int n);
Cliente *buscarCPF(Cliente *clientes, int n, char cpf[]);
Cliente *criar_Clientes(int n);
void cadastrar_Cliente(Cliente *clientes, int n);
void listar_clientes(Cliente *clientes, int n);
void depositar(Cliente *clientes, int n, char cpf[]);
bool sacar(Cliente *clientes, int n, char cpf[]);
void transferir(Cliente *clientes, float valor, char cpf_origem[], int n, char cpf_destino[]);
void busca_cpf(Cliente *clientes, char cpf[], int n);


#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "banco.h"


bool cliente_existe(Cliente *clientes, char cpf[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(cpf, clientes[i].cpf) == 0)
        {
            return true;
        }
    }
    return false;
}

Cliente *buscarCPF(Cliente *clientes, int n, char cpf[])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(cpf, clientes[i].cpf) == 0)
        {
            return &clientes[i];
        }
    }
    return NULL;
}

Cliente *criar_Clientes(int n)
{
    Cliente *clientes = malloc(n * sizeof(Cliente));
    return clientes;
}

void cadastrar_Cliente(Cliente *clientes, int n)
{
    printf("digite seu nome: ");
    scanf("%s", clientes[n].nome);
    printf("Digite seu cpf: ");
    scanf("%s", clientes[n].cpf);
    printf("Digite o teu saldo: ");
    scanf("%f", &clientes[n].saldo);
}

void listar_clientes(Cliente *clientes, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("lista de clientes: %s\n", clientes[i].nome);
    }
}

void depositar(Cliente *clientes, int n, char cpf[])
{
    float valor;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(cpf, clientes[i].cpf) == 0)
        {
            printf("qual valor deseja depositar? ");
            scanf("%f", &valor);
            clientes[i].saldo += valor;
        }
    }
}

bool sacar(Cliente *clientes, int n, char cpf[])
{
    float valor_saque;
    Cliente *cliente = buscarCPF(clientes, n, cpf);
    if (cliente == NULL)
    {
        printf("Cliente nao existe!\n");
        return false;
    }

    printf("Qual valor deseja sacar?");
    scanf("%f", &valor_saque);

    if(cliente->saldo < valor_saque){
        printf("VOCÊ É DURO E NÃO TEM DINHEIRO!\n");
        return false;
    }
    else{
        cliente->saldo -= valor_saque;
        printf("Saque realizado! Novo saldo: R$ %.2f\n", cliente->saldo);
        return true;
    }
}

void transferir(Cliente *clientes, float valor, char cpf_origem[], int n, char cpf_destino[]){
    Cliente *remetente = buscarCPF(clientes, n, cpf_origem);
    if(remetente == NULL){
        printf("Usuario não existe! ");
    }
    Cliente *destinatario = buscarCPF(clientes, n, cpf_destino);
    if(destinatario == NULL){
        printf("Usuario não existe! ");
    }

    float valor_transferencia;
    printf("digite o valor que deseja enviar: ");
    scanf("%f", &valor_transferencia);
    if(remetente->saldo < valor_transferencia){
        printf("VOCÊ É DURO! NAO TEM MONEY. ");
    }
    else{
        remetente->saldo -= valor_transferencia;
        destinatario->saldo += valor_transferencia;
        printf("Transferencia de R$ %.2f realizada com sucesso!\n", valor_transferencia);
        printf("Seu novo saldo: R$ %.2f\n", remetente->saldo);
    }
}

void busca_cpf(Cliente *clientes, char cpf[], int n){

    Cliente *cliente = buscarCPF(clientes, n, cpf);
    if(cliente == NULL){
        printf("usuario invalido! ");
    }
    else{
        printf("Nome: %s\n", cliente->nome);
        printf("Saldo: R$ %.2f\n", cliente->saldo);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "banco.h"
#include "lista.h"


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

void cadastrar_Cliente(Cliente* novo_cliente)
{
    printf("digite seu nome: ");
    scanf("%s", novo_cliente->nome);
    printf("Digite seu cpf: ");
    scanf("%s", novo_cliente->cpf);
    printf("Digite o teu saldo: ");
    scanf("%f", &novo_cliente->saldo);
}

void listar_clientes(Cliente *clientes, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("lista de clientes: %s\n", clientes[i].nome);
    }
}

void depositar(Lista* clientes, char cpf[])
{
    No* no_cliente = buscar_cliente(clientes, cpf);
    float valor;
   
    if (strcmp(cpf, no_cliente->cliente.cpf) == 0)
    {
        printf("qual valor deseja depositar? ");
        scanf("%f", &valor);
        no_cliente->cliente.saldo += valor;
    }
}

void sacar(Lista* clientes, char cpf[])
{
    float valor_saque;
    No* no_cliente = buscar_cliente(clientes, cpf);
    if (no_cliente == NULL)
    {
        printf("Cliente nao existe!\n");
        return;
    }

    printf("Qual valor deseja sacar?");
    scanf("%f", &valor_saque);

    if(no_cliente->cliente.saldo < valor_saque){
        printf("VOCÊ É DURO E NÃO TEM DINHEIRO!\n");
        return;
    }
    else{
        no_cliente->cliente.saldo -= valor_saque;
        printf("Saque realizado! Novo saldo: R$ %.2f\n", no_cliente->cliente.saldo);
        return;
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

float balanco_total(Cliente *clientes, int n) {
    float soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += clientes[i].saldo;
    }
    return soma;
}

void cliente_vip(Cliente *clientes, int n) {
    if (n <= 0) {
        printf("Nenhum cliente cadastrado no banco ainda!\n");
        return;
    }
    int indice_vip = 0;
    for (int i = 1; i < n; i++) {
        if (clientes[i].saldo > clientes[indice_vip].saldo) {
            indice_vip = i;
        }
    }
    printf("CLIENTE VIP \n");
    printf("Nome: %s\n", clientes[indice_vip].nome);
    printf("CPF: %s\n", clientes[indice_vip].cpf);
    printf("Saldo: R$ %.2f\n", clientes[indice_vip].saldo);
}

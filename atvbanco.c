#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Cliente
{
    char nome[100];
    char cpf[100];
    float saldo;
} Cliente;

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

// void transferir(Cliente *clientes, Cliente *d, float valor, char cpf[], int n, char CPF_TRANSFERIR[]){
//     float valor_transferir;
//     for(int i = 0; i < n; i++){
//         if(strcmp(CPF_TRANSFERIR
//     }
// }

int main()
{

    Cliente *clientes;
    int opcao = 0, n;
    float deposito;
    char cpf[100];
    char CPF_TRANSFERIR[100];

    while(opcao != 7)
    {

        printf("\n BEM-VINDO AO BANCO MASTER\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Depositar\n");
        printf("4 - Sacar\n");
        printf("5- Transferir\n");
        printf("6- Buscar por cpf\n");
        printf("7- sair\n");
        printf("digite: \n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Quantos clientes deseja cadastrar? ");
            scanf("%d", &n);
            clientes = criar_Clientes(n);
            for (int i = 0; i < n; i++)
            {
                printf("Cliente %d:\n", i + 1);
                cadastrar_Cliente(clientes, i);
            }
            break;
        case 2:
            listar_clientes(clientes, n);
            break;
        case 3:
            printf("Qual seu cpf? ");
            scanf("%s", cpf);
            depositar(clientes, n, cpf);
            break;
        case 4:
            printf("Qual seu cpf? ");
            scanf("%s", cpf);
            sacar(clientes, n, cpf);
            break;
        case 5:
            printf("Qual seu cpf? ");
            scanf("%s", cpf);
            printf("digite o cpf da pessoa que deseja transferir: ");
            scanf("%s", CPF_TRANSFERIR);
        }
    }
}
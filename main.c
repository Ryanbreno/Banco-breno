#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "banco.h"

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
            transferir(clientes, 0, cpf, n, CPF_TRANSFERIR);

        case 6:
            printf("Qual o cpf deseja buscar? ");
            scanf("%s", cpf);
            busca_cpf(clientes, cpf, n);

        }

    }
}

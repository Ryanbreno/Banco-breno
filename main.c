#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "banco.h"
#include "lista.h"

int main()
{

    Lista* clientes;
    inicializar_lista(clientes);
    int opcao = 0, n;
    char cpf[100];
    char CPF_TRANSFERIR[100];

    while(opcao != 9)
    {

        printf("\n BEM-VINDO AO BANCO MASTER\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Depositar\n");
        printf("4 - Sacar\n");
        printf("5-  Transferir\n");
        printf("6-  Buscar por cpf\n");
        printf("7 - Ver balanço total\n");
        printf("8 - Ver o cliente vip\n");
        printf("9 - Sair\n");
        printf("digite: \n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Cadastro de novo cliente: \n");
            Cliente novo_cliente;
            cadastrar_Cliente(&novo_cliente);
            adicionar_cliente(clientes, novo_cliente);

            break;
        case 2:
            imprimir_lista(clientes);
            break;
        case 3:
            printf("Qual seu cpf? ");
            scanf("%s", cpf);
            depositar(clientes, cpf);
            break;
        case 4:
            printf("Qual seu cpf? ");
            scanf("%s", cpf);
            sacar(clientes, cpf);
            break;
        // case 5:
        //     printf("Qual seu cpf? ");
        //     scanf("%s", cpf);
        //     printf("digite o cpf da pessoa que deseja transferir: ");
        //     scanf("%s", CPF_TRANSFERIR);
        //     transferir(clientes, 0, cpf, n, CPF_TRANSFERIR);

        // case 6:
        //     printf("Qual o cpf deseja buscar? ");
        //     scanf("%s", cpf);
        //     busca_cpf(clientes, cpf, n);
        // case 7:
        //     printf("O balanco total do Banco Master é: R$ %.2f\n", balanco_total(clientes, n));
        //     break;

        // case 8:
        //     cliente_vip(clientes, n);
        //     break;
            
        case 9:
            printf("Saindo do sistema... Ate logo!\n");
            break;
        
        default:
            if (opcao != 9) {
                printf("Opcao invalida!\n");
            }
            break;
        }

    }
}

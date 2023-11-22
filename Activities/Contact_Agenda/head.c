#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include <string.h>
#include <stdbool.h>

int menu()
{
    int op;
    printf("1 - Cadastrar contato\n2 - Buscar contato\n3 - Excluir contato\n4 - Editar contato\n5 - Listar contatos\n6 - Sair\n");
    scanf("%d", &op);
    return op;
}

void cadastrarContato(contato *pessoa)
{
    pessoa[100];
    int i;
    bool numero_valido = false;
    printf("Insira -1 no nome do contado para sair\n");
    for (i = 0; i < count; i++)
    {
        printf("Digite o nome do contato: ");
        fgets(pessoa[i].nome, 50, stdin);
        pessoa[i].nome[strcspn(pessoa[i].nome, "\n")] = '\0';
        if (strcmp(pessoa[i].nome, "-1") == 0)
        {
            break;
        }
        do
        {
            printf("Digite o telefone do contato: ");
            fgets(pessoa[i].telefone, 20, stdin);
            pessoa[i].telefone[strcspn(pessoa[i].telefone, "\n")] = '\0';

            if (isdigit(pessoa[i].telefone) == 0)
            {
                printf(red "Digite apenas numeros no telefone!\n" reset);
                numero_valido = true;
                break;
            }
        } while (numero_valido == true);

        printf("Digite o email do contato: ");
        fgets(pessoa[i].email, 50, stdin);
        pessoa[i].email[strcspn(pessoa[i].email, "\n")] = '\0';

        printf(green "Contato cadastrado com sucesso!\n", reset);
    }
}

void buscarContato(contato pessoa)
{
    pessoa[100];
    int i;
    char nome[50];
    printf("Digite o nome do contato que deseja buscar: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    for (i = 0; i < count; i++)
    {
        if (strcmp(pessoa[i].nome, nome) == 0)
        {
            printf("Nome: %s\nTelefone: %s\nEmail: %s\n", pessoa[i].nome, pessoa[i].telefone, pessoa[i].email);
        }
    }
}
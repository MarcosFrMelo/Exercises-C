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

void cadastrarContato(agenda *agendas)
{
    int i;
    for (i = agendas->quantidade; i < 100; i++)
    {
        printf("Insira o nome do contato: ");
        fgets(agendas->contato[i].nome, 50, stdin);
        agendas->contato[i].nome[strcspn(agendas->contato[i].nome, "\n")] = '\0';

        if (agendas->contato[i].nome == -1)
        {
            return;
        }

        do
        {
            printf("Insira o telefone do contato: ");
            fgets(agendas->contato[i].telefone, 20, stdin);
            agendas->contato[i].telefone[strcspn(agendas->contato[i].telefone, "\n")] = '\0';

            if (isdigit(agendas->contato[i].telefone) == false)
            {
                printf("Insira apenas numeros\n");
            }

        } while (isdigit(agendas->contato[i].telefone) == false);

        printf("Insira o email do contato: ");
        fgets(agendas->contato[i].email, 50, stdin);
        agendas->contato[i].email[strcspn(agendas->contato[i].email, "\n")] = '\0';

        agendas->quantidade++;
        printf(green "Contato cadastrado com sucesso!\n", reset);
    }
}

void buscarContato(agenda pessoa)
{
    char nome[50];
    int i;
    bool contatoEncontrado = false;
    printf("Insira o nome do contato que deseja buscar: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (i = 0; i < pessoa.quantidade; i++)
    {
        if (nome == pessoa.contato[i].nome)
        {
            printf("------------------------------------------------------------\n");
            printf(green "Nome: %s\nTelefone: %s\nEmail: %s\n", pessoa.contato[i].nome, pessoa.contato[i].telefone, pessoa.contato[i].email, reset);
            printf("------------------------------------------------------------\n");
            system("pause");
            return;
        }
        else
        {
            contatoEncontrado = false;
        }
    }
    if (contatoEncontrado == false)
    {
        printf(red "Contato nao encontrado!\n", reset);
    }
}
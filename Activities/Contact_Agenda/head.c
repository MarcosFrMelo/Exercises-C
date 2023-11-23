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
    int i, j;
    bool numeroValido = false;
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
            for (j = 0; j < 20; j++)
            {
                if (!isdigit(agendas->contato[i].telefone[j]))
                {
                    numeroValido = false;
                    printf(red "Numero invalido!\n", reset);
                    break;
                }
                numeroValido = true;
            }
        } while (numeroValido == false);

        printf("Insira o email do contato: ");
        fgets(agendas->contato[i].email, 50, stdin);
        agendas->contato[i].email[strcspn(agendas->contato[i].email, "\n")] = '\0';

        agendas->quantidade++;
        printf(green "Contato cadastrado com sucesso!\n", reset);
    }
}

void printarMensagem(agenda agendas, int i)
{
    printf("------------------------------------------------------------\n");
    printf(green "Nome: %s\nTelefone: %s\nEmail: %s\n", agendas.contato[i].nome, agendas.contato[i].telefone, agendas.contato[i].email, reset);
    printf("------------------------------------------------------------\n");
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
            printarMensagem(pessoa, i);
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

void excluirContato(agenda *agendas)
{
    char nome[50];
    int i, j;
    int opcao;
    bool contatoEncontrado = false;

    printf("Insira o nome do contato que deseja excluir: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (i = 0; i < agendas->quantidade; i++)
    {
        if (nome == agendas->contato[i].nome)
        {
            printarMensagem(*agendas, i);
            printf("Deseja realmente excluir este contato?\n1 - Sim\n2 - Nao\n");
            scanf("%d", &opcao);

            if (opcao == 1)
            {
                for (j = i; j < agendas->quantidade; j++)
                {
                    agendas->contato[j] = agendas->contato[j + 1];
                }
                agendas->quantidade--;
                printf(green "Contato excluido com sucesso!\n", reset);
                system("pause");
                return;
            }
            else
            {
                return;
            }
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

void editarContato(agenda *agendas)
{
    char nome[50];
    int i, j;
    int opcao;
    bool contatoEncontrado = false;

    printf("Insira o nome do contato que deseja editar: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (i = 0; i < agendas->quantidade; i++)
    {
        if (nome == agendas->contato[i].nome)
        {
            printarMensagem(*agendas, i);
            printf("Deseja realmente editar este contato?\n1 - Sim\n2 - Nao\n");
            scanf("%d", &opcao);

            if (opcao == 1)
            {
                printf("O que deseja editar?\n1 - Nome\n2 - Telefone\n3 - Email\n4 - Tudo\n");
            }
            else
            {
                return;
            }
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

void listarContatos(agenda agendas)
{
    int i;
    for (i = 0; i < agendas.quantidade; i++)
    {
        printarMensagem(agendas, i);
    }
    system("pause");
}

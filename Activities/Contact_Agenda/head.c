#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define green "\033[0;32m"
#define red "\033[0;31m"
#define reset "\033[0m"

typedef struct
{
    char nome[50];
    long int telefone;
    char email[100];
} pessoa;

typedef struct
{
    pessoa contato[100];
    int quantidade;
} agenda;

void printarMensagem(agenda agendas, int i)
{
    printf("------------------------------------------------------------\n");
    printf("Contato %d:\n", i + 1);
    printf(green "Nome: %s\nTelefone: %ld\nEmail: %s\n", agendas.contato[i].nome, agendas.contato[i].telefone, agendas.contato[i].email);
    printf(reset);
    printf("------------------------------------------------------------\n");
}

void cadastrarContato(agenda *agendas)
{
    int i, j;

    for (i = agendas->quantidade; i < 100; i++)
    {
        while ((getchar()) != '\n')
            ;
        Nome(agendas, i);
        Telefone(agendas, i);
        Email(agendas, i);

        agendas->quantidade += 1;
        printf("Deseja cadastrar outro contato?\n1 - Sim\n2 - Nao\n");
        scanf("%d", &j);

        if (j == 2)
        {
            return;
        }
    }
}

void buscarContato(agenda agendas)
{
    char nome[50];
    int i;
    bool contatoEncontrado = true;

    if (agendas.quantidade == 0)
    {
        printf(red "Nao ha contatos cadastrados!\n");
        printf(reset);
        system("pause");
        return;
    }

    while ((getchar()) != '\n')
        ;
    printf("Insira o nome do contato que deseja buscar: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (i = 0; i < agendas.quantidade; i++)
    {
        if (strcmp(nome, agendas.contato[i].nome) == 0)
        {
            printarMensagem(agendas, i);
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
        printf(red "Contato nao encontrado!\n");
        printf(reset);
        system("pause");
    }
}

void excluirContato(agenda *agendas)
{
    char nome[50];
    int i, j;
    int opcao;
    bool contatoEncontrado = true;

    if (agendas->quantidade == 0)
    {
        printf(red "Nao ha contatos cadastrados!\n");
        printf(reset);
        system("pause");
        return;
    }

    while ((getchar()) != '\n')
        ;
    printf("Insira o nome do contato que deseja excluir: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (i = 0; i < agendas->quantidade; i++)
    {
        if (strcmp(nome, agendas->contato[i].nome) == 0)
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
                printf(green "Contato excluido com sucesso!\n");
                printf(reset);
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
        printf(red "Contato nao encontrado!\n");
        printf(reset);
        system("pause");
    }
}

void editarContato(agenda *agendas)
{
    char nome[50];
    int i;
    int opcao, opcao2;
    bool contatoEncontrado = true;

    if (agendas->quantidade == 0)
    {
        printf(red "Nao ha contatos cadastrados\n");
        printf(reset);
        system("pause");
        return;
    }

    while ((getchar()) != '\n')
        ;
    printf("Insira o nome do contato que deseja editar: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (i = 0; i < agendas->quantidade; i++)
    {

        if (strcmp(nome, agendas->contato[i].nome) == 0)
        {
            contatoEncontrado = true;
            printarMensagem(*agendas, i);
            printf("Deseja realmente editar este contato?\n1 - Sim\n2 - Nao\n");
            scanf("%d", &opcao);

            if (opcao == 1)
            {
                printf("O que deseja editar?\n1 - Nome\n2 - Telefone\n3 - Email\n4 - Tudo\n5 - Sair\n");
                scanf("%d", &opcao2);
                switch (opcao2)
                {
                case 1:
                    Nome(agendas, i);
                    break;
                case 2:
                    Telefone(agendas, i);
                    break;
                case 3:
                    Email(agendas, i);
                    break;
                case 4:
                    Nome(agendas, i);
                    Telefone(agendas, i);
                    Email(agendas, i);
                    break;
                case 5:
                    return;
                default:
                    printf(red "Opcao invalida!\n");
                    printf(reset);
                    system("pause");
                    break;
                }
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
        printf(red "Contato nao encontrado!\n");
        printf(reset);
        system("pause");
    }
}

void listarContatos(agenda agendas)
{
    int i;
    if (agendas.quantidade == 0)
    {
        printf(red "Nao ha contatos cadastrados!\n");
        printf(reset);
        system("pause");
        return;
    }

    for (i = 0; i < agendas.quantidade; i++)
    {
        printarMensagem(agendas, i);
    }
    system("pause");
}

void Nome(agenda *agendas, int i)
{
    while ((getchar()) != '\n')
        ;
    printf("Insira o nome do contato: ");
    fgets(agendas->contato[i].nome, 50, stdin);
    agendas->contato[i].nome[strcspn(agendas->contato[i].nome, "\n")] = '\0';
}

void Telefone(agenda *agendas, int i)
{
    bool telefoneValido = true;
    do
    {
        printf("Insira o telefone do contato: ");
        scanf("%ld", &agendas->contato[i].telefone);

        if (isdigit(agendas->contato[i].telefone))
        {
            printf(red "Telefone invalido!\n");
            printf(reset);
            telefoneValido = false;
            system("pause");
        }

    } while (telefoneValido == false);
}

void Email(agenda *agendas, int i)
{
    while ((getchar()) != '\n')
        ;
    printf("Insira o email do contato: ");
    fgets(agendas->contato[i].email, 100, stdin);
    agendas->contato[i].email[strcspn(agendas->contato[i].email, "\n")] = '\0';

    return;
}

void carregarDados(agenda *agendas)
{
    FILE *arq;
    int i;

    arq = fopen("agenda.bin", "rb");
    if (arq == NULL)
    {
        printf(red "Erro ao abrir o arquivo!\n");
        printf(reset);
        system("pause");
        return;
    }

    fread(&agendas->quantidade, sizeof(int), 1, arq);
    for (i = 0; i < agendas->quantidade; i++)
    {
        fread(&agendas->contato[i], sizeof(pessoa), 1, arq);
    }
    fclose(arq);
    printf(green "Dados carregados com sucesso!\n");
    printf(reset);
    system("pause");
}

void salvarDados(agenda *agendas)
{
    FILE *arq;
    int i;

    arq = fopen("agenda.bin", "wb");
    if (arq == NULL)
    {
        printf(red "Erro ao abrir o arquivo!\n");
        printf(reset);
        system("pause");
        return;
    }

    fwrite(&agendas->quantidade, sizeof(int), 1, arq);
    for (i = 0; i < agendas->quantidade; i++)
    {
        fwrite(&agendas->contato[i], sizeof(pessoa), 1, arq);
    }
    fclose(arq);
    printf(green "Dados salvos com sucesso!\n");
    printf(reset);
    system("pause");
}
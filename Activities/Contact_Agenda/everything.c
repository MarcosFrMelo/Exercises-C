#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define green "\033[0;32m"
#define red "\033[0;31m"
#define reset "\x1b[0m"

typedef struct
{
    char nome[50];
    long telefone[20];
    char email[100];
} pessoa;

typedef struct
{
    pessoa contato[100];
    int quantidade;
} agenda;

int menu();
void cadastrarContato(agenda *agendas);
void buscarContato(agenda agendas);
void excluirContato(agenda *agendas);
void editarContato(agenda *agendas);
void listarContatos(agenda agendas);
void Nome(agenda *agendas, int i);
void Telefone(agenda *agendas, int i);
void Email(agenda *agendas, int i);
void carregarDados(agenda *agendas);
void salvarDados(agenda *agendas);

int main()
{
    agenda agendas;
    agendas.quantidade = 0;
    int opcao;
    while (1)
    {
        system("cls");
        printf("Insira a opcao desejada:\n1 - Adicionar contatos\n2 - Buscar contatos\n3 - Excluir contatos\n4 - Editar contatos\n5 - Listar contatos\n6 - Sair\n7 - Salvar\n8 - Carregar\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            cadastrarContato(&agendas);
            break;
        case 2:
            buscarContato(agendas);
            break;
        case 3:
            excluirContato(&agendas);
            break;
        case 4:
            editarContato(&agendas);
            break;
        case 5:
            listarContatos(agendas);
            break;
        case 6:
            printf(green "Finalizando programa");
            printf(reset);
            return;
        case 7:
            salvarDados(&agendas);
            break;
        case 8:
            carregarDados(&agendas);
            break;
        default:
            printf(red "Opcao invalida!\n");
            printf(reset);
            system("pause");
            break;
        }
    }
}

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
        printf(red "Nao ha contatos cadastrados!\n", reset);
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
        printf(red "Contato nao encontrado!\n", reset);
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
        printf(red "Nao ha contatos cadastrados!\n", reset);
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
        printf(reset);
        system("pause");
    }
}

void editarContato(agenda *agendas)
{
    char nome[50];
    int i;
    int opcao, opcao2;
    bool contatoEncontrado = false;

    if (agendas->quantidade == 0)
    {
        printf(red "Nao ha contatos cadastrados!\n", reset);
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
                    printf(red "Opcao invalida!\n", reset);
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
        printf(red "Contato nao encontrado!\n", reset);
        printf(reset);
        system("pause");
    }
}

void listarContatos(agenda agendas)
{
    int i;
    if (agendas.quantidade == 0)
    {
        printf(red "Nao ha contatos cadastrados!\n", reset);
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
    int j;

    while ((getchar()) != '\n')
        ;
    printf("Insira o nome do contato: ");
    fgets(agendas->contato[i].nome, 50, stdin);
    agendas->contato[i].nome[strcspn(agendas->contato[i].nome, "\n")] = '\0';
}

void Telefone(agenda *agendas, int i)
{
    int j;

    printf("Insira o telefone do contato: ");
    scanf("%d", &agendas->contato[i].telefone);
    agendas->contato[i].telefone[strcspn(agendas->contato[i].telefone, "\n")] = '\0';
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
        printf(red "Erro ao abrir o arquivo!\n", reset);
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
    printf(green "Dados carregados com sucesso!\n", reset);
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
        printf(red "Erro ao abrir o arquivo!\n", reset);
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
    printf(green "Dados salvos com sucesso!\n", reset);
    printf(reset);
    system("pause");
}
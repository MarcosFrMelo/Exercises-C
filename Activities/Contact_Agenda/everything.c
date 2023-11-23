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
    char telefone[20];
    char email[50];
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

int main()
{
    agenda agendas;
    agendas.quantidade = 0;
    int opcao;
    while (1)
    {
        system("cls");
        printf("Insira a opcao desejada:\n1 - Adicionar contatos\n2 - Buscar contatos\n3 - Excluir contatos\n4 - Editar contatos\n5 - Listar contatos\n6 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("%d", opcao);
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
    printf(green "Nome: %s\nTelefone: %s\nEmail: %s\n", agendas.contato[i].nome, agendas.contato[i].telefone, agendas.contato[i].email, reset);
    printf("------------------------------------------------------------\n");
}

void cadastrarContato(agenda *agendas)
{
    int i, j;
    int teste;

    for (i = agendas->quantidade; i < 100; i++)
    {
        while ((getchar()) != '\n');
        Nome(&agendas, i);
        Telefone(&agendas, i);
        Email(&agendas, i);
        agendas->quantidade++;

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
    
    while ((getchar()) != '\n'); // Limpa o buffer de entrada
    printf("Insira o nome do contato que deseja buscar: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (i = 0; i < agendas.quantidade; i++)
    {
        if (nome == agendas.contato[i].nome)
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
        system("pause");
    }
}

void excluirContato(agenda *agendas)
{
    char nome[50];
    int i, j;
    int opcao;
    bool contatoEncontrado = true;
    
    while ((getchar()) != '\n');
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
    int i;
    int opcao, opcao2;
    bool contatoEncontrado = false;
    
    while ((getchar()) != '\n');
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
                scanf("%d", &opcao2);
                switch (opcao2)
                {
                case 1:
                    Nome(&agendas, i);
                    break;
                case 2:
                    Telefone(&agendas, i);
                    break;
                case 3:
                    Email(&agendas, i);
                    break;
                case 4:
                    Nome(&agendas, i);
                    Telefone(&agendas, i);
                    Email(&agendas, i);
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

void Nome(agenda *agendas, int i)
{
    int j;
    bool nomeValido;
    do
    {
        while ((getchar()) != '\n');
        printf("Insira o nome do contato: ");
        fgets(agendas->contato[i].nome, 50, stdin);
        agendas->contato[i].nome[strcspn(agendas->contato[i].nome, "\n")] = '\0';
        nomeValido = true;
        for (j = 0; j < 50; i++)
        {
            if (!isalpha(agendas->contato[i].nome[j]) == false)
            {
                printf(red "Nome invalido!\n", reset);
                nomeValido = false;
                break;
            }
        }
    } while (nomeValido == false);

    printf(green "Nome editado com sucesso!\n", reset);
}

void Telefone(agenda *agendas, int i)
{
    int j;
    bool numeroValido = false;
    do
    {
        while ((getchar()) != '\n');
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

    printf(green "Telefone editado com sucesso!\n", reset);
}

void Email(agenda *agendas, int i)
{
    while ((getchar()) != '\n');
    printf("Insira o email do contato: ");
    fgets(agendas->contato[i].email, 50, stdin);
    agendas->contato[i].email[strcspn(agendas->contato[i].email, "\n")] = '\0';

    printf(green "Email editado com sucesso!\n", reset);
}
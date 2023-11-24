/* Crie um programa em C para gerenciar uma agenda de contatos. O programa deve permitir:

Adicionar contatos (cada contato terá um nome, telefone e email).
Buscar contatos pelo nome.
Excluir contatos.
editar contatos.

Listar todos os contatos da agenda. */
#include <stdio.h>
#include "head.h"

#define green "\033[0;32m"
#define red "\033[0;31m"
#define reset "\033[0m"

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
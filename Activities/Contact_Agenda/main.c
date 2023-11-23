/* Crie um programa em C para gerenciar uma agenda de contatos. O programa deve permitir:

Adicionar contatos (cada contato terá um nome, telefone e email).
Buscar contatos pelo nome.
Excluir contatos.
editar contatos.

Listar todos os contatos da agenda. */
#include <stdio.h>
#include "head.h"

#define green "\033[0;32m"
#define red "\033[0;31m
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
    while (1)
    {
        system("cls");
        int resultado;
        resultado = menu();
        switch (resultado)
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
            printf(green "Finalizando programa", reset);
            return;
        default:
            break;
        }

    }
}
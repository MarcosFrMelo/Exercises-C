/* Crie um programa em C para gerenciar uma agenda de contatos. O programa deve permitir:

Adicionar contatos (cada contato terá um nome, telefone e email).
Buscar contatos pelo nome.
Excluir contatos.
editar contatos.

Listar todos os contatos da agenda. */
#include <stdio.h>
#include "head.h"

int main()
{
    agenda agendas;
    do
    {

        switch (menu())
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
            listarContatos(&agendas);
            break;
        case 6:
            break;
        default:
            break;
        }

    } while (menu() != 6);
}
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
    contato contatos[100];
    do
    {

        switch (menu())
        {
        case 1:
            cadastrarContato(&contatos);
            break;
        case 2:
            buscarContato(contatos);
            break;
        case 3:
            excluirContato(&contatos);
            break;
        case 4:
            editarContato(&contatos);
            break;
        case 5:
            listarContatos(&contatos);
            break;
        case 6:
            break;
        default:
            break;
        }

    } while (menu() != 6);
}
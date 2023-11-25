
#include "head.h"

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
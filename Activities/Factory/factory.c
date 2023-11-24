#include <stdio.h>

// Uma fábrica de argamassas vende 3 produtos: argamassa AC3 20kg, argamassa AC2 20kg e rejunte
// 5kg. Suas entregas são feitas em Palmas ou Porto Nacional. Durante o último ano, esta fábrica
// manteve registros de pedidos de 2 grandes clientes. Cada cliente fez um número indeterminado de
// pedidos (no máximo 10), sendo que cada pedido tem o tipo do produto, a quantidade de pacotes e a
// localidade da entrega.
// Faça um programa em Linguagem C que leia os dados dos pedidos de cada cliente e imprima um
// dos seguintes relatórios:
//- Relatório por pedido: dado o número do cliente e do pedido, mostre o tipo e a quantidade do
// produto, a localidade e o valor do frete.
//- Relatório por cliente: dado o número do cliente mostre a média de peso dos seus pedidos e o
// número de pedidos feitos no período.
//- Relatório geral: mostre quantos kg de material foram vendidos no período e quais pedidos
// tem menos de 1000kg.
// Após imprimir um relatório, deve ser possível ao usuário imprimir outro caso queira.
// Obs.:
// Cálculo do frete: Se o pedido tem menos que 1000kg, o frete é grátis. Se tem de 1001kg a 2000kg, o
// frete é R$ 100,00 para Palmas e 200,00 para Porto Nacional. Se tiver mais que 2000kg, o valor do
// frete será 2 reais por pacote.

typedef struct
{
    char tipo[20];
    int quantidade;
    char localidade[20];
} pedido;

typedef struct
{
    pedido pedidos[10];
    int quantidade;
} cliente;

void cadastrarPedido(cliente *clientes);
void relatorioPedido(cliente clientes);
void relatorioCliente(cliente clientes);
void relatorioGeral(cliente clientes);
void tipo(cliente *clientes, int i);
void quantidade(cliente *clientes, int i);
void localidade(cliente *clientes, int i);
void carregarDados(cliente *clientes);
void salvarDados(cliente *clientes);

int main()
{
    cliente clientes;
    clientes.quantidade = 0;
    int opcao;
    while (1)
    {
        system("cls");
        printf("Insira a opcao desejada:\n1 - Cadastrar pedido\n2 - Relatorio por pedido\n3 - Relatorio por cliente\n4 - Relatorio geral\n5 - Sair\n6 - Salvar\n7 - Carregar\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarPedido(&clientes);
            break;
        case 2:
            relatorioPedido(clientes);
            break;
        case 3:
            relatorioCliente(clientes);
            break;
        case 4:
            relatorioGeral(clientes);
            break;
        case 5:
            return 0;
        case 6:
            salvarDados(&clientes);
            break;
        case 7:
            carregarDados(&clientes);
            break;
        case 8:
            printf("Finalizando programa");
            return 0;
        default:
            printf("Opcao invalida\n");
            break;
        }
        system("pause");
    }
}

void cadastrarPedido(cliente *clientes)
{
    if (clientes->quantidade >= 10)
    {
        printf("Numero maximo de pedidos atingido\n");
        return;
    }
    
}

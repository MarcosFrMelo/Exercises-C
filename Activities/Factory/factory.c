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
    int tipo;
    int quantidade;
    int localidade[20];
} pedido;

typedef struct
{
    pedido pedidos[10];
    int quantidadeGeral;
    int quantidadePedidos;
} cliente;

void cadastrarPedido(cliente *clientes);
void relatorioPedido(cliente clientes);
void relatorioCliente(cliente clientes[]);
void relatorioGeral(cliente clientes);
void editar(cliente *clientes);
void excluir(cliente *clientes);
void tipo(cliente *clientes, int i, int j);
void quantidade(cliente *clientes, int i, int j);
void localidade(cliente *clientes, int i, int j);
void carregarDados(cliente *clientes);
void salvarDados(cliente *clientes, int i, int j);
void calcularFrete(cliente clientes[]);
int peso(cliente clientes[], int i, int j);

int main()
{
    cliente clientes[2] = {0};
    int opcao;
    while (1)
    {
        system("cls");
        printf("Insira a opcao desejada:\n1 - Cadastrar pedido\n2 - Relatorio por pedido\n3 - Relatorio por cliente\n4 - Relatorio geral\n5 - Sair\n6 - Salvar\n7 - Carregar\n8 - Calcular frete\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarPedido(&clientes);
            break;
        case 2:
            relatorioPedido(clientes[2]);
            break;
        case 3:
            relatorioCliente(clientes);
            break;
        case 4:
            relatorioGeral(clientes[2]);
            break;
        case 5:
            return 0;
        case 6:
           
        case 8:
            calcularFrete(clientes);
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
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("Cliente %d\n", i + 1);
        if (clientes[i].quantidadePedidos < 10)
        {
            int j;
            for (j = clientes[i].quantidadePedidos; i < 10; i++)
            {
                printf("Pedido %d\n", j + 1);
                tipo(clientes, i, j);
                quantidade(clientes, i, j);
                localidade(clientes, i, j);

                clientes[i].quantidadePedidos++;

                int opcao;

                printf("Deseja cadastrar outro pedido?\n1 - Sim\n2 - Nao\n");
                scanf("%d", &opcao);
                if (opcao == 2)
                {
                    break;
                }
            }
        }
        else
        {
            printf("Numero maximo de pedidos atingido no cliente %d\n", i + 1);
            break;
        }
        int opcao2;
        printf("Deseja cadastrar outro pedido?\n1 - Sim\n2 - Nao\n");
        scanf("%d", &opcao2);

        if (opcao2 == 2)
        {
            break;
        }
    }
}

void relatorioPedido(cliente clientes)
{
    int numCliente, numPedido;
    printf("Insira o numero do cliente\n");
    scanf("%d", &numCliente);
    printf("Insira o numero do pedido\n");
    scanf("%d", &numPedido);
    printf("-------------------------------------------------\n");
    printf("Tipo: %d\nQuantidade: %d\nLocalidade: %s\n", clientes.pedidos[numPedido - 1].tipo, clientes.pedidos[numPedido - 1].quantidade, clientes.pedidos[numPedido - 1].localidade);
    printf("-------------------------------------------------\n");
}

void relatorioCliente(cliente clientes[])
{
    int numCliente;
    int i, divisao;

    printf("Insira o numero do cliente\n");
    scanf("%d", &numCliente);

    for (i = 0; i < clientes[numCliente - 1].quantidadePedidos; i++)
    {
        printf("-------------------------------------------------\n");
        printf("Pedido %d\n", i + 1);
        printf("Tipo: %d\nQuantidade: %d\nLocalidade: %s\n", clientes[numCliente - 1].pedidos[i].tipo, clientes[numCliente - 1].pedidos[i].quantidade, clientes[numCliente - 1].pedidos[i].localidade);
        divisao = clientes[numCliente - 1].quantidadeGeral / clientes[numCliente - 1].quantidadePedidos;
        printf("-------------------------------------------------\n");
    }
    printf("Media de peso dos pedidos: %d\n", divisao);
}

void relatorioGeral(cliente clientes)
{
}

void editar(cliente *clientes)
{
    int numCliente, numPedido, opcao, i;
    printf("Insira o numero do cliente\n");
    scanf("%d", &numCliente);

    for (i = 0; i < clientes[numCliente].quantidadePedidos; i++)
    {
        printf("-------------------------------------------------\n");
        printf("Pedido %d\n", i + 1);
        printf("Tipo: %d\nQuantidade: %d\nLocalidade: %s\n", clientes[numCliente].pedidos[i].tipo, clientes[numCliente].pedidos[i].quantidade, clientes[numCliente].pedidos[i].localidade);
        printf("-------------------------------------------------\n");
    }
    printf("Insira o numero do pedido que deseja editar\n");
    scanf("%d", &numPedido);

    printf("Tem certeza que deseja editar o pedido %d do cliente %d?\n1 - Sim\n2 - Nao\n", numPedido, numCliente);
    scanf("%d", &opcao);

    if (opcao == 2)
    {
        return;
    }
    else
    {
        tipo(clientes, numCliente, numPedido);
        quantidade(clientes, numCliente, numPedido);
        localidade(clientes, numCliente, numPedido);
    }
}

void excluir(cliente *clientes)
{
    int numCliente, numPedido, opcao, i;
    printf("Insira o numero do cliente\n");
    scanf("%d", &numCliente);

    for (i = 0; i < clientes[numCliente].quantidadePedidos; i++)
    {
        printf("-------------------------------------------------\n");
        printf("Pedido %d\n", i + 1);
        printf("Tipo: %d\nQuantidade: %d\nLocalidade: %s\n", clientes[numCliente].pedidos[i].tipo, clientes[numCliente].pedidos[i].quantidade, clientes[numCliente].pedidos[i].localidade);
        printf("-------------------------------------------------\n");
    }
    printf("Insira o numero do pedido que deseja excluir\n");
    scanf("%d", &numPedido);

    printf("Tem certeza que deseja excluir o pedido %d do cliente %d?\n1 - Sim\n2 - Nao\n", numPedido, numCliente);
    scanf("%d", &opcao);

    if (opcao == 2)
    {
        return;
    }
    else
    {
        clientes[numCliente].quantidadeGeral -= clientes[numCliente].pedidos[numPedido].quantidade;
        clientes[numCliente].quantidadePedidos--;
        int i;
        for (i = numPedido; i < clientes[numCliente].quantidadePedidos; i++)
        {
            clientes[numCliente].pedidos[i] = clientes[numCliente].pedidos[i + 1];
        }
    }
}

void tipo(cliente *clientes, int i, int j)
{
    do
    {
        printf("Insira o tipo do produto\n1 - AC3\n2 - AC2\n3 - Rejunte\n");
        scanf("%d", &clientes[i].pedidos[j].tipo);
    } while (clientes[i].pedidos[j].tipo < 1 || clientes[i].pedidos[j].tipo > 3);
}

void quantidade(cliente *clientes, int i, int j)
{

    printf("Insira a quantidade de pacotes\n");
    scanf("%d", &clientes[i].pedidos[j].quantidade);

    clientes[i].quantidadeGeral += clientes[i].pedidos[j].quantidade;
}

void localidade(cliente *clientes, int i, int j)
{
    do
    {
        printf("Insira a localidade da entrega\n1 - Palmas\n2 - Porto Nacional\n");
        scanf("%d", &clientes[i].pedidos[j].localidade);

    } while (clientes[i].pedidos[j].localidade != 1 && clientes[i].pedidos[j].localidade != 2);
}

void carregarDados(cliente *clientes)
{
    FILE *arquivo;
    arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    int i;
    for (i = 0; i < 2; i++)
    {
        fread(&clientes[i], sizeof(cliente), 1, arquivo);
    }
    fclose(arquivo);
}

void salvarDados(cliente *clientes, int i, int j)
{
    FILE *arquivo;
    arquivo = fopen("dados.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    fwrite(&clientes[i].pedidos[j], sizeof(cliente), 1, arquivo);
}

void calcularFrete(cliente clientes[])
{
    int i;
    int j;
    printf("insira o numero do cliente\n");
    scanf("%d", &i);

    printf("insira o numero do pedido\n");
    scanf("%d", &j);
    int resultado;
    resultado = peso(clientes, i, j);

    if (resultado < 1000)
    {
        printf("Frete gratis\n");
    }
    else if (resultado >= 1000 && resultado <= 2000)
    {
        if (clientes[i].pedidos[j].localidade == 1)
        {
            printf("Frete: R$ 100,00\n");
        }
        else
        {
            printf("Frete: R$ 200,00\n");
        }
    }
    else
    {
        printf("Frete: R$ %d\n", clientes[i].pedidos[j].quantidade * 2);
    }
}

int peso(cliente clientes[], int i, int j)
{
    if (clientes[i].pedidos[j].tipo == 1)
        return clientes[i].pedidos[j].quantidade * 20;

    else if (clientes[i].pedidos[j].tipo == 2)
        return clientes[i].pedidos[j].quantidade * 20;

    else if (clientes[i].pedidos[j].tipo == 3)
        return clientes[i].pedidos[j].quantidade * 5;

    return 0;
}

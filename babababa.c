#include <stdio.h>
#include <stdbool.h>

#define MAX_BIBLIOTECAS 25
#define MAX_SEMANAS 20

int main() {
    int i, j, op;
    int ficcao[MAX_BIBLIOTECAS][MAX_SEMANAS], nao_ficcao[MAX_BIBLIOTECAS][MAX_SEMANAS];
    int ficcaoSemana[MAX_SEMANAS], nao_ficcaoSemana[MAX_SEMANAS], bibliotecaFiccao[MAX_BIBLIOTECAS] = {0}, bibliotecaNaoFiccao[MAX_BIBLIOTECAS] = {0};
    int total_ficcao = 0, total_nao_ficcao = 0, semana, biblioteca;
    bool emprestimos0 = false;

    for (i = 0; i < MAX_BIBLIOTECAS; i++) {
        printf("Biblioteca %d\n", i + 1);
        for (j = 0; j < MAX_SEMANAS; j++) {
            printf("Semana %d\n", j + 1);
            printf("Livros de ficção emprestados: ");
            scanf("%d", &ficcao[i][j]);
            printf("Livros de não-ficção emprestados: ");
            scanf("%d", &nao_ficcao[i][j]);
            ficcaoSemana[j] += ficcao[i][j];
            nao_ficcaoSemana[j] += nao_ficcao[i][j];
            if (ficcao[i][j] == 0 && nao_ficcao[i][j] == 0)
                emprestimos0 = true;
            total_ficcao += ficcao[i][j];
            total_nao_ficcao += nao_ficcao[i][j];
            bibliotecaFiccao[i] += ficcao[i][j];
            bibliotecaNaoFiccao[i] += nao_ficcao[i][j];
        }
    }

    do {
        system("cls");
        printf("Escolha o tipo de relatório:\n1 - Relatório por semana\n2 - Relatório por biblioteca\n3 - Relatório de análise de circulação\n4 - Sair\n");
        scanf("%d", &op);
        switch (op) {
        case 1:
            printf("Informe a semana (1 a 20): ");
            scanf("%d", &semana);
            if (semana < 1 || semana > 20)
                printf("Semana inválida!\n");
            else {
                printf("Relatório da semana %d:\n", semana);
                printf("Livros de ficção emprestados: %d\nLivros de não-ficção emprestados: %d\n", ficcaoSemana[semana - 1], nao_ficcaoSemana[semana - 1]);
            }
            break;
        case 2:
            printf("Informe a biblioteca (1 a 25): ");
            scanf("%d", &biblioteca);
            if (biblioteca < 1 || biblioteca > 25)
                printf("Biblioteca inválida!\n");
            else {
                printf("Relatório da biblioteca %d:\n", biblioteca);
                printf("Livros de ficção emprestados: %d\nLivros de não-ficção emprestados: %d\n", bibliotecaFiccao[biblioteca - 1], bibliotecaNaoFiccao[biblioteca - 1]);
            }
            break;
        case 3:
            printf("Relatório de análise de circulação:\n");
            printf("Total de livros de ficção emprestados: %d\n", total_ficcao);
            printf("Total de livros de não-ficção emprestados: %d\n", total_nao_ficcao);
            if (total_ficcao + total_nao_ficcao < 350)
                printf("Alerta: Baixa circulação de acervo!\n");
            if (total_ficcao > 1500 || total_nao_ficcao > 1100)
                printf("Alerta: Alta circulação de acervo!\n");
            if (emprestimos0)
                printf("Alerta: Houve semanas sem empréstimos registrados!\n");
            break;
        case 4:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (op != 4);
    return 0;
}
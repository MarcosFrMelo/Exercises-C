/// Uma escola de idiomas mantém 3 turmas de no máximo 30 alunos em cada. Os alunos recebem 2
// notas ao longo do ano, a média aritmética destas notas consiste na média final do aluno e a média
// para aprovação é no mínimo 7,0 pontos. O aluno deve ter também no máximo 10 faltas, caso
// contrário será reprovado por falta. Se o aluno tiver média final abaixo de 5,0 também será
// reprovado. O aluno que não foi aprovado, nem reprovado, terá a chance de fazer uma prova
// substitutiva. Elabore um programa em linguagem C que leia para cada aluno, seu nome, suas 2
// notas, sua frequência e mostre os seguintes relatórios:
//- Consulta por aluno:
// Dado o número do aluno e de sua turma, mostre seu nome, suas notas, sua média final, sua
// frequência e uma das mensagens: “Reprovado por falta”, “Reprovado por nota”, “Aprovado” ou
// “Fará substitutiva”.
//- Consulta por turma:
// Dado o número da turma, mostre quantos alunos a turma tem, quantos tiveram média final acima de
// 8, quantos alunos tiveram algum zero em suas notas, quantos farão prova substitutiva e qual é a
// média de notas geral da turma.
// Após imprimir um relatório, deve ser possível ao usuário imprimir outro caso queira.
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[40];
    float notaSemestral[2];
    float mediaFinal;
    int falta;
} aluno;

typedef struct
{
    aluno alunos[30];
    int contadorAluno;
    int mediaAcima8;
    int nota0;
    int provaSubsti;
    float mediaTurma;
} turma;

// void cadastrarAlunos(turma *turmas);
void dadosAlunos(turma turmas[]);
void dadosTurma(turma turmas[]);
void printarMensagem(turma *turmas, int numTurma, int numAluno);
// void salvarDados(turma *turmas);
// void carregarDados(turma *turmas);
// void modificarTurma(turma *turmas);
// void deletarTurma(turma *turmas);

int main()
{
    turma turmas[3] = {0};

    int i, j, k, op;
    bool notaZero;

    for (i = 0; i < 3; i++)
    {
        printf("\n\tTurma %d\n", i + 1);
        for (j = 0; j < 30; j++)
        {
            printf("\n\tAluno %d\n", j + 1);

            while ((getchar()) != '\n')
                ;
            printf("Insira o nome do aluno:\n");
            fgets(turmas[i].alunos[j].name, 40, stdin);
            turmas[i].alunos[j].name[strcspn(turmas[i].alunos[j].name, "\n")] = '\0';

            notaZero = false;
            for (k = 0; k < 2; k++)
            {
                printf("insira a nota %d do aluno %d\n", k + 1, j + 1);
                scanf("%f", &turmas[i].alunos[j].notaSemestral[k]);

                turmas[i].alunos[j].mediaFinal += turmas[i].alunos[j].notaSemestral[k];
                turmas[i].mediaTurma += turmas[i].alunos[j].notaSemestral[k];

                if (turmas[i].alunos[j].notaSemestral[k] == 0)
                {
                    notaZero = true;
                }
            }
            turmas[i].alunos[j].mediaFinal = turmas[i].alunos[j].mediaFinal / 2;

            if (notaZero == true)
            {
                turmas[i].nota0++;
            }
            if (turmas[i].alunos[j].mediaFinal > 8)
            {
                turmas[i].mediaAcima8++;
            }
            if (turmas[i].alunos[j].mediaFinal > 5 && turmas[i].alunos[j].mediaFinal < 7)
            {
                turmas[i].provaSubsti++;
            }

            printf("Insira a quantidade de falta desse aluno:\n");
            scanf("%d", &turmas[i].alunos[j].falta);

            turmas[i].contadorAluno++;

            printf("Deseja continuar inserindo mais alunos? Insira '1' para sim, '2' para nao\n");
            scanf("%d", &op);

            if (op == 2)
            {
                break;
            }
        }
        turmas[i].mediaTurma = turmas[i].mediaTurma / turmas[i].contadorAluno;
    }

    while (1)
    {
        int menu;

        printf("Escolha uma opcao\n1 - Consulta do aluno\n2 - Consulta da turma\n3 - Salvar\n4 - Carregar\n5 - Sair\n");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            dadosAlunos(turmas);
            break;
        case 2:
            dadosTurma(turmas);
            break;
        case 3:
            printf("Nao criada\n");
            break;
        case 4:
            printf("Nao criada\n");
            break;
        case 5:
            printf("\n\t\tFinalizando programa, aguarde");
            for (i = 0; i < 3; i++)
            {
                printf(".");
                Sleep(1000);
            }
            return 0;
        default:
            break;
        }
    }
}

void dadosAlunos(turma turmas[])
{
    int numeroturma, numeroaluno;

    printf("Insira o numero da turma:\n");
    scanf("%d", &numeroturma);

    printf("Insira o numero do aluno:\n");
    scanf("%d", &numeroaluno);

    printf("Nome: %s\n", turmas[numeroturma - 1].alunos[numeroaluno - 1].name);
    printf("Primeira nota: %.2f\n", turmas[numeroturma - 1].alunos[numeroaluno - 1].notaSemestral[0]);
    printf("Segunda nota: %.2f\n", turmas[numeroturma - 1].alunos[numeroaluno - 1].notaSemestral[1]);
    printf("Media final: %.2f\n", turmas[numeroturma - 1].alunos[numeroaluno - 1].mediaFinal);
    printf("Faltas: %d\n", turmas[numeroturma - 1].alunos[numeroaluno - 1].falta);

    printarMensagem(turmas, numeroturma, numeroaluno);

    return;
}

void printarMensagem(turma *turmas, int numTurma, int numAluno)
{
    if (turmas[numTurma - 1].alunos[numAluno - 1].falta > 10)
    {
        printf("Reprovado por falta\n");
    }
    else
    {
        if (turmas[numTurma - 1].alunos[numAluno - 1].mediaFinal < 5)
        {
            printf("Reprovado por nota\n");
        }
        else if (turmas[numTurma - 1].alunos[numAluno - 1].mediaFinal > 7)
        {
            printf("Aprovado\n");
        }
        else
        {
            printf("Fara Substitutiva");
        }
    }
    return;
}

void dadosTurma(turma turmas[])
{
    int op;

    printf("insira a turmma que deseja ver\n");
    scanf("%d", &op);

    printf("Quantidade de alunos na turma: %d\n", turmas[op - 1].contadorAluno);
    printf("Quantos alunos tiveram media acima de 8: %d\n", turmas[op - 1].mediaAcima8);
    printf("Quantidade de Alunos que tiveram alguma nota 0: %d\n", turmas[op - 1].nota0);
    printf("Quantidade de alunos que farao a prova subtitutiva: %d\n", turmas[op - 1].provaSubsti);
    printf("Media geral da turma: %2.f\n", turmas[op - 1].mediaTurma);

    return;
}

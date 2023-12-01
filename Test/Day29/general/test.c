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

#define red "\033[0;31m"
#define green "\033[0;32m"
#define reset "\033[0m"
#define yellow "\033[0;33m"

void cadastrarAlunos(turma turmas[]);
void nomeAluno(turma *turmas, int numTurma, int numAluno);
void notaAluno(turma *turmas, int numTurma, int numAluno);
void faltaAluno(turma *turmas, int numTurma, int numAluno);
void consultaAlunos(turma turmas[]);
void consultaTurma(turma turmas[]);
void printarMensagem(turma *turmas, int numTurma, int numAluno);
void modificarTurma(turma turmas[]);
void deletarTurma(turma turmas[]);
void salvarDados(turma turmas[]);
void carregarDados(turma turmas[]);
void verificacaoTurma(turma *turmas, int numTurma);
void apagarAlgumacoisa(turma *turmas, int numTurma);
void printarAlunos(turma *turmas, int numTurma, int numAluno);
void printarTurma(turma *turmas, int numTurma);
void mostrarTurma(turma turmas[]);

int main()
{
    turma turmas[3] = {0};
    int opcao, i;

    while (1)
    {
        system("cls");
        printf("Insira a opcao que deseja:\n1 - Cadastrar Alunos\n2 - Consultar Alunos\n3 - Consultar Turma\n4 - Modificar Turma\n5 - Deletar Turma\n6 - Salvar\n7 - Carregar\n8 - Mostrar Turma\n9 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarAlunos(&turmas);
            break;
        case 2:
            consultaAlunos(turmas);
            break;
        case 3:
            consultaTurma(turmas);
            break;
        case 4:
            modificarTurma(&turmas);
            break;
        case 5:
            deletarTurma(&turmas);
            break;
        case 6:
            salvarDados(&turmas);
            break;
        case 7:
            carregarDados(&turmas);
            break;
        case 8:
            mostrarTurma(turmas);
            break;
        case 9:
            printf(red "Finalizando Programa");
            for (i = 0; i < 4; i++)
            {
                printf(".");
                Sleep(1300);
            }
            return 0;
        default:
            printf(red "Opcao invalida\n" reset);
            break;
        }
    }
}

void cadastrarAlunos(turma turmas[])
{
    int i, j, op, op2;

    for (i = 0; i < 3; i++)
    {
        printf("\n\tTurma %d\n", i + 1);

        if (turmas[i].contadorAluno == 30)
        {
            printf(red "Turma cheia\n" reset);
            system("pause");
            continue;
        }

        for (j = turmas[i].contadorAluno; j < 30; j++)
        {
            printf("\n\tAluno %d\n", j + 1);

            nomeAluno(turmas, i, j);
            notaAluno(turmas, i, j);
            faltaAluno(turmas, i, j);

            turmas[i].contadorAluno++;

            printf("contador: %d\n", turmas[i].contadorAluno);

            printf(green "Deseja cadastrar outro aluno?\n1 - Sim\n2 - Nao\n" reset);
            scanf("%d", &op);

            if (op == 2)
            {
                break;
            }
        }
        verificacaoTurma(turmas, i+1);
        
        printf(green "Deseja cadastrar mais turmas?\n1 - Sim\n2 - Nao\n" reset);
        scanf("%d", &op2);

        if (op2 == 2)
        {
            break;
        }
    }
    return;
}

void nomeAluno(turma *turmas, int numTurma, int numAluno)
{
    while (getchar() != '\n')
        ;
    printf("Insira o nome do aluno:\n");
    fgets(turmas[numTurma].alunos[numAluno].name, 40, stdin);
    turmas[numTurma].alunos[numAluno].name[strcspn(turmas[numTurma].alunos[numAluno].name, "\n")] = '\0';
    return;
}

void notaAluno(turma *turmas, int numTurma, int numAluno)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        do
        {
            printf("Insira a nota %d do aluno:\n", i + 1);
            scanf("%f", &turmas[numTurma].alunos[numAluno].notaSemestral[i]);

            if (turmas[numTurma].alunos[numAluno].notaSemestral[i] < 0 || turmas[numTurma].alunos[numAluno].notaSemestral[i] > 10)
            {
                printf(red "Nota invalida, Insira outra nota\n" reset);
            }
        } while (turmas[numTurma].alunos[numAluno].notaSemestral[i] < 0 || turmas[numTurma].alunos[numAluno].notaSemestral[i] > 10);
    }
    return;
}

void faltaAluno(turma *turmas, int numTurma, int numAluno)
{
    printf("Insira a falta do aluno:\n");
    scanf("%d", &turmas[numTurma].alunos[numAluno].falta);

    return;
}

void consultaAlunos(turma turmas[])
{
    int numTurma, numAluno;

    printf("Insira o numero da turma que deseja consultar:\n");
    scanf("%d", &numTurma);

    if (turmas[numTurma - 1].contadorAluno == 0)
    {
        printf(red "Turma vazia\n" reset);
        system("pause");
        return;
    }

    printf("Insira o numero do aluno que deseja consultar:\n");
    scanf("%d", &numAluno);

    printarAlunos(turmas, numTurma-1, numAluno-1);
    system("pause");
    return;
}

void consultaTurma(turma turmas[])
{
    int numTurma;

    printf("Insira o numero da turma que deseja consultar:\n");
    scanf("%d", &numTurma);

    printarTurma(turmas, numTurma-1);

    system("pause");

    return;
}

void printarMensagem(turma *turmas, int numTurma, int numAluno)
{
    if (turmas[numTurma].alunos[numAluno].falta > 10)
    {
        printf(red "Reprovado por falta\n" reset);
    }
    else
    {
        if (turmas[numTurma].alunos[numAluno].mediaFinal < 5)
        {
            printf(red "Reprovado por nota\n" reset);
        }
        else if (turmas[numTurma].alunos[numAluno].mediaFinal > 7)
        {
            printf(green "Aprovado\n" reset);
        }
        else
        {
            printf(yellow "Fara substitutiva\n" reset);
        }
    }
}

void modificarTurma(turma turmas[])
{
    int numTurma, numAluno, opcao;

    printf("Insira o numero da turma que deseja modificar:\n");
    scanf("%d", &numTurma);

    if (turmas[numTurma - 1].contadorAluno == 0)
    {
        printf(red "Turma vazia\n" reset);
        system("pause");
        return;
    }

    printf("Insira o numero do aluno que deseja modificar:\n");
    scanf("%d", &numAluno);

    printarAlunos(turmas, numTurma-1, numAluno-1);

    printf("Esse e o aluno que deseja modificar?\n1 - Sim\n2 - Nao\n");
    scanf("%d", &opcao);

    if (opcao == 2)
    {
        return;
    }

    printf("Insira o que deseja modificar:\n1 - Nome\n2 - Nota\n3 - Falta\n4 - Sair\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        nomeAluno(turmas, numTurma-1, numAluno-1);
        break;
    case 2:
        notaAluno(turmas, numTurma-1, numAluno-1);
        break;
    case 3:
        faltaAluno(turmas, numTurma-1, numAluno-1);
        break;
    case 4:
        printf("Saindo\n");
        system("pause");
        return;
    default:
        printf(red "Opcao invalida\n" reset);
        break;
    }
    verificacaoTurma(turmas, numTurma);
    return;
}

void deletarTurma(turma turmas[])
{
    int numTurma, numAluno, i, op, opcao;

    printf("Deseja deletar a turma ou um aluno?\n1 - Turma\n2 - Aluno\n");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        printf("Insira o numero da turma que deseja deletar:\n");
        scanf("%d", &numTurma);

        printarTurma(turmas, numTurma-1);

        printf("Esse e a turma que deseja deletar?\n1 - Sim\n2 - Nao\n");
        scanf("%d", &op);

        if (opcao == 2)
        {
            return;
        }

        for (i = numTurma - 1; i < 2; i++)
        {
            turmas[i] = turmas[i + 1];
        }

        printf(green "Turma deletada com sucesso\n" reset);
        system("pause");
        return;
    }

    printf("Insira o numero da turma que deseja deletar:\n");
    scanf("%d", &numTurma);

    printf("Insira o numero do aluno que deseja deletar:\n");
    scanf("%d", &numAluno);

    printarAlunos(turmas, numTurma-1, numAluno-1);

    printf("Esse e o aluno que deseja deletar?\n1 - Sim\n2 - Nao\n");
    scanf("%d", &op);

    if (opcao == 2)
    {
        return;
    }

    for (i = opcao - 1; i < turmas[numTurma - 1].contadorAluno - 1; i++)
    {
        turmas[numTurma - 1].alunos[i] = turmas[numTurma - 1].alunos[i + 1];
    }
    turmas[numTurma - 1].contadorAluno--;

    printf(green "Aluno deletado com sucesso\n" reset);
    system("pause");
    return;
}

void salvarDados(turma turmas[])
{
    FILE *arquivo;
    int i;

    arquivo = fopen("class.bin", "wb");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    for (i = 0; i < 3; i++)
    {
        fwrite(&turmas[i], sizeof(turma), 1, arquivo);
    }

    printf(green "Dados salvos com sucesso\n" reset);

    fclose(arquivo);
    return;
}

void carregarDados(turma turmas[])
{
    FILE *arquivo;
    int i;

    arquivo = fopen("class.bin", "rb");

    if (arquivo == NULL)
    {
        printf(red "Erro ao abrir o arquivo\n" reset);
        return;
    }

    for (i = 0; i < 3; i++)
    {
        fread(&turmas[i], sizeof(turma), 1, arquivo);
    }

    fclose(arquivo);
    return;
}

void verificacaoTurma(turma *turmas, int numTurma)
{
    int i, j;
    apagarAlgumacoisa(turmas, numTurma-1);

    printf("contador: %d\n", turmas[numTurma-1].contadorAluno);
    for (i = 0; i < turmas[numTurma - 1].contadorAluno; i++)
    {

        if (turmas[numTurma].alunos[i].mediaFinal > 8)
        {
            turmas[numTurma].mediaAcima8++;
        }
        if (turmas[numTurma].alunos[i].mediaFinal >= 5 && turmas[numTurma].alunos[i].mediaFinal < 7)
        {
            turmas[numTurma].provaSubsti++;
        }

        for (j = 0; j < 2; j++)
        {

            if (turmas[numTurma].alunos[i].notaSemestral[j] == 0)
            {
                turmas[numTurma].nota0++;
            }

        }

        turmas[numTurma].alunos[i].mediaFinal += turmas[numTurma].alunos[i].notaSemestral[1] +
                                                 turmas[numTurma].alunos[i].notaSemestral[0];
        turmas[numTurma].mediaTurma += turmas[numTurma].alunos[i].mediaFinal / turmas[numTurma-1].contadorAluno;

    }

    return;
}

void apagarAlgumacoisa(turma *turmas, int numTurma)
{
    turmas[numTurma].mediaAcima8 = 0;
    turmas[numTurma].nota0 = 0;
    turmas[numTurma].provaSubsti = 0;
    turmas[numTurma].mediaTurma = 0;
}

void printarAlunos(turma *turmas, int numTurma, int numAluno)
{
    printf("--------------------------------------------\n");
    printf("\tAluno %d\n", numAluno + 1);
    printf("Nome: %s\nNota 1: %2.f\nNota 2: %2.f\nMedia final: %2.f\nFalta: %d\n",
           turmas[numTurma].alunos[numAluno].name, turmas[numTurma].alunos[numAluno].notaSemestral[0],
           turmas[numTurma].alunos[numAluno].notaSemestral[1], turmas[numTurma].alunos[numAluno].mediaFinal,
           turmas[numTurma].alunos[numAluno].falta);
    printf("--------------------------------------------\n");
}

void printarTurma(turma *turmas, int numTurma)
{
    printf("--------------------------------------------\n");
    printf("\tTurma %d\n", numTurma);
    printf("Quantidade de alunos: %d\nQuantidade de alunos com media acima de 8: %d\nQuantidade de alunos com nota 0: %d\n"
           "Quantidade de alunos que farao prova substitutiva: %d\nMedia de notas da turma: %2.f\n",
           turmas[numTurma].contadorAluno,
           turmas[numTurma].mediaAcima8,
           turmas[numTurma].nota0,
           turmas[numTurma].provaSubsti,
           turmas[numTurma].mediaTurma);
    printf("--------------------------------------------\n");
}

void mostrarTurma(turma turmas[])
{
    int numTurma, i;

    printf("Insira o numero da turma que deseja ver:\n");
    scanf("%d", &numTurma);

    for (i = 0; i < turmas[numTurma-1].contadorAluno; i++)
    {
        printarAlunos(turmas, numTurma-1, i);
    }
    system("pause");
    return;
}

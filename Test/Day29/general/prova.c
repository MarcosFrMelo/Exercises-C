/**
 Uma escola de idiomas mantém 3 turmas de no máximo 30 alunos em cada. Os alunos recebem 2
 notas ao longo do ano, a média aritmética destas notas consiste na média final do aluno e a média
 para aprovação é no mínimo 7,0 pontos. O aluno deve ter também no máximo 10 faltas, caso
 contrário será reprovado por falta. Se o aluno tiver média final abaixo de 5,0 também será
 reprovado. O aluno que não foi aprovado, nem reprovado, terá a chance de fazer uma prova
 substitutiva. Elabore um programa em linguagem C que leia para cada aluno, seu nome, suas 2
 notas, sua frequência e mostre os seguintes relatórios:
- Consulta por aluno:
 Dado o número do aluno e de sua turma, mostre seu nome, suas notas, sua média final, sua
 frequência e uma das mensagens: “Reprovado por falta”, “Reprovado por nota”, “Aprovado” ou
 “Fará substitutiva”.
- Consulta por turma:
 Dado o número da turma, mostre quantos alunos a turma tem, quantos tiveram média final acima de
 8, quantos alunos tiveram algum zero em suas notas, quantos farão prova substitutiva e qual é a
 média de notas geral da turma.
 Após imprimir um relatório, deve ser possível ao usuário imprimir outro caso queira.
*/
#include <stdio.h>
#include <stdbool.h>

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

void consultarAluno(turma turmas[]);
void consultarTurma(turma turmas[]);
void printarMensagem(turma *turmas, int numTurma, int numAluno);

int main()
{
    turma turmas[3] = {0};

    int i, j, k, op, op2;
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
                printf("Insira a nota %d do aluno:\n", k + 1);
                scanf("%f", &turmas[i].alunos[j].notaSemestral[k]);
                
                turmas[i].alunos[j].mediaFinal += turmas[i].alunos[j].notaSemestral[k];
                
                if (turmas[i].alunos[j].notaSemestral[k] == 0)
                {
                    notaZero = true;
                }
            }
            turmas[i].alunos[j].mediaFinal /= 2;
            turmas[i].mediaTurma += turmas[i].alunos[j].mediaFinal;

            printf("Insira a quantidade de faltas do aluno:\n");
            scanf("%d", &turmas[i].alunos[j].falta);

            if (turmas[i].alunos[j].mediaFinal >= 8)
            {
                turmas[i].mediaAcima8++;
            }
            if (notaZero == true)
            {
                turmas[i].nota0++;
            }
            if (turmas[i].alunos[j].mediaFinal >= 5 && turmas[i].alunos[j].mediaFinal < 7)
            {
                turmas[i].provaSubsti++;
            }

            turmas[i].contadorAluno++;

            printf("Deseja cadastrar outro aluno?\n1 - Sim\n2 - Nao\n");
            scanf("%d", &op);

            if (op == 2)
            {
                break;
            }
        }
        turmas[i].mediaTurma /= turmas[i].contadorAluno;
    }

    do
    {
        printf("Insira a opcao que deseja:\n1 - Consultar aluno\n2 - Consultar turma\n3 - Sair\n");
        scanf("%d", &op2);

        switch (op2)
        {
        case 1:
            consultarAluno(turmas);
            break;
        case 2:
            consultarTurma(turmas);
            break;
        case 3:
            printf("Finalizando programa...\n");
            return 0;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (1);
}

void consultarAluno(turma turmas[])
{
    int numTurma, numAluno;

    printf("Insira o numero da turma:\n");
    scanf("%d", &numTurma);
    
    if (numTurma > 3 || numTurma < 1)
    {
        printf("Turma nao encontrada\n");
        return;
    }
    
    printf("Insira o numero do aluno:\n");
    scanf("%d", &numAluno);

    if (numAluno < 1 || turmas[numTurma - 1].contadorAluno < numAluno)
    {
        printf("Aluno nao encontrado!\n");
        return;
    }
    
    printf("---------------------------------------------\n");
    printf("Nome: %s\nNota 1: %.2f\nNota 2: %.2f\nMedia final: %.2f\nFaltas: %d\n",
           turmas[numTurma - 1].alunos[numAluno - 1].name,
           turmas[numTurma - 1].alunos[numAluno - 1].notaSemestral[0],
           turmas[numTurma - 1].alunos[numAluno - 1].notaSemestral[1],
           turmas[numTurma - 1].alunos[numAluno - 1].mediaFinal,
           turmas[numTurma - 1].alunos[numAluno - 1].falta);
    printarMensagem(turmas, numTurma, numAluno);
    printf("---------------------------------------------\n");
}

void consultarTurma(turma turmas[])
{
    int numTurma;

    printf("Insira o numero da turma:\n");
    scanf("%d", &numTurma);

    if (numTurma > 3 || numTurma < 1)
    {
        printf("Turma nao encontrada!\n");
        return;
    }

    printf("---------------------------------------------\n");
    printf("Quantidade de alunos: %d\nQuantidade de alunos com media acima de 8: %d\nQuantidade de alunos com nota 0: %d\n"
               "Quantidade de alunos que farao prova substitutiva: %d\nMedia de notas da turma: %2.f\n",
               turmas[numTurma - 1].contadorAluno,
               turmas[numTurma - 1].mediaAcima8,
               turmas[numTurma - 1].nota0,
               turmas[numTurma - 1].provaSubsti,
               turmas[numTurma - 1].mediaTurma);
    printf("---------------------------------------------\n");
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
            printf("Fara Substitutiva\n");
        }
    }
    return;
}
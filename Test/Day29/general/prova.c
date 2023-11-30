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
#include <stdbool.h>
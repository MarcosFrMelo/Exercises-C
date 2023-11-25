#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char nome[50];
    long int telefone;
    char email[100];
} pessoa;

typedef struct
{
    pessoa contato[100];
    int quantidade;
} agenda;

#define green "\033[0;32m"
#define red "\033[0;31m"
#define reset "\033[0m"

void cadastrarContato(agenda *agendas);
void buscarContato(agenda agendas);
void excluirContato(agenda *agendas);
void editarContato(agenda *agendas);
void listarContatos(agenda agendas);
void Nome(agenda *agendas, int i);
void Telefone(agenda *agendas, int i);
void Email(agenda *agendas, int i);
void carregarDados(agenda *agendas);
void salvarDados(agenda *agendas);

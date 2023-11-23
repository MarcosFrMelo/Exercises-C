typedef struct 
{
    char nome[50];
    char telefone[20];
    char email[50];
} pessoa;

typedef struct
{
    pessoa contato[100];
    int quantidade;
} agenda;

#define count 100;
#define green "\033[0;32m"
#define red "\033[0;31m"
#define reset "\033[0m"

int menu();
void cadastrarContato(agenda *agendas);
void buscarContato(agenda agendas);
void excluirContato(agenda *agendas);
void editarContato(agenda *agendas);
void listarContatos(agenda *agendas);

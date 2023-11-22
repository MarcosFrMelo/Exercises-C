typedef struct 
{
    char nome[50];
    char telefone[20];
    char email[50];
} contato;

#define count 100
#define green "\033[0;32m"
#define red "\033[0;31m"
#define reset "\033[0m"

int menu();
void cadastrarContato(contato *pessoa);
void buscarContato(contato pessoa);
void excluirContato(contato *pessoa);
void editarContato(contato *pessoa);
void listarContatos(contato *pessoa);

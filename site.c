#include <stdio.h>
#include <stdlib.h>

#define maxProd 3
#define maxSemanas 2

typedef struct{
    int alface;
    int repolho;

}Produtor;

typedef struct{
    int quantEntregas;
    Produtor produtor[maxProd];
}Semana;

void inserirDados(Semana*);
void salvarDado(Semana*);
void carregarDado(Semana*);
void relatiorioPorSemana(Semana);
void relatorioPorProdutor(Semana*, int);
void relatorioAnaliseAbastecimento(Semana*);
void printarDados(Semana*);

int main(){
    Semana semana[maxSemanas] = {0};
    int op;
    while (1)
    {
        printf("1 - Inserir dados\n2 - Salvar dados\n3 - Carregar dados\n4 - Relatorio por semana\n5 - Relatorio por produtor\n6 - Relatorio de analise de abastecimento\n7 - Sair\n8 - Printar dados\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            inserirDados(semana);
            break;
        case 2:
            salvarDado(semana);
            break;
        case 3:
            carregarDado(semana);
            break;
        case 4:
            printf("Qual semana deseja ver o relatorio? ");
            int semanaOp;
            scanf("%d", &semanaOp);
            relatiorioPorSemana(semana[semanaOp - 1]);
            break;
        case 5:
            printf("Qual produtor deseja ver o relatorio? ");
            int prodOp;
            scanf("%d", &prodOp);
            relatorioPorProdutor(semana, prodOp - 1);
            break;
        case 6:
            relatorioAnaliseAbastecimento(semana);
            break;
        case 7:
            printf("Finalizando programa\n");
            exit(0);
        case 8:
            printarDados(semana);
            break;
        default:
            break;
        }
    }
}

/**
 * @brief Salva os dados no arquivo binario
 * @param semana - ponteiro para a struct semana
 * @return void
 */
void salvarDado(Semana *semana){
    FILE *arq;
    // Abre o arquivo binario
    arq = fopen("info_hortalicas.bin", "wb");
    // Verifica se o arquivo foi aberto
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    // Escreve os dados no arquivo
    for (int i = 0; i < maxSemanas; i++)
    {
        // Escreve a quantidade de entregas da semana i no arquivo binario
        fwrite(&semana[i].quantEntregas, sizeof(int), 1, arq);
        // ultiliza da quantidade de entregas para escrever os dados dos produtores da semana i no arquivo binario 
        for (int j = 0; j < semana[i].quantEntregas; j++)
        {
            // Escreve os dados do produtor j da semana i no arquivo binario
            fwrite(&semana[i].produtor[j], sizeof(Produtor), 1, arq);
        }
    }
    fclose(arq);
    return;
}
/**
 * @brief carrerga os dados do arquivo binario
 * @param semana - ponteiro para a struct semana
 * @return void
 */
void carregarDado(Semana *semana){
    FILE *arq;
    // Abre o arquivo binario
    arq = fopen("info_hortalicas.bin", "rb");
    // Verifica se o arquivo foi aberto
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    // Le os dados do arquivo
    for (int i = 0; i < maxSemanas; i++)
    {
        // Le a quantidade de entregas da semana i do arquivo binario e armazena na struct semana
        fread(&semana[i].quantEntregas, sizeof(int), 1, arq);
        // ultiliza da quantidade de entregas lida para ler os dados dos produtores da semana i para não ter lixo de memoria
        for (int j = 0; j < semana[i].quantEntregas; j++)
        {
            // Le os dados do produtor j da semana i de acordo com a quantidade de entregas
            fread(&semana[i].produtor[j], sizeof(Produtor), 1, arq);
        }
    }
    fclose(arq);
    return;
}

void inserirDados(Semana *semana){
    for (int i = 0; i < maxSemanas; i++)
    {
        printf("Semana %d\n", i + 1);
        for (int j = 0; j < maxProd; j++)
        {
            printf("Produtor %d\n", j + 1);
            printf("Alface: ");
            scanf("%d", &semana[i].produtor[j].alface);
            printf("Repolho: ");
            scanf("%d", &semana[i].produtor[j].repolho);
            int op;
            semana[i].quantEntregas += 1;
            printf("Continuar[0/1]? ");
            scanf("%d", &op);
            
            if (op == 0)
            {
                break;
            }
        }
        int op2;
        printf("Continuar[0/1]? ");
        scanf("%d", &op2);
        if (op2 == 0)
        {
            break;
        }
    }
    return;
}

void relatiorioPorSemana(Semana semana){
    int somaAlface = 0, somaRepolho = 0;
    for (int i = 0; i < semana.quantEntregas; i++)
    {
        somaAlface += semana.produtor[i].alface;
        somaRepolho += semana.produtor[i].repolho;
    }
    printf("Alface: %d\nRepolho: %d\n", somaAlface, somaRepolho);
    return;
}

void relatorioPorProdutor(Semana *semana, int produtor){
    int somaAlface = 0, somaRepolho = 0;
    for (int i = 0; i < maxSemanas; i++)
    {
        somaAlface += semana[i].produtor[produtor].alface;
        somaRepolho += semana[i].produtor[produtor].repolho;
    }
    printf("Alface: %d\nRepolho: %d\n", somaAlface, somaRepolho);
    return;
}

void relatorioAnaliseAbastecimento(Semana *semana){
    int somaTotalAlface = 0, somaTotalRepolho = 0, cSemanaSemEntrega = 0;
    for (int i = 0; i < maxSemanas; i++)
    {
        for (int j = 0; j < semana[i].quantEntregas; j++)
        {
            somaTotalAlface += semana[i].produtor[j].alface;
            somaTotalRepolho += semana[i].produtor[j].repolho;
        }
        if (semana[i].quantEntregas == 0)
        {
            cSemanaSemEntrega += 1;
        }
    }
    printf("\nQuantidade total de pes de alfaces entregues no periodo -->  %d\n", somaTotalAlface);
    printf("Quantidade total de pes de repolho entregues no periodo -->  %d\n", somaTotalRepolho);

    if (somaTotalAlface + somaTotalRepolho < 500){
        printf("\nRisco de desabastecimento.\n");
    }
    else if ((somaTotalAlface > 1300) || (somaTotalRepolho > 1200)){
        printf("\nSuper Producao.\n");
    }

    if (cSemanaSemEntrega > 0){
        printf("\nHouve alguma semana no periodo em que nao foram feitas entregas.\n");
    }
    return;
}

void printarDados(Semana *semanas){
    for (int i = 0; i < maxSemanas; i++)
    {
        printf("Semana %d\n", i + 1);
        for (int j = 0; j < semanas[i].quantEntregas; j++)
        {
            printf("Produtor %d\n", j + 1);
            printf("Alface: %d\nRepolho: %d\n", semanas[i].produtor[j].alface, semanas[i].produtor[j].repolho);
        }
    }
    return;
}
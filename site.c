 #include <stdio.h>
 #include <stdbool.h>
 #include <stdlib.h>

 #define MAX_FILIAIS 3
 #define MAX_DIAS 5

 int main(){
    int i, j, op;
    int genericos[40][30], marca[40][30];
    int genericosDia[30], marcaDia[30], filialgenericos[40] = {0}, filialmarca[40]= {0};
    int total_genericos = 0, total_marca = 0, dia, filial;
    bool vendas0 = false;
    for (i = 0; i < MAX_FILIAIS; i++)
    {
        printf("Filial %d\n", i + 1);
        for (j = 0; j < MAX_DIAS; j++)
        {
            printf("Dia %d\n", j + 1);
            printf("Medicamentos genericos vendidos: ");
            scanf("%d", &genericos[i][j]);
            printf("Medicamentos de marca vendidos: ");
            scanf("%d", &marca[i][j]);
            genericosDia[j] += genericos[i][j];
            marcaDia[j] += marca[i][j];
            if (genericos[i][j] == 0 && marca[i][j] == 0)
                vendas0 = true;
            total_genericos += genericos[i][j];
            total_marca += marca[i][j];
            filialgenericos[i] += genericos[i][j];
            filialmarca[i] += marca[i][j];
        }
    }
    do
    {
        system("cls");
        printf("Escolha o tipo de relatorio:\n1 - Relatorio por dia\n2 - Relatorio por filial\n3 - Relatorio de analise de estoque\n4 - Sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Informe o dia (1 a 30): ");
            scanf("%d", &dia);
            if (dia < 1 || dia > 30)
                printf("Dia invalido!\n");
            else{
                printf("Relatorio do dia %d:\n", dia);
                printf("Medicamentos genericos vendidos: %d\nMedicamentos de marca vendidos: %d\n", genericosDia[dia-1], marcaDia[dia-1]);
            }
            break;
        case 2:
            printf("Informe a filial (1 a 40): ");
            scanf("%d", &filial);
            if (filial < 1 || filial > 40)
                printf("Filial invalida!\n");
            else{
                printf("Relatorio da filial %d:\n", filial);
                printf("Medicamentos genericos vendidos: %d\nMedicamentos de marca vendidos: %d\n", filialgenericos[filial-1], filialmarca[filial-1]);
            }
            break;
        case 3:
            printf("Relatorio de analise de estoque:\n");
            printf("Medicamentos genericos vendidos: %d\nMedicamentos de marca vendidos: %d\n", total_genericos, total_marca);
            if (total_genericos < 1000)
                printf("Baixo volume de vendas\n");
            if (total_genericos > 2500 || total_marca > 1800)
                printf("Alto volume de vendas\n");
            if (vendas0)
                printf("Houve algum dia no periodo em que nao foram registradas vendas\n");
            break;
        case 4:
            printf("Saindo...\n");
            return 0;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (1);
 }
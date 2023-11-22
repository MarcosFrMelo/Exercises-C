//faça um programa que leia uma matriz 10x4 de números inteiros e salve esta matriz em um arquivo binário chamado testmatriz.//

#include <stdio.h>

int main()
{
    int matriz[10][4], i, j;
    FILE *arq;
    arq = fopen("testmatriz.bin", "wb");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Digite o valor da posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            fwrite(&matriz[i][j], sizeof(int), 1, arq);
        }
    }
    fclose(arq);
    return 0;
}
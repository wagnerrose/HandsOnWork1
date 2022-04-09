#include <stdio.h>

#define ITENS 6

int leVoto(void);
void imprimeVoto(int *valores, int total);

int main()
{
    int voto;
    char fim = 'N';
    int totalVotos = 0;
    int contagem[ITENS] = {0,0,0,0,0,0};
    for(;;)
    {
        voto = leVoto();
        ++contagem[voto-1];
        totalVotos= totalVotos + 1;
        printf("\nVota de novo? Para terminar digite N ou n.\n");
        scanf(" %c", &fim);
        if (fim == 'n' || fim == 'N') break;
    }
    imprimeVoto(contagem, totalVotos);
    return 0;
}

int leVoto()
{
    int escolha;

    printf("\nNa sua opinião, qual o melhor sistema operacional para uso em servidores?\n");
    printf("1. Windows Server.\n");
    printf("2. Unix.\n");
    printf("3. Linux.\n");
    printf("4. Netware.\n");
    printf("5. Mac OS.\n");
    printf("6. Outros.\n");
    printf("Voto: ");
    scanf("%d\n",&escolha);
    return escolha;
}

void imprimeVoto(int *valores, int total)
{
    printf("\nTotalizacao de Votos\n");
    printf("1. Windows Server --> %d %f\n",valores[0], valores[0]/total);
    printf("2. Unix --> %d %f\n",valores[1], valores[1]/total);
    printf("3. Linux --> %d %f\n",valores[2], valores[2]/total);
    printf("4. Netware --> %d %f\n",valores[3], valores[3]/total);
    printf("5. Mac OS --> %d %f\n",valores[4], valores[4]/total);
    printf("6. Outros --> %d %f\n",valores[5], valores[5]/total);
 }

#include <stdio.h>

#define ITENS 6

int leVoto(void);
void imprimeVoto(int *valores, int total);

int main()
{
    int voto;
    char fim;
    int totalVotos = 0;
    int contagem[ITENS] = {0,0,0,0,0,0};
    for(;;)
    {
        voto = leVoto();
        ++contagem[voto-1];
        ++totalVotos;
        printf("\nVota de novo? Para terminar digite N ou n.\n");
        scanf("%c", &fim);
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
    scanf("%d",&escolha);
    return escolha;
}

void imprimeVoto(int *valores, int total)
{
    printf("\nTotalizacao de Votos\n");
    printf("1. Windows Server --> %d - %.2f\%\n",valores[0], ((float) valores[0]/total)*100);
    printf("2. Unix           --> %d - %.2f\%\n",valores[1], ((float) valores[1]/total)*100);
    printf("3. Linux          --> %d - %.2f\%\n",valores[2], ((float) valores[2]/total)*100);
    printf("4. Netware        --> %d - %.2f\%\n",valores[3], ((float) valores[3]/total)*100);
    printf("5. Mac OS         --> %d - %.2f\%\n",valores[4], ((float) valores[4]/total)*100);
    printf("6. Outros         --> %d - %.2f\%\n",valores[5], ((float) valores[5]/total)*100);
 }

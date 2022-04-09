#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int vitoriasHumano;
int vitoriasComputador;
int PEDRA = 1;
int PAPEL = 2;
int TESOURA = 3;

void geraEscolha();
void apresentaEscolha(int item);
int  encontraVencedor(int jogador1, int jogador2);

int main(){

    char continua = 'S';

    printf("---------------------------------------------------\n");
    printf("         Jogo Pedra - Papel - Tessoura\n");
    printf("\n");
    printf("        Você Jogará contra o Computador  \n");
    printf("---------------------------------------------------\n");

    srand(time(NULL)); // gera a semente para o gerador de numeros aleatórios

    while (continua == 'S' || continua == 's' )
    {
        geraEscolha();
        printf("-------------------------------------------------------------------------------\n");
        printf("Quer jogar mais uma vez? \nDigite s(sim) ou outra tecla pra terminar.\n");
        scanf(" %c",&continua);
    }
    printf("*========================*\n");
    printf("    Total de Pontos\n");
    printf("         Voce: %d \n", vitoriasHumano);
    printf("   Computador: %d \n", vitoriasComputador);
    printf("*========================*\n");
    printf("\n Obrigado por jogar!\n");
    return 0;
}

void geraEscolha(){

    int humano;
    int computador;
    int vencedor;
    int erro = 0;

    do
    {
        printf("\n Opções:\n  1.Pedra \n  2.Papel \n  3.Tesoura \n Faça sua escolha: ");
        scanf("%d", &humano);
        if (humano < 1 || humano > 3)
        {
            printf("Você deve escolher um número entre 1 a 3\n");
            printf("Tente outra vez.\n");
            erro = 1;
        }
    } while (erro == 1);
    computador = rand()%3+1; //computador faz sua escolha

    printf("\n Voce -> ");
    apresentaEscolha(humano);
    printf(" x ");
    apresentaEscolha(computador);
    vencedor= encontraVencedor(humano, computador);
    printf("\n");
    switch (vencedor)
    {
       case 1:
            printf("Humano,você Ganhou.\n");
            vitoriasHumano++;
            break;
        case 2:
            printf("Eu ganhei!!! kkkkkk\n ");
            vitoriasComputador++;
            break;
        default:
            printf("O jogo empatou.\n");
    }
    printf("\n");
}

void apresentaEscolha(int item)
{
    switch(item)
    {
        case 1:
           printf("PEDRA");
            break;
        case 2:
            printf("PAPEL");
            break;
        default:
            printf("TESOURA");
    }
}

int encontraVencedor(int jogador1, int jogador2){

    int vencedor;
    if(jogador1 == jogador2){ //empate
        vencedor = 0;
    }

    if(jogador1==PEDRA && jogador2==TESOURA){ vencedor = 1; }
    if(jogador1==PEDRA && jogador2==PAPEL){ vencedor = 2; }

    if(jogador1==PAPEL && jogador2==PEDRA){ vencedor = 1; }
    if(jogador1==PAPEL && jogador2==TESOURA){ vencedor = 2; }

    if(jogador1==TESOURA && jogador2==PAPEL){ vencedor = 1; }
    if(jogador1==TESOURA && jogador2==PEDRA){ vencedor = 2; }

    return vencedor;
}

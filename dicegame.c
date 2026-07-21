/* dicegame.c */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int myRandom(int max)
{
    int x;

    //criando num aleatório entre 1 "max"
    x = rand() % max +1;

    return x;
}

int main()
{
    //variáveis: saldo, aposta, palpite, dado
    int balance, bet, guess, dice;

    //alimentando o gerador de num aleatório
    srand(getpid());

    balance = 1000;

    while(1)
    {
        printf("Faca sua aposta: ");
        fflush(stdout);
        scanf("%d", &bet);

        printf("Faca seu palpite de 1-6 (ou digite 0 para sair):\n");
        scanf("%d", &guess);
        if(guess == 0)
        {
            return 0;
        }

        printf("Rolando o dado...\n");
        sleep(2);
        dice = myRandom(6);
        printf("Resultado: %d\n", dice);

        if(guess != dice)
        {
            balance -= bet;
            printf("Voce Perdeu!!\n");
        }
        else
        {
            //se ganhar, multiplique por 3 e add o valor ao saldo (balance)
            bet *= 3;
            balance += bet;
            printf("Voce Ganhou. Parabens!!\n");
        }

        if(balance == 0)
        {
            printf("Fim de jogo\n");
            return 0;
        }

        printf("Saldo : $%d\n", balance);
    }

    return 0;
}

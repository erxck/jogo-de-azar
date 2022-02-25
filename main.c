#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* contém protótipo para função time */

/* constantes de enumeração representam status do jogo */
enum Status {CONTINUA, GANHOU, PERDEU};
int retornaDados(void);

int main(void)
{
    int soma; /* soma dos dados lançados */
    int meuPonto; /* ponto ganho */

    enum Status gameStatus; /* pode conter CONTINUA, GANHOU ou PERDEU */

    srand(time(NULL)); /* randomiza gerador de número aleatório usando hora atual */
    
    soma = retornaDados(); /* primeiro lançamento dos dados */

    /* determina status do jogo com base na soma dos dados */
    switch(soma) {

        /* vence na primeira jogada */
        case 7:
        case 11:
            gameStatus = GANHOU;
            break;

        /* perde na primeira jogada */
        case 2:
        case 3:
        case 12:
            gameStatus = PERDEU;
            break;
        
        /* lembra ponto */
        default:
            gameStatus = CONTINUA;
            meuPonto = soma;
            printf("\nMeus pontos: %d\n\n", soma);
            break;
    }

    /* enquanto jogo não termina */
    while(gameStatus == CONTINUA) {
        soma = retornaDados(); /* joga dados novamente */ 

        /* determina status do jogo */ 
        if(soma == meuPonto) { /* vence fazendo ponto */ 
            gameStatus = GANHOU; /* jogo termina, jogador vence */
        }else if(soma == 7) { /* perde por lançar 7 */
            gameStatus = PERDEU; /* jogo termina, jogador perde */
        }
    }

    /* mostra mensagem de vitória ou perda */ 
    if(gameStatus == GANHOU) { /* jogador venceu? */
        printf("\nO jogador venceu!\n");
    }else{ /* jogador perdeu */ 
        printf("\nO jogador perdeu!\n");
    }

    return 0;
}

/* lança dados, calcula soma e exibe resultados */
int retornaDados(void)
{
    int dado1; /* primeiro dado */ 
    int dado2; /* segundo dado */ 
    int soma; /* soma dos dados */

    dado1 = 1 + (rand() % 6); /* escolhe valor aleatório dado1 */
    dado2 = 1 + (rand() % 6); /* escolhe valor aleatório dado2 */
    soma = dado1 + dado2; /* soma dado1 e dado2 */

    /* exibe resultados dessa jogada */
    printf("A soma do %d + %d = %d\n", dado1, dado2, soma);
    return soma; /* retorna soma dos dados */ 
}
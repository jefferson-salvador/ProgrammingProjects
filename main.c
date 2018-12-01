#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

char player1, player2, tie, roundChar;
int i, rounds, p1_score = 0, p2_score = 0, winningScore;
int instruction(), game(), tieBreaker();

int main()
{
    start:

    printf("ROCK, PAPER, SCISSORS GAME!\n\n");

    printf("How many rounds do you want? \n");
    scanf(" %c", &roundChar);

    if(!(isdigit(roundChar)))
    {
        printf("Just enter an integer!");
        getch();
        system("cls");

        goto start;
    }

    rounds = roundChar - '0';

    winningScore = (rounds/2)+1;

    printf("\nFirst to get %d POINTS will win! Let\'s begin the game!", winningScore);

    getch();

    system("cls");

    game();

    getch();

    system("cls");

    printf("\nThank You! ");

    return (0);
}

int instruction()
{
    printf("Hey player! Please read the following instructions:\n\n");
    printf("Enter 'R' to attack with ROCK!\n");
    printf("Enter 'P' to attack with PAPER!\n");
    printf("Enter 'S' to attack with SCISSORS!\n\n");

    return (0);
}

int game()
{
    for(i = 1; i <= rounds; i++)
    {
        printf("Round %d\n\n", i);

        instruction();

        printf("Player 1, enter your attack: ");
        scanf(" %c", &player1);

        system("cls");
        printf("Round %d\n\n", i);

        instruction();

        printf("Player 2, enter your attack: ");
        scanf(" %c", &player2);
        printf("\n\n");

        if((player1 == 'P' || player1 == 'p') && (player2 == 'R' || player2 == 'r'))
        {
            printf("PAPER BEATS ROCK! PLAYER 1 WIN!! GOOD JOB!!\n");
            p1_score++;
        }
        else if((player1 == 'R' || player1 == 'r') && (player2 == 'S' || player2 == 's'))
        {
            printf("ROCK BEATS SCISSORS! PLAYER 1 WIN!! GOOD JOB!!\n");
            p1_score++;
        }
        else if((player1 == 'S' || player1 == 's') && (player2 == 'P' || player2 == 'p'))
        {
            printf("SCISSORS BEATS PAPER! PLAYER 1 WIN!! GOOD JOB!!\n");
            p1_score++;
        }
        else if((player2 == 'P' || player2 == 'p') && (player1 == 'R' || player1 == 'r'))
        {
            printf("PAPER BEATS ROCK! PLAYER 2 WIN!! GOOD JOB!!\n");
            p2_score++;
        }
        else if((player2 == 'R' || player2 == 'r') && (player1 == 'S' || player1 == 's'))
        {
            printf("ROCK BEATS SCISSORS! PLAYER 2 WIN!! GOOD JOB!!\n");
            p2_score++;
        }
        else if((player2 == 'S' || player2 == 's') && (player1 == 'P' || player1 == 'p'))
        {
            printf("SCISSORS BEATS PAPER! PLAYER 2 WIN!! GOOD JOB!!\n");
            p2_score++;
        }
        else if((player1 == 'R' || player1 == 'r') && (player2 == 'R' || player2 == 'r'))
        {
            printf("ROCK VS. ROCK! DRAW!");
            i--;
        }
        else if((player1 == 'P' || player1 == 'p') && (player2 == 'P' || player2 == 'p'))
        {
            printf("PAPER VS. PAPER! DRAW!");
            i--;
        }
        else if((player1 == 'S' || player1 == 's') && (player2 == 'S' || player2 == 's'))
        {
            printf("SCISSORS VS. SCISSORS! DRAW!");
            i--;
        }
        else
        {
            printf("INVALID INPUT!! Try again!\n");
            i--;
        }

        if(p1_score == winningScore)
        {
            getch();
            system("cls");
            printf("PLAYER 1 SCORED %d first!\n", winningScore);
            printf("\nPlayer 1 won the ROCK, PAPER, SCISSORS GAME! THAT\'S INTENSE! CONGRATS! \n");
            break;
        }

        if(p2_score == winningScore)
        {
            getch();
            system("cls");
            printf("PLAYER 2 SCORED %d first!\n", winningScore);
            printf("\nPlayer 2 WON the ROCK, PAPER, SCISSORS GAME! THAT\'S INTENSE! CONGRATS! \n");
            break;
        }

        if(rounds %2 == 0 && p1_score == winningScore -1 && p2_score == winningScore - 1)
        {
            getch();
            tieBreaker();
        }

        getch();
        system("cls");
    }

    return(0);
}

int tieBreaker()
{
    system("cls");
    printf("PLAYER 1 and 2 SCORED %d !\n", winningScore - 1);
    printf("\nWant to go to the tie- breaking round?\n\(Answer with \"Y\" for YES or \"N\" for NO only.)\n");
    scanf(" %c", &tie);

    if (tie == 'Y' || tie == 'y')
    {
        draw:
            system("cls");

            winningScore = 1;
            printf("TIE- BREAKER ROUND!\n");
            printf("The first one to get the point will win the game! Good luck!\n\n");

            instruction();


            printf("\nPlayer 1, enter your attack: ");
            scanf(" %c", &player1);

            system("cls");

            printf("TIE BREAKER ROUND!\n");

            instruction();

            printf("\nPlayer 2, enter your attack: ");
            scanf(" %c", &player2);
            system("cls");

            if(((player1 == 'P' || player1 == 'p') && (player2 == 'R' || player2 == 'r')) || ((player1 == 'R' || player1 == 'r') && (player2 == 'S' || player2 == 's')) || ((player1 == 'S' || player1 == 's') && (player2 == 'P' || player2 == 'p')))
            {
                p1_score++;
            }
            else if(player1 == player2)
            {
                printf("Draw! Try again!");
                getch();
                goto draw;
            }
            else
            {
                p2_score++;
            }

            if(p1_score > p2_score)
            {
                system("cls");
                printf("PLAYER 1 SCORED %d first!\n", winningScore);
                printf("\nPlayer 1 won the ROCK, PAPER, SCISSORS GAME! THAT\'S INTENSE! CONGRATS! \n");
            }
            else
            {
                system("cls");
                printf("PLAYER 2 SCORED %d first!\n", winningScore);
                printf("\nPlayer 2 WON the ROCK, PAPER, SCISSORS GAME! THAT\'S INTENSE! CONGRATS! \n");
            }
    }
    else
    {
        printf("It's a TIE! \n");
    }
    return (0);
}

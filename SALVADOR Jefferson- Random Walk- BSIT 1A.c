#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define SIZE 10

int i, j, k, l, move;
char arr[SIZE][SIZE];
char alpha[26];

void init(), walk(), display();

int main()
{
    char again;
    do{
        printf("\t\t\t=======RANDOM WALK=======\n");

        init();
        walk();
        display();
        printf("\n\nTry again? Press 'Y' for yes or 'N' for no: ");
        scanf(" %c", &again);
        system("cls");
    } while(again=='y' || again== 'Y');

    printf("Thank you! :*\n\n");
    getch();
    return 0;
}

void init(){
    l = 0;
    while(l < 26){
        alpha[l] = 'A' + l;
        l++;
    }

    //INITIALIZE THE ARRAY WITH '*'
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            arr[i][j] = '*';
        }
    }

    arr[0][0] = 'A';
}

void walk(){
    i = 0, j = 0;
    srand(time(NULL));
    //LOOKING FOR DIRECTION
    for (k=1; k < 26;) {

        move = rand() % 4 + 1;

        if (arr[i][j] == '*')
            arr[i][j] = alpha[k++];

        if (arr[i][j+1] != '*' && arr[i+1][j] != '*' && arr[i-1][j] != '*' && arr[i][j-1] != '*')
            break;

        switch (move) {
            case 1: // move right
                if (j < SIZE - 1 && arr[i][j+1] == '*'){
                    j++;
                    break;
                }
            case 2: // move left
                if (j > 0 && arr[i][j-1] == '*'){
                    j--;
                    break;
                }

            case 3: // move upward
                if (i > 0 && arr[i-1][j] == '*'){
                    i--;
                    break;
                }
            case 4: // move downward
                if (i < SIZE - 1 && arr[i+1][j] == '*'){
                    i++;
                    break;
                }
        }
    }
}

void display(){
    printf("\t\t\t------------START------------\n\n");
    printf("\n");
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++)
            printf("\t%c", arr[i][j]);
        printf("\n\n");
    }
    printf("\n\n\t\t\t------------END------------");
}

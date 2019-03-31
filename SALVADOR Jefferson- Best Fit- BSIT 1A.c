#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int i, j , bSize, pSize, temp, lowest=10000;
static int bArr[100],pArr[100],block[100], b2[100],process[100], frag[100];

void input(), memAloc(), display();

int main()
{
    char again;
    do{
        printf("=========BEST FIT MEMORY MANAGEMENT=========\n\n");

        input();
        memAloc();
        display();

        printf("\nTry again? Press 'Y' for yes or 'N' for No: ");
        scanf(" %c", &again);
        system("cls");

    }while(again == 'y' || again == 'Y');

    printf("\nThank you! :*\n\n");
    getch();
    return 0;
}

void input(){
    printf("Enter the total number of blocks: ");
    scanf("%d",&bSize);

    printf("Enter the total number of processes: ");
    scanf("%d",&pSize);

    printf("\nEnter the size(KB) of each block:\n");
    for(i = 1; i <= bSize; i++)
    {
        printf("Block [%d]: ",i);
        scanf("%d",&block[i]);
        b2[i] = block[1];
    }

    printf("\nEnter the size(KB) of each process:\n");
    for(i = 1; i <= pSize; i++)
    {
        printf("Process [%d]: ",i);
        scanf("%d",&process[i]);
    }
}

void memAloc(){
    for(i = 1; i <= pSize; i++) // 1
	{
		for(j = 1; j <= bSize; j++) // 1
		{
            temp = block[j] - process[i];
            if(temp >= 0){
                if(lowest >= temp){
                    pArr[i] = j;
                    bArr[i] = block[j];
                    lowest = temp;
                }
            }

		}
		frag[i] = lowest;
		block[pArr[i]] = lowest;
		lowest = 10000;
	}
}

void display(){
    printf("\nProcess No.\tProcess Size\tBlock No.\tBlock Size\tFragments\n");
	for(i = 1;i <= pSize; i++){
        if(frag[i]!= 10000){
            printf("%d\t\t[%d]KB\t\t%d\t\t[%d]KB\t\t[%d]KB\n",i,process[i],pArr[i],bArr[i],frag[i]);
        }
	}

    printf("\n\n");
	for(i = 1;i <= pSize; i++){
        if(frag[i]== 10000){
            printf("! *Process %d: [%d]KB not allocated.\n", i, process[i]);
        }
	}
	printf("\n");
	for(i = 1;i <= bSize; i++){
        if(block[i]== b2[i]){
            printf("! *Block %d: [%d]KB not used.\n", i, block[i]);
        }
	}

    printf("\n");
}

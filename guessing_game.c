#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main(void){
    srand(time(0));
    int number=rand()%100 + 1; // generates a random number between 1 and 100
    //printf("%d\n",number);
    int count=0,input;
    printf("-----------------------------------------\n");
    printf("|              WELCOME  TO              |\n");
    printf("|                  THE                  |\n");
    printf("|             GUESSING GAME             |\n");
    printf("-----------------------------------------\n");
    do{
        count++;
        printf("\nGuess a number between 1 and 100: ");
        scanf("%d", &input);
        if(input>number)
            printf("\nNope!! The number is lesser than your guess.\nTry Again!!\n");
        else if(input<number)
            printf("\nNope!! The number is greater than your guess.\nTry Again!!\n");
        else
            printf("\nJackpot!! U guessed the number in %d attempts.\n", count);
    }while(input!=number);
    return 0;
}
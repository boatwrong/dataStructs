#include<stdio.h>

void getInt(int *x)
{
    if (scanf("%d%*c", x) != 1)
    {
        int z;
        do {
            printf("try again\n");
            z = scanf("%*c%d", x);
        }while(z != 1);
    }
}

int main(int argc, char *argv[])
{

    int numGames, numQueries;

    printf("Please enter the number of games in the shop\n");
    getInt(&numGames);
    int games[numGames];


    printf("Please enter the prices of the %d games\n", numGames);   
    for(int i = 0; i < numGames; i++)
    {
        getInt(&games[i]);
    }

    printf("Please enter the number of queries allowed \n");   
    getInt(&numQueries);
    int queries[3];

    printf("Please enter %d queries to see how many games are below the price entered\n", numQueries);
    for(int i = 0; i < numQueries; i++)
    {
        getInt(&queries[i]);
    }

    // implemet binary sort

    return 0;
}


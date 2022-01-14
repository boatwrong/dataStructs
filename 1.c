#include<stdio.h>
#include<stdlib.h>

void getInt(int *x)
{
    if (scanf("%d%*c", x) != 1)
    {
        int z;
        do {
            z = scanf("%*c%d", x);
        }while(z != 1);
    }
}

int binSort(int arr[], int arrSize, int query)
{
    // binary sort method to find number of games with price <= query

    int count = 0;

    for(int i = 0; i < arrSize; i++)
    {
        // check if game price is less than query
        if(query > arr[i])
        {
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[])
{

    int numGames, numQueries;

    // take input for number of games
    getInt(&numGames);
    int games[numGames];

    // take input for game prices
    for(int i = 0; i < numGames; i++)
    {
        getInt(&games[i]);
    }

    // take input for amount of queries allowed
    getInt(&numQueries);
    int queries[3];

    // take input for array of queries
    for(int i = 0; i < numQueries; i++)
    {
        getInt(&queries[i]);
    }

    // implemet binary sort
    for(int i = 0; i < numQueries; i++)
    {
        printf("%d\n", binSort(games, numGames, queries[i]));
    }

    exit(0);
}


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int *smaller, int *bigger)
{
    int temp = *smaller;
    *smaller = *bigger;
    *bigger = temp;
}

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

void sortSmallToLarge(int arr[], int n)
{
    int smallIndex;

    for(int i = 0; i < n-1; i++)
    {
        smallIndex = i;
        
        for(int j = i+1; j < n; j++)
        {
            if(arr[smallIndex] > arr[j])
            {
                swap(&arr[smallIndex], &arr[j]);
            }
            else
            {
                continue;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int numTests, numBoys, numGirls;

    getInt(&numTests);
    for(int i=0; i<numTests; i++)
    {
        getInt(&numBoys);
        getInt(&numGirls);

        int boys[numBoys], girls[numGirls];

        for( int i=0; i<numBoys; i++)
        {
            getInt(&boys[i]);
        }

        for( int i=0; i<numGirls; i++)
        {
            getInt(&girls[i]);
        }

        sortSmallToLarge(boys, numBoys);
        sortSmallToLarge(girls, numGirls);
        
        int y = 0;
        bool stillHaveShorterGirls = true;
        while(y < numBoys && stillHaveShorterGirls)
        {
            if(boys[y] > girls[y]) 
            {
                y++;
                continue;
            }
            else
            {
                stillHaveShorterGirls = false;
                break;
            }
        }
        
        if(numBoys > numGirls)
        {
            printf("NO\n");
        }

        else if(y < numBoys)
        {
            printf("NO\n");
        }

        else if(y == numBoys)
        {
            printf("YES\n");
        }

        else
        {
            return 1;
        }
    }
    return 0;
}


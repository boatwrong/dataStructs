#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX_WORD_SIZE 15

typedef struct {
    char T[MAX_WORD_SIZE];
    char S[MAX_WORD_SIZE];
}test;

int hash(char *word)
{
    int sum = 0;
    for(int i=0; i<strlen(word)-1; i++)
    {
        sum += word[i];
    }
    return sum;
}

void takeInput(char *word)
{
    fgets(word, MAX_WORD_SIZE, stdin);
}

int checkDuplicates(char *S, char *T)
{
    // isue is maybe in here...
    int instanceT = 0;
    int instanceS = 0;
    int count = 0;
    for(int i=0; i <strlen(S); i++)
    {
        for(int j=0; i<strlen(T); i++)
        {
            if(T[j] == S[i])
            {
                instanceT++;
            }
            if(S[j] == S[i])
            {
                instanceS++;
            }
        }
        count += instanceS - instanceT;
        for(int i=0; i<(instanceS - instanceT); i++)
        {
            T[strlen(T)] = S[i];
        }
    }
    return count;
}

int addToT(char *S, char *T, int listSize)
{
    int count = 0;
    for(int i=0; i<listSize;i++)
    {
        bool TcontainsChar = false;
        for(int j=0; j<listSize; j++)
        {
            if(S[i] == T[j])
            {
                TcontainsChar = true;
            }
        }
        if(!TcontainsChar)
        {
            T[listSize] = S[i];
            count++;
        }
        count += checkDuplicates(S,T);   
    }
    return count;
}

void removeChar(char *T, int idx)
{
    for(int i=idx; i<strlen(T) - 1; i++)
    {
        T[i] = T[i+1];
    }
    T[strlen(T)] = '\0';
}

int removeFromT(char *S, char *T, int length)
{
    int count = 0;
    for(int i=0; i<length;i++)
    {
        bool ScontainsChar = false;
        for(int j=0; j<length; j++)
        {
            if(T[i] == S[j])
            {
                ScontainsChar = true;
            }
        }
        if(!ScontainsChar)
        {
            removeChar(T, i);
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
    int listSize;
    int numTests[listSize];
    scanf("%d%*c", &listSize);
    test tmp;
    for(int i=0; i<listSize; i++)
    {
        numTests[i] = 0;
        takeInput(tmp.S);
        takeInput(tmp.T);
        if(hash(tmp.S) != hash(tmp.T))
        {
            numTests[i] += removeFromT(tmp.S, tmp.T, strlen(tmp.S));
            numTests[i] += addToT(tmp.S, tmp.T, strlen(tmp.S));
            //numTests[i]*=2;
        }
    }
    for(int i=0; i<listSize; i++)
    {
        printf("%d\n", numTests[i]);
    }
    return 0;
}

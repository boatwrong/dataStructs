#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

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

void append(char *T, char c)
{
    T[strlen(T)] = c;
}

void removeChar(char *T, int idx)
{
    printf("removing %c\n", T[idx]);
    for(int i=idx; i<strlen(T) - 1; i++)
    {
        T[i] = T[i+1];
    }
    T[strlen(T)-1] = '\0';
}

void otherRemove(char *T, char c)
{
    int i=0;
    while(T[i] != c)
    {
        i++;
    }
    removeChar(T, i);
}


int duplicates(char *S, char *T)
{
    printf("duplicate function\n");
    int count = 0;
    int inS = 0;
    int inT = 0;
    for(int i=0; i<strlen(S); i++)
    {
        printf("checking %c\n", S[i]);
        for(int k=0; k<strlen(S); k++)
        {
            if(S[k] == S[i] && k != i)
            {
                inS++;
            }
        }
        for(int j=0; j<strlen(T); j++)
        {
            if(S[i] == T[j])
            {
                inT++;
            }
        }

        if(inS < inT)
        {
            printf("removing %c from T\n", S[i]);
            otherRemove(T, S[i]);
            count++;
        }
    }
    return 0;
}

int checkDuplicates(char *S, char *T)
{
    int instanceT, instanceS;
    int count = 0;
    for(int i=0; i <strlen(S); i++)
    {
        instanceS = 0;
        instanceT = 0;
        for(int j=0; j<strlen(S); j++)
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
        count += abs(instanceS - instanceT);
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
    }
    count += duplicates(S,T);   
    printf("Count from adding function: %d\n", count);
    return count;
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
            removeFromT(tmp.S, tmp.T, strlen(tmp.S));
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

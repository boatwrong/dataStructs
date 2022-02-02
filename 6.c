#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WORD_SIZE 15

typedef struct {
    char* word[MAX_WORD_SIZE];
}person;

person tmp;

int hash(char *word)
{
    int sum;
    for(int i=0; i<strlen(word)-1; i++)
    {
        sum += word[i];
    }
    return sum;
}

void takeInput(char *tmp)
{
    printf("taking input\n");
    fgets(tmp, MAX_WORD_SIZE, stdin);
    printf("input taken\n");
}

int main(int argc, char *argv[])
{
    int listSize;
    int numTests[listSize];
    printf("input number of tests\n");
    scanf("%d", &listSize);
    char T[MAX_WORD_SIZE];
    char S[MAX_WORD_SIZE];
    for(int i=0; i<listSize; i++)
    {
        numTests[i] = 0;
        printf("test %d\n", i+1);
        takeInput(T);
        takeInput(S);
        while(hash(T) != hash(S))
        {
            numTests[i]++;
            // do operations...
        }
    }
    return 0;
}


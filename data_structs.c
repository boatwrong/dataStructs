#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX_WORD_SIZE 11

typedef struct {
	char T[MAX_WORD_SIZE];
	char S[MAX_WORD_SIZE];
}test;

int removeChar(char *T, int idx)
{
    printf("\tremoving %c\n", T[idx]);
    //TODO KEEP ME
	for(int i=idx; i<strlen(T) - 1; i++)
	{
		T[i] = T[i+1];
	}
	T[strlen(T) - 1] = '\0';
    printf("new string: %s\n", T);
    return 1;
}

int addChar(char *T, char c)
{
    //TODO KEEP ME
    printf("\tadding char %c\n", c);
    int length = strlen(T);
    T[length] = c;
    T[length+1] = '\0';
    return 1;
}

int findMissingChar(char *S, char *T)
{
    //TODO KEEP ME
    int count = 0;
    bool existsInT;
    for(int i = 0; i<strlen(S); i++)
    {
        existsInT = false;
        for(int j= 0; j < strlen(T); j++)
        {
            if(T[j] == S[i])
            {
                existsInT = true;
            }
        }
        if(!existsInT)
        {
            count += addChar(T, S[i]);
        }
    }
    return count;
}

int findBadChar(char *S, char *T)
{
    //TODO KEEP ME
    int count = 0;
    bool existsInS;
    for(int i = 0; i < strlen(T); i++)
    {
        existsInS = false;
        for(int j = 0; j < strlen(S); j++)
        {
            if(T[i] == S[j])
            {
                existsInS = true;
            }
        }
        
        if(!existsInS)
        {
            count += removeChar(T, i);
            count += findMissingChar(S, T);
        }
        else
        {
            //TODO check duplicates
        }
    }
    return count;
}

void trim(char *str)
{
    char badChar = '\n';
    for(int i=0; i<strlen(str); i++)
    {
        if(str[i] == badChar)
        {
            for(int j=i; i<strlen(str) - 1; i++)
            {
                str[i] = str[i+1];
            }
            str[strlen(str) - 1] = '\0';
        }
    }
}

void takeInput(char *word)
{
	fgets(word, MAX_WORD_SIZE, stdin);
    trim(word);
}

int hash(char *word)
{
	int sum = 0;
	for(int i=0; i<strlen(word)-1; i++)
	{
		sum += word[i];
	}
	return sum;
}

bool hasDuplicates(char *T)
{
    bool hasDups = false;
    for(int i=0; i<strlen(T) - 1; i++)
    {
        for(int j=i+1; j < strlen(T); j++)
        {
            if(T[i] == T[j])
            {
                hasDups = true;
            }
        }
    }
    return hasDups;
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
        if(hasDuplicates(tmp.S))
        {
            printf("S has a duplicate!\n");
        }
        if(hasDuplicates(tmp.T))
        {
            printf("T has a duplicate!\n");
        }
        printf("string S: %s\n", tmp.S);
        printf("string T: %s\n", tmp.T);
		if(hash(tmp.S) != hash(tmp.T))
		{
			numTests[i] += findBadChar(tmp.S, tmp.T);
			//numTests[i] += addToT(tmp.S, tmp.T, strlen(tmp.S));
			//numTests[i] += removeFromT(tmp.S, tmp.T, strlen(tmp.S));
			//numTests[i]*=2;
		}
        printf("######################################################################\n");
	}
	for(int i=0; i<listSize; i++)
	{
		printf("%d\n", numTests[i]);
	}
    printf("S after edits: %s\n", tmp.S);
    printf("T after edits: %s\n", tmp.T);
	return 0;
}

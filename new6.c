#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX_WORD_SIZE 12

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

void removeChar(char *T, int idx)
{
    for(int i=idx; i<strlen(T) - 1; i++)
    {
        T[i] = T[i+1];
    }
    T[strlen(T) - 1] = '\0';
}

bool contains(char *str, char c)
{
    bool contains = false;
    for(int i=0; i<strlen(str); i++)
    {
        if(str[i] == c)
        {
            contains = true;
        }
    }
    return contains;
}

void addChar(char *T, char c)
{
    int i=0;
    while(T[i] != '\0')
    {
        i++;
    }
    T[i] = c;
    T[i+1] = '\0';  
}

int checkLength(char *S, char *T)
{
    int count = 0;
    if(strlen(S) > strlen(T))
    {
        while(strlen(S) > strlen(T))
        {
            for(int i=0; i<strlen(S); i++)
            {
                if(!contains(T, S[i]))
                {
                    addChar(T, S[i]);
                    count++;
                }
            }
        }
    }
    else if(strlen(T) > strlen(S))
    {
        while(strlen(T) > strlen(S))
        {
            removeChar(T, strlen(T) - 1);
            count++;
        }
    }
    return count;
}

int getInput(char *S, char *T)
{
    takeInput(S);
    takeInput(T);
    return checkLength(S,T);
}

void findMissing(char *S, char *T)
{
    int Scount = 0;
    int Tcount = 0;
    for(int i = 0; i < strlen(T); i++)
    {
        for(int j = 0; j < strlen(S); j++)
        {
            if(S[i] == S[j])
            {
                Scount++;
            }
        }
        for(int j = 0; j<strlen(T); j++)
        {
            if(S[i] == T[j])
            {
                Tcount++;
            }
        }
        if(Tcount < Scount)
        {
            addChar(T, S[i]);
            return;
        }
    }
}

void findExtras(char *S, char *T)
{
    int Scount = 0;
    int Tcount = 0;
    for(int i = 0; i < strlen(T); i++)
    {
        for(int j = 0; j < strlen(S); j++)
        {
            if(T[i] == S[j])
            {
                Scount++;
            }
        }
        for(int j = 0; j<strlen(T); j++)
        {
            if(T[i] == T[j])
            {
                Tcount++;
            }
        }
        if(Tcount > Scount)
        {
            removeChar(T, i);
            return;
        }
    }
}

int getIndex(char *T, char c)
{
    int idx;
    for(int i=0; i<strlen(T); i++)
    {
        if(T[i] == c)
        {
            return i;
        }
    }
    return -1;
}

int fixHash(char *S, char *T)
{
    int operations = 0;
    int countInS = 0;
    int countInT = 0;
    for(int i=0; i< strlen(S); i++)
    {
        for(int j=0; j<strlen(S); j++)
        {
            if(S[i] == S[j])
            {
                countInS++;
            }
        }
        for(int j=0; j<strlen(T); j++)
        {
            if(S[i] == T[j])
            {
                countInT++;
            }
        
        }
        if(countInS > countInT)
        {
            addChar(T, S[i]);
            findExtras(S, T);
            operations += 2;
        }
        if(countInT > countInS)
        {
            removeChar(T, getIndex(T, S[i]));
            findMissing(S,T);
            operations += 2;
        }
    }
    return operations;
}

int fixBasic(char *S, char *T)
{
    int count = 0;
    for(int i=0; i<strlen(T); i++)
    {
        if(!contains(S, T[i]))
        {
            removeChar(T, i);
            count++;
        }
    }
    for(int i=0; i<strlen(S); i++)
    {
        if(!contains(T, S[i]))
        {
            addChar(T, S[i]);
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
    int counter;
    int listSize;
    scanf("%d%*c", &listSize);
    int numTests[listSize];
    test tmp;

    for(int i=0; i<listSize; i++)
    {
        counter = 0;
        numTests[i] = 0;
        numTests[i] += getInput(tmp.S, tmp.T);
        if(hash(tmp.S) != hash(tmp.T))
        {
            numTests[i] += fixHash(tmp.S, tmp.T);
        }
    }

    for(int i=0; i<listSize; i++)
    {
        printf("%d\n", numTests[i]);
    }
    return 0;
}

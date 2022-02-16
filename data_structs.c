#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX_WORD_SIZE 12

typedef struct {
    char T[MAX_WORD_SIZE];
    char S[MAX_WORD_SIZE];
}test;

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

int removeChar(char *T, int idx)
{
    for(int i=idx; i<strlen(T) - 1; i++)
    {
        T[i] = T[i+1];
    }
    T[strlen(T) - 1] = '\0';
    return 1;
}

int addChar(char *T, char c)
{
    int i=0;
    while(T[i] != '\0')
    {
        i++;
    }
    T[i] = c;
    T[i+1] = '\0';  
    return 1;
}

int findMissingChar(char *S, char *T)
{
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

        if(!contains(S, T[i]))
        {
            count += removeChar(T, i);
            count += findMissingChar(S, T);
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

bool stillUnevenDups(char *S, char *T)
{
    bool isEven = true;
    int countInS = 0;
    int countInT = 0;
    if(strlen(S) != strlen(T))
    {
    }
    for(int i=0; i< strlen(S); i++)
    {
        for(int j=0; j<strlen(S); j++)
        {
            if(T[j] == T[i])
            {
                countInT++;
            }
            if(S[j] == S[i])
            {
                countInS++;
            }
            if(countInS != countInT)
            {
                isEven = false;
            }
        }
    }
    return isEven;
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

int fixDuplicates(char *S, char *T)
{
    int countInS = 0;
    int countInT = 0;
    for(int i=0; i< strlen(S); i++)
    {
        for(int j=0; j<strlen(S); j++)
        {
            if(T[i] == S[j])
            {
                countInS++;
            }
            if(T[i] == T[j])
            {
                countInT++;
            }
        }
        if(countInT > countInS)
        {
            removeChar(T, i);
            findMissing(S,T);
            return 2;
        }
        if(countInS > countInT)
        {
            addChar(T, T[i]);
            findExtras(S, T);
            return 2;
        }
    }
    return 0;
}

int makeMethodNameBetter(char *S, char *T)
{
    int count = 0;
    int i;
    if(strlen(T) > strlen(S))
    {
        i=strlen(T);
        while(strlen(T) > strlen(S))
        {
            count += removeChar(T, i);
            i--;
        }
    }
    
    if(strlen(T) < strlen(S))
    {
        i=strlen(S);
        while(strlen(T) < strlen(S))
        {
            count += addChar(T, S[i-1]);
            i--;
        }
    }

    return count;
}

int main(int argc, char *argv[])
{
    int counter;
    bool hasDups;
    int listSize;
    scanf("%d%*c", &listSize);
    int numTests[listSize];
    test tmp;
    
    for(int i=0; i<listSize; i++)
    {
        counter = 0;
        hasDups = false;
        numTests[i] = 0;
        takeInput(tmp.S);
        takeInput(tmp.T);

        if(strlen(tmp.S) != strlen(tmp.T))
        {
            numTests[i] += makeMethodNameBetter(tmp.S,tmp.T);
        }
        if(hasDuplicates(tmp.S) || hasDuplicates(tmp.T))
        {
            hasDups = true;
        }
        if(hash(tmp.S) != hash(tmp.T))
        {
            // if(hasDups)
            // {
            //     while(!stillUnevenDups(tmp.S, tmp.T) && counter < 20) 
            //     {
            //         //TODO infinite loop here...
            //         numTests[i]+=fixDuplicates(tmp.S, tmp.T);
            //         counter++;
            //     }
            // }
            // numTests[i] += findBadChar(tmp.S, tmp.T);
            numTests[i]+=fixDuplicates(tmp.S, tmp.T);
            numTests[i] += findBadChar(tmp.S, tmp.T);
        }
    }
    for(int i=0; i<listSize; i++)
    {
        printf("%d\n", numTests[i]);
    }
    return 0;
}



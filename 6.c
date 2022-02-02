#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void takeInput(char* string)
{
    //TODO Figure out why string in put not working...
    int length = 0;
    char c = '!';
    string = (char *) malloc(sizeof(char));
    if(string == NULL)
    {
        exit(1);
    }
    length++;
    while((c = getchar()) != '\n')
    {
        string = realloc(string, (sizeof(char) * length + 1));
        length++;
    }
    printf("here\n");
}

int main(int argc, char *argv[])
{
    int x;
    char* t;
    printf("input # of tests\n");
    scanf("%d", &x);
    for(int i=0; i<x; i++)
    {
        printf("test %d\n", i+1);
        takeInput(t);
    }
    printf("%lu", strlen(t));
    printf("\n");
    return 0;
}


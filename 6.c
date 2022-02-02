#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* takeInput(char* string)
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
    while((c = getchar()) != ' ' && c != '\n')
    {
        string = realloc(string, (sizeof(char) * length + 1));
    }
    printf("here\n");
    return string;
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
        t = takeInput(t);
    }
    for(int i=0; i < strlen(t); i++)
    {
        printf("%c", t[i]);
    }
    printf("\n");
    return 0;
}


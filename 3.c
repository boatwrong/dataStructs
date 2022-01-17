#include<stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    struct node *next;
} node;

struct node *head = NULL;
struct node *tail = NULL;

void append(int x)
{
    node *current = (node*)malloc(sizeof(node*));

    current->value = x;
}
int main()
{

    int numElements;

    scanf("%d", &numElements);
    if(numElements < 0)
    {
        return 1;
    }
    return 0;
}

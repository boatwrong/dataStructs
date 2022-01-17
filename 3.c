#include<stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void createFirst(int x)
{
    struct node *current = (struct node*)malloc(sizeof(struct node*));
    current->value = x;
    current->next = 0;
}

void push(int x)
{
    struct node *current = (struct node*)malloc(sizeof(struct node*));
    current->value = x;
    current->next = 0;
    tail->next = current;
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

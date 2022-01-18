#include<stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node *head = NULL;

void push(int x)
{
    // create new and temp node
    struct node *current = NULL;
    struct node *temp = NULL;
    current = malloc(sizeof(struct node*));
    temp = malloc(sizeof(struct node*));
    current = head;
    temp->value = x;
    temp->next=0;

    while(current->next != 0)
    {
        current = current->next;
    }

    current->next = temp;
}

void outputList()
{
    printf("In output function\n");
    struct node *pointer = NULL;
    pointer = malloc(sizeof(struct node*));
    pointer = head;

    printf("[ ");
    while(pointer != NULL)
    {
        printf("%d ", pointer->value);
        pointer = pointer->next;
    }
    printf("]\n");
}

int main()
{
    head = malloc(sizeof(struct node*));

    int numElements;
    scanf("%d", &numElements);

    int x;
    scanf("%d", &x);
    head->value = x;
    head->next = 0;

    for(int i = 1; i < numElements; i++)
    {
        printf("adding node\n");
        scanf("%d", &x);
        push(x);
    }
    outputList();
    return 0;
}

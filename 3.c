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
    current = (struct node*) malloc(sizeof(struct node*));
    temp = (struct node*) malloc(sizeof(struct node*));
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
    pointer = (struct node*) (malloc(sizeof(struct node*)));
    pointer = head;

    while(pointer != NULL)
    {
        printf("%d ", pointer->value);
        pointer = pointer->next;
    }
    printf("\n");
}

void traverseAndSwap()
{
    struct node *pointer = NULL;
    struct node *temp = NULL;
    pointer = (struct node*) malloc(sizeof(struct node*));
    pointer = head;
    int tempValue;

    while(pointer->next != 0)
    {
        if((pointer->value % 2) == 0 && (pointer->next->value % 2 == 0))
        {
            tempValue = pointer->next->value;
            pointer->next->value = pointer->value;
            pointer->value = tempValue;
        }
        pointer = pointer->next;
    }
}

int main()
{
    head = (struct node*) malloc(sizeof(struct node*));

    int numElements;
    scanf("%d", &numElements);

    int x;
    scanf("%d", &x);
    head->value = x;
    head->next = 0;

    for(int i = 1; i < numElements; i++)
    {
        scanf("%d", &x);
        push(x);
    }
    outputList();
    traverseAndSwap();
    outputList();
    return 0;
}

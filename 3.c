#include<stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void startList(struct node* head, int x)
{
    struct node *current = (struct node*)malloc(sizeof(struct node*));
    current->value = x;
    current->next = 0;
    head = current;
}

void push(int x)
{
    struct node *current = NULL;
    current = malloc(sizeof(struct node*));
    current->value = x;
    current->next = 0;
}

void outputList(struct node* head)
{
    printf("In output function\n");
    struct node *pointer = head;

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
    tail = malloc(sizeof(struct node*));

    int numElements;
    scanf("%d", &numElements);

    int x;
    scanf("%d", &x);
    head->value = x;
    scanf("%d", &x);
    tail->value = x;
    tail->next = 0;
    head->next = tail;

    for(int i = 2; i < numElements; i++)
    {
        scanf("%d", &x);
    }
    return 0;
}

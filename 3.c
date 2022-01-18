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
    // create new and temp node
    struct node *current = NULL;
    struct node *temp = NULL;
    current = malloc(sizeof(struct node*));
    temp = malloc(sizeof(struct node*));

    // temp is placeholder for tail value;
    // tail will be reassigned to current
    // and current will become the new tail
    temp->value = tail->value;
    temp->next = tail;
    tail->value = x;
    current->value = temp->value;
    current->next = tail;
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
        push(x);
    }
    return 0;
}

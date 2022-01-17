#include<stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void startList(int x)
{
    struct node *current = (struct node*)malloc(sizeof(struct node*));
    current->value = x;
    current->next = 0;
    head = current;
}

void push(int x)
{
    struct node *current = (struct node*)malloc(sizeof(struct node*));
    current->value = x;
    current->next = NULL;
   // tail->next = current;
   // printf("passed assigning tail pointer to current node\n");
    tail = current;
}

void outputList()
{
    struct node *current = head;

    //while(current != 0)
    //{
    //    printf("%d ", current->value);
    //}
}

int main()
{

    int numElements;

    scanf("%d", &numElements);
    if(numElements < 0)
    {
        return 1;
    }

    int x;
    scanf("%d", &x);
    startList(x);

    for(int i = 1; i < numElements; i++)
    {
        scanf("%d", &x);
        push(x);
    }

    outputList();

    return 0;
}

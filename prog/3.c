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

void outputList(int num)
{
    struct node *pointer = NULL;
    pointer = (struct node*) (malloc(sizeof(struct node*)));
    pointer = head;

    while(pointer != NULL)
    {
        if(num < 100 && pointer->next == NULL)
        {
            printf("%d", pointer->value);
            pointer = pointer->next;
        }
        else
        {
            printf("%d ", pointer->value);
            pointer = pointer->next;
        }

    }
}

void swap(struct node *p1, struct node *p2)
{
    int tmp = p2->value;
    p2->value = p1->value;
    p1->value = tmp;
    
}

void swapNodes(struct node *pointer, int index)
{
    if(index == 1)
    {
        swap(pointer, pointer->next);
        return;
    }

    int tmpVt;
    int tmpVh = pointer->value;
    struct node *temp = NULL;
    temp = (struct node*) malloc(sizeof(struct node*));
    temp = pointer;

    for(int i = 0; i < index; i++)
    {
        temp = temp->next;
    }

    tmpVt = temp->value;
    temp->value = tmpVh;
    pointer->value = tmpVt;
    if(index == 2)
    {
        index--;
        return;
    }
    else if(index > 2)
    {
        index-=2;
    }

    swapNodes(pointer->next, index);
}

void newTraverse(struct node *pointer)
{
    struct node *temp = NULL;
    temp = (struct node*) malloc(sizeof(struct node*));

    while(pointer->next != 0)
    {
        if((pointer->value % 2) == 0)
        {
            temp = pointer;
            int index = 0;

            while(temp->next != 0 && temp->next->value % 2 == 0)
            {
                index++;
                temp = temp->next;
            }


            temp = pointer;

            if(index > 0/*1*/)
            {
                swapNodes(pointer, index);
            }
            
            for(int i = 0; i < index; i++)
            {
                pointer = pointer->next;
            }

            if(index == 0)
            {
                pointer = pointer->next;
            }
        }

        else
        {
            pointer = pointer->next;
        }
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

    newTraverse(head);
    outputList(numElements);
    return 0;
}

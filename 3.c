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
    temp = (struct node*) malloc(sizeof(struct node*));
    pointer = head;
    int tempValue;

    while(pointer->next != 0)
    {
        if((pointer->value % 2) == 0)
        {
            printf("Made it here\n");
            // TODO fix infinite loop
            temp = pointer;
            int index = 0;
            while(pointer->next->value % 2 == 0)
            {
                index++;
                if(index == 1)
                {
                    // do single flip
                    tempValue = pointer->next->value;
                    pointer->next->value = pointer->value;
                    pointer->value = tempValue;
                    pointer = pointer->next;
                }
                else if(index == 2)
                {
                    // figure out algorithm for multiple evens
                    tempValue = pointer->next->next->value;
                    pointer->next->next->value = pointer->value;
                    pointer->value = tempValue;
                    pointer = pointer->next->next;
                }
                else if(index > 2)
                {
                    // multiple flips
                    printf("multiple evens in a row\n");
                }
            }
           //  if(pointer->next->next->value % 2 == 0)
           //  {
           //      tempValue = pointer->next->next->value;
           //      pointer->next->next->value = pointer->value;
           //      pointer->value = tempValue;
           //      pointer = pointer->next->next;
           //  }
           //  else
           //  {
           //      tempValue = pointer->next->value;
           //      pointer->next->value = pointer->value;
           //      pointer->value = tempValue;
           //      pointer = pointer->next;
           //  }
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
    traverseAndSwap();
    outputList();
    return 0;
}

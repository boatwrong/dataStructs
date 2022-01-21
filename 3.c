#include<stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node *head = NULL;

/*
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
            temp = pointer;
            int index = 0;
            while(temp->next->value % 2 == 0 && temp->next != 0)
            {
                index++;
                temp = temp->next;
            }
            temp = pointer;
            if(index == 1)
            {
                printf("2 even nodes in a row\n");
                tempValue = pointer->next->value;
                pointer->next->value = pointer->value;
                pointer->value = tempValue;
                pointer = pointer->next;
            }
            else if(index == 2)
            {
                printf("3 even nodes in a row\n");
                tempValue = pointer->next->next->value;
                pointer->next->next->value = pointer->value;
                pointer->value = tempValue;
                pointer = pointer->next->next;
            }
            else if(index > 2)
            {
                printf("%d even nodes in  a row\n",index + 1);
                pointer = pointer->next->next->next;
            }
            else
            {
                printf("no following even nodes\n");
                pointer = pointer->next;
            }
            if(pointer->next->next->value % 2 == 0)
            {
                tempValue = pointer->next->next->value;
                pointer->next->next->value = pointer->value;
                pointer->value = tempValue;
                pointer = pointer->next->next;
            }
            else
            {
                tempValue = pointer->next->value;
                pointer->next->value = pointer->value;
                pointer->value = tempValue;
                pointer = pointer->next;
            }
        }
        else
        {
            pointer = pointer->next;
        }
    }
}
*/

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
        printf("reached base case\n");
        swap(pointer, pointer->next);
        return;
    }

    printf("Multi Swap func\n");
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
    
    index--;
    swapNodes(pointer->next, index);
}

void newTraverse()
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
            // TODO fix infinite loop
            temp = pointer;
            int index = 0;

            while(temp->next->value % 2 == 0 && temp->next != 0)
            {
                index++;
                temp = temp->next;
            }

            temp = pointer;

            if(index == 1)
            {
                swap(pointer, pointer->next);
            }

            else if(index > 1)
            {
                printf("multiple even nodes\n");
                swapNodes(pointer, index);
            }
            
            for(int i = 0; i < index; i++)
            {
                printf("made it to for loop\n");
                pointer = pointer->next;
            }

            if(index == 0)
            {
                pointer = pointer->next;
            }
        }

        else
        {
            printf("else loop\n");
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
//    traverseAndSwap();
    newTraverse();
    outputList();
    return 0;
}

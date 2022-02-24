#include<stdio.h>
#include<stdlib.h>

int numElements;

struct node {
    int value;
    struct node *next;
};

struct node *head = NULL;

void push(int x)
{
    struct node *current = (struct node*) malloc(sizeof(struct node));
    current->value = x;
    current->next = head;
    head = current;
    numElements++;
}


void displayTop()
{
    printf("%d\n", head->value);
}

int pop()
{
    int x = head->value;
    head = head->next;
    numElements--;
    if(head == NULL)
    {
        return 0;
    }
    else
    {
        return x;
    }
}

void sum()
{
    struct node *pointer = head;
    int sum = pointer->value;
    while(pointer->next != 0)
    {
        pointer = pointer->next;
        sum += pointer->value;
    }
    printf("%d\n", sum);
}

void query()
{
    int sumPopped = 0;
    int x,y,n;
    scanf("%d", &y);

    switch(y) {
        case 1:
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            scanf("%d %d", &n, &x);
            for(int i=0; i<n; i++)
            {
                push(x);
            }
            break;
        case 3:
            // displayTop();
            printf("%d\n", pop());
            break;
        case 4:
            scanf("%d", &n);
            if(n <= numElements)
            {
                for(int i=0; i<n; i++)
                {
                    sumPopped += pop();
                }
                printf("%d\n", sumPopped);
                break;
            }
            sum();
            break;
        case 5:
            sum();
            break;
    }
}

int main(int argc, char *argv[])
{
    int numQueries;
    scanf("%d", &numQueries);

    for(int i=0; i < numQueries; i++)
    {
        query();
    }
    return 0;
}


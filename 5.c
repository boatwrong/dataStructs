#include<stdio.h>
#include<stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *head = NULL;

void push(int m)
{
    struct node *current = NULL;
    struct node *temp = NULL;
    current = (struct node*) malloc(sizeof(struct node*));
    temp = (struct node*) malloc(sizeof(struct node*));
    current = head;
    temp->value = m;
    temp->next=0;
    while(current->next != 0)
    {
        current = current->next;
    }
    current->next = temp;
}

void popStack(int *x, int *k)
{
    *x += head->value;
    head = head->next;
    *k-=1;
    printf("%d\n", *k);
}

void traverse(struct node* pointer)
{
    // moves a pointer through stack
    while(pointer->next != NULL)
    {
        pointer = pointer->next;
    }
}

int sumTop(int x)
{
    return 0;
}

int sumBottom(int y)
{
    return 0;
}

void checkSum(int *k)
{
    // compare sum of top and bottom of stack to find greatest value
    
}

void findLargestSum(int *x, int *k)
{
    struct node *temp = NULL;
    temp = (struct node*) malloc(sizeof(struct node*));
    temp = head;
    traverse(temp);
    while(head->value >= temp->value && k >= 0)
    {
        // pop from back of stack while head is greater than bottom of stack
        popStack(x, k);
    }

    int arr[*k+1];

    for(int i=0; i < *k; i++)
    {
        arr[i] = sumTop(*k) + sumBottom(i);
    }
    arr[*k] = sumBottom(*k);

    int largest = 0;

    for(int i =0; i<*k+1; i++)
    {
        if(arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    *x += largest;
}

int main()
{
    head = (struct node*) malloc(sizeof(struct node*));
    int k,m,n, x;
    x=0;

    scanf("%d %d", &n, &k);
    scanf("%d", &m);

    head->next = 0;
    head->value = m;

    for(int i=1; i<n; i++)
    {
        scanf("%d", &m);
        push(m);
    }

    popStack(&x, &k);
    printf("%d\n", x);
    
    // need to combine first in last out push function from assignment 3
    // maybe a traverse function for comparing
    // also will need a pop method specific for the stack and specific to a queue



}
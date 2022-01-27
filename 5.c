#include<stdio.h>
#include<stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *head = NULL;

void outputList()
{
//    struct node *current = NULL;
//    current = (struct node*) malloc(sizeof(struct node*));
//    current = head;
//
//    while(current->next != 0)
//    {
//        printf("%d", current->value);
//    }
}

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
    struct node *temp = NULL;
    temp = (struct node*) malloc(sizeof(struct node*));
    temp = head;
    // traverse(temp);
    int sum = 0;
    for(int i = 0; i < x; i++)
    {
        sum += temp->value;
        temp = temp->next;
        if(temp->next == NULL)
        {
            break;
        }
    }
    printf("returning %d\n", sum);
    return sum;
}

int sumBottom(int y)
{
    int sum = 0;
    struct node *temp = NULL;
    temp = (struct node*) malloc(sizeof(struct node*));
    temp = head;
    traverse(temp);
    for(int i = 0; i < y; i++)
    {
        sum += temp->value;
        temp = temp->next;
    }
    printf("returning %d\n", sum);
    return sum;
}

void checkSum(int *x, int *k, int n)
{
    // compare sum of top and bottom of stack to find greatest value
    int arr[*k+1];
    for(int i=0; i < *k; i++)
    {
        arr[i] = sumTop(*k-i) + sumBottom(i);
        printf("possible sum %d added to array\n", arr[i]);
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

void findLargestSum(int *x, int *k, int n)
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
    checkSum(x, k, n);
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
    findLargestSum(&x, &k, n);
    printf("%d\n", x);
    outputList();
}

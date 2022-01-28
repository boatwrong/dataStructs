#include<stdio.h>
#include<stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *head = NULL;

void outputList()
{
    struct node *current = NULL;
    current = (struct node*) malloc(sizeof(struct node*));
    current = head;
    while(current->next != 0)
    {
        current = current->next;
    }
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
    printf("popping %d\n", head->value);
    *x += head->value;
    head = head->next;
    *k-=1;
}

void traverse(struct node* pointer, int x)
{
    // moves a pointer through stack x number of times
    for(int i = 0; i < x; i++)
    {
        pointer = pointer->next;
    }
}

int sumTop(int x)
{
    struct node *temp = NULL;
    temp = (struct node*) malloc(sizeof(struct node*));
    temp = head;
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
    return sum;
}

int sumBottom(int y)
{
    int sum = 0;
    struct node *temp = NULL;
    temp = (struct node*) malloc(sizeof(struct node*));
    temp = head;
    traverse(temp, y);
    for(int i = 0; i < y; i++)
    {
        printf("addint %d to bottom sum\n", temp->value);
        sum += temp->value;
        temp = temp->next;
    }
    return sum;
}

void checkSum(int *x, int *k, int n)
{
    // compare sum of top and bottom of stack to find greatest value
    int arr[*k+1];
    for(int i=0; i < *k; i++)
    {
        arr[i] = sumTop(*k-i) + sumBottom(n - i);
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
    printf("largest sum chosen: %d\n", largest);
    *x += largest;
}

void findLargestSum(int *x, int *k, int n)
{
    struct node *temp = NULL;
    temp = (struct node*) malloc(sizeof(struct node*));
    temp = head;
    while(head->value >= temp->value && k >= 0)
    {
        // pop from back of stack while head is greater than bottom of stack
        popStack(x, k);
        n--;
        printf("%d elements left\n", n);
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
    n--;
    printf("%d elements left\n", n);
    findLargestSum(&x, &k, n);
    printf("%d\n", x);
    outputList();
}

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
    k--;
}

void popQueue(int *x, int *k)
{
    printf("made it here\n");
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
//    printf("For Top, adding: ");
    for(int i = 0; i < x; i++)
    {
        printf("%d ", temp->value);
        sum += temp->value;
        temp = temp->next;
        if(temp->next == NULL)
        {
            break;
        }
    }
    printf("= %d\n", sum);
    return sum;
}

int sumBottom(int y)
{
    int sum = 0;
    struct node *temp = NULL;
    temp = (struct node*) malloc(sizeof(struct node*));
    temp = head;
    for(int i = 0; i<y-1; i++)
    {
        temp = temp->next;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
        sum += temp->value;
    }
    return sum;
}

void checkSum(int *x, int *k, int n)
{
    int arr[*k+1];
    for(int i=0; i < *k; i++)
    {
        arr[i] = sumTop(*k-i) + sumBottom(n - i);
 //       printf("sum %d: %d + %d = %d\n", i+1, sumTop(*k-i), sumBottom(n - i), arr[i]);
    }
    arr[*k] = sumBottom(n - *k);
  //  printf("sum %d = %d\n", *k +1 , arr[*k]);
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
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("tail value = %d\n", temp->value);
    printf("head value = %d\n", head->value);
    while(head->value > temp->value)
    {
        popStack(x, k);
        n--;
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
    findLargestSum(&x, &k, n);
    printf("%d\n", x);
}

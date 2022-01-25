#include<stdio.h>

struct node {
    int value;
    struct node *next;
};

struct node *head = NULL;

void push(int x)
{
    printf("push\n");
}

void pop()
{
    printf("pop\n");
}

void sum()
{
    printf("print sum\n");
}

void displayTop()
{
    printf("display top element\n");
}

void query()
{
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
            displayTop();
            pop();
            break;
        case 4:
            scanf("%d", &n);
            for(int i=0; i<n; i++)
            {
                pop();
            }
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


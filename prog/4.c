#include<stdio.h>
#include<stdlib.h>

int numElements;

struct node {
    int value;
    struct node *next;
};

struct node *head = NULL;

// push {{{
void push(int x)
{
    // make new top node with given value
    struct node *current = (struct node*) malloc(sizeof(struct node));
    current->value = x;

    //assign new top node's next pointer to head
    current->next = head;

    // assign head to new top node
    head = current;

    numElements++;
}
// }}}

// pop {{{
int pop()
{
    // save head.value to return later
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
// }}}

// sum stack {{{
void sum()
{
    struct node *pointer = head;
    int sum = pointer->value;

    // run through stack summing elements
    //
    // increment pointer first because head value has been added to sum already
    while(pointer->next != 0)
    {
        pointer = pointer->next;
        sum += pointer->value;
    }

    printf("%d\n", sum);
}
// }}}

// switch menu {{{
void query()
{
    int sumPopped = 0;
    int x,y,n;
    scanf("%d", &y);

    switch(y) {
        // push one int
        case 1:
            scanf("%d", &x);
            push(x);
            break;

        // push int x n times
        case 2:
            scanf("%d %d", &n, &x);
            for(int i=0; i<n; i++)
            {
                push(x);
            }
            break;

        // pop one int
        case 3:
            printf("%d\n", pop());
            break;

        // pop n ints from the stack
        case 4:
            scanf("%d", &n);
            if(n <= numElements)
            {
                // sum popped elements
                for(int i=0; i<n; i++)
                {
                    sumPopped += pop();
                }
                printf("%d\n", sumPopped);
                break;
            }

            // if n > number of elements in stakck print the sum of stack
            sum();
            break;

        // just sum stack
        case 5:
            sum();
            break;
    }
}
// }}}

// main {{{
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
// }}}

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
}; 

struct node* newNode(int value) 
{
    struct node *new = (struct node*) malloc(sizeof(struct node*));
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct node* insert(struct node* tmp, int value)
{
    if(tmp == NULL)
    {
        return newNode(value);
    }

    if(value < tmp->value)
    {
        tmp->left = insert(tmp->left, value);
    }
    
    else if(value > tmp->value)
    {
        tmp->right = insert(tmp->left, value);
    }

    else
    {
        printf("value is equal to node value\n");
    }
    return tmp;
}

struct node* canGoLeft(struct node *node)
{
    printf("In can go left method\n");
    if(node == NULL) 
    {
        printf("Returning null\n");
        return NULL;
    }
    return node->left;
}

int main()
{
//    int numTests;
//    scanf("%d", &numTests);
//    for(int k=0; k < numTests; k++)
//    {
        int x, count;
        int numNodes;
        scanf("%d", &numNodes);

        scanf("%d", &x);
        struct node *head = NULL;
        head = newNode(x);
        printf("%d\n", head->value);

        for(int i=0; i<numNodes-1; i++)
        {
            scanf("%d", &x);
            insert(head, x);
        }

        count = 0;


        struct node *tmp = head;

        while(tmp != NULL)
        {
            printf("Head is not null\n");
            count++;
            tmp = canGoLeft(tmp);
        }


       // while(canGoLeft(head) != NULL)
       // {
       //     printf("Can go left\n");
       //     count++;
       // }
        
        printf("%d\n", count);
//    }
    return 0;
}

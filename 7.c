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
    struct node *node = (struct node*) malloc(sizeof(struct node*));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* insert(struct node* node, int value)
{
    if(node == NULL)
    {
        return newNode(value);
    }

    if(value < node->value)
    {
        node->left = insert(node->left, value);
    }
    else if(value > node->value)
    {
        node->right = insert(node->left, value);
    }
    else
    {
        printf("value is equal to node value\n");
    }
    return node;
}

struct node* canGoLeft(struct node *node)
{
    if(node == NULL || node->left == NULL)
    {
        return NULL;
    }
    return node->left;
}

int main()
{
    int numTests;
    scanf("%d", &numTests);
    for(int k=0; k < numTests; k++)
    {
        int x, count;
        int numNodes;
        scanf("%d", &numNodes);

        scanf("%d", &x);
        struct node *head = NULL;
        head = insert(head, x);

        for(int i=0; i<numNodes-1; i++)
        {
            scanf("%d", &x);
            insert(head, x);
        }

        count = 0;
        do {
            count++;
        } while(canGoLeft(head) != NULL);
        
        printf("%d\n", count);
    }
    return 0;
}

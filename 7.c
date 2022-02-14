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
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->value = value;
    new->left = NULL;
    new-> right = NULL;
    return new;
}

struct node* insert(struct node* leaf, int value)
{
    if(leaf == NULL)
    {
        return newNode(value);
    }
    else if(leaf->left == NULL)
    {
        leaf->left = newNode(value);
    }
    else if(leaf->right == NULL)
    {
        leaf->right = newNode(value);
    }
    return leaf;
}

int main(int argc, char *argv[])
{
    int numTests, numNodes;
    scanf("%d", &numTests);
    scanf("%d", &numNodes);

    return 0;
}


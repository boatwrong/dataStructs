#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    int depth;
    struct node *left;
    struct node *right;
}; 

// new node {{{
struct node* newNode(int value, int depth) 
{
    struct node *new = (struct node*) malloc(sizeof(struct node*));
    new->value = value;
    new->depth = depth;
    new->left = NULL;
    new->right = NULL;
    return new;
}
// }}}

// insert {{{
struct node* insert(struct node* tmp, int value, int depth)
{
    if(tmp == NULL)
    {
        return newNode(value, depth);
    }
    if(value < tmp->value)
    {
        depth++;
        tmp->left = insert(tmp->left, value, depth);
    }
    else if(value > tmp->value)
    {
        depth++;
        tmp->right = insert(tmp->left, value, depth);
    }
    else
    {
        printf("value is equal to node value\n");
    }
    return tmp;
}
// }}}

// traverse {{{
int* traverse(struct node* node, int *max)
{
    if(node == NULL)
    {
        return max;
    }
    
    if(node->depth > *max)
    {
        *max = node->depth;
    }
    traverse(node->left, max);
    traverse(node->right, max);
    return max;
}
// }}}

// main {{{
int main()
{
    int y;
    scanf("%d", &y);
    for(int k=0; k<y; k++)
    {
        int x, count;
        int numNodes;
        scanf("%d", &numNodes);

        scanf("%d", &x);
        struct node *head = NULL;
        head = newNode(x,1);
        head->depth = 1;

        for(int i=0; i<numNodes-1; i++)
        {
            scanf("%d", &x);
            insert(head, x, head->depth);
        }

        struct node *tmp = head;
        int max = 0;
        traverse(head, &max);
        printf("%d\n", max);

    }
    return 0;
}
// }}}

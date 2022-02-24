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
struct node* newNode(int x, int y) 
{
    struct node *new = (struct node*) malloc(sizeof(struct node*));
    new->value = x;
    new->depth = y;
    new->left = NULL;
    new->right = NULL;
    return new;
}
// }}}

// insert {{{
struct node* insert(struct node* tmp, int x, int depth)
{
    if(tmp == NULL)
    {
        return newNode(x, depth);
    }
    if(x < tmp->value)
    {
        depth++;
        tmp->left = insert(tmp->left, x, depth);
    }
    else if(x > tmp->value)
    {
        depth++;
        tmp->right = insert(tmp->left, x, depth);
    }

    return tmp;
}
// }}}

// traverse {{{
void traverse(struct node* node, int *max)
{
    if(node == NULL)
    {
        return;
    }
    printf("node: %d\tdepth: %d\n", node->value, node->depth);
    
    if(node->depth > *max)
    {
        *max = node->depth;
    }
    traverse(node->left, max);
    traverse(node->right, max);
    return;
}
// }}}

// print left{{{

void printLeft(struct node* node)
{
    printf("%d\n", node->value);
    if(node->left != NULL)
    {
        printLeft(node->left);
    }
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
        printLeft(tmp);
        int max = 0;
        //traverse(tmp, &max);
        printf("%d\n", max);

    }
    return 0;
}
// }}}

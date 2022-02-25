// boiler {{{
#include<stdio.h>
#include<stdlib.h>
#define ROOT 1

typedef struct node node;

struct node
{
    int value;
    int depth;
    struct node *left;
    struct node *right;
}; 
// }}}

// new node {{{
struct node* newNode(int x, int y) 
{
    struct node *tmp = (node *) malloc(sizeof(node));
    tmp->value = x;
    tmp->depth = y;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
// }}}

// insert {{{
struct node* insert(struct node* tmp, int x, int depth)
{
    if(tmp == NULL)
    {
        return newNode(x, depth);
    }

    else if(x < tmp->value)
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
    int numTests;
    scanf("%d", &numTests);
    for(int k=0; k<numTests; k++)
    {
        int nodeValue, count;
        int numNodes;
        scanf("%d", &numNodes);

        scanf("%d", &nodeValue);
        struct node *head = NULL;
        head = newNode(nodeValue, ROOT);
        head->depth = ROOT;

        for(int i=0; i<numNodes-1; i++)
        {
            scanf("%d", &nodeValue);
            insert(head, nodeValue, ROOT);
        }
        struct node *tmp = head;
        //printLeft(tmp);
        int max = 0;
        traverse(head, &max);
        printf("%d\n", max+1);

    }
    return 0;
}
// }}}

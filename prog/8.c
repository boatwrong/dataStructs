// boiler {{{
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
struct node* newNode(int nodeValue, int nodeDepth) 
{
    struct node *tmp = (node *) malloc(sizeof(node));
    tmp->value = nodeValue;
    tmp->depth = nodeDepth;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
// }}}

// insert {{{
struct node* insert(struct node* tmp, int value, int depth)
{
    if(tmp == NULL)
    {
        return newNode(value, depth);
    }

    else if(value < tmp->value)
    {
        depth++;
        tmp->left = insert(tmp->left, value, depth);
    }

    else if(value >= tmp->value)
    {
        depth++;
        tmp->right = insert(tmp->right, value, depth);
    }

    return tmp;
}
// }}}

// free {{{

void freeSubtree(node *N)
{
    if (N == NULL)
        return;
    freeSubtree(N->right);
    freeSubtree(N->left);
    N->right = NULL;
    N->left = NULL;
    free(N);
}

// }}}

// search {{{

bool search(struct node *head, int key)
{
    if(head == NULL)
    {
        return false;
    }

    if(head->value == key)
    {
        return true;
    }
    else
    {
        if(key > head->value)
        {
            return search(head->right, key);
        }
        else
        {
            return search(head->left, key);
        }
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
        int nodeValue, numNodes, numComparisons, key;

        scanf("%d", &numNodes);
        scanf("%d", &numComparisons);
        scanf("%d", &nodeValue);
        struct node *head = NULL;
        head = newNode(nodeValue, ROOT);
        head->depth = ROOT;
        for(int i=0; i<numNodes-1; i++)
        {
            scanf("%d", &nodeValue);
            insert(head, nodeValue, ROOT);
        }

        for(int i=0; i<numComparisons; i++)
        {
            scanf("%d", &key);
            if(search(head, key))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
            insert(head, key, ROOT);
        }
        
        free(head);
    }
    return 0;
}
// }}}

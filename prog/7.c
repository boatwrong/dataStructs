#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
}; 

// new node {{{
struct node* newNode(int value) 
{
    struct node *new = (struct node*) malloc(sizeof(struct node*));
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}
// }}}

// insert {{{
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
// }}}

// traverse {{{
int* traverse(struct node* node, int *idx)
{
    if(node == NULL)
    {
        idx++;
        return idx;
    }
    printf("here\n");

    traverse(node->left, idx);
    traverse(node->right, idx);
    idx++;
    return idx;
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
        head = newNode(x);

        for(int i=0; i<numNodes-1; i++)
        {
            scanf("%d", &x);
            insert(head, x);
        }

        struct node *tmp = head;
        int idx = 0;
        traverse(head, &idx);
        printf("%d\n", idx);

    }
    return 0;
}
// }}}

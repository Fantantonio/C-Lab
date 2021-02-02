#include <stdio.h>

typedef struct node
{
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
} * Node;

/*Pre: x in T*/
Node tree_minimum(Node x)
{
    while (x->left != NULL)
        x = x->left;
    return x;
}

/*Pre: x in T*/
Node tree_maximum(Node x)
{
    while (x->right != NULL)
        x = x->right;
    return x;
}
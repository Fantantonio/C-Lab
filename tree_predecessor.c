#include <stdio.h>

typedef struct node
{
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
} * Node;

Node tree_predecessor(Node x)
{
    Node y;
    if (x->left != NULL)
        return tree_maximum(x->left);
    else
    {
        y = x->p;
        while (y != NULL && x == y->left)
        {
            x = y;
            y = y->p;
        }
        return y;
    }
}
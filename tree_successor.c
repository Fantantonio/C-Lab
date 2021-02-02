#include <stdio.h>

typedef struct node
{
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
} * Node;

/*Pre: x in T*/
Node tree_successor(Node x)
{
    Node y;
    if (x->right != NULL)
        return tree_minimum(x->right);
    else
    {
        y = x->p;
        while (y != NULL && x == y->right)
        {
            x = y;
            y = y->p;
        }
        return y;
    }
}
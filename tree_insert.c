#include <stdio.h>

typedef struct node
{
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
} * Node;

typedef struct tree
{
    struct node *root;
} * Tree;

/*Post: inserisce il nodo z nell'albero T
Ipotesi: z->key=v, z->left=NULL, z->right=NULL*/
void tree_insert(Tree t, Node z)
{
    Node x, y;
    y = NULL;
    x = t->root;
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->p = y;
    if (y == NULL)
        t->root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
}
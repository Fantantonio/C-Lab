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

/*Pre: z in t*/
void tree_delete(Tree t, Node z)
{
    Node y;
    if (z->left == NULL)
        transplant(t, z, z->right);
    else if (z->right == NULL)
        transplant(t, z, z->left);
    else
    {
        y = tree_minimum(z->right);
        if (y->p != z)
        {
            transplant(t, y, y->right);
            y->right = z->right;
            z->right->p = y;
        }
        transplant(t, z, y);
        y->left = z->left;
        y->left->p = y;
    }
}
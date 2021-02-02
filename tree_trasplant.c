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

void transplant(Tree t, Node u, Node v)
{
    if (u->p == NULL)
        t->root = v;
    else
    {
        if (u == u->p->left)
            u->p->left = v;
        else
            u->p->right = v;
    }
    if (v != NULL)
        v->p = u->p;
}
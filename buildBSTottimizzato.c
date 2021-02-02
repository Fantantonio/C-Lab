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

// Solo se v[] è già ordinato

Node build_BST_aux(int v[], int inf, int sup, Node padre)
{
    int med;
    Node root;
    if (inf > sup)
        return NULL;
    med = (inf + sup) / 2;
    root = init_node(v[med]);
    root->left = build_BST_aux(v, inf, med - 1, root);
    root->right = build_BST_aux(v, med + 1, sup, root);
    root->p = padre;
    return root;
}

Tree build_BST(int v[], int dim)
{
    Tree t;
    t = init_tree();
    t->root = build_BST_aux(v, 0, dim - 1, NULL);
    return t;
}
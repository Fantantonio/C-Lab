#include <stdio.h>

typedef struct node
{
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
} * Node;

Node tree_search(Node x, int k)
{
    if (x == NULL || x->key == k)
        return x;
    else if (x->key > k)
        return tree_search(x->left, k);
    else
        return tree_search(x->right, k);
}

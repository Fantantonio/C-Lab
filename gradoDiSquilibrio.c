#include <stdio.h>
#include <stdlib.h>

/*
Grado di squilibrio di un albero
*/

typedef struct node
{
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
} * Node;

Node createNode(int val)
{
    Node new_node = (Node)malloc(sizeof(struct node));
    new_node->key = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int gradosquilaux(Node u, int *max)
{
    int buffer = 0;
    int sommaSx;
    int sommaDx;

    if (u == NULL)
    {
        return 0;
    }
    if (u->left == NULL && u->right == NULL)
    {
        return u->key;
    }
    else
    {
        sommaSx = gradosquilaux(u->left, max);
        sommaDx = gradosquilaux(u->right, max);
        buffer = abs(sommaSx - sommaDx);
        if (buffer > *max)
        {
            *max = buffer;
        }
    }
    return sommaSx + sommaDx;
}

int gradosquil(Node u)
{
    int max = 0;
    gradosquilaux(u, &max);
    return max;
}

void main()
{
    Node root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->right->left = createNode(6);

    int i = gradosquil(root);
    printf("Result: %d", i);
}
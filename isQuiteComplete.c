#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
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

int getRightHeight(Node u)
{
    int height = 0;
    if (u == NULL)
    {
        return 0;
    }
    while (u->right != NULL)
    {
        u = u->right;
        height += 1;
    }
    return height;
}

int getLeftHeight(Node u)
{
    int height = 0;
    if (u == NULL)
    {
        return 0;
    }
    while (u->left != NULL)
    {
        u = u->left;
        height += 1;
    }
    return height;
}

int isQuiteComplete(Node u, int h, int *flag)
{
    int rh = getRightHeight(u);
    int lh = getLeftHeight(u);
    int resultSx = 0;
    int resultDx = 0;

    //se il nodo non esiste
    if (u == NULL)
    {
        return 0;
    }
    // se il nodo non ha figlio left
    if (u->left == NULL)
    {
        if (h == lh && *flag == 0)
        {
            return 0;
        }
        if (h == lh - 1)
        {
            *flag = 1;
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        resultSx = isQuiteComplete(u->left, h + 1, flag);
    }
    // se il nodo non ha figlio right
    if (u->right == NULL)
    {
        if (h == rh)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        resultDx = isQuiteComplete(u->right, h + 1, flag);
    }
    if (resultDx == 0 && resultSx == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void main()
{
    int *flag = 0;
    Node root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);
    /*
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->right->left = createNode(6);
    */

    int i = isQuiteComplete(root, 0, flag);
    printf("Result: %d", i);
}
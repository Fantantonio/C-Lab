#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
} * Node;

Node createNode(int val)
{
    Node new_node = (Node)malloc(sizeof(Node));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node appendLeft(Node root, int val)
{
    root->left = createNode(val);
    return root->left;
}

Node appendRight(Node root, int val)
{
    root->right = createNode(val);
    return root->right;
}

void printTree(Node node, int liv)
{
    if (node == NULL)
        return;

    printf("(val: %d, liv: %d)\n", node->val, liv);
    liv += 1;
    printTree(node->left, liv);
    printTree(node->right, liv);
}

/*
_______________________
|                     |
|       1       liv: 0|
|------/ \-------------
|     2   3     liv: 1|
|----/ \---------------
|   4   5       liv: 2|
|------/---------------
|     6         liv: 3|
|_____________________|
*/
int main()
{
    Node root = createNode(1);

    root->left = appendLeft(root, 2);
    root->right = appendRight(root, 3);
    root->left->left = appendLeft(root->left, 4);
    root->left->right = appendRight(root->left, 5);
    root->left->right->left = appendLeft(root->left->right, 6);

    printTree(root, 0);
    return 1;
}
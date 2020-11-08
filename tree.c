#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
} * node_t;

node_t createNode(int val)
{
    node_t new_node = (node_t)malloc(sizeof(node_t));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node_t appendLeft(node_t root, int val)
{
    root->left = createNode(val);
    return root->left;
}

node_t appendRight(node_t root, int val)
{
    root->right = createNode(val);
    return root->right;
}

void printTree(node_t node, int liv)
{
    if (node == NULL)
        return;

    printf("(val: %d, liv: %d)\n", node->val, liv);
    liv += 1;
    printTree(node->left, liv);
    printTree(node->right, liv);
}

int main()
{
    node_t root = createNode(1);

    root->left = appendLeft(root, 2);
    root->right = appendRight(root, 3);
    root->left->left = appendLeft(root->left, 4);
    root->left->right = appendRight(root->left, 5);
    root->left->right->left = appendLeft(root->left->right, 6);

    printTree(root, 0);
    return 1;
}
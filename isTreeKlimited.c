#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
} * Node;

/*
     ()
    /  \
  (x)  ()
  / \
/k\ /n-k-1\

Se considero un albero di n nodi e un suo nodo x e il suo sottoalbero
sinistro di k nodi, allora se al numero totale di nodi n tolgo x e il
numero di nodi del sottoalbero sinistro, cioè k, ottengo i nodi del
sottoalbero destro x.
Allora, in generale avrò che:
    T(n) <= T(k) + T(n - k - 1) + d
con d = operazione di visita costante (d > 0).
*/

int k_limitato_aux(Node u, int k, int *sum)
{
    int rissx, risdx, sumsx, sumdx;
    if (u == NULL)
    {
        *sum = 0;
        return 1;
    }
    rissx = k_limitato_aux(u->left, k, &sumsx);
    risdx = k_limitato_aux(u->right, k, &sumdx);
    if (u->left == NULL && u->right)
        *sum = sumdx + u->key;
    else if (u->right == NULL && u->left)
        *sum = sumsx + u->key;
    else
    {
        int maxsx, maxdx;
        maxsx = sumsx + u->key;
        maxdx = sumdx + u->key;
        if (maxsx <= maxdx)
            *sum = maxdx;
        else
            *sum = maxsx;
    }
    return rissx && risdx && (sum <= k);
}

int k_limitato(Node u, int k)
{
    int sum;
    return k_limitato_aux(u, k, &sum);
}
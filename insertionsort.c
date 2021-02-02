/*
Caso migliore Theta(n)
Caso medio Theta(n^2)
Caso peggiore Theta(n^2)
*/

int DIM = 10;

void insertionsort(int a[])
{
    int i, j, key;
    for (j = 1; j < DIM; j++)
    {
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > key)
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}
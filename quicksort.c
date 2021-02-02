/*
Caso migliore Thete(nlogn)
Caso medio Thete(nlogn)
Caso peggiore Thete(n^2)
*/

int partition(int a[], int p, int r)
{
    int x, i, j;
    x = a[r];
    i = p - 1;
    for (j = p; j <= r - 1; j++)
    {
        if (a[j] <= x)
        {
            i++;
            scambia(a, i, j);
        }
    }
    scambia(a, i + 1, r);
    return i + 1;
}

void quicksort(int a[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}
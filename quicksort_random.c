int randomize_partition(int a[], int p, int r)
{
    int i;
    i = rand() % (r - p + 1) + p;
    scambia(a, i, r);
    return partition(a, p, r);
}

void randomize_quicksort(int a[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = randomize_partition(a, p, r);
        randomize_quicksort(a, p, q - 1);
        randomize_quicksort(a, q + 1, r);
    }
}
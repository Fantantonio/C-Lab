#include <stdio.h>

/*
Theta(nlogn) per n > 1
O(1) per n <= 1
*/

void merge(int a[], int p, int q, int r)
{
    int i;
    int j;
    int k;
    int n1 = q - p + 1;
    int n2 = r - q;
    int left[n1];
    int right[n2];
    for (i = 0; i < n1; i++)
        left[i] = a[p + i];
    for (i = 0; i < n2; i++)
        right[i] = a[q + i + 1];
    i = 0;
    j = 0;
    for (k = p; k <= r; k++)
    {
        if (i < n1 && j < n2)
        {
            if (left[i] <= right[j])
            {
                a[k] = left[i];
                i++;
            }
            else
            {
                a[k] = right[j];
                j++;
            }
        }
        else
        {
            if (i == n1)
            {
                a[k] = right[j];
                j++;
            }
            else
            {
                a[k] = left[i];
                i++;
            }
        }
    }
}

void mergesort(int a[], int inf, int sup)
{
    int met;
    if (inf < sup)
    {
        met = (sup + inf) / 2;
        mergesort(a, inf, met);
        mergesort(a, met + 1, sup);
        merge(a, inf, met, sup);
    }
}

void main()
{
    int a[9] = {2, 5, 1, 30, 20, 10, 3, 4, 5};

    printf("Inserito: \n");
    for (int i = 0; i < 9; i += 1)
    {
        printf("%d ", a[i]);
    }

    mergesort(a, 0, 9);

    printf("\n\nOrdinato: \n");
    for (int i = 0; i < 9; i += 1)
    {
        printf("%d ", a[i]);
    }
}
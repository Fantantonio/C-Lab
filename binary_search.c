/*
Input:
vettore = vettore ordinato in ordine crescente
dim = dimensione dell'array
k = elemento da cercare

Output:
posizione di k nell'array o -1
*/

int ricercaBinaria(int vettore[], int dim, int k)
{
    int first = 0,
        last = dim - 1,
        mid;

    while (first <= last)
    {
        mid = (first + last) / 2;
        if (vettore[mid] == k)
            return mid;
        else if (vettore[mid] < k)
            first = mid + 1;
        else
            last = mid - 1;
    }
    return -1;
}
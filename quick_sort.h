#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>
#include <random>

using namespace std;

int partition(vector<int> &Arr, int p, int r)
{
    int x = Arr[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (Arr[j] <= x)
        {
            i++;
            swap(Arr[i], Arr[j]);
        }
    }
    swap(Arr[i + 1], Arr[r]);
    return i + 1;
}

int random_partition(vector<int> &Arr, int p, int r)
{
    int i = p + rand() % (r - p + 1); // Random pivot
    swap(Arr[r], Arr[i]);
    return partition(Arr, p, r);
}

void quick_sort(vector<int> &Arr, int p, int r)
{
    if (p < r)
    {
        int q = random_partition(Arr, p, r);
        quick_sort(Arr, p, q - 1);
        quick_sort(Arr, q + 1, r);
    }
}

#endif // QUICK_SORT_H
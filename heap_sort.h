#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>

using namespace std;

void heapify(vector<unsigned int> &Arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && Arr[l] > Arr[largest])
        largest = l;

    if (r < n && Arr[r] > Arr[largest])
        largest = r;

    if (largest != i) {
        swap(Arr[i], Arr[largest]);
        heapify(Arr, n, largest);
    }
}

void build_heap(vector<unsigned int> &Arr)
{
    for(int i = (Arr.size() / 2) - 1; i >= 0; i--)
    {
        heapify(Arr, Arr.size(), i);
    }
}

void heap_sort(vector<unsigned int> &Arr)
{
    build_heap(Arr);
    for(int i = Arr.size() - 1; i >= 0; i--)
    {
        swap(Arr[0], Arr[i]);
        heapify(Arr, i, 0);
    }
}

#endif // HEAP_SORT_H
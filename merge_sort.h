#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>
#include <limits>

using namespace std;

void merge(vector<int> &Arr, int p, int q, int r)
{
    int n1 = q - p + 1; //size of left subarray
    int n2 = r - q; //size of right subarray
    vector<int> L;
    vector<int> R;
    for(int i = 0; i < n1; i++)
    {
        L.push_back(Arr[p + i]);
    }
    for(int j = 0; j < n2; j++)
    {
        R.push_back(Arr[q + j + 1]);
    }
    L.push_back(numeric_limits<int>::max());
    R.push_back(numeric_limits<int>::max());

    // merge the subarrays
    int i = 0;
    int j = 0;
    for(int k = p; k<=r; k++)
    {
        if(L[i] <= R[j])
        {
            Arr[k] = L[i];
            i++;
        }
        else
        {
            Arr[k] = R[j];
            j++;
        }
    }
}

void merge_sort(vector<int> &Arr, int p, int r)
{
    if(p < r)
    {
        int q = (p + r) / 2;
        merge_sort(Arr, p, q);
        merge_sort(Arr, q + 1, r);
        merge(Arr, p, q, r);
    }
}

#endif // MERGE_SORT_H
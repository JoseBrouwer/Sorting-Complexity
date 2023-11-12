#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H
#include <vector>

using namespace std;

void counting_sort(vector<int> &Arr, int k)
{
    vector<int> B(Arr.size());
    vector<int> C(k + 1, 0);

    for (int j = 0; j < Arr.size(); j++)
    {
        C[Arr[j]]++;
    }

    for (int i = 1; i <= k; i++)
    {
        C[i] += C[i - 1];
    }

    for (int j = Arr.size() - 1; j >= 0; j--)
    {
        B[C[Arr[j]] - 1] = Arr[j];
        C[Arr[j]]--;
    }

    //after sorting set Arr to B
    for (int i = 0; i < Arr.size(); i++)
    {
        Arr[i] = B[i];
    }
}

#endif // COUNTING_SORT_H
#ifndef RADIX_SORT_H
#define RADIX_SORT_H
#include <vector>
#include <cmath>
using namespace std;


void radix_counting_sort(vector<int> &Arr, int exp)
{
    const int base = 10;
    vector<int> B(Arr.size());
    vector<int> C(base, 0);

    for (int i = 0; i < Arr.size(); i++)
        C[(Arr[i] / exp) % base]++;

    for (int i = 1; i < base; i++)
        C[i] += C[i - 1];

    for (int i = Arr.size() - 1; i >= 0; i--)
    {
        B[C[(Arr[i] / exp) % base] - 1] = Arr[i];
        C[(Arr[i] / exp) % base]--;
    }

    for (int i = 0; i < Arr.size(); i++)
        Arr[i] = B[i];
}

void radix_sort(vector<int> &Arr)
{
    // Find the maximum number to know number of digits
    int max = Arr[0];
    for (int i = 1; i < Arr.size(); i++)
    {
        if (Arr[i] > max)
            max = Arr[i];
    }
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    for (int exp = 1; max / exp > 0; exp *= 10)
        radix_counting_sort(Arr, exp);
}

#endif // RADIX_SORT_H
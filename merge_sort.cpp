#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <chrono>

using namespace std;

void merge(vector<unsigned int> &Arr, int p, int q, int r)
{
    int n1 = q - p + 1; //size of left subarray
    int n2 = r - q; //size of right subarray
    vector<unsigned int> L;
    vector<unsigned int> R;
    for(int i = 0; i < n1; i++)
    {
        L.push_back(Arr[p + i]);
    }
    for(int j = 0; j < n2; j++)
    {
        R.push_back(Arr[q + j + 1]);
    }
    L.push_back(numeric_limits<unsigned int>::max());
    R.push_back(numeric_limits<unsigned int>::max());
}

void merge_sort(vector<unsigned int> &Arr, int p, int r)
{
    if(p < r)
    {
        int q = (p + r) / 2;
        merge_sort(Arr, p, q);
        merge_sort(Arr, q + 1, r);
        merge(Arr, p, q, r);
    }
}
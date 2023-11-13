#include <vector>
#include <list>
#include <cmath>
#include "insertion_sort.h"

using namespace std;

void bucket_sort(vector<float> &Arr)
{
    int n = Arr.size();
    vector<list<float>> B(n);
    // Create n empty lists
    for(int i = 0; i < n; i++)
    {
        B[i] = list<float>();
    }
    // Insert elements into their respective buckets
    for(int i = 0; i < n; i++)
    {
        int index = floor(n * Arr[i]);
        B[index].push_front(Arr[i]);
        //cout << "Inserted " << Arr[i] << " into bucket " << index << endl;
    }

    for(int i = 0; i < n; i++)
    {
        list_insertion_sort(B[i]);
    }
    // Concatenate the sorted buckets
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto j = B[i].begin(); j != B[i].end(); ++j)
        {
            Arr[k] = *j;
            k++;
        }
    }
}
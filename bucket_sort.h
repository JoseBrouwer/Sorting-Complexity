#include <vector>
#include <list>
#include <cmath>
#include "insertion_sort.h"

using namespace std;

void bucket_sort(vector<float> &Arr)
{
    cout << "Inside Bucket Sort" << endl;
    int n = Arr.size();
    vector<list<float>> B(n);
    // Create n empty lists
    for(int i = 0; i < n; i++)
    {
        B[i] = list<float>();
    }
    cout << "Created " << n << " empty lists" << endl;
    // Insert elements into their respective buckets
    for(int i = 0; i < n; i++)
    {
        int index = floor(n * Arr[i]);
        B[index].push_front(Arr[i]);
        //cout << "Inserted " << Arr[i] << " into bucket " << index << endl;
    }
    cout << "Inserted elements into their respective buckets" << endl;
    // Print the bucket contents
    // for(int i = 0; i < n; i++)
    // {
    //     cout << "Bucket " << i << ": ";
    //     for (auto j = B[i].begin(); j != B[i].end(); ++j)
    //     {
    //         cout << *j << " ";
    //     }
    //     cout << endl;
    // }
    // Sort the elements of each bucket
    for(int i = 0; i < n; i++)
    {
        list_insertion_sort(B[i]);
        // cout << "Sorted bucket " << i << ": ";
        // for(auto j = B[i].begin(); j != B[i].end(); ++j)
        // {
        //     cout << *j << " ";
        // }
        // cout << endl;
    }
    cout << "Sorted the elements of each bucket" << endl;
    // Concatenate the sorted buckets
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto j = B[i].begin(); j != B[i].end(); ++j)
        {
            Arr[k] = *j;
            k++;
        }
        // cout << "clearing bucket " << i << endl;
        // B[i].clear(); // clear the list
        // cout << "bucket " << i << " cleared" << endl;
        // // B[i] = nullptr;
    }
}
// insertion_sort.h

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <vector>
#include <list>

using namespace std;

// Function prototype for insertion_sort
void insertion_sort(vector<int> &Arr)
{
    int key;
    for (int j = 1; j < Arr.size(); j++)
    {
        key = Arr[j];
        int i = j - 1;
        while (i >= 0 && Arr[i] > key)
        {
            Arr[i + 1] = Arr[i];
            i--;
        }
        Arr[i + 1] = key;
    }
}

//for use in bucket_sort
void list_insertion_sort(list<float> &Arr)
{
    // loop through nodes in list
    for (auto j = next(Arr.begin()); j != Arr.end(); ++j)
    {
        // retrieve value of node and previous node
        float item = *j;
        auto i = prev(j);

        // move nodes to the right until the correct position is found
        while (i != prev(Arr.begin()) && *i > item)
        {
            auto prev_i = prev(i);
            *j = *i; //set value of current node to value of previous node
            j = i; //set current node to previous node
            i = prev_i; //set previous node to previous of previous node
        }
        *j = item; //set value of current node to value of previous node
    }
}

#endif // INSERTION_SORT_H

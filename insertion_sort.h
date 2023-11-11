// insertion_sort.h

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <vector>

// Function prototype for insertion_sort
void insertion_sort(std::vector<unsigned int> &Arr)
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

#endif // INSERTION_SORT_H

#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> Arr)
{
    int key;
    for(int j = 1; j < Arr.size(); j++)
    {
        key = Arr[j];
        int i = j - 1;
        while(i >= 0 && Arr[i] > key)
        {
            Arr[i + 1] = Arr[i];
            i--;
        }
        Arr[i + 1] = key;
    }
}

int main()
{
    vector<int> Arr = {5, 2, 4, 6, 1, 3};
    insertion_sort(Arr);
    return 0;
}

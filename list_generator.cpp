#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <string>

using namespace std;

vector<unsigned int> generate_list(int size)
{
    vector<unsigned int> Arr;
    random_device rd;                // Create a random device
    default_random_engine gen(rd()); // Create a default random engine
    uniform_int_distribution<unsigned int> dis(0, numeric_limits<unsigned int>::max());

    for (int i = 0; i < size; i++)
    {
        Arr.push_back(dis(gen));
    }
    return Arr;
}

// write list to file
// different file for each list size 
void write_list(vector<unsigned int> Arr, int list_num) 
{
    ofstream file;
    string file_name = "list" + to_string(list_num) + ".txt";
    file.open(file_name, ios::app); // append to file
    file << "A: ["; // A: [ Arr[0], Arr[1], Arr[2], ...
    for(int i = 0; i < Arr.size(); i++)
    {
        if(i == Arr.size() - 1)
            file << Arr[i] << "]" << endl;
        else
            file << Arr[i] << ",";
    }
    file.close();
}

int main()
{
    int n10 = 100; //100 lists of size 10
    int n50 = 100; //100 lists of size 50
    int n100 = 100; //100 lists of size 100
    int n500 = 50; //50 lists of size 500
    int n1000 = 10; //50 lists of size 1000
    int n5000 = 10; //10 lists of size 5000
    //everything above 5k will have one list

    // Generate and write lists using the updated counter
    for (int i = 0; i < n10; i++)
    {
        write_list(generate_list(10), 10);
    }
    for (int i = 0; i < n50; i++)
    {
        write_list(generate_list(50), 50);
    }
    for (int i = 0; i < n100; i++)
    {
        write_list(generate_list(100), 100);
    }
    for (int i = 0; i < n500; i++)
    {
        write_list(generate_list(500), 500);
    }
    for (int i = 0; i < n1000; i++)
    {
        write_list(generate_list(1000), 1000);
    }
    for (int i = 0; i < n5000; i++)
    {
        write_list(generate_list(5000), 5000);
    }
    //one list for all of the larger sets
    write_list(generate_list(10000), 10000); 
    write_list(generate_list(50000), 50000);
    write_list(generate_list(100000), 100000);
    write_list(generate_list(500000), 500000);
    write_list(generate_list(1000000), 1000000);
}

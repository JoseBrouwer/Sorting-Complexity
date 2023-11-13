#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

vector<int> generate_list(int size)
{
    vector<int> Arr;
    random_device rd;                // Create a random device
    // static std::mt19937 gen(rd());
    // std::uniform_int_distribution<int> dis(0, numeric_limits<int>::max());
    default_random_engine gen(rd()); // Create a default random engine
    uniform_int_distribution<int> dis(0, 65536); // U[0, 2^16)

    for (int i = 0; i < size; i++)
    {
        Arr.push_back(dis(gen));
    }
    return Arr;
}

vector<float> generate_floats(int size)
{
    vector<float> Arr;

    for (int i = 0; i < size; i++)
    {
        float number = static_cast<float>(rand());
        number = number / static_cast<float>(RAND_MAX);
        number = roundf(number * 10000) / 10000;
        if(number == 1.0) // 1.0 is not in the range
            number = 0.9000;
        Arr.push_back(number);
    }
    return Arr;
}

// write list to file
// different file for each list size 
void write_list(vector<int> Arr, int list_num) 
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

void write_floats(vector<float> Arr, int list_num)
{
    ofstream file;
    string file_name = "float_list" + to_string(list_num) + ".txt";
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

void create_list()
{
    int n10 = 100;  // 100 lists of size 10
    int n50 = 100;  // 100 lists of size 50
    int n100 = 100; // 100 lists of size 100
    int n500 = 50;  // 50 lists of size 500
    int n1000 = 10; // 50 lists of size 1000
    int n5000 = 10; // 10 lists of size 5000
    // everything above 5k will have one list

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
    // one list for all of the larger sets
    write_list(generate_list(10000), 10000);
    write_list(generate_list(50000), 50000);
    write_list(generate_list(100000), 100000);
    write_list(generate_list(500000), 500000);
    write_list(generate_list(1000000), 1000000);
}

void create_floats()
{
    int n10 = 100;  // 100 lists of size 10
    int n50 = 100;  // 100 lists of size 50
    int n100 = 100; // 100 lists of size 100
    int n500 = 50;  // 50 lists of size 500
    int n1000 = 10; // 50 lists of size 1000
    int n5000 = 10; // 10 lists of size 5000
    // everything above 5k will have one list

    // Generate and write lists using the updated counter
    for (int i = 0; i < n10; i++)
    {
        write_floats(generate_floats(10), 10);
    }
    for (int i = 0; i < n50; i++)
    {
        write_floats(generate_floats(50), 50);
    }
    for (int i = 0; i < n100; i++)
    {
        write_floats(generate_floats(100), 100);
    }
    for (int i = 0; i < n500; i++)
    {
        write_floats(generate_floats(500), 500);
    }
    for (int i = 0; i < n1000; i++)
    {
        write_floats(generate_floats(1000), 1000);
    }
    for (int i = 0; i < n5000; i++)
    {
        write_floats(generate_floats(5000), 5000);
    }
    // one list for all of the larger sets
    write_floats(generate_floats(10000), 10000);
    write_floats(generate_floats(50000), 50000);
    write_floats(generate_floats(100000), 100000);
    write_floats(generate_floats(500000), 500000);
    write_floats(generate_floats(1000000), 1000000);
}

int main()
{
    create_list();
    create_floats();
}

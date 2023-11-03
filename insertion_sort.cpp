#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <chrono>

using namespace std;

void insertion_sort(vector<int> &Arr)
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

    // Specify the input and output file names
    string inputFileName;
    string outputFileName;
    cout << "Enter the file name to sort: ";
    cin >> inputFileName;
    cout << endl;

    // Open the input file
    ifstream inputFile(inputFileName);

    if (!inputFile)
    {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Read the array from the input file
    vector<int> Arr;
    string num;

    // SAMPLE: A: [1,2,3,4,5,6,7,8,9,10]
    // Skip characters until the start of the array
    while(inputFile)
    {
        cout << "in while loop" << endl;

        // Read the array elements one string at a time
        cout << "before reading num" << endl;
        while (inputFile >> num)
        {
            cout << "num is: " << num << endl;
            string temp = ""; // to store the number
            for (int i = 0; i < num.length(); i++)
            {
                // If the character is a digit, add it to temp
                if (isdigit(num[i]))
                {
                    temp += num[i];
                }
                // If the character is a comma, convert temp to int and add it to Arr
                else if (num[i] == ',')
                {
                    Arr.push_back(stoi(temp));
                    temp = "";
                }
                else if (num[i] == ']')
                {
                    Arr.push_back(stoi(temp));
                    break;
                }
            }

            auto start = chrono::high_resolution_clock::now(); // Start the timer
            insertion_sort(Arr); // Sort the array using insertion sort
            auto stop = chrono::high_resolution_clock::now();
            auto micro = chrono::duration_cast<chrono::microseconds>(stop - start);
            auto milli = chrono::duration_cast<chrono::milliseconds>(stop - start);
            auto seconds = chrono::duration_cast<chrono::seconds>(stop - start);

            if(Arr.size() > 0)
            {
                cout << "Array Sorted!" << endl;
                cout << "Sorted A: [";
                for (int i = 0; i < Arr.size(); i++)
                {
                    if(i == Arr.size() - 1)
                        cout << Arr[i] << "]" << endl;
                    else
                        cout << Arr[i] << ","; // Add a comma after each element (except the last one
                }
                cout << "\nSorting Time: \n" << micro.count() << " microseconds \n";
                cout << milli.count() << " milliseconds \n";
                cout << seconds.count() << " seconds";
                cout << "\n\n";
                Arr.clear(); // Clear the array for the next iteration
            }
        }
        
    }
    // Close the input file
    inputFile.close();
    return 0;
}

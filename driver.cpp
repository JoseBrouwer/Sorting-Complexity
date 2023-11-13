#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <limits>
#include "insertion_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "quick_sort.h"
#include "counting_sort.h"
#include "radix_sort.h"
#include "bucket_sort.h"

using namespace std;

int get_max(vector<int> &Arr)
{
    int max = Arr[0];
    for(int i = 1; i < Arr.size(); i++)
    {
        if(Arr[i] > max)
            max = Arr[i];
    }
    return max;
}

int main()
{
    while (true)
    {
        // Specify the input and output file names
        string inputFileName;
        string outputFileName;
        string sortingName;
        bool isFloat = false;

        cout << "Enter the file name to sort (type 'quit' to exit / type 'help' for guidance): ";
        cin >> inputFileName;
        cout << endl;

        if (inputFileName == "quit")
        {
            break; // Exit the loop if the user enters 'quit'
        }
        else if (inputFileName == "help")
        {
            cout << "The input file should contain a list of integers, one per line." << endl;
            cout << "The output file will contain the time taken to sort the input file." << endl;
            cout << "The output file will be appended to if it already exists." << endl;
            cout << "The algorithm should be typed as follows (just the name): " << endl;
            cout << "1 - insertion_sort" << endl;
            cout << "2 - merge_ssort" << endl;
            cout << "3 - quick_sort" << endl;
            cout << "4 - heap_sort" << endl;
            cout << "5 - radix_sort" << endl;
            cout << "6 - counting_sort" << endl;
            cout << "7 - bucket_sort" << endl;
            cout << endl;
            continue; // Skip the rest of the loop and prompt for a new file
        }

        // Check if the input file is opened successfully
        ifstream inputFile(inputFileName);
        if (!inputFile)
        {
            cerr << "Error: Unable to open input file." << endl;
            continue; // Skip the rest of the loop and prompt for a new file
        }
        if (inputFileName.find("float") != string::npos)
        {
            isFloat = true;
        }

        cout << "Enter the sorting algorithm to use (type 'help' for guidance): ";
        cin >> sortingName;
        cout << endl;
        if (sortingName == "quit")
        {
            break; // Exit the loop if the user enters 'quit'
        }
        else if(sortingName == "help")
        {
            cout << "The algorithm should be typed as follows (just the name): " << endl;
            cout << "1 - insertion_sort" << endl;
            cout << "2 - merge_ssort" << endl;
            cout << "3 - quick_sort" << endl;
            cout << "4 - heap_sort" << endl;
            cout << "5 - radix_sort" << endl;
            cout << "6 - counting_sort" << endl;
            cout << "7 - bucket_sort" << endl;
            cout << endl;
            continue; // Skip the rest of the loop and prompt for a new file
        }
        else if(sortingName != "insertion_sort" && sortingName != "merge_sort" 
        && sortingName != "quick_sort" && sortingName != "heap_sort" && sortingName != "radix_sort"
        && sortingName != "counting_sort" && sortingName != "bucket_sort")
        {
            cout << "Invalid algorithm name. Start over." << endl;
            continue; // Skip the rest of the loop and prompt for a new file
        }

        // Determine the output file name based on the selected sorting algorithm
        outputFileName = sortingName + "_times.txt";
        ofstream outputFile(outputFileName, ios::app);
        if (!outputFile)
        {
            cerr << "Error: Unable to open output file." << endl;
            return 1;
        }

        vector<int> Arr;
        vector<float> Arr2;
        string num;
        int array_num = 0; // for output file array listing

        // SAMPLE: A: [1,2,3,4,5,6,7,8,9,10]
        // Skip characters until the start of the array
        while (inputFile)
        {
            //cout << "in while loop" << endl;
            outputFile << "-------LIST: " << inputFileName << " SORTED-------" << endl;
            // Read the array elements one string at a time
            cout << "before reading num" << endl;
            while (inputFile >> num)
            {
                // //cout << "num is: " << num << endl;
                // if(num.length() == 2)
                //     break;
                //cout << "size of num: " << num.length() << endl;
                string temp = ""; // to store the number
                // if the file opened is not a float file use Arr
                if(isFloat == false)
                {
                    cout << "Parsing Integers" << endl;
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
                }
                // if the file opened is a float file use Arr2
                else
                {
                    cout << "Parsing Floats" << endl;
                    for (int i = 0; i < num.length(); i++)
                    {
                        // If the character is a digit, add it to temp
                        if (isdigit(num[i]) || num[i] == '.')
                        {
                            temp += num[i];
                        }
                        // If the character is a comma, convert temp to int and add it to Arr
                        else if (num[i] == ',')
                        {
                            Arr2.push_back(stof(temp));
                            temp = "";
                        }
                        else if (num[i] == ']')
                        {
                            Arr2.push_back(stof(temp));
                            break;
                        }
                    }
                    // cout << "size of Arr2: " << Arr2.size() << endl;
                    // cout << "contents of Arr2: ";
                    // for(int i = 0; i < Arr2.size(); i++)
                    // {
                    //     cout << Arr2[i] << ",";
                    // }
                    // cout << endl;
                }
                

                // remove array printing and move timing into its own function
                // Also move the outputFile writing to the function
                if (Arr.size() > 0 || Arr2.size() > 0)
                {
                    //for use in instances where work must be done before the timer starts
                    //For example, counting sort needs to find the max value in the array
                    std::chrono::time_point<std::chrono::high_resolution_clock> temp;
                    if (sortingName == "insertion_sort")
                    {
                        auto start = chrono::high_resolution_clock::now(); // Start the timer
                        insertion_sort(Arr); // Sort the array using insertion sort
                        temp = start;
                    }
                    else if(sortingName == "merge_sort")
                    {
                        auto start = chrono::high_resolution_clock::now(); // Start the timer
                        merge_sort(Arr, 0, Arr.size()-1); //merge_sort(Arr, p, r);  // Sort the array using merge sort
                        temp = start;
                    }
                    else if(sortingName == "heap_sort")
                    {
                        auto start = chrono::high_resolution_clock::now(); // Start the timer
                        heap_sort(Arr); // Sort the array using heap sort
                        temp = start;
                    }
                    else if(sortingName == "quick_sort")
                    {
                        auto start = chrono::high_resolution_clock::now(); // Start the timer
                        quick_sort(Arr, 0, Arr.size()-1); // Sort the array using quick sort
                        temp = start;
                    }
                    else if(sortingName == "counting_sort")
                    {
                        int max = get_max(Arr);
                        auto start = chrono::high_resolution_clock::now(); // Start the timer
                        counting_sort(Arr, max); // Sort the array using counting sort
                        temp = start;
                    }
                    else if(sortingName == "radix_sort")
                    {
                        auto start = chrono::high_resolution_clock::now(); // Start the timer
                        radix_sort(Arr); // Sort the array using radix sort
                        temp = start;
                    }
                    //chose a float array text file
                    else if(sortingName == "bucket_sort" && isFloat == true)
                    {
                        auto start = chrono::high_resolution_clock::now(); // Start the timer
                        bucket_sort(Arr2); // Sort the array using bucket sort
                        temp = start;
                    }
                    //did not choose a float array text file
                    else if(sortingName == "bucket_sort" && isFloat == false)
                    {
                        cout << "Bucket sort requires a float array. Start over." << endl;
                        break;
                    }
                    auto stop = chrono::high_resolution_clock::now();
                    auto micro = chrono::duration_cast<chrono::microseconds>(stop - temp);
                    auto milli = chrono::duration_cast<chrono::milliseconds>(stop - temp);
                    auto seconds = chrono::duration_cast<chrono::seconds>(stop - temp);

                    cout << "Array Sorted!" << endl;

                    // if(isFloat == false)
                    // {
                    //     cout << "Sorted A: [";
                    //     for (int i = 0; i < Arr.size(); i++)
                    //     {
                    //         if (i == Arr.size() - 1)
                    //             cout << Arr[i] << "]" << endl;
                    //         else
                    //             cout << Arr[i] << ","; // Add a comma after each element (except the last one
                    //     }
                    // }
                    // else
                    // {
                    //     cout << "Sorted A: [";
                    //     for (int i = 0; i < Arr2.size(); i++)
                    //     {
                    //         if (i == Arr2.size() - 1)
                    //             cout << Arr2[i] << "]" << endl;
                    //         else
                    //             cout << Arr2[i] << ","; // Add a comma after each element (except the last one
                    //     }
                    // }
                    cout << "\nSorting Time: \n"
                        << micro.count() << " microseconds \n";
                    cout << milli.count() << " milliseconds \n";
                    cout << seconds.count() << " seconds";
                    cout << "\n\n";
                    if(isFloat == false)
                        Arr.clear(); // Clear the array for the next iteration
                    else
                    {
                        cout << "Clearing Arr2" << endl;
                        Arr2.clear();
                        cout << "size of Arr2 after clearing: " << Arr2.size() << endl;
                    }

                    // Write the time to sort to the output file
                    /*
                    Array 0:
                    Sorting Time:
                        0.000001 microseconds
                        0.000001 milliseconds
                        0.000001 seconds
                    */

                    outputFile << "Array " << array_num << ": " << endl;
                    outputFile << "Sorting Time: \n\t" << micro.count() << " microseconds \n";
                    outputFile << "\t" << milli.count() << " milliseconds \n";
                    outputFile << "\t" << seconds.count() << " seconds\n"
                               << endl;

                    array_num++; // Increment the array number for the output file
                }
            }
        }
        // Close the input & output file
        inputFile.close();
        outputFile.close();
    }

    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <chrono>

using namespace std;

void insertion_sort(vector<unsigned int> &Arr)
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

int main() //modify to keep taking file names and sorting until user quits
{

    // Specify the input and output file names
    string inputFileName;
    string outputFileName;
    cout << "Enter the file name to sort: ";
    cin >> inputFileName;
    cout << endl;

    outputFileName = "insertion_sort_times.txt";

    // Open the input file
    ifstream inputFile(inputFileName); // open the file
    ofstream outputFile(outputFileName, ios::app); // append to file

    if (!inputFile)
    {
        while(!inputFile)
        {
            cerr << "Error: Unable to open input file." << endl;
            cout << "\nEnter the file name to sort: ";
            cin >> inputFileName;
            cout << endl;
            inputFile.open(inputFileName); // open the file
        }
    }
    else if (!outputFile)
    {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    // Read the array from the input file
    vector<unsigned int> Arr;
    string num;
    int array_num = 0; //for output file array listing

    // SAMPLE: A: [1,2,3,4,5,6,7,8,9,10]
    // Skip characters until the start of the array
    while(inputFile)
    {
        cout << "in while loop" << endl;
        outputFile << "-------LIST: " << inputFileName << " SORTED-------" <<endl;
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
                    Arr.push_back(stoull(temp));
                    temp = "";
                }
                else if (num[i] == ']')
                {
                    Arr.push_back(stoull(temp));
                    break;
                }
            }
            
            //remove array printing and move timing into its own function
            //Also move the outputFile writing to the function
            if(Arr.size() > 0)
            {
                auto start = chrono::high_resolution_clock::now(); // Start the timer
                insertion_sort(Arr);                               // Sort the array using insertion sort
                auto stop = chrono::high_resolution_clock::now();
                auto micro = chrono::duration_cast<chrono::microseconds>(stop - start);
                auto milli = chrono::duration_cast<chrono::milliseconds>(stop - start);
                auto seconds = chrono::duration_cast<chrono::seconds>(stop - start);

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
                outputFile << "\t" << seconds.count() << " seconds\n" << endl;

                array_num++; // Increment the array number for the output file
            }
        }
        
    }
    // Close the input & output file
    inputFile.close();
    outputFile.close();
    return 0;
}

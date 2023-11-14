# Sorting Algorithm Analysis with C++ and Python
## Repository Contents
  - ### Sorting Implementations
    - insertion_sort.h
    - merge_sort.h
    - heap_sort.h
    - quick_sort.h
    - counting_sort.h
    - radix_sort.h
    - bucket_sort.h
  - ### List Generation, Driver and Makefile
    - list_generator.cpp
    - driver.cpp
    - Makefile
  - ### Input
    - user_input.txt
    - insert_input.txt
    - list{n}.txt
    - float_list{n}.txt
      - where n is 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000
  - ### Plot
    - plotting.py

## Input File Format
- The list{n}.txt and float_list{n}.txt files contain arrays of random values in the range U[0, 2^16) and U[0, 1) respectively. 
  - The array format is `A: [rand1,rand2,...,n-1,n]`
- The input.txt files contain the user's input if the user wants to test all list sizes on each algorithm.
  - For reasons explained below, the insertion_sort input is separate from the other algorithms and has its own input file.

## How it Works
- **Each algorithm is implemented in a header file.**
- ### The `driver.cpp` program includes the headers and makes calls to the respective sorting function when indicated by the user.
  - The algorithm is timed using the chrono library from the C++ STL.
  - The timed results are outputted into a text file named as follows`sortingName_times.txt`.
- ### Running `plotting.py` in the same directory as the files will ask for some attributes of the graph (on the terminal).
  - Input the time metric (0 for microseconds, 1 for milliseconds, 2 for seconds) you want to view a graph for.
  - Determine whether or not you want to view insertion_sort along with all the other algorithms.
    - Insertion sort overshadows all of the other times making them stay at 0.0.
  - Determine the number of lists you want to be displayed.
    - Like an array, you can express the maximum size of your graph as an index(i).
    - 1 = list10.txt, 2 = list50.txt, ..., 10 = list500000.txt, 11 = list1000000.txt.
    - The plot will then display lists[0 - i)

## Makefile Targets
**all**: Builds both `list_generator` and `driver`.

**list_generator**: Compiles `list_generator.cpp` to create the `list_generator` executable.

**driver**: Compiles `driver.cpp` along with sorting algorithms' header files to create the `driver` executable.

**run_gen**: Runs the `list_generator` executable.

**run_driver**: Runs the `driver` executable with input from `user_input.txt`.

**run_plot**: Plots the data from running `driver.cpp` by running `plotting.py`

**clean**: Removes the `list_generator` and `driver` executables.

**clean_data**: Removes generated list data files (`list*.txt` and `float_list*.txt`).

**clean_results**: Removes generated time data files (`sortingName_times*.txt`).

## Make Order
```
make
make run_gen
make driver
make run_driver
```
  -  `make run_driver` uses the `user_input.txt` to iterate through every input the user would have to make to test every file on every sorting algorithm other than `insertion_sort`. Because `insertion_sort` takes anywhere from 21 - 35 minutes to complete, it would be impractical to test it along with the other algorithms. The other algorithms take seconds to iterate through all the files. To test insertion sort you can run:
```
make run_insert
```
_**or**_
```
./driver < insert_input.txt
```
```
make run_plot
```
  - To run the Python program please make sure to have `matplotlib` installed on your system's version of Python.
  - Matplotlib can be downloaded as follows:
```
pip install matplotlib
```

## Note on List Generation On Linprog

**TLDR**: `list_generation` on linprog rarely gets time on the CPU and therefore takes forever to complete. Please, use the provided lists as suggested by Dr.Mascagni.

Linprog takes a ridiculous amount of time to complete running the `list_generator` executable. If you wait it will finish ... Eventually. At first, I thought it may be due to a library I was using. But after using the `htop` command and filtering by _"./list_generator"_ I observed the program doing nothing. The CPU had not yet granted the program its turn on the CPU schedule. If you do this as well you can observe the same behavior, where the program is only granted a millisecond or two at a time in intervals of multiple minutes. Because of this, the `list_generator` will take forever to complete its process. I tried to use different methods of generating the lists just in case the libraries/functions I was using were the root of the problem. This did not improve the problem. Please, use the lists provided on the `.tar` file. 

The file was tested on a variety of environments other than linprog. `list_generator` runs without any issues on Windows 10, a VM running Ubuntu 22.04, and WSL2 running Ubuntu 20.04. 

## Million Item Sorting with Insertion Sort on Linprog
You may encounter some unexpected behavior when testing `insertion_sort` on `list1000000.txt`. Since sorting this list takes over 20 minutes to complete, it may seem like linprog _"hangs"_ after finishing its sorting. This can again be observed using the `htop` command and filtering by `./driver` you will see how long the program has been running and after 21-35 minutes you will see the timer stop counting yet the program has not returned the Sorting Time. This can be due to a broken pipe (from inactivity). If you haven't been disconnected, pressing enter on the terminal a couple of times after the timer on `htop` has stopped will update the terminal returning the sorting time. 

- This issue does not happen every time.
- This issue was not observed on any of the other three aforementioned environments used for testing. 


# Sorting Algorithm Analysis with C++ and Python
- ## Complexity Analysis of Sorting Algorithms:
- Insertion Sort
- Merge Sort
- Quick Sort
- Heap Sort
- Counting Sort
- Bucket Sort
- Radix Sort
- ## How it Works:
- **Each algorithm is implemented in a header file.**
- ### The `driver.cpp` program includes the headers and makes calls to the respective sorting function when indicated by the user.
  - The algorithm is timed using the chrono library from the C++ STL.
  - The timed results are outputted into a text file named as follows`sortingName_times.txt`.
- ### Running `plotting.py` in the same directory as the files will ask for some attributes of the graph.
  - Input the time metric (0 for microseconds, 1 for milliseconds, 2 for seconds) you want to view a graph for.
  - Determine whether or not you want to view insertion_sort along with all the other algorithms.
    - Insertion sort overshadows all of the other times making them stay at 0.0.
  - Determine the number of lists you want to be displayed.
    - Like an array, you can express the maximum size of your graph as an index(i).
    - 1 = list10.txt, 2 = list50.txt, ..., 10 = list500000.txt, 11 = list1000000.txt.
    - The plot will then display lists[0 - i)

# Makefile Targets
**all**: Builds both `list_generator` and `driver`.

**list_generator**: Compiles `list_generator.cpp` to create the `list_generator` executable.

**driver**: Compiles `driver.cpp` along with sorting algorithms' header files to create the `driver` executable.

**run_gen**: Runs the `list_generator` executable.

**run_driver**: Runs the `driver` executable with input from `user_input.txt`.

**run_plot**: Plots the data from running `driver.cpp` by running `plotting.py`

**clean**: Removes the `list_generator` and `driver` executables.

**clean_data**: Removes generated list data files (`list*.txt` and `float_list*.txt`).

**clean_results**: Removes generated time data files (`sortingName_times*.txt`).

# Make Order
1. `make`
2. `make run_gen`
3.  `make driver`
4.  `make run_driver`
5.  `make run_plot`

# Note on List Generation On Linprog

TLDR: `list_generation` on linprog rarely gets time on the CPU and therefore takes forever to complete. Please, use the provided lists as suggested by Dr.Mascagni.

Linprog takes a ridiculous amount of time to complete running the `list_generator` executable. At first, I thought it may be due to a library I was using. But after using the `htop` command and filtering by _"./list_generator"_ I observed the program doing nothing. The CPU had not yet granted the program its turn on the CPU schedule. If you do this as well you can observe the same behavior, where the program is only granted a millisecond or two at a time in intervals of multiple minutes. Because of this, the `list_generator` will take forever to complete its process. I tried to use different methods of generating the lists just in case the libraries/functions I was using were the root of the problem. This did not improve the problem. Please, use the lists provided on the `.tar` file. 


Because insertion sort overshadows all of the other algorithms when it comes to the time it takes
to complete, plotting the times for all of the lists we see all other algorithms assume a flat line
(value of 0) due to the scale of the Y-Axis. Excluding insertion sort from our plots (by selecting
‘n’ when prompted) allows us to take a closer look at how these algorithms perform. Below I
have included the plot for all the lists including insertion sort in the mix. The plot is in seconds
but we observe the same relationship across all time metrics. The rest of the plots have been
labeled and exclude insertion sort.

If we exclude every list after list10000.txt we can compare Insertion Sort to all the other
algorithms for those given sizes. We can observe how the plot for insertion sort demonstrates a
similar curve regardless of the time metric being used.

How the lists are generated:
Taking a look at the list_generator.cpp program we have two versions of each function that
mirror one another. One version is for lists of integers (U[0, 2 )) and the other is for lists of 16
floats (U[0, 1)). Generate_lists(size) uses the random library’s default_random_engine and
uniform_int_distribution to generate a uniformly distributed integer list of a given size.
Generate_floats(size) simply uses the rand function in a for loop to generate random floats.
Rounding(number * 1000) to make them whole numbers and then dividing by 1000 yields a list
of floats with 4 decimal places in the desired range. I had to account for this setup generating the
value time on occasion. When this happened I set that value to 0.9 to avoid unexpected behavior.
These values are stored in arrays. These arrays are then written, by the write_list and write_floats
functions, to a text file with the names list{n}.txt and float_list{n}.txt respectively. The value n
represents each of the sizes of the arrays created. For lists with array sizes 10, 50, 100, 500,
1000, and 5000 I created more than one array of values to acquire an average time performance
over multiple iterations. They each had 100, 100, 100, 50, 10, and 10 arrays respectively. The
create_lists and create_floats functions specified these sizes and called the functions described
above to generate all of the lists

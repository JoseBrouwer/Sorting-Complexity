import matplotlib.pyplot as plt

# import matplotlib as mpl
import numpy as np
import re


# Function to extract sorting times from the output file
def extract_sorting_times(file_path):
    # 11 different list sizes, stored in order [0] = list10.txt, [1] = list50.txt, etc.
    file_path_times = []
    with open(file_path, "r") as file:
        data = file.read()

    # Use regular expressions to find sorting times
    pattern = re.compile(
        r"Sorting Time:\s*\n\t*(\d+) microseconds\s*\n\t*(\d+) milliseconds\s*\n\t*(\d+) seconds"
    )
    # Stored in a list of tuples
    # (<microseconds>, <milliseconds>, <seconds>)
    matches10 = pattern.findall(data)[:100]  # get 100 times from list10.txt
    matches50 = pattern.findall(data)[100:200]  # get 100 times from list50.txt
    matches100 = pattern.findall(data)[200:300]  # get 100 times from list100.txt
    matches500 = pattern.findall(data)[300:350]  # get 50 times from list500.txt
    matches1000 = pattern.findall(data)[350:360]  # get 10 times from list1000.txt
    matches5000 = pattern.findall(data)[360:370]  # get 10 times from list5000.txt
    last_matches = pattern.findall(data)[370:]  # get rest of times (5 more times)

    # calculate average for each list size
    total_microseconds = 0
    total_milliseconds = 0
    total_seconds = 0

    avg_microseconds = 0
    avg_milliseconds = 0
    avg_seconds = 0

    lists = [matches10, matches50, matches100, matches500, matches1000, matches5000]

    # calculate average for each list size
    for item in lists:
        for match in item:
            microseconds, milliseconds, seconds = map(int, match)
            total_microseconds = total_microseconds + microseconds
            total_milliseconds = total_milliseconds + milliseconds
            total_seconds = total_seconds + seconds

        avg_microseconds = total_microseconds / len(item)
        avg_milliseconds = total_milliseconds / len(item)
        avg_seconds = total_seconds / len(item)

        avg_tuple = (avg_microseconds, avg_milliseconds, avg_seconds)
        file_path_times.append(avg_tuple)

        # reset variables
        total_microseconds = 0
        total_milliseconds = 0
        total_seconds = 0

        avg_microseconds = 0
        avg_milliseconds = 0
        avg_seconds = 0

    # calculate average for last 5 list sizes
    for match in last_matches:
        microseconds, milliseconds, seconds = map(int, match)
        total_microseconds = total_microseconds + microseconds
        total_milliseconds = total_milliseconds + milliseconds
        total_seconds = total_seconds + seconds

        avg_microseconds = total_microseconds
        avg_milliseconds = total_milliseconds
        avg_seconds = total_seconds

        avg_tuple = (avg_microseconds, avg_milliseconds, avg_seconds)
        file_path_times.append(avg_tuple)

        # reset variables
        total_microseconds = 0
        total_milliseconds = 0
        total_seconds = 0

        avg_microseconds = 0
        avg_milliseconds = 0
        avg_seconds = 0

    return file_path_times


import matplotlib.pyplot as plt


def plot_average_times(file_path_times):
    labels = [
        "list10",
        "list50",
        "list100",
        "list500",
        "list1000",
        "list5000",
        "list10000",
        "list50000",
        "list100000",
        "list500000",
        "list1000000",
    ]

    # Extract microseconds, milliseconds, and seconds from the tuples
    avg_microseconds = [t[0] for t in file_path_times]
    avg_milliseconds = [t[1] for t in file_path_times]
    avg_seconds = [t[2] for t in file_path_times]

    # Plotting
    plt.figure(figsize=(10, 6))
    plt.plot(labels, avg_microseconds, marker="o", label="Microseconds")
    plt.plot(labels, avg_milliseconds, marker="o", label="Milliseconds")
    plt.plot(labels, avg_seconds, marker="o", label="Seconds")

    plt.title("Average Sorting Times")
    plt.xlabel("List Size")
    plt.ylabel("Time")
    plt.legend()
    plt.grid(True)
    plt.show()


if __name__ == "__main__":
    insertion_sort = extract_sorting_times("insertion_sort_times.txt")
    merge_sort = extract_sorting_times("merge_sort_times.txt")
    heap_sort = extract_sorting_times("heap_sort_times.txt")
    quick_sort = extract_sorting_times("quick_sort_times.txt")
    counting_sort = extract_sorting_times("counting_sort_times.txt")
    radix_sort = extract_sorting_times("radix_sort_times.txt")
    bucket_sort = extract_sorting_times("bucket_sort_times.txt")
    print("Insertion Sort Times: ", insertion_sort, "\n")
    print("Merge Sort Times: ", merge_sort, "\n")
    print("Heap Sort Times: ", heap_sort, "\n")
    print("Quick Sort Times: ", quick_sort, "\n")
    print("Counting Sort Times: ", counting_sort, "\n")
    print("Radix Sort Times: ", radix_sort, "\n")
    print("Bucket Sort Times: ", bucket_sort, "\n")

    # Plotting
    plot_times = insertion_sort
    plot_average_times(plot_times)

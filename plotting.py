import matplotlib.pyplot as plt
import re


# Function to extract sorting times from the output file
def extract_sorting_times(file_path):
    """
    This function parses the sorting time text files
    using regular expressions and storing the results
    of each array as a tuple of microseconds, milliseconds
    and seconds
    :param file_path: The file to extract data from
    :return: array of tuples for each list
    """
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


def plot_average_times(file_path_times, time_metric, max_list_size):
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
    ][:max_list_size]

    plt.figure(figsize=(12, 10))
    for algorithm, times in file_path_times.items():
        avg_times = [t[time_metric] for t in times][:max_list_size]
        plt.plot(labels, avg_times, marker="o", label=algorithm.capitalize())

    if time_metric == 0:
        time_metric_str = "microseconds"
    elif time_metric == 1:
        time_metric_str = "milliseconds"
    else:
        time_metric_str = "seconds"

    plt.title(f"Average Sorting Times ({time_metric_str.capitalize()})")
    plt.xlabel("List Size")
    plt.ylabel(f"Time ({time_metric_str.capitalize()})")
    plt.legend()
    plt.grid(True)
    plt.show()


def on_close(event):
    plt.close()


if __name__ == "__main__":
    algorithms = [
        "insertion_sort",
        "merge_sort",
        "heap_sort",
        "quick_sort",
        "counting_sort",
        "radix_sort",
        "bucket_sort",
    ]

    algorithm_times = {}
    for algorithm in algorithms:
        times = extract_sorting_times(f"{algorithm}_times.txt")
        algorithm_times[algorithm] = times

    time_metric = input(
        "Enter the time metric (microseconds(0), milliseconds(1), seconds(2)): "
    )
    while time_metric not in ["0", "1", "2"]:
        print("Invalid time metric. Please enter one of: 0, 1, 2")
        time_metric = input(
            "Enter the time metric (microseconds(0), milliseconds(1), seconds(2)): "
        )
    time_metric = int(time_metric)

    insertion = input("Display insertion sort? (y/n): ")
    while insertion not in ["y", "n"]:
        print("Invalid input. Please enter one of: y, n")
        insertion = input("Display insertion sort? (y/n): ")
    if insertion == "n":
        del algorithm_times["insertion_sort"]

    max_list_size = int(input("Enter the maximum list size to display: "))
    while max_list_size < 1 or max_list_size > 11:
        print("Invalid list size. Please enter a value between 1 and 11.")
        max_list_size = int(input("Enter the maximum list size to display: "))

    display = True
    while display:
        plot_average_times(algorithm_times, time_metric, max_list_size)
        fig = plt.gcf()
        if display:
            fig.canvas.mpl_connect("close_event", on_close("close_event"))
            display = False

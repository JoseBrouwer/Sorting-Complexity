CXX = g++
CXXFLAGS = -std=c++11

# List of list sizes
LIST_SIZES = 10 50 100 500 1000 5000 10000 50000 100000 500000 1000000
ALGORITHMS = insertion_sort merge_sort heap_sort quick_sort counting_sort radix_sort bucket_sort

# Targets
all: list_generator driver

list_generator: list_generator.cpp
	$(CXX) $(CXXFLAGS) -o list_generator list_generator.cpp

driver: driver.cpp insertion_sort.h merge_sort.h heap_sort.h quick_sort.h counting_sort.h radix_sort.h bucket_sort.h
	$(CXX) $(CXXFLAGS) -o driver driver.cpp

run_gen: clean_data list_generator
	./list_generator

run_driver: driver
	./driver < user_input.txt

run_plot: plotting.py
	python3 plotting.py

clean:
	rm -f list_generator
	rm -f driver

clean_data:
	for size in $(LIST_SIZES); do \
		rm -f list$${size}.txt; \
		rm -f float_list$${size}.txt; \
	done

clean_results:
	for size in $(ALGORITHMS); do \
		rm -f $${size}_times.txt; \
	done

.PHONY: all clean run_gen run_insert clean_data

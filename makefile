CXX = g++
CXXFLAGS = -std=c++11

# List of list sizes
LIST_SIZES = 10 50 100 500 1000 5000 10000 50000 100000 500000 1000000

# Targets
all: list_generator driver

list_generator: list_generator.cpp
	$(CXX) $(CXXFLAGS) -o list_generator list_generator.cpp

driver: driver.cpp insertion_sort.h merge_sort.h heap_sort.h 
	$(CXX) $(CXXFLAGS) -o driver driver.cpp


clean:
	rm -f list_generator
	rm -f driver

run_gen: list_generator
	./list_generator

#rm -f insertion_sort_times.txt;
clean_data:
	for size in $(LIST_SIZES); do \
		rm -f list$${size}.txt; \
	done

.PHONY: all clean run_gen run_insert clean_data

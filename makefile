CXX = g++
CXXFLAGS = -std=c++11

# List of list sizes
LIST_SIZES = 10 50 100 500 1000 5000 10000 50000 100000 500000 1000000

# Targets
all: list_generator insertion_sort

list_generator: list_generator.cpp
	$(CXX) $(CXXFLAGS) -o list_generator list_generator.cpp

insertion_sort: insertion_sort.cpp
	$(CXX) $(CXXFLAGS) -o insertion_sort insertion_sort.cpp

clean:
	rm -f list_generator
	rm -f insertion_sort

run_gen: list_generator
	./list_generator

run insert: list_generator
	./list_generator
	for size in $(LIST_SIZES); do \
		./insertion_sort list$${size}.txt; \
	done

clean_data:
	for size in $(LIST_SIZES); do \
		rm -f list$${size}.txt; \
		rm -f time_list$${size}.txt; \
	done

.PHONY: all clean run clean_data

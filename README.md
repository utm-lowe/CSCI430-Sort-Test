# Sort-Test
This program validates sorting algorithms and then computes their average
running time over a user specified number of runs. (The default number of runs
is 10.)

To use this program, place your sorting algorithms in the sorts directory. The
sorting algorithms must be divided up into a header and cpp file. The header file
must have the same name as the sorting function and it should accept a vector of
integers by reference as its only argument.

As an example, the file `sorts/std_sort.h` and `sorts/std_sort.cpp` are provided.
These files run the STL `std::sort` algorithm on a vector. See these files for
the expected format and usage.

You can define multiple functions in your `cpp` files, so long as the primary
interface is as described.

Running `make` will build the program. Apart from adding your files to the
`sorts` directories, no other modifications are necessary. 

## Running the Test
To run the program use the command `./sort-test <array size> [<run count>]`
This will create a random vector of array size random integers and run them
for run count iterations. The program will also verify that each sort algorithm
works. If the validity test fails, then the program will exit with an error.

The program will report the results of the validity tests, and if the sorts pass
it will then move on to the timing test. The timing test will report the average
running time of the sorting algorithm in nano seconds.
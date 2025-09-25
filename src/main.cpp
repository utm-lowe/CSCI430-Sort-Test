/**
 * @file main.cpp
 * @author Robert Lowe <rlowe8@utm.edu> 
 * @brief Test sorting algorithms for speed.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "sortTest.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
    unsigned int arsize;
    unsigned int runcount=10;

    // Display usage 
    if(argc != 2 and argc != 3) {
        std::cerr << "Usage: " << argv[0] 
                  << " <array size> [<run count>]" << std::endl;
        return -1;
    }

    // get the arsize and runcount
    arsize = static_cast<unsigned int>(std::strtoul(argv[1], nullptr, 10));
    if(argc == 3) {
        runcount = static_cast<unsigned int>(std::strtoul(argv[2], nullptr, 10));
    }

    // handle invalid arguments 
    if(arsize == 0 or runcount == 0) {
        std::cerr << "Invalid arguments." << std::endl;
        return -2;
    }

    // First, run the validity test
    std::cout << "Running validity test with array size " 
              << arsize << std::endl;
    if(not validityTest(arsize)) {
        std::cerr << "Validity test failed. Aborting." << std::endl;
        return -3;
    }
    std::cout << std::endl;

    // Now run the timing tests
    std::cout << "Average running timing test with array size " 
              << arsize << " and run count " << runcount << std::endl;
    timeTest(arsize, runcount);
}

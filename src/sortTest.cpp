/**
 * @file sortTest.cpp
 * @author Robert Lowe <rlowe8@utm.edu>
 * @brief Implementation of the sort tests.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "timingFixture.hpp"
#include "sortTest.hpp"
#include "sorts.h"
#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <random>
#include <algorithm>

/**
 * @brief Return a vector with n random entries.
 * 
 * @param n 
 * @return std::vector<int> 
 */
static std::vector<int> randomVector(std::size_t n)
{
    std::vector<int> v(n);
    std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<int> dist(0, n*10);

    std::generate(v.begin(), v.end(), [&mt, &dist]() { return dist(mt); });

    return v;
}


// Test the validity of the sort functions.
bool validityTest(unsigned int arsize)
{
    std::vector<int> v = randomVector(arsize);
    std::vector<int> sorted = v;

    // sort the vector with std::sort to get the correct answer
    std::sort(sorted.begin(), sorted.end());

    // Now test each of our sort functions
    for(const auto& sort : sorts) {
        std::vector<int> toSort = v;
        sort.function(toSort);
        if(toSort != sorted) {
            std::cout << "Sort " << sort.name << " failed!" << std::endl;
            return false;
        } else {
            std::cout << "Sort " << sort.name << " passed." << std::endl;
        } 
    }
    return true;
}


// Run the time tests and print the results.
void timeTest(unsigned int arsize, unsigned int runcount)
{
    std::vector<int> v = randomVector(arsize);

    // Run each sort runcount times and average the results
    for(const auto& sort : sorts) {
        auto timer = makeTimingFixture<std::chrono::nanoseconds>(sort.function, v);
        timer.run(); // warmup run
        std::cout << sort.name << "\t" << timer.average(runcount) << std::endl;
    }
}
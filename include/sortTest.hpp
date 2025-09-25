/**
 * @file sortTest.hpp
 * @author Robert Lowe <rlowe8@utm.edu>
 * @brief Handy things for testing sorts.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#include <string>
#include <vector>
#include <functional>


/**
 * @brief The type of the function we will be testing.
 * 
 */
using SortFunction = std::function<void(std::vector<int>&)>;

/**
 * @brief A convenient way to store functions so we can name them.
 * 
 */
struct SortContainer
{
    std::string name;
    SortFunction function;
};

/**
 * @brief Test the validity of the sort functions.
 * 
 * @param arsize Size of the array
 * @return true 
 * @return false 
 */
bool validityTest(unsigned int arsize);

/**
 * @brief Run the time tests and print the results.
 * 
 * @param arsize Size of the array
 * @param runcount How many times should we run it?
 */
void timeTest(unsigned int arsize, unsigned int runcount);
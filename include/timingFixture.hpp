/**
 * @file timingFixture.hpp
 * @author Bob Lowe <rlowe8@utm.edu
 * @brief This is a template for a high-resolution timing fixture.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#include <chrono>


/**
 * @brief A timing fixture for measuring the performance of a function.
 * 
 * @tparam Resolution The std::chrono resolution type
 * @tparam Function The function type
 * @tparam Argument The argument type
 */
template<typename Resolution, typename Function, typename Argument>
class TimingFixture
{
public: 
    /**
     * @brief Construct a new Timing Fixture object
     * 
     * @param func The function to time
     * @param arg The argument to the function
     */
    TimingFixture(Function func, Argument arg) : func(func), arg(arg) {}

    
    /**
     * @brief Run the timing fixture once and return the time.
     * 
     * @return unsigned long long The duration in the specified resolution
     */
    unsigned long long run() {
        // copy the argument
        Argument argcopy(arg);

        // Perform the run 
        auto start = std::chrono::high_resolution_clock::now();
        func(arg);
        auto end = std::chrono::high_resolution_clock::now();

        // get the duration
        auto duration = std::chrono::duration_cast<Resolution>(end-start);
        return duration.count();
    }


    /**
     * @brief Run the timing fixture count times and return the average time.   
     * 
     * @param count The number of times to run the test
     * @return unsigned long long The average duration in the specified resolution
     */
    unsigned long long average(unsigned int count) {
        unsigned long long total=0;

        // run for count number of times, accumulating total
        for(unsigned int i=0; i<count; i++) {
            total += run();
        }

        // return the average
        return total / count;
    }
private:
    Function func;
    Argument arg;
};


/**
 * @brief A factory function to create a TimingFixture with type deduction.
 * 
 * @tparam Resolution The std::chrono resolution type
 * @tparam Function The function type
 * @tparam Argument The argument type
 * @param func The function
 * @param arg The argument
 * @return TimingFixture<Resolution, Function, Argument> 
 */
template<typename Resolution, typename Function, typename Argument>
TimingFixture<Resolution, Function, Argument> makeTimingFixture(Function func, Argument arg) 
{
    return TimingFixture<Resolution, Function, Argument>(func, arg);
}
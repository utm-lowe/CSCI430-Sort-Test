#include "std_sort.h"
#include <algorithm>

 // Sort the vector using the standard library sort.
void std_sort(std::vector<int> &v)
{
    std::sort(v.begin(), v.end());
}
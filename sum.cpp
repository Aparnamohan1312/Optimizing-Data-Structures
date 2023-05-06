#include <cstdlib>
#include "archlab.h"
#include <unistd.h>
#include<algorithm>
#include<cstdint>
#include<unordered_set>
#include <unordered_map>
#include "perfstats.h"
#include "sum.h"
#include "math.h"

#define START_C extern "C" { // this just hides the braces from the editor, so it won't try to indent everything.
#define END_C  }


START_C

uint64_t sum_of_locations_solution(uint64_t *search_space, uint32_t search_space_size, uint64_t* queries, uint32_t query_count)

    {
  uint64_t r = 0;
    //I broke down the optimization problem into two parts. Step 1 is to sort both arrays
    std::sort(search_space, search_space + search_space_size);
    std::sort(queries, queries + query_count);
    //Step 2 is using two pointers approach 
    uint32_t pointer1 = 0;
    uint32_t pointer2 = 0;
    while (pointer1 < query_count && pointer2 < search_space_size) {
         if (queries[pointer1] < search_space[pointer2]) 
            pointer1 = pointer1+1;
         else if (queries[pointer1] > search_space[pointer2]) 
            pointer2 = pointer2+1;
         else {
            r += pointer1;
            pointer2 = pointer2+1;}
    }
return r;
}
// hello
END_C
#include "allocator.h"

#include <map>
#include <iostream>


int factorial(int n)
{
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}


int main()
{
    using allocator = reserved_allocator<10>::allocator<std::pair<int, int>>;
    std::map<int, int, std::less<int>, allocator> test_map;

    for (int i=0; i<10; i++)
    {
        test_map.insert(std::pair<int, int>(i, factorial(i)));
    }

    std::cout << "map with custom allocator:" << std::endl;
    for (const auto &pair: test_map)
    {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}

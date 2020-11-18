#include "allocator.h"
#include "stack.h"

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
    std::map<int, int> map_std_alloc;

    for (int i=0; i<10; i++)
    {
        map_std_alloc.insert(std::pair<int, int>(i, factorial(i)));
    }

    std::cout << "map with std allocator:" << std::endl;
    for (const auto &pair: map_std_alloc)
    {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    using allocator = reserved_allocator<10>::allocator<std::pair<int, int>>;
    std::map<int, int, std::less<int>, allocator> map_custom_alloc;

    for (int i=0; i<10; i++)
    {
        map_custom_alloc.insert(std::pair<int, int>(i, factorial(i)));
    }

    std::cout << "map with custom allocator:" << std::endl;
    for (const auto &pair: map_custom_alloc)
    {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    stack<int> stack_std_alloc;
    for (int i=0; i<10; i++)
    {
        stack_std_alloc.push(i);
    }

    std::cout << "stack with std allocator:" << std::endl;
    for (int i=0; i<10; i++)
    {
        std::cout << stack_std_alloc[i] << std::endl;
    }
}

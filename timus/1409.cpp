#include <iostream>


int main()
{
    int harry_shoot_count, larry_shoot_count;
    std::cin >> harry_shoot_count >> larry_shoot_count;
    int total_count = harry_shoot_count + larry_shoot_count - 1;    // one is common

    std::cout
        << total_count - harry_shoot_count << " "
        << total_count - larry_shoot_count << std::endl; 
}

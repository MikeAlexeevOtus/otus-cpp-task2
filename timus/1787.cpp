#include <iostream>


int main()
{
    int cars_throughput, observation_duration_minutes;
    std::cin >> cars_throughput >> observation_duration_minutes;

    int stucked_cars = 0;
    int added_cars;
    for (int i=0; i < observation_duration_minutes; i++)
    {
        std::cin >> added_cars;
        stucked_cars += (added_cars - cars_throughput);
        stucked_cars = stucked_cars > 0? stucked_cars: 0;
    }

    std::cout << stucked_cars << std::endl;
}

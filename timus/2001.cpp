#include <iostream>


int main()
{
    int a1, b1, a2, b2, a3, b3;
    std::cin
        >> a1 >> b1
        >> a2 >> b2
        >> a3 >> b3;

    int result_a = b3 - b1;     // (busket b + result a + result b) - (busket b + result b)
    int result_b = a2 - a1;     // (busket a + result a + result b) - (busket a + result a)
    std::cout << result_a << " " << result_b << std::endl;
}

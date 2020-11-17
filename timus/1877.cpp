#include <iostream>
#include <string>

bool IsEven(int number) 
{
    return !(number % 2);
}


int main()
{
    int code_1, code_2;
    std::cin >> code_1 >> code_2;
    bool can_be_cracked = IsEven(code_1) or !IsEven(code_2);
    const std::string answer = can_be_cracked? "yes": "no";
    std::cout << answer << std::endl;
}

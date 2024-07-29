#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    try
    {
        std::vector<int>::iterator iter = easyFind(vec, 3);
        std::vector<int>::iterator it_nope = easyFind(vec, 6);
        std::cout << "Found: " << *iter << std::endl;
        std::cout << "Found: " << *it_nope << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Not found" << std::endl;
    }
    return 0;
}
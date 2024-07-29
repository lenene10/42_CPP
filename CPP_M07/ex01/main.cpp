#include "iter.hpp"

#include <iostream>

void ft_print(int& i)
{
    std::cout << i << std::endl;
}

void ft_print_str(char **&c)
{
    std::cout << *c << std::endl;
}

int main()
{
    try {
        char ***chartab = new char**[2];
        chartab[0] = new char*;
        chartab[1] = new char*;
    
        chartab[0][0] = (char*)"ab";
        chartab[1][0] = (char*)"cd";
        int tab[] = {0, 1, 2, 3, 4};
        ::iter(tab, sizeof(tab) / sizeof(int), ft_print);
        ::iter(chartab, 2, ft_print_str);

        delete chartab[0];
        delete chartab[1];
        delete [] chartab;
    }
    catch (std::bad_alloc &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
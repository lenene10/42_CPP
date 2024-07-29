#include "Span.hpp"
#include <exception>
#include <iostream>

int main()
{

    try
    {
        Span sp1 = Span(5);
        sp1.addNumber(5);
        sp1.addNumber(3);
        sp1.addNumber(17);
        sp1.addNumber(9);
        sp1.addNumber(11);
        std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
        Span sp = Span(1);
        sp.addNumber(11);
        sp.addNumber(12);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try {
        Span sp = Span(10001);
        std::vector<int> vec(10000);
        int i = 0;
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
            *it = ((i++ + 1) * 2);
        
        //print_vector(vec);
        sp.fillArray(vec);
        sp.addNumber(1);
        sp.printContent();
        sp.addNumber(1);
    
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
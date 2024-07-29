#include "RPN.hpp"
#include <exception>
#include <iomanip>
#include <iostream>
#include <cmath>

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Bad input. Usage: " << argv[0] << " <expression>" << std::endl;
        return 1;
    }

    RPN rpn;
    bool was_symbol = false;

    for (int i = 0; argv[1][i]; i++) {
        if (argv[1][i] == ' ')
        {
            was_symbol = false;
            continue;
        }
        if (was_symbol)
        {
            std::cerr << "Error: Please separate the symbols with at least 1 space" << std::endl;
            return 1;
        }
        if (argv[1][i + 1] && argv[1][i + 1] != ' ')
        {
            std::cerr << "Error: Each symbol must be exactly 1 character " << std::endl;
            return 1;
        }
        try {
            rpn.push_to_stack(argv[1][i]);
            if (argv[1][i] == '+' || argv[1][i] == '-' || argv[1][i] == '*' || argv[1][i] == '/')
                rpn.operate(argv[1][i]);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }
        was_symbol = true;
    }
    try {
        float num = rpn.get_result();
        std::cout << num << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
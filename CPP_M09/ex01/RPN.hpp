#pragma once

#include <iostream>
#include <stack>

class RPN {
    std::stack<float> _stack;
    public:
        RPN();
        RPN &operator=(const RPN &rhs);
        RPN(const RPN &other);
        ~RPN();

        void    push_to_stack(const char ch);
        void    operate(char ch);
        float   get_result() const;
};
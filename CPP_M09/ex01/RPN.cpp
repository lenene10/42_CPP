#include "RPN.hpp"
#include <stdexcept>

void    RPN::push_to_stack(const char ch) {
    if (ch >= '0' && ch <= '9')
        _stack.push(ch - '0');
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        if (_stack.top() == 0 && ch == '/')
            throw std::runtime_error("Division by zero");
        if (_stack.size() < 2)
            throw std::runtime_error("Not enough operands");
    }
    else
        throw std::runtime_error("Invalid character");
}

void    RPN::operate(char ch)
{
    float   a;
    float   b;

    a = _stack.top();
    _stack.pop();
    b = _stack.top();
    _stack.pop();

    if (ch == '+')
        _stack.push(a + b);
    else if (ch == '-')
        _stack.push(b - a);
    else if (ch == '*')
        _stack.push(a * b);
    else if (ch == '/')
        _stack.push(b / a);

    if (_stack.top() > static_cast<float>(2147483647) || _stack.top() < static_cast<float>(-2147483648))
        throw std::runtime_error("Overflow");
}

float   RPN::get_result() const {
    if(_stack.size() != 1)
        throw std::runtime_error("Invalid expression");
    return _stack.top();
}

RPN::RPN() {
    _stack = std::stack<float>();
}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rhs) {
    _stack = rhs._stack;
    return *this;
}
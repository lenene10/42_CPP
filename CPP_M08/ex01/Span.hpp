#pragma once

#include <iostream>
#include <vector>

class Span
{
    private:
        unsigned int _size;
        unsigned int _currentlyFilled;
        std::vector<int> _vec;
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int n);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        void fillArray(std::vector<int> vec);

        unsigned int getSize() const;
        unsigned int getCurrentlyFilled() const;
        std::vector<int> getArr() const;

        void   printContent();

        class ArrayFullException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class NumberAlreadyExists : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class ArrayTooSmall : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};
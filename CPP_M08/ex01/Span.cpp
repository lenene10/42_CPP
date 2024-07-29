#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int N) : _size(N), _currentlyFilled(0)
{
    _vec = std::vector<int>(N);
}


Span& Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _size = other.getSize();
        _currentlyFilled = other.getCurrentlyFilled();
        _vec = std::vector<int>(_size);
        for (unsigned int i = 0; i < _currentlyFilled; i++)
            _vec[i] = other.getArr()[i];
    }
    return *this;
}

Span::~Span()
{}

Span::Span(const Span& other)
{
    if (this != &other)
        *this = other;
}

//getters

unsigned int Span::getSize() const
{
    return _size;
}

std::vector<int> Span::getArr() const
{
    return _vec;
}

unsigned int Span::getCurrentlyFilled() const
{
    return _currentlyFilled;
}

//methods

void Span::addNumber(int n)
{
    if (_currentlyFilled == _size)
        throw Span::ArrayFullException();
    for (unsigned int i = 0; i < _currentlyFilled; i++)
    {
        if (_vec[i] == n)
            throw Span::NumberAlreadyExists();
    }
    _vec[_currentlyFilled++] = n;
}

unsigned int Span::shortestSpan()
{
    unsigned int res = 0;
    if (_currentlyFilled < 2)
        throw Span::ArrayTooSmall();
    std::sort(_vec.begin(), _vec.end());
    res = _vec[1] - _vec[0];
    for(unsigned int i = 2; i < _currentlyFilled; i++)
    {
        if (static_cast<unsigned int>(abs(_vec[i] - _vec[i - 1])) < res)    //check the smallest diffetence
            res = _vec[i] - _vec[i - 1];    //new smallest? if yes, set it
    }
    return res;
}

unsigned int Span::longestSpan()
{
    unsigned int res = 0;
    if (_currentlyFilled < 2)
        throw Span::ArrayTooSmall();
    res += *std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end());
    return res;
}

void Span::fillArray(std::vector<int> vec)
{
   
    if (vec.size() > _size - _currentlyFilled)
        throw Span::ArrayFullException();
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        addNumber(*it);
}

//exceptions

const char* Span::ArrayFullException::what() const throw()
{
    return "Array is full!";
}

const char* Span::NumberAlreadyExists::what() const throw()
{
    return "Number already exists!";
}

const char* Span::ArrayTooSmall::what() const throw()
{
    return "Array is too small!";
}

void Span::printContent()
{
    for (unsigned int i = 0; i < _currentlyFilled; i++)
        std::cout << _vec[i] << std::endl;
}